#include "TestRuleOnCode.h"
#include "rules/custom/CheckCurveBraceRule.cpp"
#include "testExamples/CheckCurveBraceMethodDeclarationExamples.h"
#include "testExamples/CheckCurveBraceIfStatementExamples.h"
#include "testExamples/CheckCurveBraceSwitchStatementExamples.h"
#include "testExamples/CheckCurveBraceDoStatementExamples.h"
#include "testExamples/CheckCurveBraceForStatementExamples.h"
#include "testExamples/CheckCurveBraceWhileStatementExamples.h"


TEST(CheckCurveBraceRuleTest, PropertyTest)
{
    CheckCurveBraceRule rule;
    EXPECT_EQ(3, rule.priority());
    EXPECT_EQ("check curve brace", rule.name());
    EXPECT_EQ("custom", rule.category());
}

TEST(CheckCurveBraceRuleTest, TestCorrectCurveBracesAtMethodDeclaration)
{
    testRuleOnObjCCode(new CheckCurveBraceRule(), correctCurveBracesAtMethodDeclaration);
}

TEST(CheckCurveBraceRuleTest, TestCorrectCurveBracesAtForStatement)
{
    testRuleOnObjCCode(new CheckCurveBraceRule(), correctCurveBracesAtForStatement);
}

TEST(CheckCurveBraceRuleTest, TestCorrectCurveBracesAtIfStatement)
{
    testRuleOnObjCCode(new CheckCurveBraceRule(), correctCurveBracesAtIfStatement);
}

TEST(CheckCurveBraceRuleTest, TestInCorrectCurveBracesAtWhileStatement)
{
    testRuleOnObjCCode(new CheckCurveBraceRule(), correctCurveBracesAtWhileStatement);
}

TEST(CheckCurveBraceRuleTest, TestInCorrectCurveBracesAtDoStatement)
{
    testRuleOnObjCCode(new CheckCurveBraceRule(), correctCurveBracesAtDoStatement);
}

TEST(CheckCurveBraceRuleTest, TestWhenCurveBracesAtMethodDeclarationWithSameLineWithCodee)
{
    testRuleOnObjCCode(new CheckCurveBraceRule(), curveBracesAtMethodDeclarationWithSameLineWithCode,
    0, 9, 13, 9, 13, "Фигурные скобки (в if/else/switch/while и т.д за исключением блоков) всегда должны открываться и закрываться на новой строке");
}

TEST(CheckCurveBraceRuleTest, TestWhenCurveBracesAtMethodDeclarationWithExtraSpaces)
{
    testRuleOnObjCCode(new CheckCurveBraceRule(), curveBracesAtMethodDeclarationWithExtraSpaces,
    0, 10, 5, 10, 5, "Фигурные скобки (в if/else/switch/while и т.д за исключением блоков) всегда должны открываться и закрываться на новой строке");
}

TEST(CheckCurveBraceRuleTest, TestWhenEndCurveBracesAtMethodDeclarationWithExtraSymbols)
{
    testRuleOnObjCCode(new CheckCurveBraceRule(), endCurveBracesAtMethodDeclarationWithExtraSymbols,
    0, 11, 15, 11, 15, "Фигурные скобки (в if/else/switch/while и т.д за исключением блоков) всегда должны открываться и закрываться на новой строке");
}

TEST(CheckCurveBraceRuleTest, TestWhenCurveBracesAtIfStatementWithSameLineWithCode)
{
    testRuleOnObjCCode(new CheckCurveBraceRule(), curveBracesAtIfStatementWithSameLineWithCode,
    0, 11, 12, 11, 12, "Фигурные скобки (в if/else/switch/while и т.д за исключением блоков) всегда должны открываться и закрываться на новой строке");
}

TEST(CheckCurveBraceRuleTest, TestWhenEndCurveBracesAtElseStatementWithSameLineWithCode)
{
    testRuleOnObjCCode(new CheckCurveBraceRule(), endCurveBracesAtElseStatementWithSameLineWithCode,
    0, 17, 19, 17, 19, "Фигурные скобки (в if/else/switch/while и т.д за исключением блоков) всегда должны открываться и закрываться на новой строке");
}

TEST(CheckCurveBraceRuleTest, TestWhenEndCurveBracesAtIfStatementWithSameLineWithCode)
{
    testRuleOnObjCCode(new CheckCurveBraceRule(), endCurveBracesAtIfStatementWithSameLineWithCode,
    0, 14, 15, 14, 15, "Фигурные скобки (в if/else/switch/while и т.д за исключением блоков) всегда должны открываться и закрываться на новой строке");
}

TEST(CheckCurveBraceRuleTest, TestWhenStartCurveBracesAtElseStatementWithSameLineWithCode)
{
    testRuleOnObjCCode(new CheckCurveBraceRule(), startCurveBracesAtElseStatementWithSameLineWithCode,
    0, 15, 10, 15, 10, "Фигурные скобки (в if/else/switch/while и т.д за исключением блоков) всегда должны открываться и закрываться на новой строке");
}

TEST(CheckCurveBraceRuleTest, TestWhenStartCurveBracesAtElseIfStatementWithSameLineWithCode)
{
    testRuleOnObjCCode(new CheckCurveBraceRule(), startCurveBracesAtElseIfStatementWithSameLineWithCode,
    0, 15, 10, 15, 10, "Фигурные скобки (в if/else/switch/while и т.д за исключением блоков) всегда должны открываться и закрываться на новой строке");
}

TEST(CheckCurveBraceRuleTest, TestStartCurveBracesAtForStatementWithSameLineWithCode)
{
    testRuleOnObjCCode(new CheckCurveBraceRule(), startCurveBracesAtForStatementWithSameLineWithCode,
    0, 11, 33, 11, 33, "Фигурные скобки (в if/else/switch/while и т.д за исключением блоков) всегда должны открываться и закрываться на новой строке");
}

TEST(CheckCurveBraceRuleTest, TestStartCurveBracesAtMethodDeclarationWithEmptyLineWithCode)
{
    testRuleOnObjCCode(new CheckCurveBraceRule(), startCurveBracesAtMethodDeclarationWithEmptyLineWithCode,
    0, 11, 1, 11, 1, "Фигурные скобки (в if/else/switch/while и т.д за исключением блоков) всегда должны открываться и закрываться на новой строке");
}

TEST(CheckCurveBraceRuleTest, TestStartCurveBracesAtForStatementWithEmptyLineWithCode)
{
    testRuleOnObjCCode(new CheckCurveBraceRule(), startCurveBracesAtForStatementWithEmptyLineWithCode,
    0, 13, 5, 13, 5, "Фигурные скобки (в if/else/switch/while и т.д за исключением блоков) всегда должны открываться и закрываться на новой строке");
}

TEST(CheckCurveBraceRuleTest, TestEndCurveBracesAtForStatementWithEmptyLineWithCode)
{
    testRuleOnObjCCode(new CheckCurveBraceRule(), endCurveBracesAtForStatementWithEmptyLineWithCode,
    0, 13, 20, 13, 20, "Фигурные скобки (в if/else/switch/while и т.д за исключением блоков) всегда должны открываться и закрываться на новой строке");
}

TEST(CheckCurveBraceRuleTest, TestStartCurveBracesAtIfStatmentWithEmptyLineWithCode)
{
    testRuleOnObjCCode(new CheckCurveBraceRule(), startCurveBracesAtIfStatmentWithEmptyLineWithCode,
    0, 13, 5, 13, 5, "Фигурные скобки (в if/else/switch/while и т.д за исключением блоков) всегда должны открываться и закрываться на новой строке");
}

TEST(CheckCurveBraceRuleTest, TestStartCurveBracesAtElseStatmentWithEmptyLineWithCode)
{
    testRuleOnObjCCode(new CheckCurveBraceRule(), startCurveBracesAtElseStatmentWithEmptyLineWithCode,
    0, 19, 9, 19, 9, "Фигурные скобки (в if/else/switch/while и т.д за исключением блоков) всегда должны открываться и закрываться на новой строке");
}

TEST(CheckCurveBraceRuleTest, TestCorrectCurveBracesAtSwitchStatement)
{
    testRuleOnObjCCode(new CheckCurveBraceRule(), correctCurveBracesAtSwitchStatement);
}

TEST(CheckCurveBraceRuleTest, TestStartCurveBracesAtSwitchStatementWithSameLineWithCode)
{
    testRuleOnObjCCode(new CheckCurveBraceRule(), startCurveBracesAtSwitchStatementWithSameLineWithCode,
    0, 13, 24, 13, 24, "Фигурные скобки (в if/else/switch/while и т.д за исключением блоков) всегда должны открываться и закрываться на новой строке");
}

TEST(CheckCurveBraceRuleTest, TestEndCurveBracesAtSwitchStatementWithSameLineWithCode)
{
    testRuleOnObjCCode(new CheckCurveBraceRule(), endCurveBracesAtSwitchStatementWithSameLineWithCode,
    0, 28, 19, 28, 19, "Фигурные скобки (в if/else/switch/while и т.д за исключением блоков) всегда должны открываться и закрываться на новой строке");
}

TEST(CheckCurveBraceRuleTest, TestStartCurveBracesAtSwitchStatementBodyWithSameLineWithCode)
{
    testRuleOnObjCCode(new CheckCurveBraceRule(), startCurveBracesAtSwitchStatementBodyWithSameLineWithCode,
    0, 19, 17, 19, 17, "Фигурные скобки (в if/else/switch/while и т.д за исключением блоков) всегда должны открываться и закрываться на новой строке");
}

TEST(CheckCurveBraceRuleTest, TestEndCurveBracesAtSwitchStatementBodyWithSameLineWithCode)
{
    testRuleOnObjCCode(new CheckCurveBraceRule(), endCurveBracesAtSwitchStatementBodyWithSameLineWithCode,
    0, 21, 20, 21, 20, "Фигурные скобки (в if/else/switch/while и т.д за исключением блоков) всегда должны открываться и закрываться на новой строке");
}

TEST(CheckCurveBraceRuleTest, TestStartCurveBracesAtWhileStatementBodyWithSameLineWithCode)
{
    testRuleOnObjCCode(new CheckCurveBraceRule(), startCurveBracesAtWhileStatementBodyWithSameLineWithCode,
    0, 12, 20, 12, 20, "Фигурные скобки (в if/else/switch/while и т.д за исключением блоков) всегда должны открываться и закрываться на новой строке");
}

TEST(CheckCurveBraceRuleTest, TestEndCurveBracesAtWhileStatementBodyWithSameLineWithCode)
{
    testRuleOnObjCCode(new CheckCurveBraceRule(), endCurveBracesAtWhileStatementBodyWithSameLineWithCode,
    0, 14, 14, 14, 14, "Фигурные скобки (в if/else/switch/while и т.д за исключением блоков) всегда должны открываться и закрываться на новой строке");
}

TEST(CheckCurveBraceRuleTest, TestStartCurveBracesAtDoStatementBodyWithSameLineWithCode)
{
    testRuleOnObjCCode(new CheckCurveBraceRule(), startCurveBracesAtDoStatementBodyWithSameLineWithCode,
    0, 12, 8, 12, 8, "Фигурные скобки (в if/else/switch/while и т.д за исключением блоков) всегда должны открываться и закрываться на новой строке");
}

TEST(CheckCurveBraceRuleTest, TestEndCurveBracesAtDoStatementBodyWithSameLineWithCode)
{
    testRuleOnObjCCode(new CheckCurveBraceRule(), endCurveBracesAtDoStatementBodyWithSameLineWithCode,
    0, 14, 14, 14, 14, "Фигурные скобки (в if/else/switch/while и т.д за исключением блоков) всегда должны открываться и закрываться на новой строке");
}
