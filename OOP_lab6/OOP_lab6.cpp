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
				system("pause");
				break;
			}
			else if constexpr (std::is_same_v<T, double>) {
				system("cls");
				double num;
				cout << "Введите число: ";
				cin >> num;
				set->addEl(num);
				system("pause");
				break;
			}
			else {
				system("cls");
				Student student;
				set->addEl(student);
				system("pause");
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
	Set<T>* setFirst = new Set<T>();
	Set<T>* setSecond = new Set<T>();
	int index;
	do {
		system("cls");
		cout << "Меню: \n" <<
			"1. Создать множество №1\n" <<
			"2. Создать множество №2\n" <<
			"3. Операции над множествами\n" <<
			"4. Выход\n" << endl;
		cout << "Ввод: ";
		cin >> index;
		switch (index)
		{
		case 1: {
			system("cls");
			workingWithMultiple(setFirst);
			break;
		}
		case 2: {
			system("cls");
			workingWithMultiple(setSecond);
			break;
		}
		case 3: {
			int index;

			if (setFirst == nullptr || setSecond == nullptr) {
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
					system("cls");
					setFirst->unionOfSets(setFirst, setSecond);
					system("pause");
					break;
				}
				case 2: {
					system("cls");
					setFirst->intersectionOfSets(setFirst, setSecond);
					system("pause");
					break;
				}
				case 3: {
					system("cls");
					setFirst->differenceOfSets(setFirst, setSecond);
					system("pause");
					break;
				}
				case 4: {
					system("cls");
					setFirst->symmetricDifference(setFirst, setSecond);
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
						system("cls");
						setFirst->subsetOfSets(setFirst, setSecond);
						system("pause");
						break;
					}
					case 2: {
						system("cls");
						setSecond->subsetOfSets(setSecond, setFirst);
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
			break;
		}
	} while (index != 4);
	delete setFirst;
	delete setSecond;
	setFirst = nullptr;
	setSecond = nullptr;
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