#include "TestRuleOnCode.h"
#include "rules/custom/CheckCurveBraceRule.cpp"

static string correctCurveBraces =
R"(@interface NSObject
@end

@interface BaseObject : NSObject
@end

@implementation BaseObject

- (int)hash
{
    return 0;
}

@end

)";

static string correctFewCurveBraces =
R"(@interface NSObject
@end

@interface BaseObject : NSObject
@end

@implementation BaseObject

- (int)hash
{
    if (1)
    {

    }
    return 0;
}

@end

)";

static string correctCurveBracesAtForStatement =
R"(@interface NSObject
@end

@interface BaseObject : NSObject
@end

@implementation BaseObject

- (int)hash
{
    for (int i = 0; i < 10; i++)
    {
        int a = 0;
    }
    return 0;
}

@end

)";

static string curveBracesAtMethodDeclarationWithSameLineWithCode =
R"(@interface NSObject
@end

@interface BaseObject : NSObject
@end

@implementation BaseObject

- (int)hash {
    return 0;
}

@end

)";

static string curveBracesAtMethodDeclarationWithExtraTabs =
R"(@interface NSObject
@end

@interface BaseObject : NSObject
@end

@implementation BaseObject

- (int)hash
    {
    return 0;
}

@end

)";

static string curveBracesAtMethodDeclarationWithExtraSpaces =
R"(@interface NSObject
@end

@interface BaseObject : NSObject
@end

@implementation BaseObject

- (int)hash
    {
    return 0;
}

@end

)";

static string endCurveBracesAtMethodDeclarationWithExtraSymbols =
R"(@interface NSObject
@end

@interface BaseObject : NSObject
@end

@implementation BaseObject

- (int)hash
{
    return 0; }

@end

)";

static string curveBracesAtIfStatementWithSameLineWithCode =
R"(@interface NSObject
@end

@interface BaseObject : NSObject
@end

@implementation BaseObject

- (int)hash
{
    if (1) {

    }

    return 0;
}

@end

)";

static string endCurveBracesAtElseStatementWithSameLineWithCode =
R"(@interface NSObject
@end

@interface BaseObject : NSObject
@end

@implementation BaseObject

- (int)hash
{
    if (1)
    {

    }
    else
    {      }

    return 0;
}

@end

)";

static string endCurveBracesAtIfStatementWithSameLineWithCode =
R"(@interface NSObject
@end

@interface BaseObject : NSObject
@end

@implementation BaseObject

- (int)hash
{
    if (1)
    {   }
    else
    {

    }

    return 0;
}

@end

)";

static string startCurveBracesAtElseStatementWithSameLineWithCode =
R"(@interface NSObject
@end

@interface BaseObject : NSObject
@end

@implementation BaseObject

- (int)hash
{
    if (1)
    {

    }
    else {

    }

    return 0;
}

@end

)";

static string startCurveBracesAtForStatementWithSameLineWithCode =
R"(@interface NSObject
@end

@interface BaseObject : NSObject
@end

@implementation BaseObject

- (int)hash
{
    for (int i = 0; i < 10; i++){
        int a = 0;
    }
    return 0;
}

@end

)";

static string startCurveBracesAtForStatementWithEmptyLineWithCode =
R"(@interface NSObject
@end

@interface BaseObject : NSObject
@end

@implementation BaseObject

- (int)hash
{
    for (int i = 0; i < 10; i++)
    
    {
        int a = 0;
    }
    return 0;
}

@end

)";


TEST(CheckCurveBraceRuleTest, PropertyTest)
{
    CheckCurveBraceRule rule;
    EXPECT_EQ(3, rule.priority());
    EXPECT_EQ("check curve brace", rule.name());
    EXPECT_EQ("custom", rule.category());
}

TEST(CheckCurveBraceRuleTest, TestInCorrectCase)
{
    testRuleOnObjCCode(new CheckCurveBraceRule(), correctCurveBraces);
}

TEST(CheckCurveBraceRuleTest, TestCorrectCurveBracesAtForStatement)
{
    testRuleOnObjCCode(new CheckCurveBraceRule(), correctCurveBracesAtForStatement);
}

TEST(CheckCurveBraceRuleTest, TestInCorrectCaseForStmt)
{
    testRuleOnObjCCode(new CheckCurveBraceRule(), correctCurveBraces);
}

TEST(CheckCurveBraceRuleTest, TestWhenCurveBracesAtMethodDeclarationWithSameLineWithCodee)
{
    testRuleOnObjCCode(new CheckCurveBraceRule(), curveBracesAtMethodDeclarationWithSameLineWithCode,
    0, 9, 1, 11, 1, "Фигурные скобки (в if/else/switch/while и т.д за исключением блоков) всегда должны открываться и закрываться на новой строке");
}

TEST(CheckCurveBraceRuleTest, TestWhenCurveBracesAtMethodDeclarationWithExtraTabs)
{
    testRuleOnObjCCode(new CheckCurveBraceRule(), curveBracesAtMethodDeclarationWithExtraTabs,
    0, 9, 1, 12, 1, "Фигурные скобки (в if/else/switch/while и т.д за исключением блоков) всегда должны открываться и закрываться на новой строке");
}

TEST(CheckCurveBraceRuleTest, TestWhenCurveBracesAtMethodDeclarationWithExtraSpaces)
{
    testRuleOnObjCCode(new CheckCurveBraceRule(), curveBracesAtMethodDeclarationWithExtraSpaces,
    0, 9, 1, 12, 1, "Фигурные скобки (в if/else/switch/while и т.д за исключением блоков) всегда должны открываться и закрываться на новой строке");
}

TEST(CheckCurveBraceRuleTest, TestWhenEndCurveBracesAtMethodDeclarationWithExtraSymbols)
{
    testRuleOnObjCCode(new CheckCurveBraceRule(), endCurveBracesAtMethodDeclarationWithExtraSymbols,
    0, 9, 1, 11, 15, "Фигурные скобки (в if/else/switch/while и т.д за исключением блоков) всегда должны открываться и закрываться на новой строке");
}

TEST(CheckCurveBraceRuleTest, TestWhenCurveBracesAtIfStatementWithSameLineWithCode)
{
    testRuleOnObjCCode(new CheckCurveBraceRule(), curveBracesAtIfStatementWithSameLineWithCode,
    0, 11, 12, 13, 5, "Фигурные скобки (в if/else/switch/while и т.д за исключением блоков) всегда должны открываться и закрываться на новой строке");
}

TEST(CheckCurveBraceRuleTest, TestWhenEndCurveBracesAtElseStatementWithSameLineWithCode)
{
    testRuleOnObjCCode(new CheckCurveBraceRule(), endCurveBracesAtElseStatementWithSameLineWithCode,
    1, 16, 5, 16, 12, "Фигурные скобки (в if/else/switch/while и т.д за исключением блоков) всегда должны открываться и закрываться на новой строке");
}

TEST(CheckCurveBraceRuleTest, TestWhenEndCurveBracesAtIfStatementWithSameLineWithCode)
{
    testRuleOnObjCCode(new CheckCurveBraceRule(), endCurveBracesAtIfStatementWithSameLineWithCode,
    0, 12, 5, 12, 9, "Фигурные скобки (в if/else/switch/while и т.д за исключением блоков) всегда должны открываться и закрываться на новой строке");
}

TEST(CheckCurveBraceRuleTest, TestWhenStartCurveBracesAtElseStatementWithSameLineWithCode)
{
    testRuleOnObjCCode(new CheckCurveBraceRule(), startCurveBracesAtElseStatementWithSameLineWithCode,
    0, 15, 10, 17, 5, "Фигурные скобки (в if/else/switch/while и т.д за исключением блоков) всегда должны открываться и закрываться на новой строке");
}

TEST(CheckCurveBraceRuleTest, TestStartCurveBracesAtForStatementWithSameLineWithCode)
{
    testRuleOnObjCCode(new CheckCurveBraceRule(), startCurveBracesAtForStatementWithSameLineWithCode,
    0, 11, 33, 13, 5, "Фигурные скобки (в if/else/switch/while и т.д за исключением блоков) всегда должны открываться и закрываться на новой строке");
}

TEST(CheckCurveBraceRuleTest, TestStartCurveBracesAtForStatementWithEmptyLineWithCode)
{
    testRuleOnObjCCode(new CheckCurveBraceRule(), startCurveBracesAtForStatementWithEmptyLineWithCode,
    0, 13, 5, 15, 5, "Фигурные скобки (в if/else/switch/while и т.д за исключением блоков) всегда должны открываться и закрываться на новой строке");
}

