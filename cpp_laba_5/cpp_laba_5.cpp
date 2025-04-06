#include <iostream>
using namespace std;
#define SIZE 10

class List {
protected:
    int* arr;
    int capasity; //вместимость
    int top;

public:
    List(int size = SIZE) { //конструктор
        arr = new int[size];
        capasity = size;
        top = -1;
    }
    ~List() { //деструктор
        delete[] arr;
    }

    void push(int elem) { //добавить элемент
        if (isFull()) {
            cout << "Overflow\nProgram Terminated\n";
            exit(EXIT_FAILURE);
        }

        cout << "Insearting " << elem << endl;
        arr[++top] = elem;
    }

    bool isFull() {
        return top == capasity - 1;
    }
    bool isEmpty() {
        return top == -1;
    }
};

class Stack : public List {
public:
    int peek() { //вернуть последний элемент
        if (!isEmpty()) {
            return arr[top];
        }
        else {
            exit(EXIT_FAILURE);
        }
    }

    int pop() { //удалить последний элемент
        if (isEmpty()) {
            cout << "Underflow\nProgram Terminated\n";
            exit(EXIT_FAILURE);
        }

        cout << "Removing " << peek() << endl;
        return arr[top--];
    }
};

class Queue : public List {
public:
    int peek() { //вернуть первый элемент
        if (!isEmpty()) {
            return arr[0];
        }
        else {
            exit(EXIT_FAILURE);
        }
    }

    int degueue() { //удалить первый элемент
        if (isEmpty()) {
            cout << "Underflow\nProgram Terminated\n";
            exit(EXIT_FAILURE);
        }

        cout << "Removing: " << arr[0] << endl;
        for (int i = 0; i < top - 1; i++) {
            arr[i] = arr[i + 1];
        }
        top--;
        return arr[0];
    }
};


int main()
{
    //пупупу
}