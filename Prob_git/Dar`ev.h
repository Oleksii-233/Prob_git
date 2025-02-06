#pragma once
#ifndef DARYEV
#define DARYEV


#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>



using namespace std;
struct PeopleInformation {
	int Number = 0;
	char Name[50] = "\0";
	char Surname[50] = "\0";
	char Sex[50] = "\0";
	int Height = 0;
	int Weight = 0;
	int ClothesNumber = 0;
	int ShoesNumber = 0;

};

void WriteInFile(fstream& File);

void Shapka();


void Shapka() {
	cout <<setw(1)<< "№ людини" << setw(10) << "Ім'я" << setw(10) << "Фамилія" << setw(10) << "Стать" << setw(10) << "Зріст" << setw(10) << "Вага" << setw(10) << "№ одежі" << setw(10) << "№ взуття" << endl;
}

void WriteInFile(fstream& File) {
	PeopleInformation People;
	int NumberPeople=0;
	

	File.open("PeopleInformation.dat", ios::out| ios::binary);

if (File.is_open()) {
		cout << "Файл створено!" << endl;
	}
	else cout << "Файл не створено!" << endl;

	cout << "Введіть кількість людей: "; cin >> NumberPeople;
	for (int i = 0; i < NumberPeople; i++) {
		cout << "Введіть номер людини: "; cin >> People.Number;
		cout << "\nВведіть ім'я людини: "; cin.get(People.Name, 50);
		cout << "\nВведіть прізвище людини: "; cin.get(People.Surname, 50);
		cout << "\nВведіть стать людини: "; cin.get(People.Sex, 50);
		cout << "\nВведіть зріст людини: "; cin >> People.Number;
		cout << "\nВведіть вагу людини: "; cin >> People.Number;
		cout << "\nВведіть номер одягу людини: "; cin >> People.Number;
		cout << "\nВведіть номер взуття людини: "; cin >> People.Number;
	File.write((char*)&People, sizeof People);
	}
	File.close();
	File.clear();
}

void ShowSex(fstream& File) {
	PeopleInformation People;

	File.open("PeopleInformation.dat", ios::out | ios::binary);


	while (File.read((char*)&People, sizeof People)) {

		cout << People.Number;
		cout<<People.Name;
		cout<<People.Surname;
		cout<<People.
		

	}
}











