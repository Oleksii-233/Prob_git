#pragma once

#ifndef Yatsiyk
#define Yatsiyk

#include <iostream>
#include <iomanip>
#include <fstream>
#include "Dar`ev.h"

void readfromfile(fstream& file){
PeopleInformation inf;

file.open("PeopleInformation.dat", ios::in, ios::binary);

if (!file.is_open()) {
	cout << "Не вдалось відкрити файл." << endl;
	exit(1);
}

  Shapka();	
  while (file.read((char*)&inf, sizeof(inf)))
	  ShowPeople(inf);
		
file.close();
}

void sortbysize(fstream& file){
PeopleInformation inf;
int k = 0;
file.open("PeopleInformation.dat", ios::in, ios::binary);

if (!file.is_open()) {
	cout << "Не вдалось відкрити файл." << endl;
	exit(1);
}
	
cout<<"Прізвища людей, в яких ном. одягу більше 46 та розмір взуття менше 41:\n";		
  while (file.read((char*)&inf, sizeof(inf)))
  { 
	  if(inf.ClothesNumber>46 && inf.ShoesNumber<41){
		  cout << inf.Number << "\t" << inf.Surname << endl;
	  k++;
	  }
  }

  if (k == 0) 
	  cout << "Відсутні..." << endl;
  
   file.close();

}

double avweight(fstream& file){
PeopleInformation inf;

	file.clear();
	file.seekg(0);

	double avweight = 0.;
	int count = 0;
	while (file.read((char*)&inf, sizeof inf))
    { 
    avweight+=inf.Weight;
	count++;
    }

	if (count == 0) {
		cout << "Записи у файлі відсутні для підрахування середньої ваги." << endl;
		return 0.;
	}
	else
		return avweight / count;
}

double avheight(fstream& file){
PeopleInformation inf;

	file.clear();
	file.seekg(0);

	double avheight = 0;
	int count = 0;
	while (file.read((char*)&inf, sizeof inf))
    { 
    	avheight+=inf.Height;
		count++;
    }

	if (count == 0) {
		cout << "Записи у файлі відсутні для підрахування середнього росту." << endl;
		return 0.;
	}
	else
		return avheight / count;
}


void sortaverage(fstream& file) {
	PeopleInformation inf;
	file.open("PeopleInformation.dat", ios::in, ios::binary);

	if (!file.is_open()) {
		cout << "Файл не відкритий." << endl;
		exit(1);
	}

	double avhe = avheight(file);
	double avwe = avweight(file);

	file.clear();
	file.seekg(0);

	int k = 0;
	cout << "Люди з ростом +-10% від середнього росту: \n";
	Shapka();
	while (file.read((char*)&inf, sizeof inf))
		if (inf.Height <avhe * 1.1 && inf.Height>avhe * 0.9) {
			ShowPeople(inf);
			k++;
		}

	if (k == 0)
		cout << "Відсутні." << endl;

	file.clear();
	file.seekg(0);

	k = 0;
	cout << "Люди з вагою +-5% від середньої ваги: \n";
	Shapka();
	while (file.read((char*)&inf, sizeof inf))
		if (inf.Weight<avwe * 1.05 && inf.Weight>avwe * 0.95) {
			ShowPeople(inf);
			k++;
		}
	
	if (k == 0)
		cout << "Відсутнію" << endl;

	file.close();
}

#endif
