# ObjcLint
Objective-C rules for OCLint

[OCLint documentation](http://docs.oclint.org/en/stable/index.html)

[Default cocoa rules by OCLint](https://github.com/oclint/oclint/tree/master/oclint-rules/rules/cocoa)

## Подготовка среды разработки правил для OCLint
- [OCLint checkout](http://docs.oclint.org/en/stable/devel/checkout.html)
- [OCLint build](http://docs.oclint.org/en/stable/devel/compiletest.html)

## Шаги разработки нового правила
- создать шаблон правила
- написать тесты с примерами кода и результатом должен ли быть warning или нет
- написать правила и добиться прохождения всех тестов
- подключить правила к Xcode

### Как создать шаблон правила
- в директории oclint-scripts выполнить скрипт ./scaffoldRule с параметрами: название нового правила, тип правила через флаг -t (удобнее ASTVisitor). В папках с исходными файлами создаются заготовки (oclint-rules/test/custom и oclint-rules/rules/custom)

### Как писать тесты для правил
- в папке oclint-rules/test/custom находим файл с названием соответствующим создоваемому правилу
- определяем примеры со всеми вариантами соответсвующими и не соответсвующими правилу в переменной типа  string
- пишем тесты с использованием вспомогательной функции:
void testRuleOnObjCCode(RuleBase *rule,
            const string &code,
            int violationIndex,
            int expectStartLine,
            int expectStartColumn,
            int expectEndLine,
            int expectEndColumn,
            const string& expectMessage = "");
- запуск тестов: в директории oclint-scripts выполнить скрипт ./test rules

### Как писать правила
- в папке oclint-rules/rules/custom находим файл с названием соответствующим создоваемому правилу
- если используется тип правила ASTVisitor, то определяем тип интересующей ноды. Например, если правило для методов, то можно использовать метод VisitObjCMethodDecl.
- выделяем диапозон в исходном файле с помощью node->getSourceRange()
- если необходимо расширить диапозон, то используем nodeRange.getBegin() или nodeRange.getEnd()
- для получения исходной строки по диапозону используем Lexer::getSourceText
- для анализа полученной строки используем регулярные выражения с помощью <regex>
- для вывода warning необходимо вызвать addViolation(const clang::Decl *decl,
RuleBase *rule, const std::string& message)

### Как подключить к Xcode
Необходимо создать Aggregate target с builde step "custom script".
xcodebuild -configuration Debug -scheme XXXX -workspace XXXX.xcworkspace clean
xcodebuild -configuration Debug -scheme XXXX -workspace XXXX.xcworkspace | xcpretty -r json-compilation-database -o compile_commands.json
oclint-json-compilation-database -i XXXX/ -- -report-type xcode

### Список правил:
blocker
- неправильное использование компонентов с MRC в коде, не обнуление ссылок и т.д.
- вызов блока без проверки на существование
- delegate с неправильными атрибутами
- обращение к ivar внутри блоков
- объявление свойств простых типов с атрибутом отличным от assign
- использование NSNotificationCenter addObserver без removeObserver
- retain cycle в блоках
- добавление nil в коллекции

critical
- обращение к propety в init, dealloc, getter, setter
- объявление ivar в интерфейсе
- использование @selector() без реализации
- отсутствие проверки вызова optional метода делегата
- обработка ошибок if (![self trySomethingWithError:&error])

major
- использование performSelector
- объявление мутабельных типов без copy атрибута, включая блоки (NSString, ...)
- литеральный синтаксис
- использование констант вместо #define
- использование NS_ENUM вместо enum
- ипосльзование - (id)init вместо - (instancetype)init
- использования блочного синтаксиса создания объектов = ({
- naming свойств, методов, локальных переменных
- использование ((NSIndexPath*) вместо объявления NSIndexPath *indexPath = ...
- использование Core Data без performBlock/performBlockAndWait
- использование updateConstraints, prepareForReuse, viewDidLoad, viewWillAppear, viewDidAppear и т.д без вызова super
- инициализация NSTimer без реализации selector
- case fallthrough

minor
- пробелы, переносы {}, опечатки
- обращение к свойствам через вызов getter, а не через . array.count
- использование внутри if больше 2 условий if(bool1 && bool2 && bool3)
- использование int внутри for вместо NSUInteger
- использование внутри if вызовов методов, if ([someObj someMethod])
- использование CGRectMake(0,0,0,0), вместо CGRectZero
- использование UIEdgeInsetsMake(0, 0, 0, 0), вместо UIEdgeInsetsZero
- использование frame.size.width, вместо CGRectGetWidth и т.д
- закомментированный код
- пустые методы
- неправильный порядок объявления свойств
- длина строк == 120 символов
- исключить избыточную проверку BOOL ( if (bool1 == YES), if (object != nil) )
- обязательные скобки для блоков if/else
