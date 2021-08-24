#include <iostream>

//we just add the functions we will use
using std::string;
using std::cout;
using std::endl;

//using namespace std; we not add all namespace, because we will not use all functions.

/*
This sample demonstrates : The Four Pillars of Object Oriented Programming

Encapsulation
     Encapsulation is accomplished when each object maintains a private state, inside a class.
     Other objects can not access this state directly, instead, they can only invoke a list of public functions.
     The object manages its own state via these functions and no other class can alter it unless explicitly allowed.
     In order to communicate with the object, you will need to utilize the methods provided.
Abstraction
      Abstraction is an extension of encapsulation. It is the process of selecting data from a larger pool to show only the relevant details to the object.
Inheritance
      Inheritance is the ability of one object to acquire some/all properties of another object.
Polymorphism
      Polymorphism gives us a way to use a class exactly like its parent so there is no confusion with mixing types.
      This being said, each child sub-class keeps its own functions/methods as they are.
*/

class AbstractEmployee{
    virtual void AskForPromotion() = 0; // pure function most be used in child
};

class Employee:AbstractEmployee{
private://Encapsulation
    string Company;
    int Age;
protected:
    string Name;

public:
    Employee(string name, string company, int age){
        this->Name = name;
        this->Company = company;
        this->Age = age;
    }
    void IntroduceYourself(){
        cout << "Name - " << Name << endl;
        cout << "Company - " << Company << endl;
        cout << "Age - " << Age << endl;
    }
    void AskForPromotion()//Abstraction
    {
        if (Age > 30)
            cout << Name << " got promoted!" << endl;
        else
            cout << Name << ", sorry NO promotion for you!" << endl;
    }
    virtual void Work() // Polymorphism : virtual means that when a virtual function is involved,
    // can you please check if there is implementation of this function in my derived classes.
    // If yes, please execute that instead.
    {
        cout << Name << " is checking email, task backlog, performing tasks..." << endl;
    }

    string getCompany() const
    {
        return Company;
    }
    void setCompany(const string &value)
    {
        Company = value;
    }
    int getAge() const
    {
        return Age;
    }
    void setAge(int value)
    {
        Age = value;
    }
    string getName() const
    {
        return Name;
    }
    void setName(const string &value)
    {
        Name = value;
    }
};

class Developer: public Employee{//Inheritance
public:
    string FavProgrammingLanguage;
    Developer(string name, string company, int age, string favProgrammingLanguage)
        :Employee(name, company, age)
    {
        this->FavProgrammingLanguage = favProgrammingLanguage;
    }
    void FixBug(){
        cout << Name << " fixed bug using " << FavProgrammingLanguage << endl;
    }
    void Work() override // Polymorphism : only virtual member functions can be marked 'override'
    {
        cout << Name << " is writing " << FavProgrammingLanguage << " code" << endl;
    }
};

class Teacher: public Employee{//Inheritance
public:
    string Subject;
    Teacher(string name, string company, int age, string subject)
        :Employee(name, company, age)
    {
        this->Subject = subject;
    }
    void PrepareLesson(){
        cout << Name << " is preparing " << Subject << " lesson" << endl;
    }
    void Work() override // Polymorphism : only virtual member functions can be marked 'override'
    {
        cout << Name << " is teaching " << Subject << endl;
    }
};

int main()
{
    Employee employe1 = Employee("Türkay", "biliyor.com", 47);
    Developer d = Developer("Türkay", "biliyor.com", 47, "c++");
    Teacher t =  Teacher("Ahmet", "ates.com", 50, "History");

    d.Work();
    t.Work();

    // the most common use of polymorphism is when a
    // parent class reference is used to refer to a child class object
    // this only works if function defined as virtual at parent class
    Employee *e1= &d;
    Employee *e2= &t;

    e1->Work();
    e2->Work();
    return 0;
}


