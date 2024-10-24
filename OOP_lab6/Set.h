#include <iostream>
#include <vector>
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

	void unionOfSets(Set<T>*, Set<T>*);
	void intersectionOfSets(Set<T>*, Set<T>*);
	void differenceOfSets(Set<T>*, Set<T>*);
	void symmetricDifference(Set<T>*, Set<T>*);
	bool subsetOfSets(Set<T>*, Set<T>*);

	~Set() {
		removeAll();
	}
};

template<typename T>
void Set<T>::unionOfSets(Set<T>* first, Set<T>* second) {
	vector<T> mas;
	vector<T> forResult;
	Node* temp = first->head;
	Node* temp_2 = second->head;
	while (temp) {
		mas.push_back(temp->el);
		temp = temp->next;
	}
	while (temp_2) {
		mas.push_back(temp_2->el);
		temp_2 = temp_2->next;
	}
	for (int i = 0; i < mas.size(); i++)
	{
		bool dobl = false;
		for (int j = 0; j < forResult.size(); j++)
		{
			if (mas[i] == forResult[j]) {
				dobl = true;
				break;
			}
		}
		if (dobl == false) {
			forResult.push_back(mas[i]);
		}
	}

	for (int i = 0; i < forResult.size(); i++)
	{
		cout << forResult[i] << endl;
	}
}

template<typename T>
void Set<T>::intersectionOfSets(Set<T>* first, Set<T>* second) {
	vector<T> masFirst;
	vector<T> masSecond;
	vector<T> forResult;
	Node* temp = first->head;
	Node* temp_2 = second->head;
	while (temp) {
		masFirst.push_back(temp->el);
		temp = temp->next;
	}
	while (temp_2) {
		masSecond.push_back(temp_2->el);
		temp_2 = temp_2->next;
	}
	for (int i = 0; i < masFirst.size(); i++)
	{
		bool flag = false;
		for (int j = 0; j < masSecond.size(); j++)
		{
			if (masFirst[i] == masSecond[j]) {
				flag = true;
				for (int h = 0; h < forResult.size(); h++)
				{
					if (masFirst[i] == forResult[h]) {
						flag = false;
						break;
					}
				}
			}
		}
		if (flag) {
			forResult.push_back(masFirst[i]);
		}
	}

	for (int i = 0; i < forResult.size(); i++)
	{
		cout << forResult[i] << endl;
	}
}

template<typename T>
void Set<T>::differenceOfSets(Set<T>* first, Set<T>* second) {
	vector<T> masForFirst, masForSecond, masForResult;
	Node* temp = first->head;
	Node* temp_2 = second->head;
	while (temp) {
		masForFirst.push_back(temp->el);
		temp = temp->next;
	}
	while (temp_2) {
		masForSecond.push_back(temp_2->el);
		temp_2 = temp_2->next;
	}
	for (int i = 0; i < masForFirst.size(); i++)
	{
		bool dobl = false;
		for (int j = 0; j < masForSecond.size(); j++)
		{
			if (masForFirst[i] == masForSecond[j]) {
				dobl = true;
				break;
			}
		}
		if (!dobl) {
			masForResult.push_back(masForFirst[i]);
		}
	}
	for (int i = 0; i < masForResult.size(); i++)
	{
		cout << masForResult[i] << endl;
	}
}

template<typename T>
void Set<T>::symmetricDifference(Set<T>* first, Set<T>* second) {
	vector<T>mas;
	vector<T>masForResult;
	Node* temp = first->head;
	Node* temp_2 = second->head;
	while (temp) {
		mas.push_back(temp->el);
		temp = temp->next;
	}
	while (temp_2) {
		mas.push_back(temp_2->el);
		temp_2 = temp_2->next;
	}
	for (int i = 0; i < mas.size(); i++)
	{
		bool dubl = true;
		for (int j = 0; j < mas.size(); j++) {
			if (mas[i] == mas[j] && (i != j)) {
				dubl = false;
				break;
			}
		}
		if (dubl) {
			masForResult.push_back(mas[i]);
		}
	}
	for (int i = 0; i < masForResult.size(); i++)
	{
		cout << masForResult[i] << endl;
	}
}

template<typename T>
bool Set<T>::subsetOfSets(Set<T>* first, Set<T>* second) {
	vector<T> masForFirst, masForSecond;
	Node* temp = first->head;
	Node* temp_2 = second->head;
	while (temp) {
		masForFirst.push_back(temp->el);
		temp = temp->next;
	}
	while (temp_2) {
		masForSecond.push_back(temp_2->el);
		temp_2 = temp_2->next;
	}
	bool flag = false;
	for (int i = 0; i < masForFirst.size(); i++)
	{
		for (int j = 0; j < masForSecond.size(); j++) {
			if (masForFirst[i] == masForSecond[j]) {
				flag = true;
				break;
			}
			else {
				flag = false;
			}
		}
		if (flag == false) {
			break;
		}
	}
	if (flag) {
		cout << "��������� �������� �������������" << endl;
		return true;
	}
	else if (flag == false) {
		cout << "��������� �� �������� �������������" << endl;
		return false;
	}
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