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
	int getSize();

	Set<T>* unionOfSets(Set<T>*);
	void intersectionOfSets(Set<T>*);
	void differenceOfSets(Set<T>*);
	void symmetricDifference(Set<T>*);
	bool subsetOfSets(Set<T>*);

	~Set() {
		removeAll();
	}
};

template<typename T>
Set<T>* Set<T>::unionOfSets(Set<T>* other) {
	int totalSize = getSize() + other->getSize();
	int resultSize = 0;
	T* mas = new T[totalSize];
	T* forResult = new T[totalSize];
	Set<T>* forEnd = new Set<T>();
	Node* temp = head;
	Node* temp_2 = other->head;

	int i = 0;
	while (temp) {
		mas[i++] = temp->el;
		temp = temp->next;
	}
	while (temp_2) {
		mas[i++] = temp_2->el;
		temp_2 = temp_2->next;
	}
	for (int i = 0; i < totalSize; i++)
	{
		bool dobl = false;
		for (int j = 0; j < resultSize; j++)
		{
			if (mas[i] == forResult[j]) {
				dobl = true;
				break;
			}
		}
		if (dobl == false) {
			forResult[resultSize++] = mas[i];
		}
	}

	for (int i = 0; i < resultSize; i++)
	{
		forEnd->addEl(forResult[i]);
	}
	delete[] mas;
	mas = nullptr;
	return forEnd;
}

template<typename T>
void Set<T>::intersectionOfSets(Set<T>* other) {
	int totalSize = getSize() + other->getSize();
	int resultSize = 0;
	T* masFirst = new T[getSize()];
	T* masSecond = new T[other->getSize()];
	T* forResult = new T[totalSize];
	Node* temp = head;
	Node* temp_2 = other->head;
	int i = 0;
	while (temp) {
		masFirst[i++] = temp->el;
		temp = temp->next;
	}
	int j = 0;
	while (temp_2) {
		masSecond[j++] = temp_2->el;
		temp_2 = temp_2->next;
	}
	for (int i = 0; i < getSize(); i++)
	{
		bool flag = false;
		for (int j = 0; j < other->getSize(); j++)
		{
			if (masFirst[i] == masSecond[j]) {
				flag = true;
				for (int h = 0; h < resultSize; h++)
				{
					if (masFirst[i] == forResult[h]) {
						flag = false;
						break;
					}
				}
			}
		}
		if (flag) {
			forResult[resultSize++] = masFirst[i];
		}
	}

	for (int i = 0; i < resultSize; i++)
	{
		cout << forResult[i] << endl;
	}
	delete[] masFirst;
	delete[] masSecond;
	delete[] forResult;
}

template<typename T>
void Set<T>::differenceOfSets(Set<T>* other) {
	vector<T> masForFirst, masForSecond, masForResult;
	Node* temp = head;
	Node* temp_2 = other->head;
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
void Set<T>::symmetricDifference(Set<T>* other) {
	vector<T>mas;
	vector<T>masForResult;
	Node* temp = head;
	Node* temp_2 = other->head;
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
bool Set<T>::subsetOfSets(Set<T>* other) {
	vector<T> masForFirst, masForSecond;
	Node* temp = head;
	Node* temp_2 = other->head;
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
		cout << "Ìíîæåñòâî ÿâëÿåòñÿ ïîäìíîæåñòâîì" << endl;
		return true;
	}
	else if (flag == false) {
		cout << "Ìíîæåñòâî íå ÿâëÿåòñÿ ïîäìíîæåñòâîì" << endl;
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
template<typename T>
int Set<T>::getSize() {
	if (isEmpty()) {
		return 0;
	}
	int count = 0;
	Node* temp = head;
	while (temp) {
		count += 1;
		temp = temp->next;
	}
	return count;
}