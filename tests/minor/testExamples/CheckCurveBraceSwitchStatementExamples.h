static string correctCurveBracesAtSwitchStatement =
R"(@interface NSObject
@end

@interface BaseObject : NSObject
@end

@implementation BaseObject

- (int)hash
{
    int oldVersion = 3;
    int i;
    switch (oldVersion) 
    {
        case 0:
        {
            i = 1;
        }
        case 1:
        {
            i = 0;
        }
        case 2:
        {
            i = 3;
        }
        default:
        {
            i = 2;
        }
    }
    return 0;
}
@end
)";

static string startCurveBracesAtSwitchStatementWithSameLineWithCode =
R"(@interface NSObject
@end

@interface BaseObject : NSObject
@end

@implementation BaseObject

- (int)hash
{
    int oldVersion = 3;
    int i;
    switch (oldVersion){
        case 0:
        {
            i = 1;
        }
        case 1: 
        {
            i = 0;
        }
        case 2:
        {
            i = 3;
        }
        default:
        {
            i = 2;
        }
    }
    return 0;
}
@end
)";

static string endCurveBracesAtSwitchStatementWithSameLineWithCode =
R"(@interface NSObject
@end

@interface BaseObject : NSObject
@end

@implementation BaseObject

- (int)hash
{
    int oldVersion = 3;
    int i;
    switch (oldVersion)
    {
        case 0:
        {
            i = 1;
        }
        case 1:
        {
            i = 0;
        }
        case 2:
        {
            i = 3;
        }
        default:
            i = 2;}
    return 0;
}
@end
)";

static string startCurveBracesAtSwitchStatementBodyWithSameLineWithCode =
R"(@interface NSObject
@end

@interface BaseObject : NSObject
@end

@implementation BaseObject

- (int)hash
{
    int oldVersion = 3;
    int i;
    switch (oldVersion)
    {
        case 0:
        {
            i = 1;
        }
        case 1: {
            i = 0;
        }
        case 2:
        {
            i = 3;
        }
        default:
        {
            i = 2;
        }
    }
    return 0;
}
@end
)";

static string endCurveBracesAtSwitchStatementBodyWithSameLineWithCode =
R"(@interface NSObject
@end

@interface BaseObject : NSObject
@end

@implementation BaseObject

- (int)hash
{
    int oldVersion = 3;
    int i;
    switch (oldVersion)
    {
        case 0:
        {
            i = 1;
        }
        case 1:
        {
            i = 0; }
        case 2:
        {
            i = 3;
        }
        default:
        {
            i = 2;
        }
    }
    return 0;
}
@end
)";