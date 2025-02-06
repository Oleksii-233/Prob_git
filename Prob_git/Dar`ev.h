#pragma once
#ifndef DARYEV
#define DARYEV


#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <locale>

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

void CreateFile(fstream& File);
void WriteInFile(fstream& File);

void CreateFile(fstream& File) {
	File.open("PeopleInformation.dat", ios::out, ios::binary);
	if (File.is_open()) {
		cout << "���� ��������!" << endl;
		File.close();
	}
	else cout << "���� �� ��������!" << endl;
}
void WriteInFile(fstream& File) {
	PeopleInformation People[50];
	int NumberPeople=0;

	File.open("PeopleInformation.dat", ios::out, ios::binary);
	cout << "������ ������� �����: "; cin >> NumberPeople;
	for (int i = 0; i < NumberPeople; i++) {
		cout << "������ ����� ������: "; cin >> People[i].Number;
		cout << "������ ��'� ������: "; cin.get(People[i].Name, 50);
		cout << "������ ������� ������: "; cin.get(People[i].Surname, 50);
		cout << "������ ����� ������: "; cin.get(People[i].Sex, 50);
		cout << "������ ���� ������: "; cin >> People[i].Number;
		cout << "������ ���� ������: "; cin >> People[i].Number;
		cout << "������ ����� ����� ������: "; cin >> People[i].Number;
		cout << "������ ����� ������ ������: "; cin >> People[i].Number;
	}
	File.write((char*)People, sizeof People);
	File.close();
	File.clear();




}

#endif