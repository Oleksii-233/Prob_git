#pragma once

#ifndef Nikitiuk
#define Nikitiuk

#include <iostream>
#include <iomanip>
#include <fstream>
#include "Dar`ev.h"
#include "Protocol.h"

using namespace std;

void addtofile();
void My_Swap(PeopleInformation& p0, PeopleInformation& p1);
void My_Sort();

void addtofile(){
	PeopleInformation inf;
	ifstream f1("PeopleInformation.dat", ios::binary);
	ofstream f2("PeopleInformation1.dat", ios::binary);

	if (!f1.is_open() || !f2.is_open()) {
		cout << "���� �� ������� �������." << endl;
		exit(1);
	}

	p_Inic();
	p_Add("��������� �� �����.");

	while (f1.read((char*)&inf, sizeof inf))
		f2.write((char*)&inf, sizeof inf);

	int num;
	cout << "�-��, ��� ������ ��������: "; cin >> num; cin.get();
	cout << "������� ���:\n";
	for (int i = 0; i <= num - 1; i++)
	{
		EnterPeople(inf);
		p_Add(inf);
		f2.write((char*)&inf, sizeof inf);
	}

	f1.close();
	f2.close();
	p_Close();

	remove("PeopleInformation.dat");
	rename("PeopleInformation1.dat", "PeopleInformation.dat");

}


void My_Swap(PeopleInformation& p0, PeopleInformation& p1) {
	PeopleInformation t;
	t = p0;
	p0 = p1;
	p1 = t;
}

void My_Sort() {
	PeopleInformation peo, p[15];
	int len = 0;
	char name[] = "PeopleInformation.dat";

	fstream file(name, ios::in | ios::binary);

	if (!file.is_open()) {
		cout << "���� �� �������." << endl;
		exit(1);
	} // �������� �� �������� ����

	while (file.read((char*)&peo, sizeof(peo)))
		p[len++] = peo; // ���������� ��� ������ �������� �� ������������ ������� � ������

	file.close();

	bool variat;
	cout << "������� �� ��� ��������� 0 - �� ��������, ���� - ��� ���� �������� - �� ��'��.";
	cin >> variat;

	if (!variat) {
		for (int i = 0; i < len - 1; i++) {
			for (int j = i + 1; j < len; j++)
				if (strcmp(p[i].Surname, p[j].Surname) > 0)
					My_Swap(p[i], p[j]);
		}
	} // ���������� �� ��������
	else {
		for (int i = 0; i < len - 1; i++) {
			for (int j = i + 1; j < len; j++)
				if (strcmp(p[i].Name, p[j].Name) > 0)
					My_Swap(p[i], p[j]);
		}
	} // ���������� �� ��'��


	fstream fbuf("bufer.dat", ios::out | ios::binary);
	if (!fbuf.is_open()) {
		cout << "���� ����� �� �������." << endl;
		exit(1);
	}
	fbuf.write((char*)&p, sizeof(p[0]) * len);
	fbuf.close();

	remove(name);
	rename("bufer.dat", name);

}
#endif