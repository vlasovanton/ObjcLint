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

TEST(CheckCurveBraceRuleTest, TestInCorrectCaseFewBraces)
{
    testRuleOnObjCCode(new CheckCurveBraceRule(), correctFewCurveBraces);
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
    0, 11, 5, 13, 5, "Фигурные скобки (в if/else/switch/while и т.д за исключением блоков) всегда должны открываться и закрываться на новой строке");
}

TEST(CheckCurveBraceRuleTest, TestWhenEndCurveBracesAtElseStatementWithSameLineWithCode)
{
    testRuleOnObjCCode(new CheckCurveBraceRule(), endCurveBracesAtElseStatementWithSameLineWithCode,
    0, 11, 5, 16, 12, "Фигурные скобки (в if/else/switch/while и т.д за исключением блоков) всегда должны открываться и закрываться на новой строке");
}

TEST(CheckCurveBraceRuleTest, TestWhenEndCurveBracesAtIfStatementWithSameLineWithCode)
{
    testRuleOnObjCCode(new CheckCurveBraceRule(), endCurveBracesAtIfStatementWithSameLineWithCode,
    0, 11, 5, 16, 12, "Фигурные скобки (в if/else/switch/while и т.д за исключением блоков) всегда должны открываться и закрываться на новой строке");
}
