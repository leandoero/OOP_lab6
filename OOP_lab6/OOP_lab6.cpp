#include <iostream>
using namespace std;

template<typename T>
class Set {
	struct Node {
		T el;
		Node* next;

		Node(T _el) : el(_el), next{ nullptr } {};
	};
	Node* head;

public:
	Set() :head{ nullptr } {};
	void addEl(T el);
	void removeEl();
	void removeAll();
	void removeHead();
	void print();
	bool isEmpty();
};

template<typename T>
void unionOfSets(Set<T>* first, Set<T>* second) {

}

template<typename T>
bool Set<T>::isEmpty() {
	return head == nullptr;
}
template<typename T>
void Set<T>::addEl(T el) {
	Node* newEl = new Node(el);
	if (head == nullptr) {
		head = newEl;
		return;
	}
	Node* cur = head;
	while (cur->next) {
		cur = cur->next;
	}
	cur->next = newEl;
}
template<typename T>
void Set<T>::removeHead() {
	if (isEmpty()) {
		return;
	}
	Node* temp = head;
	head = head->next;
	delete temp;
	temp = nullptr;
}
template<typename T>
void Set<T>::removeAll() {
	if (isEmpty()) {
		return;
	}
	while (head) {
		removeHead();
	}
}
template<typename T>
void Set<T>::removeEl() {
	if (isEmpty()) {
		return;
	}
	if (head->next == nullptr) {
		delete head;
		head = nullptr;
		return;
	}
	Node* temp = head;
	Node* cur = nullptr;
	while (temp->next) {
		cur = temp;
		temp = temp->next;
	}
	cur->next = nullptr;
	delete temp;
	temp = nullptr;
}
template<typename T>
void Set<T>::print() {
	if (isEmpty()) {
		return;
	}
	Node* temp = head;
	while (temp) {
		cout << temp->el << endl;
		temp = temp->next;
	}
}
int main() {
	Set<int>* first = new Set<int>();
}