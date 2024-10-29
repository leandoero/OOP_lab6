#include "Student.h"

string names[5] = { "Vladimir", "Ivan", "Nikolay", "Roman", "Maxim" };
int ages[5] = { 20, 21, 22, 23, 25 };

Student::Student() {
	age = ages[rand() % 5];
	name = names[rand() % 5];
}

ostream& operator<<(ostream& os, const Student& student) {
	os << "name : " << student.name << " age: " << student.age << endl;
	return os;
}

bool Student::operator==(const Student& other) {
	return ((age == other.age) && (name == other.name));
}