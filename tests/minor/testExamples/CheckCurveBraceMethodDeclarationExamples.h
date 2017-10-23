static string correctCurveBracesAtMethodDeclaration =
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

static string startCurveBracesAtMethodDeclarationWithEmptyLineWithCode =
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