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
    
    void checkFirstLineAtNode(Decl *node)
    {
        auto nodeRange = node->getSourceRange();
        auto nodeStringRef = Lexer::getSourceText(CharSourceRange::getCharRange(nodeRange), _carrier->getSourceManager(), LangOptions());
        auto pair = nodeStringRef.split("\n");
        auto tail = pair.second;
        pair = tail.split('\n');
        auto firstLine = pair.first;

        if (firstLine.str() != "{") 
        {
            addViolation(node, this, description);
        } 
    }

    void checkLastLineAtNode(Decl *node)
    {
        auto nodeRange = node->getSourceRange();
        auto endLoc = nodeRange.getEnd();
        auto trueEndLoc = endLoc.getLocWithOffset(1);
        nodeRange.setEnd(trueEndLoc);
        auto nodeText = Lexer::getSourceText(CharSourceRange::getCharRange(nodeRange), _carrier->getSourceManager(), LangOptions());
        auto pair = nodeText.rsplit('\n');
        auto lastLine = pair.second;
        if (lastLine.str() != "}") 
        {
            addViolation(node, this, description);
        } 
    }

    void checkFirstLineAtNode(Stmt *node)
    {
        auto nodeRange = node->getSourceRange();
        auto nodeStringRef= Lexer::getSourceText(CharSourceRange::getCharRange(nodeRange), _carrier->getSourceManager(), LangOptions());

        auto pair = nodeStringRef.split("\n");
        auto tail = pair.second;
        pair = tail.split('\n');
        auto firstLine = pair.first;

        std::regex curve_regex("(^|\n)\\s+\\{");
        std::smatch curve_match;
        if (std::regex_search(nodeStringRef.str(), curve_match, curve_regex)) 
        {
        } else
        {
            addViolation(node, this, description);
        }
    }

    void checkLastLineAtNode(Stmt *node)
    {
        auto nodeRange = node->getSourceRange();
        auto endLoc = nodeRange.getEnd();
        auto trueEndLoc = endLoc.getLocWithOffset(1);
        nodeRange.setEnd(trueEndLoc);
        auto nodeStringRef= Lexer::getSourceText(CharSourceRange::getCharRange(nodeRange), _carrier->getSourceManager(), LangOptions());
        auto pair = nodeStringRef.rsplit('\n');
        auto lastLine = pair.second;
        std::regex curve_regex2("(\n)\\s+\\}$");
        std::smatch curve_match2;
        if (std::regex_search(nodeStringRef.str(), curve_match2, curve_regex2)) 
        {
        } else
        {
            addViolation(node, this, description);
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
        checkFirstLineAtNode(node);
        checkLastLineAtNode(node);
        // ofstream myfile;
        // myfile.open ("/Users/antonvlasov/Downloads/example.txt", ios::out | ios::app);
        // myfile << ref.str();
        // myfile << "\n";
        // myfile.close();
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
        return true;
    }


    bool VisitObjCForCollectionStmt(ObjCForCollectionStmt *node)
    {
        return true;
    }
   
    bool VisitObjCMethodDecl(ObjCMethodDecl *node)
    {
        checkFirstLineAtNode(node);
        checkLastLineAtNode(node);
        return true;
    }

};

static RuleSet rules(new CheckCurveBraceRule());
