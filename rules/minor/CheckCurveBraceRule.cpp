#include "oclint/AbstractASTVisitorRule.h"
#include "oclint/RuleSet.h"
#include "clang/Lex/Lexer.h"
#include <regex>
#include <fstream>

using namespace std;
using namespace clang;
using namespace oclint;

class CheckCurveBraceRule : public AbstractASTVisitorRule<CheckCurveBraceRule>
{
private:
    string description = "Фигурные скобки (в if/else/switch/while и т.д за исключением блоков) всегда должны открываться и закрываться на новой строке";
    
    StringRef getLineAtLineNumber(unsigned int lineNumber)
    {
        SourceManager& sourceManager = _carrier->getSourceManager();
        auto fileID = sourceManager.getMainFileID();
        auto fileEntry = sourceManager.getFileEntryForID(fileID);

        auto startLocation = sourceManager.translateFileLineCol(fileEntry, lineNumber, 1);
        auto endLocation = sourceManager.translateFileLineCol(fileEntry, lineNumber+1, 1);

        auto endLocationWithoutSlashN = endLocation.getLocWithOffset(-1);

        auto lineSourceRange = SourceRange(startLocation, endLocationWithoutSlashN);

        auto nodeStringRef = Lexer::getSourceText(CharSourceRange::getCharRange(lineSourceRange), sourceManager, LangOptions());

        return nodeStringRef;
    }

    bool checkFirstLineOfDeclForStringRef(StringRef string)
    {
        if (string.str() != "{") 
        {
            return true;
        }
        return false;
    }

    bool checkLastLineOfDeclForStringRef(StringRef string)
    {
        if (string.str() != "}") 
        {
            return true;
        }
        return false;
    }

    bool checkFirstLineOfStmtForStringRef(StringRef string)
    {
        std::regex curve_regex("^[\\t ]+\\{(\n|$)");
        std::smatch curve_match;
        if (std::regex_search(string.str(), curve_match, curve_regex)) 
        {
            return false;
        } 
        else
        {
            return true;
        }
    }

    bool checkLastLineOfStmtForStringRef(StringRef string)
    {
        std::regex curve_regex("^\\s+\\}$");
        std::smatch curve_match;

        if (std::regex_search(string.str(), curve_match, curve_regex)) 
        {
            return false;
        }
        else
        {
            return true;
        }
    }

public:
    virtual const string name() const override
    {
        return "check curve brace";
    }

    virtual int priority() const override
    {
        return 3;
    }

    virtual const string category() const override
    {
        return "custom";
    }

#ifdef DOCGEN
    virtual const std::string since() const override
    {
        return "0.12";
    }

    virtual const std::string description() const override
    {
        return ""; // TODO: fill in the description of the rule.
    }

    virtual const std::string example() const override
    {
        return R"rst(
.. code-block:: cpp

    void example()
    {
        // TODO: modify the example for this rule.
    }
        )rst";
    }

    /* fill in the file name only when it does not match the rule identifier
    virtual const std::string fileName() const override
    {
        return "";
    }
    */

    /* add each threshold's key, description, and its default value to the map.
    virtual const std::map<std::string, std::string> thresholds() const override
    {
        std::map<std::string, std::string> thresholdMapping;
        return thresholdMapping;
    }
    */

    /* add additional document for the rule, like references, notes, etc.
    virtual const std::string additionalDocument() const override
    {
        return "";
    }
    */

    /* uncomment this method when the rule is enabled to be suppressed.
    virtual bool enableSuppress() const override
    {
        return true;
    }
    */
#endif

    virtual void setUp() override {}
    virtual void tearDown() override {}
    
    //Visit IfStmt
    bool VisitIfStmt(IfStmt *node)
    {
        // auto ifStmt = node->getThen();
        // if (ifStmt)
        // {
        //     checkFirstLineAtNode(ifStmt);
        //     checkLastLineAtNode(ifStmt);
        // }
        
        // auto elseStmt = node->getElse();
        // if (elseStmt)
        // {
        //     checkFirstLineAtNode(elseStmt);
        //     checkLastLineAtNode(elseStmt);
        // }

        return true;
    }
    

    bool VisitSwitchStmt(SwitchStmt *node)
    {
        return true;
    }

    bool VisitWhileStmt(WhileStmt *node)
    {
        return true;
    }

    bool VisitDoStmt(DoStmt *node)
    {
        return true;
    }


    bool VisitForStmt(ForStmt *node)
    {
        // auto forBody = node->getBody();

        // if (forBody)
        // {
        //     checkFirstLineAtNode(forBody);
        //     checkLastLineAtNode(forBody);
        // }
        return true;
    }


    bool VisitObjCForCollectionStmt(ObjCForCollectionStmt *node)
    {
        return true;
    }
   
    bool VisitObjCMethodDecl(ObjCMethodDecl *node)
    {
        SourceManager& sourceManager = _carrier->getSourceManager();
 
        auto declaratorEndLoc = node->getDeclaratorEndLoc();
        auto declaratorEndLocWithoutOneSymbol = declaratorEndLoc.getLocWithOffset(-1);
        auto declaratorEndLineNumber = sourceManager.getPresumedLineNumber(declaratorEndLocWithoutOneSymbol);
        auto stringAfterDeclaration = getLineAtLineNumber(declaratorEndLineNumber+1);

        ofstream myfile;
        myfile.open ("/Users/antonvlasov/Downloads/example.txt", ios::out | ios::app);
        myfile << stringAfterDeclaration.str();
        myfile.close();

        if(checkFirstLineOfDeclForStringRef(stringAfterDeclaration))
        {
            addViolation(node, this, description);
        }

        auto bodyEndLoc = node->getLocEnd();
        auto bodyEndLineNumber = sourceManager.getPresumedLineNumber(bodyEndLoc);
        auto stringEndBody = getLineAtLineNumber(bodyEndLineNumber);

        if(checkLastLineOfDeclForStringRef(stringEndBody))
        {
            addViolation(node, this, description);
        }

        return true;
    }

};

static RuleSet rules(new CheckCurveBraceRule());
