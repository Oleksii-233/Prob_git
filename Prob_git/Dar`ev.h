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

void Shapka() {
	cout << setw(3) << "N" << setw(10) << "�������" << setw(10) << "��'�" << setw(8) << "�����" << setw(5) << "г��" << setw(5) << "����" << setw(7) << "����" << setw(7) << "������" << endl;
}

void ShowPeople(PeopleInformation inf) {
	cout << setw(3) << inf.Number << setw(10) << inf.Surname << setw(10) << inf.Name << setw(8) << inf.Sex << setw(5) << inf.Height << setw(5) << inf.Weight << setw(7) << inf.ClothesNumber << setw(8) << inf.ShoesNumber << endl;
}

void EnterPeople(PeopleInformation& People) {
	cout << "������ ����� ������: "; cin >> People.Number; cin.ignore();
	cout << "������ ��'� ������: "; cin.getline(People.Name, 50);
	cout << "������ ������� ������: "; cin.getline(People.Surname, 50);
	cout << "������ ����� ������: "; cin.getline(People.Sex, 50);
	cout << "������ ���� ������: "; cin >> People.Height;
	cout << "������ ���� ������: "; cin >> People.Weight;
	cout << "������ ����� ����� ������: "; cin >> People.ClothesNumber;
	cout << "������ ����� ������ ������: "; cin >> People.ShoesNumber;
}

void WriteInFile(fstream& File) {
	PeopleInformation People;
	int NumberPeople=0;
	
	File.open("PeopleInformation.dat", ios::out| ios::binary);

if (!File.is_open()) {
		cout << "���� �� ��������!" << endl;
		exit(1);
}

	p_Inic();
	p_Add("���� ��������");

	cout << "������ ������� �����: "; cin >> NumberPeople;

	for (int i = 0; i < NumberPeople; i++) {
	
	EnterPeople(People);
	p_Add(People);
	File.write((char*)&People, sizeof People);

	}

	File.close();
	p_Close();
}

void ShowSex(fstream& File) {
	PeopleInformation People;
	char SexIndex[15] = "\0";
	cout << "������ �����: "; cin.ignore(); cin.get(SexIndex, 15);
	int k = 0;

	File.open("PeopleInformation.dat", ios::in | ios::binary);

	if (!File.is_open()) {
		cout << "���� �� �������!" << endl;
		exit(1);
	}

	p_Inic();
	p_Add("���� ������ ����.");

	Shapka();
	while (File.read((char*)&People, sizeof People)) {

		if (strcmp(People.Sex,SexIndex) == 0) {
			p_Add(People);
			ShowPeople(People);
			k++;
		}
	}

	if (k == 0) {
		system("cls");
		cout << "����� ������ ���� �� ��������." << endl;
		p_Add("���� ������ ���� ������.");
	}

	File.close();
	p_Close();
}

void IndenticalHeightAndShoes(fstream& File) {
	PeopleInformation People[15], p;
	int counter = 0;

	File.open("PeopleInformation.dat", ios::in | ios::binary);

	if (!File.is_open()) {
		cout << "�� ������� ������� ����." << endl;
		exit(1);
	}

	p_Inic();

	while (File.read((char*)&p, sizeof p))
		People[counter++] = p;
	

	p_Add("���� �������� ���� �� ������ ������.");

	int k = 0;
	cout << setw(10) << "�������" << setw(10) << "����" << setw(10) << "����� ������" << endl;
	for (int i = 0; i < counter - 1; i++) {
		int ind = 0;
		for (int j = i + 1; j < counter; j++) {
			if (People[i].Weight == People[j].Weight && People[i].ShoesNumber == People[j].ShoesNumber) {
				if (ind == 0) {
					p_Add(People[i]); p_Add(People[j]);
					cout << setw(10) << People[i].Surname << setw(10) << People[i].Weight << setw(10) << People[i].ShoesNumber << endl;
					cout << setw(10) << People[j].Surname << setw(10) << People[j].Weight << setw(10) << People[j].ShoesNumber << endl;
				}
				else {
					cout << setw(10) << People[j].Surname << setw(10) << People[j].Weight << setw(10) << People[j].ShoesNumber << endl;
					p_Add(People[j]);
				}
				ind++;
				k++;
			}
		}
	}

	if (k == 0) {
		cout << "³�����." << endl;
		p_Add("���� � ��������� ������� ���� �� ������ ������.");
	}

	File.close();
}
#endif
