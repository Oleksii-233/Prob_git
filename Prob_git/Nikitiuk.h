#pragma once

#ifndef Nikitiuk
#define Nikitiuk

#include <iostream>
#include <iomanip>
#include <fstream>
#include "Dar`ev.h"

using namespace std;

void addtofile(){
	PeopleInformation inf;
	ifstream f1("PeopleInformation.dat", ios::binary);
	ofstream f2("PeopleInformation1.dat", ios::binary);

	if (!f1.is_open() || !f2.is_open()) {
		cout << "Файл не вдалось відкрити." << endl;
		exit(1);
	}

	while (f1.read((char*)&inf, sizeof inf))
		f2.write((char*)&inf, sizeof inf);

	int num;
	cout << "К-ть, яку хочете дописати: "; cin >> num; cin.get();
	cout << "Введите дані:\n";
	for (int i = 0; i <= num - 1; i++)
	{
		EnterPeople(inf);
		f2.write((char*)&inf, sizeof inf);
	}

	f1.close();
	f2.close();

	remove("PeopleInformation.dat");
	rename("PeopleInformation1.dat", "PeopleInformation.dat");

}

#endif