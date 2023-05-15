
#include <iostream>
#include <windows.h>
#include <iomanip>
#include<string.h>
#include <fstream>

using namespace std;

const int Nmacc = 25;
const int Smacc = 25;
const int Mmacc = 25;
const int Dmacc = 25;


void input(char* n, char* s, char* m) {
	cout << "Введите: Наименование, Тип, Посевная площать (га), Урожайность (ц/га) >" << endl;
	cin >> n >> s >> m;
}

void printftable(char n[4][Nmacc], char s[4][Smacc], char m[4][Mmacc]) {
	cout << "|"; cout.width(80); cout.fill('-'); cout << "|" << endl;
	cout << "|Сельскохозяйственные культуры"; cout.fill(' '); cout << setw(51) << "|" << endl;
	cout << "|"; cout.width(80); cout.fill('-'); cout << "|" << endl;
	cout << "| Наименование | Тип | Посевная площать (га) | Урожайность (ц/га) | Дата начала |" << endl;
	cout << "|"; cout.width(80); cout.fill('-'); cout << "|" << endl;
	cout << "|"; cout.fill(' '); cout << setw(14) << n[0] << "|" << setw(5) << n[1] << "|" << setw(23) << n[2] << "|" << setw(20) << n[3] << "|" << setw(13) << n[4] << "|" << endl;
	cout << "|"; cout.width(80); cout.fill('-'); cout << "|" << endl;
	cout << "|"; cout.fill(' '); cout << setw(14) << s[0] << "|" << setw(5) << s[1] << "|" << setw(23) << s[2] << "|" << setw(20) << s[3] << "|" << setw(13) << s[4] << "|" << endl;
	cout << "|"; cout.width(80); cout.fill('-'); cout << "|" << endl;
	cout << "|"; cout.fill(' '); cout << setw(14) << m[0] << "|" << setw(5) << m[1] << "|" << setw(23) << m[2] << "|" << setw(20) << m[3] << "|" << setw(13) << m[4] << "|" << endl;
	cout << "|"; cout.width(80); cout.fill('-'); cout << "|" << endl;
	cout << "| Примечание: З - зерновые, Б - бобовые"; cout.fill(' '); cout << setw(42) << "|" << endl;
	cout << "|"; cout.width(80); cout.fill('-'); cout << "|" << endl;

}

int prak_0() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char n[5][Nmacc];
	char s[5][Smacc];
	char m[5][Mmacc];

	for (int i = 0; i < 5; ++i)
		input(n[i], s[i], m[i]);
	printftable(n, s, m);
	return 0;
}


struct Data {
	unsigned short day;
	unsigned short month;
	unsigned short year;
};

struct Record {
	char name[25];
	char type[25];
	float acreage;
	unsigned int productivity;
	struct Data data;
};

void printftable(struct Record* Table);
void printline(struct Record* Table);
void printt_Date(unsigned short day, unsigned short month, unsigned short year, int line);

int prak_1()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	struct Record Table[10];

	Table[0] = { "Соя", "Б", 1300, 45, {03, 03, 2022} };
	Table[1] = { "Чумиза", "З", 8000, 17, { 03,04,2022} };
	Table[2] = { "Рис", "З", 25650, 24, {04,03,2022} };
	printftable(Table);
	return 1;
}

void printt_Date(unsigned short day, unsigned short month, unsigned short year, int line) {
	int temp = 10;
	int temp_2 = (line - temp) / 2 - 1;
	cout << left; cout.width(temp_2); cout << " ";
	if (day < 9) {

		cout << day;
	}

	else {

		cout << "0" << day;
	}
	cout << ".";

	if (month > 12) {

		cout << month;
	}

	else {

		cout << "0" << month;
	}
	cout << ".";
	cout << year;
	cout.width(temp_2); cout << " ";
}

void printftable(struct Record* Table) {
	cout << "|"; cout.width(80); cout.fill('-'); cout << "|" << endl; cout.fill(' ');
	cout << "| Сельскохозяйственные культуры"; cout.fill(' '); cout << setw(50) << "|" << endl;
	cout << "|"; cout.width(80); cout.fill('-'); cout << "|" << endl; cout.fill(' ');
	cout << "| Наименование | Тип | Посевная площать (га) | Урожайность (ц/га) | Дата начала |" << endl;
	cout << "|"; cout.width(80); cout.fill('-'); cout << "|" << endl; cout.fill(' ');
	for (int i = 0; i < 3; i++) {
		cout << left << '|'; cout.width(14); cout << left << Table[i].name;

		cout << left << '|'; cout.width(5); cout << left << Table[i].type;

		cout << left << '|'; cout.width(23); cout << left << Table[i].acreage;

		cout << left << '|'; cout.width(20); cout << left << Table[i].productivity;
		cout << left << '|';
		printt_Date(Table[i].data.day, Table[i].data.month, Table[i].data.year, 16);
		cout << "|" << endl;
	}
	cout << right << "|"; cout.width(80); cout.fill('-'); cout << "|" << endl; cout.fill(' ');
	cout << "| Примечание: З - зерновые, Б - бобовые"; cout << right; cout.width(42); cout << "|" << endl;
	cout << right << "|"; cout.width(80); cout.fill('-'); cout << "|" << endl; cout.fill(' ');
	cout << "| Минимум каждого столбца"; cout.fill(' '); cout << setw(56) << "|" << endl;
	cout << right << "|"; cout.width(80); cout.fill('-'); cout << "|" << endl; cout.fill(' ');
	printline(Table);
	cout << right << "|"; cout.width(80); cout.fill('-'); cout << "|" << endl; cout.fill(' ');
}

void printline(Record* Table) {
	struct Record record = Table[0];

	for (int i = 1; i < 3; i++) {
		if (strcmp(record.name, Table[i].name) > 0) {
			for (int j = 0; j < 25; j++) {
				record.name[j] = Table[i].name[j];
			}
		}
		if (strcmp(record.type, Table[i].type) > 0) {
			for (int j = 0; j < 25; j++) {
				record.type[j] = Table[i].type[j];
			}
		}
		if (record.acreage > Table[i].acreage) {
			record.acreage = Table[i].acreage;
		}
		if (record.productivity > Table[i].productivity) {
			record.productivity = Table[i].productivity;
		}
		if (record.data.year > Table[i].data.year) {
			record.data.year = Table[i].data.year;
			record.data.month = Table[i].data.month;
			record.data.day = Table[i].data.day;
		}
		else if (record.data.year == Table[i].data.year) {
			if (record.data.month > Table[i].data.month) {
				record.data.year = Table[i].data.year;
				record.data.month = Table[i].data.month;
				record.data.day = Table[i].data.day;
			}
			else if (record.data.month > Table[i].data.month) {
				if (record.data.day > Table[i].data.day) {
					record.data.year = Table[i].data.year;
					record.data.month = Table[i].data.month;
					record.data.day = Table[i].data.day;
				}
			}
		}
	}
	cout << left << '|'; cout.width(14); cout << left << record.name;
	cout << left << '|'; cout.width(5); cout << left << record.type;
	cout << left << '|'; cout.width(23); cout << left << record.acreage;
	cout << left << '|'; cout.width(20); cout << left << record.productivity;
	cout << left << '|';
	printt_Date(record.data.day, record.data.month, record.data.year, 16);
	cout << "|" << endl;
}

//struct Data {
//	unsigned short day;
//	unsigned short month;
//	unsigned short year;
//};
//
//struct Record {
//	char name[25];
//	char type[25];
//	float acreage;
//	unsigned int productivity;
//	struct Data data;
//};

void printftable(struct Record* Table, int size);
void printline_2(struct Record* Table);
void printt_Date(unsigned short day, unsigned short month, unsigned short year, int line);

int prak_2()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int size;
	struct Record* Table, * Table2;
	cin >> size;
	Table = (Record*)malloc(size * sizeof(Record));
	Table2 = new Record[10];
	for (int i = 0; i < size; i++) {
		cin >> Table[i].name;
		cin >> Table[i].type;
		cin >> Table[i].acreage;
		cin >> Table[i].productivity;
		cin >> Table[i].data.day;
		cin >> Table[i].data.month;
		cin >> Table[i].data.year;

	}
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 25; j++) {
			Table2[i].name[j] = Table[i].name[j];
		}
		for (int j = 0; j < 25; j++) {
			Table2[i].type[j] = Table[i].type[j];
		}
		Table2[i].acreage = Table[i].acreage;
		Table2[i].productivity = Table[i].productivity;
		Table2[i].data.day = Table[i].data.day;
		Table2[i].data.month = Table[i].data.month;
		Table2[i].data.year = Table[i].data.year;
	}
	printftable(Table, size);
	delete[] Table;

	printftable(Table2, 10);
	delete[] Table2;
	return 2;
}

void print_Date(unsigned short day, unsigned short month, unsigned short year, int line) {
	int temp = 10;
	int temp_2 = (line - temp) / 2 - 1;
	cout << left; cout.width(temp_2); cout << " ";
	if (day < 9) {

		cout << day;
	}

	else {

		cout << "0" << day;
	}
	cout << ".";

	if (month > 12) {

		cout << month;
	}

	else {

		cout << "0" << month;
	}
	cout << ".";
	cout << year;
	cout.width(temp_2); cout << " ";
}

void printftable(struct Record* Table, int size) {
	cout << "|"; cout.width(80); cout.fill('-'); cout << "|" << endl; cout.fill(' ');
	cout << "| Сельскохозяйственные культуры"; cout.fill(' '); cout << setw(50) << "|" << endl;
	cout << "|"; cout.width(80); cout.fill('-'); cout << "|" << endl; cout.fill(' ');
	cout << "| Наименование | Тип | Посевная площать (га) | Урожайность (ц/га) | Дата начала |" << endl;
	cout << "|"; cout.width(80); cout.fill('-'); cout << "|" << endl; cout.fill(' ');
	for (int i = 0; i < size; i++) {
		cout << left << '|'; cout.width(14); cout << left << Table[i].name;

		cout << left << '|'; cout.width(5); cout << left << Table[i].type;

		cout << left << '|'; cout.width(23); cout << left << Table[i].acreage;

		cout << left << '|'; cout.width(20); cout << left << Table[i].productivity;
		cout << left << '|';
		print_Date(Table[i].data.day, Table[i].data.month, Table[i].data.year, 16);
		cout << "|" << endl;
	}
	cout << right << "|"; cout.width(80); cout.fill('-'); cout << "|" << endl; cout.fill(' ');
	cout << "| Примечание: З - зерновые, Б - бобовые"; cout << right; cout.width(42); cout << "|" << endl;
	cout << right << "|"; cout.width(80); cout.fill('-'); cout << "|" << endl; cout.fill(' ');
}

void printline_2(Record* Table) {
	struct Record record = Table[0];

	for (int i = 1; i < 3; i++) {
		if (strcmp(record.name, Table[i].name) > 0) {
			for (int j = 0; j < 25; j++) {
				record.name[j] = Table[i].name[j];
			}
		}
		if (strcmp(record.type, Table[i].type) > 0) {
			for (int j = 0; j < 25; j++) {
				record.type[j] = Table[i].type[j];
			}
		}
		if (record.acreage > Table[i].acreage) {
			record.acreage = Table[i].acreage;
		}
		if (record.productivity > Table[i].productivity) {
			record.productivity = Table[i].productivity;
		}
		if (record.data.year > Table[i].data.year) {
			record.data.year = Table[i].data.year;
			record.data.month = Table[i].data.month;
			record.data.day = Table[i].data.day;
		}
		else if (record.data.year == Table[i].data.year) {
			if (record.data.month > Table[i].data.month) {
				record.data.year = Table[i].data.year;
				record.data.month = Table[i].data.month;
				record.data.day = Table[i].data.day;
			}
			else if (record.data.month > Table[i].data.month) {
				if (record.data.day > Table[i].data.day) {
					record.data.year = Table[i].data.year;
					record.data.month = Table[i].data.month;
					record.data.day = Table[i].data.day;
				}
			}
		}
	}
	cout << left << '|'; cout.width(14); cout << left << record.name;
	cout << left << '|'; cout.width(5); cout << left << record.type;
	cout << left << '|'; cout.width(23); cout << left << record.acreage;
	cout << left << '|'; cout.width(20); cout << left << record.productivity;
	cout << left << '|';
	print_Date(record.data.day, record.data.month, record.data.year, 16);
	cout << "|" << endl;
}

//struct Data {
//	unsigned short day;
//	unsigned short month;
//	unsigned short year;
//};

//struct Record {
//	char name[25] = "";
//	char type[25];
//	float acreage;
//	unsigned int productivity;
//	struct Data data;
//};

struct List {
	Record record;
	List* next = NULL;
};

void input(List* element);
void output(List* next);

int prak_3() {
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
	return 3;
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

struct date
{
	int day;
	int month;
	int year;
};

struct record {
	string name;
	string type;
	float acreage;
	double productivity;
	date Date;
};



void drawdate(int day, int month, int year, int wline)
{
	int w = 10;
	int delta = (wline - w);
	cout.width(delta); cout << " ";
	cout << left;
	if (day > 9) cout << day;
	else cout << "0" << day;
	cout << ".";
	if (month > 9) cout << month;
	else cout << "0" << month;
	cout << ".";
	cout << year << "|" << endl;
}

struct node
{
	struct record note;
	struct node* next;
};
struct node* myHead;
int countItem = 0;


void additem(string name, string type, int acreage, double productivity, date zhaba)
{
	struct node* newitem = new node();
	newitem->note.name = name;
	newitem->note.type = type;
	newitem->note.acreage = acreage;
	newitem->note.productivity = productivity;
	newitem->note.Date.day = zhaba.day;
	newitem->note.Date.month = zhaba.month;
	newitem->note.Date.year = zhaba.year;
	if (countItem == 0)
	{
		newitem->next = NULL;
	}
	else
	{
		newitem->next = myHead;
	}
	myHead = newitem;
	countItem++;
}
void printitem()
{
	struct node* current = myHead;
	cout << endl;
	cout.width(70); cout.fill('-'); cout << "-" << endl;
	cout.fill(' '); cout.width(71); cout << left << "|Сельскохозяйственные культуры"; cout << "|" << endl;
	cout.width(70); cout.fill('-'); cout << "-" << endl;
	cout << left << "|Наименование ";
	cout << left << "|Тип";
	cout << left << "|Посевная площать (га)";
	cout << left << "|Урожайность (ц/га)";
	cout << left << "|Дата начала";
	cout << "|" << endl;
	cout.width(71); cout.fill('-'); cout << "-" << endl;
	cout.fill(' ');

	while (current)
	{
		cout << left << "|"; cout.width(13); cout << left << current->note.name;
		cout << left << "|"; cout.width(3); cout << left << current->note.type;
		cout << left << "|"; cout.width(21); cout << left << current->note.acreage;
		std::cout.precision(0);
		cout << left << "|"; cout.width(18); cout << left << fixed << current->note.productivity;
		cout << left << "|";
		drawdate(current->note.Date.day, current->note.Date.month, current->note.Date.year, 11);
		current = current->next;
	}
	cout.width(71); cout.fill('-'); cout << "-" << endl;
	cout << "|"; cout.width(70); cout.fill(' '); cout << left << "Примечание: З - зерновые, Б - бобовые"; cout << "|" << endl;
	cout.width(71); cout.fill('-'); cout << "-" << endl << endl;
}

void deleteitem(int index)
{
	if (index >= 0 and countItem > 0 and index < countItem)
	{

		struct node* current = myHead;
		struct node* old;
		if (index == 0)
		{
			old = myHead;
			myHead = current->next;
			delete old;
			countItem--;
		}
		else {
			int i = 0;
			while (current)
			{
				if (i == index - 1) {
					old = current->next->next;
					delete current->next;
					current->next = old;
					countItem--;
					break;
				}
				current = current->next;
				i++;
			}

		}
	}
}
void insertitem(int index, record note)
{
	if (not (index >= 0 and index <= countItem and countItem >= 0)) return;
	if (index == 0) {
		additem(note.name, note.type, note.productivity, note.productivity, note.Date);
	}
	else {
		struct node* current = myHead;
		for (int i = 0; i < index - 1; i++) {
			current = current->next;
		}
		struct node* newItem = new node();
		newItem->note = note;
		newItem->next = current->next;
		current->next = newItem;
		countItem++;
	}
}

int prak_4()
{
	setlocale(LC_ALL, "ru");
	struct record records[4] = { "Рис","З",25650,24,{04,03,2022,},
	   "Соя","Б",13000,45,{03,03,2022},
	   "Чумиза","З",8000,17,{03,04,2022} };
	ifstream intt;
	ofstream outb;
	ofstream outt("AT", ios_base::out);
	outb.open("AB", ios_base::out | ios_base::binary);
	char a[] = "\n123\n";
	cout << sizeof(records) << "\n";
	for (int i = 0; i < 3; i++)
	{
		outb << " " << records[i].name << " " << records[i].type << " " << records[i].acreage << ' ' << records[i].productivity << ' ' << records[i].Date.day << ' ' << records[i].Date.month << ' ' << records[i].Date.year << endl;
		outt << " " << records[i].name << " " << records[i].type << " " << records[i].acreage << ' ' << records[i].productivity << ' ' << records[i].Date.day << ' ' << records[i].Date.month << ' ' << records[i].Date.year << endl;
	}
	outt.close();
	record out[4];
	intt.open("AT", ios_base::in);
	for (int i = 0; !intt.eof(); i++)
	{
		intt >> out[i].name >> out[i].type >> out[i].acreage >> out[i].productivity >> out[i].Date.day >> out[i].Date.month >> out[i].Date.year;
	}
	additem(out[0].name, out[0].type, out[0].acreage, out[0].productivity, out[0].Date);
	additem(out[1].name, out[1].type, out[1].acreage, out[1].productivity, out[1].Date);
	additem(out[2].name, out[2].type, out[2].acreage, out[2].productivity, out[2].Date);
	printitem();
	intt.close();
	cout << endl << "второй этап";
	ofstream outtt;
	outtt.open("AT", ofstream::app);
	out[3] = { "Горох", "Б",23000, 56, {23, 03, 2023} };
	outtt << " " << out[3].name << " " << out[3].type << " " << out[3].acreage << ' ' << out[3].productivity << ' ' << out[3].Date.day << ' ' << out[3].Date.month << ' ' << out[3].Date.year << endl;
	outtt.close();
	additem(out[3].name, out[3].type, out[3].acreage, out[3].productivity, out[3].Date);
	printitem();
	record temp = out[0];
	deleteitem(3);
	//printitem();
	insertitem(1, temp);
	//printitem();
	temp = out[2];
	deleteitem(2);
	//printitem();
	cout << "поменять 2 и 4 строки местами:" << endl;
	insertitem(3, temp);
	printitem();
	return 4;
}
//
//struct Data {
//	unsigned short day;
//	unsigned short month;
//	unsigned short year;
//};

//struct Record {
//	char name[25];
//	char type[25];
//	float acreage;
//	unsigned int productivity;
//	struct Data data;
//};

class clData {
private:
	unsigned short day;
	unsigned short month;
	unsigned short year;


public:
	clData()
	{
		day = 0;
		month = 0;
		year = 0;
	};

	clData(unsigned short _day, unsigned short _month, unsigned short _year)
	{
		day = _day;
		month = _month;
		year = _year;
	};
	clData(struct Data D)
	{
		day = D.day;
		month = D.month;
		year = D.year;
	};
	clData(struct Data* D)
	{
		day = D->day;
		month = D->month;
		year = D->year;
	};

	~clData() {}

	void setData()
	{

	}

	Data getData()
	{
		Data D;
		D.day = this->day;
		D.month = this->month;
		D.year = this->year;
		return D;
	}

	void printData() {
		if (day > 31 || day < 0 || month > 12 || year < 0) {
			cout << "Неверный формат даты!";
			return;
		}
		if (day < 10) { cout << "0" << day << "."; }
		else { cout << day << "."; }

		if (month < 10) { cout << "0" << month << "."; }
		else { cout << month << "."; }

		if (year < 10) { cout << "0" << year << endl; }
		else { cout << year << endl; }
	}
	void addDay(unsigned short d) {
		day += d;
		printData();
	}
};


class clRecord {
	string name;
private:
	unsigned int productivity;
protected:
	float acreage;
	clData Data;
public:
	string type;

	clRecord(string nm2, unsigned int prod, float acr, string typ, clData* dt2);
	clRecord(struct Record* record);
	string get_name() { return name; }
	string get_type() { return type; }

	unsigned int get_productivity() { return productivity; }

	float get_acreage() { return acreage; }

	clData get_Data() { return Data.getData(); }

	void get_clData();
};


clRecord::clRecord(string nm2, unsigned int prod, float acr, string typ, clData* dt2) {
	name = nm2;
	type = typ;
	productivity = prod;
	acreage = acr;
	Data = *dt2;
}

clRecord::clRecord(struct Record* record) {
	name = record->name;
	type = record->type;
	acreage = record->acreage;
	productivity = record->productivity;
	Data = record->data;
}

void clRecord::get_clData() {
	get_name();
	get_type();
	get_acreage();
	get_productivity();
	get_Data();
}

int prak_5() {
	setlocale(LC_ALL, "Rus");

	Data MD = { 3, 3, 2023 };
	struct Record* record = new Record({ "Соя", "Б", 1300, 45, { 03, 03, 2022 } });
	struct Record* record1 = new Record({ "Чумиза", "З", 8000, 17, { 03,04,2022 } });
	struct Record* record2 = new Record({ "Рис", "З", 25650, 24, { 04,03,2022 } });
	clData D0;
	clData D3(&MD);
	clData D2(MD);
	clData D1(12, 03, 12);
	clData* D5;
	clData* d1 = new clData(03, 03, 2022), * d2 = new clData(03, 04, 2022), * d3 = new clData(04, 03, 2022);
	clRecord* RC = new clRecord("Соя", 1300, 45, "Б", d1);
	clRecord RC1(Record);
	clRecord* Rarr[3] = { new clRecord("Соя", 1300, 45, "Б", d1),  new clRecord("Чумиза", 8000, 17, "З", d2),  new clRecord("Рис", 25650, 24, "З", d3) };



	D5 = new clData(1, 1, 1);
	D0.printData();
	D1.printData();
	D2.printData();
	D3.printData();
	D5->printData();
	D0.addDay(5);

	delete D5;
	return 5;
}

void menu() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int menu = -10;
	while (menu != 0) {
		cout << "Введите значение от 0 до 6:" << endl;
		cout << "0: Выход" << endl;
		cout << "1: Практика 0" << endl;
		cout << "2: Практика 1" << endl;
		cout << "3: Практика 2" << endl;
		cout << "4: Практика 3" << endl;
		cout << "5: Практика 4" << endl;
		cout << "6: Практика 5" << endl;
		cin >> menu;
		system("cls");
		switch (menu) {
		case 0: break;
		case 1: prak_0(); break;
		case 2: prak_1(); break;
		case 3: prak_2(); break;
		case 4: prak_3(); break;
		case 5: prak_4(); break;
		case 6: prak_5(); break;
		default:
			cout << "Введите другое значение. Вы ввели: " << menu << " Должно быть в диапазоне от 0 до 6" << endl;
			break;
		}
	}

}

int main()
{
	menu();
}

