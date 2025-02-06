#pragma once
#ifndef Nikitiuk
#define Nikitiuk
#include <iosrteam>
#include <fstream>
#include "Dar'ev.h"
using namespace std;

void addtofile(){
	PeopleInformation inf;
	ifstream f1("PeopleInformation.dat", ios::binary);
	ofstream f2("PeopleInformation1.dat", ios::binary);
	while (f1.read((char*)&inf, sizeof inf))
		f2.write((char*)&inf, sizeof inf);
	int num;
	cout << "К-ть, яку хочете дописати: "; cin >> num; cin.get();
	cout << "Введите дані:\n";
	for (i = 0; i <= num - 1; i++)
	{
		for (int i = 0; i < NumberPeople; i++) {
		cout << "Введіть номер людини: "; cin >> inf.Number;
		cout << "\nВведіть ім'я людини: "; cin.get(inf.Name, 50);
		cout << "\nВведіть прізвище людини: "; cin.get(inf.Surname, 50);
		cout << "\nВведіть стать людини: "; cin.get(inf.Sex, 50);
		cout << "\nВведіть зріст людини: "; cin >> inf.Number;
		cout << "\nВведіть вагу людини: "; cin >> inf.Number;
		cout << "\nВведіть номер одягу людини: "; cin >> inf.Number;
		cout << "\nВведіть номер взуття людини: "; cin >> inf.Number;
	f2.write((char*)&inf, sizeof inf);
	}
	}
	f1.close();
	f2.close();

	remove("PeopleInformation.dat");
	rename("PeopleInformation1.dat", "PeopleInformation.dat");


}
void poshuk(char Surname, int Height, int ClothesNumber, int ShoesNumber, int Weight){
  for(
}
