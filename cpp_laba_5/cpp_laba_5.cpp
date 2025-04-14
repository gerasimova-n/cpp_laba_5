#include <iostream>
#include <string>
#include <cassert>
using namespace std;

struct Node {
	string data;
	Node* next;
};

//класс Список
//Атрибуты: начало списка
//Функции: конструктор
//         ~деструктор
//         добавить элемент (в начало)
//         вернуть первый элемент
//         печать всех значений

class List {
protected:
	Node* head;
	Node* last;
	int size;

public:
	List() : head(0), last(0), size(0) {}
	
	~List() { 
		while (head != 0) {
			Node* temp = head;
			head = head->next;
			delete temp;
		}
	}

	void prepend(string data) {
		Node* temp = new Node;
		assert(temp != 0);
		temp->data = data;
		temp->next = head;
		if (size == 1) {
			last = head;
		}
		head = temp;
		size++;
	}

	Node* returnHead() const {
		return head;
	}

	void print() const {
		Node* temp = head;
		while (temp != 0) {
			cout << temp->data << "->";
			temp = temp->next;
		}
		cout << "end" << endl;
	}

	int returnSize() {
		return size;
	}
};

class Stack : public List {
public:
	void del(){
		assert(size != 0);
		Node* temp = head;
		head = head->next;
		delete temp;
		size--;
	}
};

class Queue : public List {
public:
	void del() {
		assert(size != 0);
		Node* temp = head;
	    while(last != temp->next)
			temp = temp->next;
		delete last;
		last = temp;
		last->next = 0;
		size--;
	}
};

int main() {
	setlocale(LC_ALL, "Russian");
	Stack frog;
	frog.prepend("ква");
	frog.prepend("кваква");
	frog.prepend("квааа");
	frog.print();
	frog.del();
	frog.print();
	cout << "Размер frog: " << frog.returnSize() << endl;
	Queue cat;
	cat.prepend("мя");
	cat.prepend("мяу");
	cat.prepend("мрр");
	cat.prepend("shhhh");
	cat.print();
	cat.del();
	cat.print();
	cout << "Размер cat: " << cat.returnSize() << endl;
}