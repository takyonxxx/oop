#include <QCoreApplication>
#include "utils.h"

// dynamic_cast <new_type> (expression) can be used only with pointers and references to objects. Conversion is safe
//  Always successful when we cast a class to one of its base classes
// reinterpret_cast <new_type> (expression) converts any pointer type to any other pointer type, 
//  a simple binary copy of the value from one pointer to the other
// static_cast <new_type> (expression)conversions between pointers to related classes,
//  up to the programmer to ensure that the conversion is safe
// const_cast <new_type> (expression) in order to pass a const argument to a function that expects a non-constant parameter
// typeid allows to check the type of an expression: typeid (expression)

// four different data types in C++?
// Primitive/Basic: Char, int, short, float, double, long, bool, etc.
// Derived: Array, pointer, etc.
// Enumeration: Enum
// User-defined: Structure, class, etc.

// Pointers are the variables that store the memory address of another variable. 
// The type of the variable must correspond with the type of pointer.

// STL stands for standard template library. It is a library of container templates that provide generic classes and functions.
// STL components are containers, algorithms, iterators, and function objects.

// A copy constructor is a member function that initializes an object using another object within the same class.

// A scope resolution operator is represented as ::
// This operator is used to associate function definition to a particular class.
// The scope operator is used for the following purposes:
// To access a global variable when you have a local variable with the same name.
// To define a function outside the class.

// Object: Anything that exists physically in the real world is called an object.
// Class: The collection of objects is called class.
// Inheritance: Properties of parent class inherited into child class is known as inheritance.
// Polymorphism: It is the ability to exist in more than one form.
// Encapsulation: Binding of code and data together into a single unit.
// Abstraction: Hiding internal details and showing functionality to the user.
    
//--------------------------------------------------------------------------->

//Nesne Yönelimli Programlama, (OOP) (Object Oriented Programming)
//Nesneye Yönelik programlama, sınıf (Class), nesneler (Objects) ve bu ikisi etrafında dönen kalıtım (Inheritance), polimorfizm (Polymorphism),
//soyutlama (Abstraction), kapsülleme (Encapsulation) gibi diğer kavramlarla ilişkili bir programlama biçimidir.

//Nesne, bazı özellikleri ve davranışları olan tanımlanabilir bir varlıktır. Nesne bir sınıf örneğidir.
//Sınıf tanımlandığında, bellek ayrılmaz, ancak örnek oluşturulduğunda (yani bir nesne oluşturulduğunda) bellek ayrılır.

//Encapsulation (Kapsülleme)
//Üzerinde çalışan verilerin ve yöntemlerin veya işlevlerin birlikte paketlendiği işlemdir.
//Bunu yaparak, verilere dış dünyadan kolayca erişilemez.

//Inheritance (Kalıtım)
// Bir nesnenin özelliklerinin farklı nesneler tarafından da kullanılabilmesine olanak sağlayan yöntemdir.
// Kalıtım veya Miras alma da denir.

//Access Specifiers
// public, protected, and private inheritance have the following features:
// public inheritance makes public members of the base class public in the derived class and the protected members of the base class remain protected in the derived class.
// protected inheritance makes the public and protected members of the base class protected in the derived class.
// private inheritance makes the public and protected members of the base class private in the derived class.

//Polymorphism (Polimorfizm)
// Aynı adı taşıyan, ancak farklı eylemler gerçekleştirecek farklı argümanlara sahip fonksiyonlar oluşturmamızı sağlayan bir özelliktir.
// Polymorphism relates to many forms that differ in different situations. It occurs when the hierarchy of multiple classes is related to one another by inheritance. In C++, the two types of polymorphism are

// Compile Time Polymorphism - Achieved by operation or function overloading.
// Runtime Polymorphism - Achieved by function overriding. 
// A member function in the base class redefined in a derived class is a virtual function. It is declared using the virtual keyword. 
// Virtual function: A member function in the base class redefined in a derived class. It is declared with a virtual keyword.
// Pure virtual function: A function with no implementation. It is declared by assigning 0. It does not have a body

//Abstraction (Soyutlama)
// Veri soyutlama, dış dünyaya sadece gerekli bilgileri sağlamak ve arka plan ayrıntılarını gizlemek
// setter, getter türü fonksiyonlar
// Abstraction means displaying the essential details to the user while hiding the irrelevant or particular details
// that you don’t want to show to a user. It is of two types:

// A friend class is capable of accessing protected, private, and public members of other classes in which it is declared as friends.
// A friend function can also access protected, private, and public members, but it is not a member function.

//--------------------------------------------------------------------------->
// Destructors are used to deallocate memory and perform the cleanup. Can not overload.

// no constructor             //rule of zero
// copy constructor           //rule of three
// copy assignment operator   //rule of three
// destructor                 //rule of three
// move constructor           //rule of five c++11
// move assignment operator   //rule of five c++11

//Sadece kopyalanabilen (Copyable Objects) objeler söz konusu olduğunda
//Otomatik kaynak yönetimi kullanılıyorsa: The Rule of Zero.
//Manuel kaynak yönetimi kullanılıyorsa: The Rule of Three.
//Hem kopyalanabilen hem taşınabilen (Moveable Objects) objeler söz konusu olduğunda
//Otomatik kaynak yönetimi kullanılıyorsa: The Rule of Zero.
//Manuel kaynak yönetimi kullanılıyorsa: The Rule of Five.

//--------------------------------------------------------------------------->
// An abstract class is a class whose objects cannot be created. It serves as a parent for the derived classes.
// Placing a pure virtual function in the class makes it an abstract class. 

// A static member function can be called even if no class objects exist. 
// It is accessed using only the class name and the scope resolution operator (::).  

// public, protected, and private inheritance have the following features:

// public inheritance makes public members of the base class public in the derived class, and the protected members of the base class remain protected in the derived class.
// protected inheritance makes the public and protected members of the base class protected in the derived class.
// private inheritance makes the public and protected members of the base class private in the derived class.

// --------------------------------------------------------------------------------->
// In the call by value method, you pass the copies of actual parameters to the function's formal parameters. 
// This means if there is any change in the values inside the function, then that change will not affect the actual values.

// In the call-by-reference method, the reference or address of actual parameters is sent to the function's formal parameters.
// This means any change in values inside the function will be reflected in the actual values.

// Size of char: 1 byte
// Size of short int: 2 bytes
// Size of int, unsigned int: 4 bytes
// Size of float: 4 bytes
// Size of long int: 8 bytes
// Size of double: 8 bytes
// Size of wchar_t : 4 bytes

//içinde en az bir pure(saf) metod olan class
class AbstractClass //Abtstract Class
{
public:
    string tur="abstract";
public :
    // Abstract fonksiyon, en az bir tane Pure Virtual Function
    virtual void AbstractMethod() = 0;
    // polymorphism
    virtual int alan(int taban, int yukseklik){
        cout << "AbstractClass calculate" << endl;
        return taban*yukseklik;
    }
};


class FreeClass : public AbstractClass
{

public:

    // Prefixing the explicit keyword to the constructor prevents the compiler from using that constructor for implicit conversions.
    // derleyicinin bu oluşturucuyu örtük dönüştürmeler için kullanmasını engeller
    explicit FreeClass()
    {
        cout << "Freelass Constructor invoked" << endl;
    }

    ~FreeClass(){
        cout << "Freelass Destructor invoked" << endl;
    }

    FreeClass(const FreeClass&)
    {
        cout << "Freelass Copy Constructor invoked" << endl;
    }

    FreeClass(FreeClass&& other)
    {
        cout << "Freelass Move Constructor invoked" << endl;
        swap(x, other.x);
    }

    FreeClass& operator=(const FreeClass&)
    {
        cout << "Freelass Copy Assigment invoked" << endl;
        return *this;
    }

    FreeClass& operator=(const FreeClass&&)
    {
        cout << "Freelass Move Assigment invoked" << endl;
        return *this;
    }

    // Using the override identifier prompts the compiler to display error messages when these mistakes are made.
    void AbstractMethod() override
    {
        cout << "Freelass AbstractMethod invoked" << endl;
    }

    //    A static function is a member function of a class that can be called even when an object of the class is not initialized.
    //    A static function cannot access any variable of its class except for static variables.
    static void static_function()
    {
        cout << "int_static_degisken değeri : " << int_static_degisken << endl; // Acceptable
//        cout << x; // Error!
    }

    int x, y;
    static int int_static_degisken;

    //    default all 5 is enabled
    //    Freelass() = delete; // disable constructor
    //    ~Freelass() = delete; // disable destructor
    //    Freelass(const Freelass&) = delete; // disable copy constructor
    //    Freelass(Freelass&&) = delete; // disable move constructor
    //    Freelass& operator=(const Freelass&)= delete; // disable copy assigment
    //    Freelass& operator=(const Freelass&&)= delete; // disable move assigment
};


class BaseClass
{
public:
    BaseClass(){
        cout << "BaseClass Constructor invoked" << endl;
    }

    // When a base class is intended for polymorphic use,
    // its destructor may have to be declared public and virtual.
    virtual ~BaseClass(){
        cout << "BaseClass Destructor invoked" << endl;
    }

    BaseClass(const BaseClass&) = default; // copy constructor
    BaseClass(BaseClass&&) = delete; // move constructor

    BaseClass& operator=(const BaseClass&) = default; // copy assigment
    BaseClass& operator=(const BaseClass&&)= delete; // disable move assigment

    int _publInt{0};
    int publFunc()
    {
        return privVirtFunc();
    }

private:
    int _privInt{0};
    int privFunc(){return 0;}
    virtual int privVirtFunc(){return 0;}
    // Now class  Freelass can
    // access private and protected members of BaseClass
    friend class FreeClass;

protected:
    int _protInt{0};
    int protFunc(){return 0;}

};

class DerivedClass : public BaseClass
{
public:
    DerivedClass(){
        cout << "DerivedClass Constructor invoked" << endl;
    }
    ~DerivedClass(){
        cout << "DerivedClass Destructor invoked" << endl;
    }
    void change_protected()
    {
        _protInt = 5;
        cout << "New protected member value is : " << _protInt << endl;
    }

};

void test_five_rules()
{
    cout << "\nTesting five rules : \n" << endl;
    cout << boolalpha
         << "constructible? " << std::is_constructible<BaseClass>::value << '\n'
         << "move_constructible? " << std::is_move_constructible<BaseClass>::value << '\n'
         << "copy_constructible? " << std::is_copy_constructible<BaseClass>::value << '\n'
         << "move_assignable? " << std::is_move_assignable<BaseClass>::value << '\n'
         << "copy_assignable? " << std::is_copy_assignable<BaseClass>::value << '\n'
         << "destructible? " << std::is_destructible<BaseClass>::value << endl;

    cout << "\nTesting five rules with class: \n" << endl;
    FreeClass t1, t2, t5;  // Normal constructor is called here
    t2 = t1;              // Copy assigment is called here
    FreeClass t3 = t1;     // Copy constructor is called here
    t1.x=5;
    FreeClass t4 (std::move(t1)); // Move constructor is called here
    t5 = std::move(t4); // Move assigment is called here, destructor
    cout << "\nt4.x:" << t4.x << endl;// Move constructor swaped x value.

}


//automatically delete themselves when they go out of scope, c++14
void test_smart_pointers()
{
    cout << "\nTesting smart pointers : \n" << endl;

    //auto_ptr<DerivedClass> p1(new DerivedClass);

    // cant share, can't copy unique_ptr, But, unique_ptr can be moved using the new move semantics
    unique_ptr<FreeClass>unPtr1 = make_unique<FreeClass>();
    unique_ptr<FreeClass>unPtr2 = move(unPtr1);

    // can share
    shared_ptr<DerivedClass>shPtr1 = make_shared<DerivedClass>();
    // cout << shPtr1.use_count() << endl;
    shared_ptr<DerivedClass>shPtr2 = shPtr1;
    // cout << shPtr1.use_count() << endl;
    // cout << shPtr1.get() << endl;
    // and pointer becomes NULL
    shPtr1.reset();
    // cout << shPtr1.get() << endl;
}

//Function Overloading
class printData {
public:
    void print(int i) {
        cout << "Printing int: " << i << endl;
    }
    void print(double  f) {
        cout << "Printing float: " << f << endl;
    }
    void print(string c) {
        cout << "Printing string: " << c << endl;
    }
};


void test_function_overloading()
{
    printData pd;
    // Call print to print integer
    pd.print(5);
    // Call print to print float
    pd.print(500.263);
    // Call print to print character
    pd.print("Hello Friend");
}

//Operator Overloading
//Operators that can be overloaded

//Binary Arithmetic     ->     +, -, *, /, %
//Unary Arithmetic     ->     +, -, ++, —
//Assignment     ->     =, +=,*=, /=,-=, %=
//Bit- wise      ->     & , | , << , >> , ~ , ^
//De-referencing     ->     (->)
//Dynamic memory allocation and De-allocation     ->     New, delete
//Subscript     ->     [ ]
//Function call     ->     ()
//Logical      ->     &,  | |, !
//Relational     ->     >, < , = =, <=, >=

class Box {
public:
    double getVolume(void) {
        return length * breadth * height;
    }
    void setLength( double len ) {
        length = len;
    }
    void setBreadth( double bre ) {
        breadth = bre;
    }
    void setHeight( double hei ) {
        height = hei;
    }

    // Overload + operator to add two Box objects.
    Box operator+(const Box& b) {
        Box box;
        box.length = this->length + b.length;
        box.breadth = this->breadth + b.breadth;
        box.height = this->height + b.height;
        return box;
    }

private:
    double length;      // Length of a box
    double breadth;     // Breadth of a box
    double height;      // Height of a box
};

void test_operator_overloading()
{
    Box Box1;                   // Declare Box1 of type Box
    Box Box2;                // Declare Box2 of type Box
    Box Box3;                // Declare Box3 of type Box
    double volume = 0.0;     // Store the volume of a box here

    // box 1 specification
    Box1.setLength(6.0);
    Box1.setBreadth(7.0);
    Box1.setHeight(5.0);

    // box 2 specification
    Box2.setLength(12.0);
    Box2.setBreadth(13.0);
    Box2.setHeight(10.0);

    // Add two object as follows:
    Box3 = Box1 + Box2;
    // volume of box 3
    volume = Box3.getVolume();
    cout << "Volume of Box3 : " << volume <<endl;

}

class ConstClass {
public:
    void regularFunction() {
        std::cout << "Regular Function" << std::endl;
    }

    void constFunction() const {
        std::cout << "Constant Function" << std::endl;
        // Uncommenting the line below would result in a compilation error
        // regularFunction();  // Error: Cannot call non-const member function from a const member function
    }
};

// Global variable with the same name as a local variable in the class
int globalVariable = 42;

class MyClass {
public:
    int localVar; // Local variable with the same name as the global variable

    MyClass(int value) : localVar(value) {}

    // Function defined outside the class using scope resolution operator
    void printValues();

    // Function to access the global variable using scope resolution
    void accessGlobalVar();
};

// Definition of the function outside the class using scope resolution operator
void MyClass::printValues() {
    std::cout << "Local variable: " << localVar << ", Global variable: " << ::globalVariable << std::endl;
}

// class başlatılmadan kullanabildik
int FreeClass::int_static_degisken = 5;

class RuleOfFive {
public:

    // Constructor
    explicit RuleOfFive() {
        std::cout << "RuleOfFive Constructor" << std::endl;
    }

    // Destructor
    // When a base class is intended for polymorphic use,
    // its destructor may have to be declared public and virtual.
    virtual ~RuleOfFive() {
        std::cout << "RuleOfFive Destructor" << std::endl;
    }

    // Copy Constructor
    RuleOfFive(const RuleOfFive& other) {
        // Copy data from 'other' to 'this'
        std::cout << "Copy data from 'other' to 'this'" << std::endl;
    }

    // Copy Assignment Operator
    RuleOfFive& operator=(const RuleOfFive& other) {
        if (this != &other) {
            std::cout << "Copy data from 'other' to 'this'" << std::endl;
        }
        return *this;
    }

    // Move Constructor
    RuleOfFive(RuleOfFive&& other) noexcept {
        // Transfer resources from 'other' to 'this'
        std::cout << "Transfer resources from 'other' to 'this'" << std::endl;
    }

    // Move Assignment Operator
    RuleOfFive& operator=(RuleOfFive&& other) noexcept {
        if (this != &other) {
            // Transfer resources from 'other' to 'this'
            std::cout << "Transfer resources from 'other' to 'this'" << std::endl;
        }
        return *this;
    }

    // Pure virtual function makes this class abstract
    virtual void doSomething() const = 0;
};

class DerivedRuleOfFive : public RuleOfFive {
public:
    // Constructor
    DerivedRuleOfFive() {
        std::cout << "DerivedClass Constructor" << std::endl;
    }

    // Destructor
    // The DerivedClass destructor will be automatically called
    // even when deleting through a RuleOfFive pointer
    ~DerivedRuleOfFive() {
        std::cout << "DerivedClass Destructor" << std::endl;
        // Release any allocated resources specific to DerivedClass
    }

    // Implementation of the pure virtual function
    void doSomething() const override {
        std::cout << "DerivedRuleOfFive doing something" << std::endl;
    }

    // Other member functions
};

// By using override, you make your intentions clear and enable the compiler to provide better error checking:

class MyExplicitClass {
public:
    explicit MyExplicitClass(int value) : data(value){
        // Dolaylı çağrılmaya izin vermeyen yapılandırıcı
        std::cout << data << std::endl;
    }

    ~MyExplicitClass() {
        std::cout << "MyClass Destructor with value: " << data << std::endl;
    }

    void display() const {
        std::cout << "MyClass Object with value: " << data << std::endl;
    }

private:
    int data;
};

// Class with template method
class OverloadTemplateExample {
public:
    // Template method for any type
    template <typename T>
    void display(const T& value) {
        std::cout << "Displaying value: " << value << std::endl;
    }

    // Overloaded template method for a pair of values
    template <typename T1, typename T2>
    void display(const T1& value1, const T2& value2) {
        std::cout << "Displaying values: " << value1 << " and " << value2 << std::endl;
    }
};


class BaseTest {
public:
    void publicFunction() {
        std::cout << "Public Function" << std::endl;
    }

protected:
    void protectedFunction() {
        std::cout << "Protected Function" << std::endl;
    }
};

class DerivedPublic : public BaseTest {
public:
    void useBaseFunctions() {
        publicFunction();    // Accessible
        protectedFunction(); // Accessible
    }
};

class DerivedProtected : protected BaseTest {
public:
    void useBaseFunctions() {
        publicFunction();    // Accessible
        protectedFunction(); // Accessible
    }
};

class DerivedPrivate : private BaseTest {
public:
    void useBaseFunctions() {
        publicFunction();    // Accessible
        protectedFunction(); // Accessible
    }
};

void draw_star_pyramid(int rows) {
    for (int i = 0; i < rows; i++) {

        // Print spaces before stars
        for (int j = 0; j < rows - i - 1; j++) {
            std::cout << " ";
        }

        // Print stars
        for (int k = 0; k < 2 * i + 1; k++) {
            std::cout << "*";
        }

        // Move to the next line
        std::cout << std::endl;
    }
}

class Singleton {
public:
    static Singleton& getInstance() {
        static Singleton instance;
        return instance;
    }

    void doSomething()
    {
        std::cout << "Singleton doSomething... " << std::endl;
    }

    // Other member functions and data members...

private:
    // Private constructor to prevent instantiation
    Singleton() {}
    // Private copy constructor and assignment operator to prevent copying
    // The purpose is to enforce the singleton pattern, ensuring that there is only one instance of the class throughout the program.
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
};

// Ürün arayüzü
class Product {
public:
    virtual void use() const = 0;
    virtual ~Product() {}
};

// Somut Ürün
class ConcreteProduct : public Product {
public:
    void use() const override {
        std::cout << "ConcreteProduct is being used." << std::endl;
    }
};

// Creator arayüzü
class Creator {
public:
    virtual Product* createProduct() const = 0;
    virtual ~Creator() {}
};

// Somut Creator
class ConcreteCreator : public Creator {
public:
    Product* createProduct() const override {
        return new ConcreteProduct();
    }
};

class Base {
public:
    Base() : protectedVar(42) {}

    virtual ~Base() {}

    void accessProtectedVar() {
        std::cout << "Accessing protectedVar from Base class: " << protectedVar << std::endl;
    }
protected:
    int protectedVar;
};

class DerivedTestProtected : public Base {
public:
    void accessProtectedVarFromDerived() {
        // Accessing protectedVar from the derived class
        std::cout << "Accessing protectedVar from Derived class: " << protectedVar << std::endl;
    }
};

// Hedef (Target) arayüzü
class Target {
public:
    virtual void request() const = 0;
    virtual ~Target() {}
};

// Hedef (Target) sınıfı
class ConcreteTarget : public Target {
public:
    void request() const override {
        std::cout << "ConcreteTarget request" << std::endl;
    }
};

// Adaptör arayüzü
class Adaptee {
public:
    void specificRequest() const {
        std::cout << "Adaptee specificRequest" << std::endl;
    }
};

// Somut Adaptör
class Adapter : public Target {
private:
    Adaptee* adaptee;

public:
    Adapter(Adaptee* adapteeObj) : adaptee(adapteeObj) {}

    void request() const override {
        adaptee->specificRequest();
    }
};

#include <iostream>

// Forward declaration of the friend class
class FriendClass;

// The class that declares another class as a friend
class SampleClass {
private:
    int privateMember;

public:
    SampleClass() : privateMember(42) {}

    // Declare FriendClass as a friend of MyClass
    friend class FriendClass;
};

// The friend class that can access private members of MyClass
class FriendClass {
public:
    void accessPrivateMember(const SampleClass& obj) {
        // FriendClass can access private members of MyClass
        std::cout << "Accessing private member of MyClass: " << obj.privateMember << std::endl;
    }
};

// Dependency Injection (DI) is a design pattern in software development that deals with how components or services obtain their dependencies.
// In other words, it's a technique where the dependencies of a class or module are injected from the outside rather than being created within the class itself.

class Database {
public:
    void write(const std::string& message) {
        std::cout << "Writing to the database: " << message << std::endl;
    }
};

class Logger {
public:
    Logger(Database& db) : database(db) {}

    void log(const std::string& message) {
        // Use the injected database
        database.write(message);
    }

private:
    Database& database;
};

// Inline function definition
inline int add(int a, int b) {
    return a + b;
}

class Derived : public Base {};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    draw_star_pyramid(5);

    int result = add(3, 4);  // The add() function is expanded in-place
    std::cout << "Result: " << result << std::endl;

    Base baseObjProtected;
    baseObjProtected.accessProtectedVar();  // This is allowed

    DerivedTestProtected derivedObjProtected;
    derivedObjProtected.accessProtectedVarFromDerived();  // This is allowed

    // Create a Database object
    Database myDatabase;
    // Create a Logger object and inject the Database
    Logger myLogger(myDatabase);
    // Use the Logger to log a message
    myLogger.log("Hello, Logger!");

    SampleClass myObject;
    FriendClass friendObject;

    // FriendClass can access private members of MyClass
    friendObject.accessPrivateMember(myObject);

    std::unique_ptr<FreeClass> myPtr = std::make_unique<FreeClass>();
    // Automatically releases memory when myPtr goes out of scope

    std::shared_ptr<FreeClass> sharedPtr1 = std::make_shared<FreeClass>();
    std::shared_ptr<FreeClass> sharedPtr2 = sharedPtr1;  // Shared ownership
    // Memory is released when the last sharedPtr owning the resource is destroyed

    std::shared_ptr<FreeClass> sharedPtr = std::make_shared<FreeClass>();
    std::weak_ptr<FreeClass> weakPtr = sharedPtr;  // Non-owning reference
    // Use weakPtr to check if the resource is still valid before accessing it
    // Using the weak pointer
    if (auto lockedSharedPtr = weakPtr.lock()) {
        // The weak pointer is valid, so use it
        lockedSharedPtr->alan(10, 5);
    } else {
        // The weak pointer is no longer valid (shared_ptr has been destructed)
        std::cout << "The shared_ptr is no longer available." << std::endl;
    }

    double myDouble = 3.14;
    int myInt = static_cast<int>(myDouble);  // Açıkça tip dönüşümü, Explicit type conversion

    // MyExplicitClass obj = 42;  // Hata: 'explicit' nedeniyle dolaylı dönüşüm izin verilmez
    MyExplicitClass obj2(42);  // Açıkça yapılandırma

    OverloadTemplateExample example;

    // Calling the template methods with different types and numbers of arguments
    example.display(42);
    example.display(3.14);
    example.display("Hello, Template Overloading!");
    example.display(10, 20);
    example.display(3.14, "pi");

    int intValue = 1024;
    // Using reinterpret_cast to treat the integer as an array of bytes
    unsigned char* bytePtr = reinterpret_cast<unsigned char*>(&intValue);

    // Accessing individual bytes
    for (size_t i = 0; i < sizeof(int); ++i) {
        std::cout << "Byte " << i << ": " << static_cast<int>(bytePtr[i]) << std::endl;
    }

    Derived derivedObj;
    Base baseObj = static_cast<Base>(derivedObj);

    Base* basePtr = new Derived;

    // Using typeid in a polymorphic hierarchy
    if (typeid(*basePtr) == typeid(Derived)) {
        std::cout << "basePtr points to a Derived object." << std::endl;
    } else {
        std::cout << "basePtr does not point to a Derived object." << std::endl;
    }

    delete basePtr;

    // Client tarafından kullanım
    Creator* creator = new ConcreteCreator();
    Product* product = creator->createProduct();

    product->use();

    // Belleği temizle
    delete product;
    delete creator;

    // Client tarafından kullanım
    ConcreteTarget target;
    Adaptee adaptee;
    Adapter adapter(&adaptee);

    // Hedef (Target) sınıfının doğrudan kullanımı
    target.request();

    std::cout << "------" << std::endl;

    // Adaptör aracılığıyla kullanım
    adapter.request();

    // Access the singleton instance
    Singleton& mySingleton = Singleton::getInstance();

    // Use the singleton
    mySingleton.doSomething();

    DerivedPublic derivedPublic;
    derivedPublic.publicFunction();
    // derivedPublic.protectedFunction();  // Error: protected inheritance
    derivedPublic.useBaseFunctions();

    DerivedProtected derivedProtected;
    derivedProtected.useBaseFunctions();
    // derivedProtected.publicFunction();      // Error: protected inheritance
    // derivedProtected.protectedFunction();   // Error: protected inheritance

    DerivedPrivate derivedPrivate;
    derivedPrivate.useBaseFunctions();
   //  derivedPrivate.publicFunction();        // Error: private inheritance
   //  derivedPrivate.protectedFunction();     // Error: private inheritance


    // Create a DerivedRuleOfFive object
    DerivedRuleOfFive _obj1;
    DerivedRuleOfFive _obj2 = _obj1;  // Copy Constructor
    DerivedRuleOfFive _obj3;
    _obj3 = _obj1;  // Copy Assignment Operator

    DerivedRuleOfFive obj4 = std::move(_obj1);  // Move Constructor
    DerivedRuleOfFive obj5;
    obj5 = std::move(_obj1);  // Move Assignment Operator

    // Declare a vector of integers
    std::vector<int> myVector;

    // Add elements to the vector
    myVector.push_back(10);
    myVector.push_back(20);
    myVector.push_back(30);
    myVector.push_back(10);

    // Access elements using index
    std::cout << "First element: " << myVector[0] << std::endl;

    // Iterate through the vector
    for (int i : myVector) {
        std::cout << i << " " << std::endl;
    }

    // Declare a map with string keys and int values
    std::map<std::string, int> myMap;

    // Insert key-value pairs
    myMap["Alice"] = 25;
    myMap["Bob"] = 30;
    myMap["Bob"] = 111;
    myMap["Charlie"] = 22;

    // Access values using keys
    std::cout << "Bob's age: " << myMap["Bob"] << std::endl;

    // Iterate through the map
    for (const auto& pair : myMap) {
        std::cout << pair.first << ": " << pair.second << " " << std::endl;
    }

    // Create an unordered_map with string keys and int values
    std::unordered_map<std::string, int> myUnorderedMap;

    // Insert key-value pairs
    myUnorderedMap["one"] = 1;
    myUnorderedMap["two"] = 2;
    myUnorderedMap["three"] = 3;

    // Search for a key
    std::string key = "two";
    auto it = myUnorderedMap.find(key);

    if (it != myUnorderedMap.end()) {
        // Key found
        std::cout << "Value for key '" << key << "': " << it->second << std::endl;
    } else {
        // Key not found
        std::cout << "Key '" << key << "' not found.\n";
    }

    // Try to search for a non-existent key
    key = "four";
    it = myUnorderedMap.find(key);

    if (it != myUnorderedMap.end()) {
        // Key found
        std::cout << "Value for key '" << key << "': " << it->second << std::endl;
    } else {
        // Key not found
        std::cout << "Key '" << key << "' not found." << std::endl;
    }



//     MyClass obj(42);

//     // Accessing local and global variables using scope resolution
//     obj.printValues();

//     const ConstClass constObj;
//     // constObj.regularFunction();  // Error: Cannot call non-const member function on a const object
//     constObj.constFunction();


//     // class başlatılmadan kullanabildik
//     FreeClass::static_function();

//     test_five_rules();

//     DerivedClass *d_class = new DerivedClass();
// //    d_class->_protInt = 5;
//     d_class->change_protected();
//     // if not delete, demonstrates a basic memory leak
//     delete  d_class;

//     {
//         //no memory leak
//         test_smart_pointers();
//     }

//     test_templates();
//     test_function_overloading();
//     test_operator_overloading();

    return a.exec();
}
