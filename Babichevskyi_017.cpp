//Max Babichevskyi Homework 017
//Написати базовий клас Figure фігура, з двома членами класу m_x,
//m_y з типом double, і віртуальний метод area(), який повертає
//площу фігури(double).В класі фігура функція повертає - 0.
//Створити конструктор з параметрами з значеннями по
//замовчуванню = 0.
////Figure(double a = 0, double b = 0) { m_x = a; m_y = b; }
//Додати метод Print() для виводу назви фігури, значення вхідних
//даних(Наприклад Радіус для кола чи Сторони для прямокутника),
//та вивести площу фігури.Даний метод віртуальний з
//ідентифікатором final.
//Від класу Figure успадкувати наступні класи для фігур і підрахувати
//їхню площу(Формули тут).Нових членів класу не додавати!, тільки
//використовувати з базового класу.
//● Прямокутник(дано 2 сторони)
//● Коло(дано радіус)
//● Трикутник(дано одну сторону і висоту, перша формула
//	“Формула площі трикутника за стороною та висотою”)
//	● Робм(дано одну сторону і висоту)
//	Використати всі ідентифікатори - virtual, override
//	При потребі дописати свої прості чи віртуальні функції.
//	В мейні створити всі об'єкти наших фігур - 4. Створити масив типу
//	базового класу з 4рьої елементів і присвоїти вказівники на фірури.В
//	циклі для кожного елементу масиву викликати метод Print().
//	Приклад результатів
//	Фігура - Коло, радіус = 10, площа = 314.1592
//	Фігура - Прямокутник, a = 5, b = 10, площа = 50
//	...
#include <iostream>
#include <Windows.h>
using namespace std;

class  Figure {
protected:
	double m_x;
	double m_y;
public:
	Figure(double a = 0, double b = 0) : m_x{ a }, m_y{ b } {}
	virtual double area() { return 0; }
	virtual void print() {
		printInfo();
	}
	virtual void printInfo() {}
};

class Rectangle_ : public Figure {
public:
	Rectangle_( double a = 0, double b = 0 ) : Figure(a, b) {}
	double area() override { return m_x * m_y; }
	void printInfo() override final {
		cout << "Фигура прямоугольник, стороны: " << m_x << " и " << m_y << ", площадь: " << area() << endl;
	}
};

class Circle : public Figure {
public:
	Circle(double a = 0) : Figure(a) {}
	double area() override { return 3.14 * m_x * m_x; }
	void printInfo() override final {
		cout << "Фигура круг, радиус: " << m_x << ", площадь: " << area() << endl;
	}
};

class Triangle : public Figure {
public:
	Triangle(double a = 0, double b = 0) : Figure(a, b) {}
	double area() override { 
		double a = 1.0 / 2 * m_x * m_y;
		return a;
	}
	void printInfo() override final {
		cout << "Фигура треугольник, сторона: " << m_x << " высота: " << m_y << ", площадь: " << area() << endl;
	}
};

class Rhomb : public Figure {
public:
	Rhomb(double a = 0, double b = 0) : Figure(a, b) {}
	double area() override { return m_x * m_y; }
	void printInfo() override {
		cout << "Фигура ромб, сторона: " << m_x << " высота: " << m_y << ", площадь: " << area() << endl;
	}
};

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Rectangle_ fr(5, 7);
	Circle fc(4.5);
	Triangle ft(5, 8);
	Rhomb frh(5, 7);
	Figure** figures = new Figure*[4];
	figures[0] = &fr;
	figures[1] = &fc;
	figures[2] = &ft;
	figures[3] = &frh;
	for (int i = 0; i < 4; i++)figures[i]->print();
return 0;
}