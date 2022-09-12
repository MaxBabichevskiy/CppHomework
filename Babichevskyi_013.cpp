//Babichevskyi 013
//
//Завдання 3 (оригінал завдання за посиланням)
//Тема: Динамічні структури даних – однозв’язний список
//Реалізуйте стек у вигляді однозв’язного списку.
//Потрібно реалізувати типові операції з роботи зі стеком.
//При переповненні стеку потрібно збільшувати його розмір
#include <iostream>
using namespace std;

template<class T>
class Stack {
    struct node {
        T d;
        node* next;
        node(void) : next(NULL) {}
    };
private:
    node* ptr;
public:
    Stack(void) : ptr(NULL) {}
    ~Stack() {
        this->clear();
    }

    // добавление элемента по LIFO (последним зашёл, первым вышел)
    void  push(T d) {
        node* n = new node();
        n->next = ptr;
        n->d = d;
        ptr = n;
    }
    T& top(void) { return ptr->d; }

    // вытолкнуть элемент из верхушки стека
    void pop(void) {
        node* tmp = ptr;
        ptr = ptr->next;
        delete tmp;
        tmp = NULL;
    }
    bool empty(void) const { return (!ptr); }

    // удалить весь стек
    void clear(void) {
        node* tmp;
        while (ptr != NULL) {
            tmp = ptr;
            ptr = ptr->next;
            delete tmp;
            tmp = NULL;
        }
    }
};

int  main(void) {
    Stack<int> st;
    // заполняем стек
    for (int i = 100; i <= 200; st.push(i++));

    // выводим все элементы стека в консоль
    while (!st.empty()) {
        cout << st.top() << ", ";
        st.pop();
    }
    cin.get();
    return 0;
}