static string correctCurveBracesAtDoStatement =
R"(@interface NSObject
@end

@interface BaseObject : NSObject
@end

@implementation BaseObject

- (int)hash
{
    int i = 0;
    do
    {
        i++;
    }
    while (i<10);

    return 0;
}

@end

)";

static string startCurveBracesAtDoStatementBodyWithSameLineWithCode =
R"(@interface NSObject
@end

@interface BaseObject : NSObject
@end

@implementation BaseObject

- (int)hash
{
    int i = 0;
    do {
        i++;
    }
    while (i<10);

    return 0;
}

@end

)";

static string endCurveBracesAtDoStatementBodyWithSameLineWithCode =
R"(@interface NSObject
@end

@interface BaseObject : NSObject
@end

@implementation BaseObject

- (int)hash
{
    int i = 0;
    do
    {
        i++; }
    while (i<10);

    return 0;
}

@end

)";