#include <iostream>
#include <string>
using namespace std;
#define SIZE 10

class List {
protected:
    void** arr;
    int last;
    int capasity;

public:
    List(int size = SIZE) {
        arr = new void* [size]; //создание массива указателей
        capasity = size;
        last = -1; //элемента с индексом 0 нет - массив пуст
    }

    template <typename T>
    void push(T elem) { //добавить элемент
        if (isFull()) {
            cout << "Overflow\nProgram Terminated\n";
            exit(EXIT_FAILURE);
        }

        cout << "Insearting " << *elem << endl;
        arr[++last] = elem;
    }

    int returnSize() {
        return last + 1;
    }

    bool isFull() {
        return last == capasity - 1;
    }
    bool isEmpty() {
        return last == -1;
    }
};


class Stack : public List {
public:
    using List::List;

    void del() { //удалить последний элемент
        if (isEmpty()) {
            cout << "Underflow\nProgram Terminated\n";
            exit(EXIT_FAILURE);
        }

        last--;
    }
};

class Queue : public List {
public:
    using List::List;

    void del() { //удалить первый элемент
        if (isEmpty()) {
            cout << "Underflow\nProgram Terminated\n";
            exit(EXIT_FAILURE);
        }

        for (int i = 0; i < last - 1; i++) {
            arr[i] = arr[i + 1];
        }

        last--;
    }
};


int main()
{
    setlocale(LC_ALL, "Russian");

    int c = 8;
    char cc = 'k';
    float ccc = 3.14;
    string cccc = "trippi troppi";

    //Создадим стэк
    cout << "Создадим стэк" << endl;
    Stack stack(4);
    int s = stack.returnSize();
    cout << "В стэке элементов: " << s << endl;

    stack.push(&c);
    stack.push(&cc);
    stack.push(&ccc);
    s = stack.returnSize();
    cout << "В стэке элементов: " << s << endl;
    stack.push(&cccc);
    cout << "Удалим 1 элемент " << endl;
    stack.del();
    s = stack.returnSize();
    cout << "В стэке элементов: " << s << endl;

    cout << endl;

    //Создадим очередь
    cout << "Создадим очередь" << endl;
    Queue queue(5);
    int w = queue.returnSize();
    cout << "В очереди элементов: " << w << endl;

    queue.push(&c);
    queue.push(&cc);
    queue.push(&ccc);
    queue.push(&cccc);
    w = queue.returnSize();
    cout << "В очереди элементов: " << w << endl;

    cout << "Удалим 1 элемент " << endl;
    queue.del();
    w = queue.returnSize();
    cout << "В очереди элементов: " << w << endl;

}