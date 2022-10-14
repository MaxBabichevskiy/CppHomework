//Babichevskyi Maxim 026
//Переробити клас SmartPointer на ShatedPointer,
//щоб можна тримати кілька однакових вказівників і вони не
//удалялись аж поки останній об'єкт ShatedPointer не
//видалено.
#include <iostream>
#include <vector>
using namespace std;

struct Node {
	void* ptr;
	int count;
	Node(void* ptr) {
		this->ptr = ptr;
		count = 1;
	}
};

static vector<Node> ptrArray;
template <class T>

class ShatedPointer {
	T* ptr;
public:
	ShatedPointer(T* ptr = NULL) {
		this->ptr = ptr;
		bool p = false;
		int i = 0;
		for(;i<ptrArray.size();i++)
			if (ptrArray[i].ptr == ptr) {
				ptrArray[i].count++;
				p = true;
				break;
			}
		if (!p) 
			ptrArray.push_back(Node(ptr));
	}
	ShatedPointer(const ShatedPointer& obj) {
		this->ptr = obj.ptr;
		for(int i = 0; i < ptrArray.size();i++)
			if (ptrArray[i].ptr == obj.ptr) {
				ptrArray[i].count++;
				break;
			}
	}
	~ShatedPointer() {
		bool p = false;
		int i = 0;
		for(;i<ptrArray.size();i++)
			if (ptrArray[i].ptr == ptr) {
				if (ptrArray[i].count > 1)
					ptrArray[i].count--;
				else
					ptrArray[i].count = 0;
				break;
			}
	}
	T& operator*() { return *ptr; }
	T& operator->() { return ptr; }
};

int main() {
	int k = 18;
	int* pint = &k;
	ShatedPointer<int> w = pint;
	*w = 11;
	ShatedPointer<int> m = w;
	cout << &*w << endl << &*m;
	cout << endl << *w << endl <<*m;
}