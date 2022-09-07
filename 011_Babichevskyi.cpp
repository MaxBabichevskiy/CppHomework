/*
Babichevskyi 011
Створити базовий клас «Домашня тварина» і похідні
класи «Собака», «Кішка», «Папуга».
За допомогою конструктора встановити ім’я кожної
тварини і її характеристики.
*/
#include <string>
#include <iostream>
using namespace std;

class Animal
{
protected:
    string name;
public:
    Animal(string name):name(name){}

    virtual void Say() = 0;
};

class Dog : public Animal
{
public:
    Dog(string name) : Animal(name){}

    void Say() override
    {
        cout << name << " speak gav-gav" << endl;
    }
};

class Cat : public Animal
{
public:
    Cat(string name) : Animal(name){}

    void Say() override
    {
        cout << name << " speak may-may" << endl;
    }
};

class Bird : public Animal
{
public:
    Bird(string name) : Animal(name){}

    void Say() override
    {
        cout << name << " speak kray-kray" << endl;
    }
};

int main()
{
    Animal* animals[3] = {
        new Dog("Dog"),
        new Cat("Cat"),
        new Bird("Bird")
    };

    for (int i = 0; i < 3; ++i)
        animals[i]->Say();

    return 0;
}