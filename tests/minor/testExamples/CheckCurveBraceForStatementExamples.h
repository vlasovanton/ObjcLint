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

static string endCurveBracesAtForStatementWithEmptyLineWithCode =
R"(@interface NSObject
@end

@interface BaseObject : NSObject
@end

@implementation BaseObject

- (int)hash
{
    for (int i = 0; i < 10; i++)
    {
        int a = 0; }
    return 0;
}

@end

)";