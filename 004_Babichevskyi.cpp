/* "Max Babichevskyi" Homework 
Task 
Create a class Person.
Fields:
■ identification number;
■ surname;
■ name;
■ patronymic (for last name, first name and patronymic memory
highlight dynamically!);
■ date of birth (it is recommended to create an additional class
Date (day, month, year).
Member functions:
■ constructor with parameters identification number,
surname, first name, patronymic, date of birth. In the constructor
use the list of class field initializers;
■ default constructor. In the constructor
use constructor delegation; ■ constructor
copying;
■ destructor;
■ a member function to count the class instances created
"Man";
■ setters / getters for the corresponding fields of the class.;
■ displaying information about a person on the screen.
*/
#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

class Birthday {
private:
	int day;
	int month;
	int year;
public:
	//Set
	int setDay(int m_day) { day = m_day; };
	int setMonth(int m_month) { month = m_month; };
	int setYear(int m_year) { year = m_year; };
	//Get
	int getDay() { return day; };
	int getMonth() { return  month; };
	int getYear() { return year; };
	//Print 
	void printBirthday() { cout << "Day: " << day << "\nMonth: " << month << "\nYear: " << year << endl; }
	//Constructor
	Birthday() : day(0), month(0), year(0) {}
};

class Human {
private:
	int ID;
	string *lastName = new string;
	string *name = new string;
	string *patronymic = new string;
	Birthday date;
public:
	static int count;
	//Set
	int setID(int m_id) { ID = m_id; }
	string setLastName(string m_lastName) { *lastName = m_lastName; }
	string setName(string m_name) { *name = m_name; }
	string setPatronymic(string m_patronymic) { *patronymic = m_patronymic; }
	//Get
	int getID() { return ID; }
	string getLastName() { return *lastName; }
	string getName() { return *name; }
	string getPatronymic() { return *patronymic; }
	//Print
	void print() { cout << "Last name: " << *lastName << "\nName: " << *name << "\nPatronymic: " << *patronymic << "\n"; date.printBirthday(); }
	//Constructor
	Human(const Human& other) {
		this->ID = other.ID;
		this->lastName = other.lastName;
		this->name = other.name;
		this->patronymic = other.patronymic;
		this->date = other.date;
	}
	Human(int m_id, string m_lastName, string m_name, string m_patronymic) { ID = m_id; *lastName = m_lastName; *name = m_name; *patronymic = m_patronymic; count++; }
	Human() { ID = 0000000000; *lastName = "No last name "; *name = "No name "; *patronymic = "No patronymic "; count++; }
	//Destructor
	~Human() { delete[]lastName; delete[]name; delete[]patronymic; }
};

int main() {
	setlocale(LC_ALL, "ru");
	srand(time(NULL));

	Human Max;
	Max.print();

}

int Human::count = 0;
