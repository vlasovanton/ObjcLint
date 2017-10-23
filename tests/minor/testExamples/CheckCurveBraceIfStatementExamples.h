static string correctCurveBracesAtIfStatement =
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
    {
        int i = 0;}

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
    {

    int i =0; }
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

static string startCurveBracesAtElseIfStatementWithSameLineWithCode =
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
    else if(0) {

    }
    else
    {

    }

    return 0;
}

@end

)";

static string startCurveBracesAtIfStatmentWithEmptyLineWithCode =
R"(@interface NSObject
@end

@interface BaseObject : NSObject
@end

@implementation BaseObject

- (int)hash
{
    if (0)

    {

    }
    return 0;
}
@end
)";

static string startCurveBracesAtElseStatmentWithEmptyLineWithCode =
R"(@interface NSObject
@end

@interface BaseObject : NSObject
@end

@implementation BaseObject

- (int)hash
{
    if (0)
    {

    }
    else
    {
        if (1)

        {

        }
    }
    return 0;
}
@end
)";