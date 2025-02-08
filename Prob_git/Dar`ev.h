#pragma once
#ifndef DARYEV
#define DARYEV

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <string>

using namespace std;
struct PeopleInformation {
	int Number = 0;
	char Name[100] = "\0";
	char Surname[100] = "\0";
	char Sex[50] = "\0";
	int Height = 0;
	int Weight = 0;
	int ClothesNumber = 0;
	int ShoesNumber = 0;
};

void WriteInFile(fstream& File);
void ShowSex(fstream& File);
void Shapka();
void ShowPeople(PeopleInformation inf);
void EnterPeople(PeopleInformation& People);

void Shapka() {
	cout << setw(3) << "N" << setw(10) << "Прізвище" << setw(10) << "Ім'я" << setw(8) << "Стать" << setw(5) << "Ріст" << setw(5) << "Вага" << setw(7) << "Одяг" << setw(7) << "Взуття" << endl;
}

void ShowPeople(PeopleInformation inf) {
	cout << setw(3) << inf.Number << setw(10) << inf.Surname << setw(10) << inf.Name << setw(8) << inf.Sex << setw(5) << inf.Height << setw(5) << inf.Weight << setw(7) << inf.ClothesNumber << setw(8) << inf.ShoesNumber << endl;
}

void EnterPeople(PeopleInformation& People) {
	cout << "Введіть номер людини: "; cin >> People.Number; cin.ignore();
	cout << "\nВведіть ім'я людини: "; cin.getline(People.Name, 50);
	cout << "\nВведіть прізвище людини: "; cin.getline(People.Surname, 50);
	cout << "\nВведіть стать людини: "; cin.getline(People.Sex, 50);
	cout << "\nВведіть зріст людини: "; cin >> People.Height;
	cout << "\nВведіть вагу людини: "; cin >> People.Weight;
	cout << "\nВведіть номер одягу людини: "; cin >> People.ClothesNumber;
	cout << "\nВведіть номер взуття людини: "; cin >> People.ShoesNumber;
}

void WriteInFile(fstream& File) {
	PeopleInformation People;
	int NumberPeople=0;
	
	File.open("PeopleInformation.dat", ios::out| ios::binary);

if (!File.is_open()) {
		cout << "Файл не створено!" << endl;
		exit(1);
}

	cout << "Введіть кількість людей: "; cin >> NumberPeople;

	for (int i = 0; i < NumberPeople; i++) {
	
	EnterPeople(People);
	
	File.write((char*)&People, sizeof People);

	}

	File.close();

}
void ShowSex(fstream& File) {
	PeopleInformation People;
	char SexIndex[15] = "\0";
	cout << "Введіть стать: "; cin.ignore(); cin.get(SexIndex, 15);
	int k = 0;

	File.open("PeopleInformation.dat", ios::in | ios::binary);

	if (!File.is_open()) {
		cout << "Файл не відкрито!" << endl;
		exit(1);
	}

	Shapka();
	while (File.read((char*)&People, sizeof People)) {

		if (strcmp(People.Sex,SexIndex) == 0) {
			ShowPeople(People);
			k++;
		}
	}

	if (k == 0) {
		system("cls");
		cout << "Людей заданої статі не знайдено." << endl;
	}

	File.close();
}

void IndenticalHeightAndShoes(fstream& File) {
	PeopleInformation People[20];
	int counter = 0;

	File.open("PeopleInformation.dat", ios::in | ios::binary);

	while (File.read((char*)&People, sizeof People))
		counter++;
	
	int k = 0;
	cout << setw(10) << "Прізвища" << setw(10) << "Вага" << setw(10) << "Номер взуття" << endl;
	for (int i = 0; i < counter - 1; i++) {
		int ind = 0;
		for (int j = i + 1; j < counter; j++) {
			if (People[i].Weight == People[j].Weight && People[i].ShoesNumber == People[j].ShoesNumber) {
				if (ind == 0) {
					cout << setw(10) << People[i].Surname << setw(10) << People[i].Weight << setw(10) << People[i].ShoesNumber << endl;
					cout << setw(10) << People[j].Surname << setw(10) << People[j].Weight << setw(10) << People[j].ShoesNumber << endl;
				}
				else 
					cout << setw(10) << People[j].Surname << setw(10) << People[j].Weight << setw(10) << People[j].ShoesNumber << endl;
				ind++;
				k++;
			}
		}
	}

	if (k == 0) {
		cout << "Відсутні." << endl;
	}

	File.close();
}
#endif
