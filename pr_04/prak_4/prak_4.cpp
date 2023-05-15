#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

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
//struct Record
//{
//	string name;
//	string product;
//	int acreage;
//	double productivity;
//	date Date;
//};


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

int main()
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
}