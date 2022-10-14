//Babichevskyi Maxim Homework "025"
//
//Написати програму перекладач.Для реалізації напишіть клас
//Dictionary.
//При створення класу передавати назви файлу(-лів) для словника
//• через конструктор - Dictionary(string filename1, ...)
//{
//	Load(filename1, ..); Load(...);
//}
//• через метод - int Load(string path, string * arr)
//{
//	...
//}
//Також додати наступні методи в клас :
//• конструктор по замовчуванню - Dictionary() {};
//• функцію - string Translate(string word, /*змінну
//з якої на яку мову перекладати*/)
//// якщо словники не завантажені викликає throw
//• додати використання виключних ситуацій, наприклад
//виклику методе для перекладу для об'єкту класу створеного
//з конструктором по замовчуванню і не загружених
//словниках
#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>
using namespace std;

class Dictionary {
	ifstream fin1;
	ifstream fin2;
public:
	Dictionary() {}
	Dictionary(string filename1, string filename2) 
	{
		Load(filename1, filename2);
		if (!fin1.is_open() || !fin2.is_open())
			throw 1;
	}
	void Load(string file1, string file2) 
	{
		fin1.open(file1);
		fin2.open(file2);
	}

	string Translate(string word, bool direction) 
	{
		if (!fin1.is_open() || !fin2.is_open())
			throw 2;
		fin1.seekg(0);
		fin2.seekg(0);
		if (word != "") 
		{
			int index = 0;
			string tmp;
			if (direction) 
			{
				do {
					getline(fin1, tmp);
					index++;
				} while (tmp != word && !fin1.eof());
				if (tmp != word)
					return "Данное слово отсутсвует в словаре";
				for (int i = 0; i < index; i++)
					getline(fin2, tmp);
				return tmp;
			}
			else 
			{
				do {
					getline(fin2, tmp);
					index++;
				} while (tmp != word && !fin2.eof());
				if(tmp != word)
					return "Данное слово отсутсвует в словаре, попробуйте другое слово";
				for (int i = 0; i < index; i++)
					getline(fin1, tmp);
				return tmp;
			}		
		}
		return "";
	}
	bool isLoad() { return(fin1.is_open() && fin2.is_open()); }
};

int main() 
{
	setlocale(LC_ALL, "ru");
	try 
	{
		Dictionary dictionary;

		dictionary.Load("Eng.txt", "Rus.txt");

		int index;
		string tmp;
		while (true) 
		{
			cout << "Английский - Русский введите 1\n Русский - Английский введите 2\n";
			cin >> index;
			if (index == 0)
				return 0;
			if (index == 1) 
			{
				cout << "Введите английское слово: ";
				cin >> tmp;
				cout << endl << tmp << " -- " << dictionary.Translate(tmp, true) << endl << endl;
			}
			else
				if (index == 2) 
				{
					cout << "Введите русское слово: ";
					cin >> tmp;
					cout << endl << tmp << " -- " << dictionary.Translate(tmp, false) << endl << endl;
				}
				else
					cout << "Неверное значение, повторите попытку";
		}
	}
	catch (int a) 
	{
		switch (a)
		{
		case 1: cout << "Ошибка открытия файла"; break;
		case 2: cout << "Словарь не загружен"; break;
		}
	}
}
