static string correctCurveBracesAtWhileStatement =
R"(@interface NSObject
@end

@interface BaseObject : NSObject
@end

@implementation BaseObject

- (int)hash
{
    int i = 0;
    while (i < 10)
    {
        i++;
    }
    return 0;
}

@end

)";

static string startCurveBracesAtWhileStatementBodyWithSameLineWithCode =
R"(@interface NSObject
@end

@interface BaseObject : NSObject
@end

@implementation BaseObject

- (int)hash
{
    int i = 0;
    while (i < 10) {
        i++;
    }
    return 0;
}

@end

)";

static string endCurveBracesAtWhileStatementBodyWithSameLineWithCode =
R"(@interface NSObject
@end

@interface BaseObject : NSObject
@end

@implementation BaseObject

- (int)hash
{
    int i = 0;
    while (i < 10)
    {
        i++; }
    return 0;
}

@end

)";