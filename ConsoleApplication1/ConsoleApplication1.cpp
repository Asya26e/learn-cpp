#include <iostream>
#include <windows.h> 
#include <iomanip>
#include <string.h>

using namespace std;

struct Data {
	unsigned short day;
	unsigned short month;
	unsigned short year;
};

struct Record {
	char name[25] = "";
	char type[25];
	float acreage;
	unsigned int productivity;
	struct Data data;
};

struct List {
	Record record;
	List* next = NULL;
};

void input(List* element);
void output(List* next);

int main(){
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int n;
	char name[25] = "";
	List* list = NULL,
		* next = NULL;
	cin >> n;
	if (n > 0) {
		list = new List();
		next = list;
		input(list);
		next->next = new List();
		next->next->record = next->record;
		next = next->next;
	}
	for (int i = 0; i < n - 1; i++) {
		next->next = new List();
		next = next->next;
		input(next);
		next->next = new List();
		next->next->record = next->record;
		next = next->next;
	}
	output(list);
	cin >> name;
	next = list;
	List* prev = list;
	while (next != NULL) {
		if (strcmp(next->record.name, name) == 0) {
			if (list == next) {
				list = next->next;
				cout << "\nСовпадение: ";
				cout << left << '|'; cout.width(14); cout << left << next->record.name;
				cout << left << '|'; cout.width(5); cout << left << next->record.type;
				cout << left << '|'; cout.width(23); cout << left << next->record.acreage;
				cout << left << '|'; cout.width(20); cout << left << next->record.productivity;
				cout << left << '|';
				int temp = 10;
				int temp_2 = (16 - temp) / 2 - 2;
				cout << left; cout.width(temp_2); cout << " ";
				if (next->record.data.day > 9) {

					cout << next->record.data.day;
				}

				else {

					cout << "0" << next->record.data.day;
				}
				cout << ".";

				if (next->record.data.month > 12) {

					cout << next->record.data.month;
				}

				else {

					cout << "0" << next->record.data.month;
				}
				cout << ".";
				cout << next->record.data.year;
				cout.width(temp_2); cout << " ";
				cout << " |" << endl << endl;
			}
			else {
				prev->next = next->next;
				cout << "\nСовпадение: ";
				cout << left << '|'; cout.width(14); cout << left << next->record.name;
				cout << left << '|'; cout.width(5); cout << left << next->record.type;
				cout << left << '|'; cout.width(23); cout << left << next->record.acreage;
				cout << left << '|'; cout.width(20); cout << left << next->record.productivity;
				cout << left << '|';
				int temp = 10;
				int temp_2 = (16 - temp) / 2 - 2;
				cout << left; cout.width(temp_2); cout << " ";
				if (next->record.data.day > 9) {

					cout << next->record.data.day;
				}

				else {

					cout << "0" << next->record.data.day;
				}
				cout << ".";

				if (next->record.data.month > 12) {

					cout << next->record.data.month;
				}

				else {

					cout << "0" << next->record.data.month;
				}
				cout << ".";
				cout << next->record.data.year;
				cout.width(temp_2); cout << " ";
				cout << " |" << endl << endl;
			}
		}
		else {
			prev = next;
		}
		next = next->next;
	}
	output(list);
}

void input(List* element) {
	cin >> element->record.name;
	cin >> element->record.type;
	cin >> element->record.acreage;
	cin >> element->record.productivity;
	cin >> element->record.data.day;
	cin >> element->record.data.month;
	cin >> element->record.data.year;
}

void output(List* next) {
	cout << "|"; cout.width(80); cout.fill('-'); cout << "|" << endl; cout.fill(' ');
	cout << "| Сельскохозяйственные культуры"; cout.fill(' '); cout << setw(50) << "|" << endl;
	cout << "|"; cout.width(80); cout.fill('-'); cout << "|" << endl; cout.fill(' ');
	cout << "| Наименование | Тип | Посевная площать (га) | Урожайность (ц/га) | Дата начала |" << endl;
	cout << "|"; cout.width(80); cout.fill('-'); cout << "|" << endl; cout.fill(' ');
	while (next != NULL) {
		cout << left << '|'; cout.width(14); cout << left << next->record.name;
		cout << left << '|'; cout.width(5); cout << left << next->record.type;
		cout << left << '|'; cout.width(23); cout << left << next->record.acreage;
		cout << left << '|'; cout.width(20); cout << left << next->record.productivity;
		cout << left << '|';
		int temp = 10;
		int temp_2 = (16 - temp) / 2 - 2;
		cout << left; cout.width(temp_2); cout << " ";
		if (next->record.data.day > 9) {

			cout << next->record.data.day;
		}

		else {

			cout << "0" << next->record.data.day;
		}
		cout << ".";

		if (next->record.data.month > 12) {

			cout << next->record.data.month;
		}

		else {

			cout << "0" << next->record.data.month;
		}
		cout << ".";
		cout << next->record.data.year;
		cout.width(temp_2); cout << " ";
		cout << " |" << endl;
		next = next->next;
	}
	cout << right << "|"; cout.width(80); cout.fill('-'); cout << "|" << endl; cout.fill(' ');
	cout << "| Примечание: З - зерновые, Б - бобовые"; cout << right; cout.width(42); cout << "|" << endl;
	cout << right << "|"; cout.width(80); cout.fill('-'); cout << "|" << endl; cout.fill(' ');
}

/*
5
Рожь З 10 256000 03 04 2022
Соя Б 0013000 45 03 03 2022
Чумиза З 0008000 17 03 04 2022
Рис З 0025650 24 04 03 2022
Горох Б 23453 56 23 23 2003
*/