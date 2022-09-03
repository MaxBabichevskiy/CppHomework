/*
Homework  "Point"
Babichevskyi Max

Implement the class "Point" - Point. Must be stored
x, y, z coordinates in private member variables of the class.
Implement class member functions to input data,
output, implement an accessor to access member variables.
Create 2 objects of the Point class. In one object set
value.
Display the value on the screen.
Create a constructor with no parameters and assign 0 to x, y, z
Run the program and output the value to the screen.
Modify the constructor so that it is an example of x, y, z and
assigned xz to their variable class members.
Run the program and output the value to the screen

1. To the already implemented class "Point" (DZ 002 task 2 or
see below), add a mechanism to initialize class members.
a. implement 3 constructors:
i. by default
ii. with parameters x, y
iii. with parameters x, y, z
b. implement the Print() method
2. Create the "Line" class
a. add the 2nd variable members of the "Point" type class - p1 and p2
b. implement 4 constructors:
i. by default
ii. with parameters p1, p2
iii. with parameters x1, y1, x2, y2
iv. with parameters x1, y1, z1, x2, y2, z2
c. implement the Print() method
*/

#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

class Point {
	int x;
	int y;
	int z;
public:
	void set_X(int value) { x = value; };
	void set_Y(int value) { y = value; };
	void set_Z(int value) { z = value; };
	int get_X() { return x; };
	int get_Y() { return y; };
	int get_Z() { return x; };
	void print();
	//Constructors
	Point() : x{0}, y{0}, z{0} {}
	Point(int p_x, int p_y) { x = p_x; y = p_y; z = 0; };
	Point(int p_x, int p_y, int p_z)  {x = p_x; y = p_y; z = p_z; };
};

class Line {
	Point p1;
	Point p2;
public:
	void print();
	//Constructors
	Line() {};
	Line(Point p_p1, Point p_p2) : p1{p_p1}, p2{p_p2}{}
	Line(int p_x1, int p_y1, int p_x2, int p_y2) : p1{p_x1 ,p_y1}, p2{ p_x2 ,p_y2 }{}
	Line(int p_x1, int p_y1, int p_z1, int p_x2, int p_y2, int p_z2) : p1{p_x1 ,p_y1, p_z1}, p2{ p_x2 ,p_y2, p_z2 }{}
};

int main() {
	setlocale(LC_ALL, "ru");
	int value;
	Point P1;
		cout << "Введите Х" << endl;
	cin >> value;
	P1.set_X(value);
		cout << "Введите Y" << endl;
	cin >> value;
	P1.set_Y(value);
		cout << "Введите Z" << endl;
	cin >> value;
	P1.set_Z(value);
	P1.print();

	Point P2(1,2,3);
	P2.print();
}

void Point::print() {
	cout << "X: " << x << endl << "Y: " << y << endl << "Z: " << z << "\n\n";
}

void Line::print() {
	 p1.print();
	 p2.print();
}