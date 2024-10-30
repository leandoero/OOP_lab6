
#include "Set.h"
#include "Student.h"

template<typename T>
void workingWithMultiple(Set<T>* set) {
	int index;
	do {
		system("cls");
		cout << "1. Добавить элемент\n" <<
			"2. Удалить элемент\n" <<
			"3. Удалить полностью\n" <<
			"4. Удалить головной элемент\n" <<
			"5. Проверка на пустоту\n" <<
			"6. Распечатать значения\n" <<
			"7. Выйти в меню\n" << endl;
		cout << "Ввод: ";
		cin >> index;

		switch (index)
		{
		case 1: {
			if constexpr (std::is_same_v<T, int>) {
				system("cls");
				int num;
				cout << "Введите число: ";
				cin >> num;
				set->addEl(num);
				break;
			}
			else if constexpr (std::is_same_v<T, double>) {
				system("cls");
				double num;
				cout << "Введите число: ";
				cin >> num;
				set->addEl(num);
				break;
			}
			else {
				system("cls");
				Student student;
				set->addEl(student);
				break;
			}
		}
		case 2: {
			system("cls");
			set->removeEl();
			break;
		}
		case 3: {
			system("cls");
			set->removeAll();
			break;
		}
		case 4: {
			system("cls");
			set->removeHead();
			break;
		}
		case 5: {
			system("cls");
			cout << std::boolalpha;
			set->isEmpty();
			system("pause");
			break;
		}
		case 6: {
			system("cls");
			set->print();
			system("pause");
			break;
		}
		default:
			break;
		}

	} while (index != 7);
}

template<typename T>
void StartProgram() {
	int index;
	Set<T>* set = new Set<T>();
	Set<T>* other = new Set<T>();
	do {
		system("cls");
		cout << "Меню: \n" <<
			"1. Работать с множеством №1\n" <<
			"2. Работать с множеством №2\n" <<
			"3. Операции над множествами\n" <<
			"4. Выход\n" << endl;
		cout << "Ввод: ";
		cin >> index;
		switch (index)
		{
		case 1: {
			system("cls");
			workingWithMultiple(set);
			break;
		}
		case 2: {
			system("cls");
			workingWithMultiple(other);
			break;
		}
		case 3: {
			int index;

			if (set == nullptr || other == nullptr) {
				cout << "Множества не созданы" << endl;
			}
			do {
				system("cls");
				cout << "1. Объединение множеств\n" <<
					"2. Пересечение множеств\n" <<
					"3. Разность множеств\n" <<
					"4. Симметричная разность\n" <<
					"5. Проверка на подмножество\n" <<
					"6. Выйти в меню\n" << endl;
				cout << "Ввод: ";
				cin >> index;
				switch (index)
				{
				case 1: {
					Set<T>* result;
					system("cls");
					result = set->unionOfSets(other);
					result->print();
					delete result;
					result = nullptr;
					system("pause");
					break;
				}
				case 2: {
					Set<T>* result;
					system("cls");
					result = set->intersectionOfSets(other);
					result->print();
					delete result;
					result = nullptr;
					system("pause");
					break;
				}
				case 3: {
					Set<T>* result;
					system("cls");
					result = set->differenceOfSets(other);
					result->print();
					delete result;
					result = nullptr;
					system("pause");
					break;
				}
				case 4: {
					Set<T>* result;
					system("cls");
					result = set->symmetricDifference(other);
					result->print();
					delete result;
					result = nullptr;
					system("pause");
					break;
				}
				case 5: {
					int index;
					system("cls");
					cout << "1. Первое является подмножеством второго?\n" <<
						"2. Второе является подножеством первого?\n" << endl;
					cout << "Ввод: ";
					cin >> index;
					switch (index)
					{
					case 1: {
						bool result;
						system("cls");
						result = set->subsetOfSets(other);
						if (result == true) {
							cout << "Является подмножеством" << endl;
						}
						else {
							cout << "Не является подмножеством" << endl;
						}
						system("pause");
						break;
					}
					case 2: {
						bool result;
						system("cls");
						result = other->subsetOfSets(set);
						if (result == true) {
							cout << "Является подмножеством" << endl;
						}
						else {
							cout << "Не является подмножеством" << endl;
						}
						system("pause");
						break;
					}
					default:
						break;
					}
					break;
				}
				default:
					break;
				}
			} while (index != 6);
		}
		default:
		{
			break;
		}
		} 
	}while (index != 4);
	delete set;
	delete other;
	set = nullptr;
	other = nullptr;
}

int main() {
	int index;
	srand(static_cast<unsigned int>(time(0)));
	setlocale(LC_ALL, "ru");
	cout << "Выберите тип для работы:\n" <<
		"1. int\n" <<
		"2. double\n" <<
		"3. Student\n" << endl;
	cout << "Ввод: ";
	cin >> index;
	switch (index)
	{
	case 1: {
		StartProgram<int>();
		break;
	}
	case 2: {
		StartProgram<double>();
		break;
	}
	case 3: {
		StartProgram<Student>();
		break;
	}
	default:
		break;
	}
	return 0;
}