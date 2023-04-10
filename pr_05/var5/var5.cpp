#include <iostream>
#include <windows.h> 
#include <iomanip>
#include<string.h>
#include <string>
#include <stdio.h>


using namespace std;

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

	//unsigned short getDate() {
	//	return day, month, year;
	//}

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
	
	clRecord(string nm2, unsigned int prod, float acr, string typ,  clData dt2);
	clRecord(struct Record* record);
	string get_name() { return name; }
	string get_type() { return type; }

	unsigned int get_productivity() { return productivity; }

	float get_acreage() { return acreage; }

	unsigned short get_Data() { return Data.getData(); }

	void get_clData();
};


clRecord::clRecord(string nm2, unsigned int prod, float acr, string typ, clData dt2) {
	name = nm2;
	type = typ;
	productivity = prod;
	acreage = acr;
	Data = dt2;
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

int main() {
	setlocale(LC_ALL, "Rus");

	Data MD = { 3, 3, 2023 };
	struct Record* record = new Record({ "Соя", "Б", 1300, 45, { 03, 03, 2022 } });
	struct Record* record1 = new Record({ "Чумиза", "З", 8000, 17, { 03,04,2022 } });
	struct Record* record2 = new Record({"Рис", "З", 25650, 24, { 04,03,2022 } });
	clData D0;
	clData D3(&MD);
	clData D2(MD);
	clData D1(12, 03, 12);
	clData* D5;
	clRecord RC ( "Соя", "Б", 1300, 45, { 03, 03, 2022 } );
	clRecord RC1(Record);
	clRecord Rarr[3] = {
		{  "Соя", "Б", 1300, 45, { 03, 03, 2022 }} , {  "Чумиза", "З", 8000, 17, { 03,04,2022 }}, { "Рис", "З", 25650, 24, { 04,03,2022 } }
	};
	


	D5 = new clData(1, 1, 1);
	D0.printData();
	D1.printData();
	D2.printData();
	D3.printData();
	D5->printData();
	D0.addDay(5);

	delete D5;
	return 0;
}

