#include <iostream>
using namespace std;

struct Student {
	int age;
	string name;

	Student();
	friend ostream& operator<<(ostream&, const Student&);
	bool operator==(const Student&);
};