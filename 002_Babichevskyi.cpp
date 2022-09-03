/* "Max Babichevskyi" Homework 
Task 
The task is to write a program for calculating the cost of gas for a year:
1. Create a class Gas (Gas) - fields:
a. subscriber name,
b. the amount of gas consumed per month
c. other fields as needed.
2. The formula for calculating the cost of gas:
a. UAH 6 from 3-10 months
b. UAH 8 in 1-2 and 11-12 months
3. Enter information in the class for each month for the whole year with
keyboard
a. for this, create appropriate setters and getters in the class
4. Calculate the amount of payment per month and per year for subscriber Ivan
Ivanovych and take it to consol
a. The amount for each month of the year
b. The total amount to be paid for the year

Add improvements according to the studied material:
1. Move the implementation of large functions outside the class.
Example: void Gas::PrintForMonth(int monthNum)
you can do everything in one file where main is located or
export to separate files gas.h and gas.cpp
2. Create at least 2 constructors (default / empty and for
setting the name of the subscriber)
3. A member of the class name of the subscriber to announce in the class as a pointer to
array of charms and initialize method new with the appropriate
the size of the name passed in the setter function as a parameter
(setName).
a.create a method to clear memory for name if
it was selected, and the pointer is nulled. Given
call the method in the destructor.
4. In the main.cpp file, declare 2 objects/variables of this class with
two types of constructors.
a. set the data through the used gas data setter
subscribers
i. for the first subscriber
1. use an empty constructor
2. set the name through the setter - УPetroФ
3. enter data on the used gas on a monthly basis in
cycles. Write the data into an array.
ii. for the second subscriber, ask to enter the name manually
from the keyboard before declaring the class and transfer to
parameter constructor
1. also request data on gas used
enter manually in a loop
b. display the following information for two subscribers:
i. the name of the subscriber
ii. monthly payment calculations (month number,
used gas, amount per month)
iii. the total amount for the year
*/
#include <iostream>
#include <string>
#include <Windows.h>
#define MONTH 12
using namespace std;

class Gas{
private:
	string name_user;
	int count_gas_month[MONTH];
	const int price_medium_mnth = 6;
	const int price_frst_lst_mnth = 8;
public:
	//Get & Set
	void setName(string name) { name_user = name; };
	string getName() { return name_user; };
	void setMonth(int value, int month) { value >= 0 ? count_gas_month[month] = value : count_gas_month[month] = 0; };
	int getMonth(int month) { return count_gas_month[month]; };
	int getPrice(int month);
	int getPricePerMonth(int month);
	void print();
	//Constructors
	Gas(){ name_user = "No name"; }
	Gas(string name) { setName(name); }
};
//Main
int main(){
	setlocale(LC_ALL, "ru");
	srand(time(NULL));
	//Gas 1
	Gas Gas1;
	string name;
	cout << "¬ведите ваше им€ ";
	cin >> name;
	Gas1.setName(name);
	int countGas;
	for (int i = 0; i < 12; i++){
		cout << "¬ведите количество потребленого газа за " << i + 1 << " мес€ц" << endl;
		cin >> countGas;
		Gas1.setMonth(countGas, i);
	}
	 Gas1.print();
	 //Gas 2
	 Gas Gas2("Petro");
	 for (int i = 0; i < 12; i++) {
		 countGas = rand()%10;
		 Gas2.setMonth(countGas, i);
	 }
	 Gas2.print();
}
//÷ена по мес€цам
int Gas::getPrice(int month) {
	if (month >= 2 && month <= 9)
		return 6;
	else
		return 8;
}
//÷ена за мес€ц
int Gas::getPricePerMonth(int month) {
	return count_gas_month[month] * getPrice(month + 1);
}
//¬ывод 
void Gas::print() {
	cout << "================================================================" << endl;
	cout << "|| »м€: " << name_user << endl;
	cout << "----------------------------------------------------------------" << endl;
	int sum = 0;
	for (int i = 0; i < 12; i++){
		cout << "|| Ќомер мес€ца: " << i + 1 << " |  ѕотреблено газа: "<< getMonth(i) << " |  —умма за мес€ц: " << getPricePerMonth(i) << endl;
		cout << "----------------------------------------------------------------" << endl;
		sum += getPricePerMonth(i);
	}
	cout << "================================================================" << endl;
	cout << "|| ÷ена за год: " << sum << endl;
	cout << "================================================================" << "\n\n\n\n";
}