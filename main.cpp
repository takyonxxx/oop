#include <QCoreApplication>
#include "utils.h"

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
//Bir nesnenin özelliklerinin farklı nesneler tarafından da kullanılabilmesine olanak sağlayan yöntemdir.
//Kalıtım veya Miras alma da denir.
//Access Specifiers
//public, protected, and private inheritance have the following features:
//public inheritance makes public members of the base class public in the derived class and the protected members of the base class remain protected in the derived class.
//protected inheritance makes the public and protected members of the base class protected in the derived class.
//private inheritance makes the public and protected members of the base class private in the derived class.

//Polymorphism (Polimorfizm)
//Aynı adı taşıyan, ancak farklı eylemler gerçekleştirecek farklı argümanlara sahip fonksiyonlar oluşturmamızı sağlayan bir özelliktir.

//Abstraction (Soyutlama)
//Veri soyutlama, dış dünyaya sadece gerekli bilgileri sağlamak ve arka plan ayrıntılarını gizlemek
//setter, getter türü fonksiyonlar

//--------------------------------------------------------------------------->

//no constructor             //rule of zero

//copy constructor           //rule of three
//copy assignment operator   //rule of three
//destructor                 //rule of three
//move constructor           //rule of five c++11
//move assignment operator   //rule of five c++11

//Sadece kopyalanabilen (Copyable Objects) objeler söz konusu olduğunda
//Otomatik kaynak yönetimi kullanılıyorsa: The Rule of Zero.
//Manuel kaynak yönetimi kullanılıyorsa: The Rule of Three.
//Hem kopyalanabilen hem taşınabilen (Moveable Objects) objeler söz konusu olduğunda
//Otomatik kaynak yönetimi kullanılıyorsa: The Rule of Zero.
//Manuel kaynak yönetimi kullanılıyorsa: The Rule of Five.

//--------------------------------------------------------------------------->

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

// class başlatılmadan kullanabildik
int FreeClass::int_static_degisken = 5;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    // class başlatılmadan kullanabildik
    FreeClass::static_function();

    test_five_rules();

    DerivedClass *d_class = new DerivedClass();
//    d_class->_protInt = 5;
    d_class->change_protected();
    // if not delete, demonstrates a basic memory leak
    delete  d_class;

    {
        //no memory leak
        test_smart_pointers();
    }

    test_templates();
    test_function_overloading();
    test_operator_overloading();

    return a.exec();
}
