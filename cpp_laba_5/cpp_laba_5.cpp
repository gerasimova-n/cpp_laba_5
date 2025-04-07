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
        arr = new void*[size]; //создание массива указателей
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

    void tralala() { //удалить последний элемент
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

    void guzini() { //удалить первый элемент
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
    Stack tralalero(4);
    int s = tralalero.returnSize();
    cout << "В стэке элементов: " << s << endl;

    tralalero.push(&c);
    tralalero.push(&cc);
    tralalero.push(&ccc);
    s = tralalero.returnSize();
    cout << "В стэке элементов: " << s << endl;
    tralalero.push(&cccc);
    cout << "Удалим 1 элемент " << endl;
    tralalero.tralala();
    s = tralalero.returnSize();
    cout << "В стэке элементов: " << s << endl;

    cout << endl;

    //Создадим очередь
    cout << "Создадим очередь" << endl;
    Queue bombombini(5);
    int w = bombombini.returnSize();
    cout << "В очереди элементов: " << w << endl;

    bombombini.push(&c);
    bombombini.push(&cc);
    bombombini.push(&ccc);
    bombombini.push(&cccc);
    w = bombombini.returnSize();
    cout << "В очереди элементов: " << w << endl;

    cout << "Удалим 1 элемент " << endl;
    bombombini.guzini();
    w = bombombini.returnSize();
    cout << "В очереди элементов: " << w << endl;

}