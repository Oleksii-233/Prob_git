#pragma once

#ifndef Nikitiuk
#define Nikitiuk

#include <iostream>
#include <iomanip>
#include <fstream>
#include "Dar`ev.h"
#include "Protocol.h"

using namespace std;

void addtofile(){
	PeopleInformation inf;
	ifstream f1("PeopleInformation.dat", ios::binary);
	ofstream f2("PeopleInformation1.dat", ios::binary);

	if (!f1.is_open() || !f2.is_open()) {
		cout << "Файл не вдалось відкрити." << endl;
		exit(1);
	}

	p_Inic();
	p_Add("Додавання до файлу.");

	while (f1.read((char*)&inf, sizeof inf))
		f2.write((char*)&inf, sizeof inf);

	int num;
	cout << "К-ть, яку хочете дописати: "; cin >> num; cin.get();
	cout << "Введите дані:\n";
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

#endif