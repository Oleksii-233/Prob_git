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
  file.clear();
	file.seekg(0);
  cout <<setw(3)<<"№"<< setw(10)<<setw(10)<<"Ім'я"<<setw(8)<<"Стать"<<setw(5)<<"Ріст"<<setw(5)<<"Вага"<<setw(7)<<"№ одежі"<<setw(8)<<"№ взуття"<< endl;	
	
  while (file.read((char*)&inf, sizeof inf))
    {
	cout <<setw(3)<<inf.Number<< setw(10)<<inf.Surname<<setw(10)<<inf.Name<<setw(8)<<inf.Sex<<setw(5)<<inf.Height<<setw(5)<<inf.Weight<<setw(7)<<inf.ClothesNumber<<setw(8)<<inf.ShoesNumber<< endl;	
		
    }
		file.close();
		file.clear();

}

void sortbysize(fstream& file){
PeopleInformation inf;
file.open("PeopleInformation.dat", ios::in, ios::binary);
  file.clear();
	file.seekg(0);	
	cout<<"Прізвища людей, в яких ном. одягу більше 46 та розмір взуття менше 41:\n";	
	
  while (file.read((char*)&inf, sizeof inf))
    { if(inf.ClothesNumber>46 && inf.ShoesNumber<41){
	    cout<<inf.Number<<"\t"<<inf.Surname<<endl;}
    
	}
		file.close();

}

double avweight(fstream& file){
PeopleInformation inf;
	file.open("PeopleInformation.dat", ios::in, ios::binary);
double avweight=0;
int count;
	while (file.read((char*)&inf, sizeof inf))
    { 
    	avweight+=inf.Weight;
	count++;
    }
	file.close();
	return avweight/count;
}

double avheight(fstream& file){
PeopleInformation inf;
	file.open("PeopleInformation.dat", ios::in, ios::binary);
double avheight=0;
int count;
	while (file.read((char*)&inf, sizeof inf))
    { 
    	avheight+=inf.Height;
	count++;
    }
	file.close();
	return avheight/count;
}


void sortaverage(fstream& file){
	PeopleInformation inf;
	file.open("PeopleInformation.dat", ios::in, ios::binary);
double avweight=0, avheight=0;
int length;
	double avheight = avheight(file);
	double avweight = avweight(file);
	cout <<setw(3)<<"№"<< setw(10)<<setw(10)<<"Ім'я"<<setw(8)<<"Стать"<<setw(5)<<"Ріст"<<setw(5)<<"Вага"<<setw(7)<<"№ одежі"<<setw(8)<<"№ взуття"<< endl;	

	cout<<"Люди з ростом +-10% від середнього росту: \n";
	while (file.read((char*)&inf, sizeof inf))
    { 
    	if(inf.Height<avheight*1.1 && inf.Height>avheight*0.9){
	cout <<setw(3)<<inf.Number<< setw(10)<<inf.Surname<<setw(10)<<inf.Name<<setw(8)<<inf.Sex<<setw(5)<<inf.Height<<setw(5)<<inf.Weight<<setw(7)<<inf.ClothesNumber<<setw(8)<<inf.ShoesNumber<< endl;	
	}
	
    }
	cout<<"Люди з вагою +-5% від середньої ваги: \n";
	while (file.read((char*)&inf, sizeof inf))
    { 
    	if(inf.Weight<avweight*1.05 && inf.Weight>avweight*0.95){
	cout <<setw(3)<<inf.Number<< setw(10)<<inf.Surname<<setw(10)<<inf.Name<<setw(8)<<inf.Sex<<setw(5)<<inf.Height<<setw(5)<<inf.Weight<<setw(7)<<inf.ClothesNumber<<setw(8)<<inf.ShoesNumber<< endl;	
	}
	
    }
	file.close();
}

void addtofile(){
	PeopleInformation inf;
	ifstream f1("PeopleInformation.dat", ios::binary);
	//відкриваємо buffer.dat для запису
	ofstream f2("PeopleInformation1.dat", ios::binary);
	//в циклі читаємо дані і tovary.dat
	//и записуємо в buffer.dat
	while (f1.read((char*)&inf, sizeof inf))
		f2.write((char*)&inf, sizeof inf);
	int num;
	cout << "К-ть, яку хочете дописати: "; cin >> num; cin.get();
	//в циклі вводимо товари і дописуємо їх в bufer.dat 
	cout << "Введите дані:\n";
	for (i = 0; i <= m - 1; i++)
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
	//закриваємо обидва файли 
	f1.close();
	f2.close();

	remove("PeopleInformation.dat");
	rename("PeopleInformation1.dat", "PeopleInformation.dat");


}

#endif
