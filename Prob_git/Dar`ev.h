#pragma once
#ifndef DARYEV
#define DARYEV

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <string>
#include "Protocol.h"

using namespace std;



void WriteInFile(fstream& File);
void ShowSex(fstream& File);
void Shapka();
void ShowPeople(PeopleInformation inf);
void EnterPeople(PeopleInformation& People);
void IndenticalHeightAndShoes(fstream& File);
void TrueNum(int& num);

void Shapka() {
	cout << setw(3) << "N" << setw(10) << "Прізвище" << setw(10) << "Ім'я" << setw(8) << "Стать" << setw(5) << "Ріст" << setw(5) << "Вага" << setw(7) << "Одяг" << setw(7) << "Взуття" << endl;
}

void ShowPeople(PeopleInformation inf) {
	cout << setw(3) << inf.Number << setw(10) << inf.Surname << setw(10) << inf.Name << setw(8) << inf.Sex << setw(5) << inf.Height << setw(5) << inf.Weight << setw(7) << inf.ClothesNumber << setw(8) << inf.ShoesNumber << endl;
}

void EnterPeople(PeopleInformation& People) {
	cout << "Введіть номер людини: "; cin >> People.Number; cin.ignore();
	cout << "Введіть ім'я людини: "; cin.getline(People.Name, 50);
	cout << "Введіть прізвище людини: "; cin.getline(People.Surname, 50);
	cout << "Введіть стать: "; cin.getline(People.Sex, 50);
	cout << "Введіть ріст людини: "; cin >> People.Height;
	cout << "Введіть вагу людини: "; cin >> People.Weight;
	cout << "Введіть номер одягу: "; cin >> People.ClothesNumber;
	cout << "Введіть номер взуття: "; cin >> People.ShoesNumber;
}
void EnterPeopleInFile(PeopleInformation& People, fstream& File) {
	File << People.Number << endl;

	cin.ignore(); 

	cin.getline(People.Name, 50);
	File << People.Name << endl;

	cin.getline(People.Surname, 50);
	File << People.Surname << endl;

	cin.getline(People.Sex, 10);
	File << People.Sex << endl;

	File << People.Height << endl;
	File << People.Weight << endl;
	File << People.ClothesNumber << endl;
	File << People.ShoesNumber << endl;
}

void WriteInFile(fstream& File) {
	PeopleInformation People;
	int NumberPeople = 0;

	File.open("PeopleInformation.txt", ios::out | ios::binary);

	if (!File.is_open()) {
		cout << "Файл не відкрито!" << endl;
		exit(1);
	}

	p_Inic();
	p_Add("Ôàéë ñòâîðåíî");

	cout << "Ââåä³òü ê³ëüê³ñòü ëþäåé: "; TrueNum(NumberPeople);

	for (int i = 0; i < NumberPeople; i++) {

		EnterPeople(People);
		p_Add(People);
		EnterPeopleInFile(People, File);
	}

	File.close();
	p_Close();
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

	p_Inic();
	p_Add("Ëþäè çàäàíî¿ ñòàò³.");

	Shapka();
	while (File.read((char*)&People, sizeof People)) {

		if (strcmp(People.Sex, SexIndex) == 0) {
			p_Add(People);
			ShowPeople(People);
			k++;
		}
	}
	File.close();
	p_Close();
}

void IndenticalHeightAndShoes(fstream& File) {
	PeopleInformation People[15], p;
	int counter = 0;

	File.open("PeopleInformation.dat", ios::in | ios::binary);

	if (!File.is_open()) {
		cout << "Файл не відкрито." << endl;
		exit(1);
	}

	p_Inic();

	while (File.read((char*)&p, sizeof p))
		People[counter++] = p;


	p_Add("Ëþäè îäíàêîâî¿ âàãè òà íîìåðó âçóòòÿ.");

	int k = 0;
	cout << setw(10) << "Прізвище" << setw(10) << "Вага" << setw(20) << "Взуття" << endl;
	for (int i = 0; i < counter - 1; i++) {

		for (int j = i + 1; j < counter; j++) {
			if (People[i].Weight < People[j].Weight) {
				swap(People[i], People[j]);
			}
			k++;
		}
	}
	if (k == 0) {
		cout << "Такі люди відсутні." << endl;
		p_Add("Ëþäè ç îäíàêîâèì íîìåðîì âàãè òà âçóòòÿ â³äñòóí³.");
	}
	bool found = false;
	for (int i = 0; i < counter - 1; i++) {
		bool groupPrinted = false;
		for (int j = i + 1; j < counter; j++) {
			if (People[i].Weight == People[j].Weight && People[i].ShoesNumber == People[j].ShoesNumber) {
				if (!groupPrinted) {
					cout << setw(15) << People[i].Surname << setw(10) << People[i].Weight << setw(10) << People[i].ShoesNumber << endl;
					groupPrinted = true;
				}
				cout << setw(15) << People[j].Surname << setw(10) << People[j].Weight << setw(10) << People[j].ShoesNumber << endl;
				found = true;
			}
		}
	}

	if (!found) {
		cout << "Такі люди відсутні." << endl;
	}


	File.close();
}

void TrueNum(int& num) {
	do {
		cin >> num;
	} while (num <= 0 || num >= 15);
}

#endif

