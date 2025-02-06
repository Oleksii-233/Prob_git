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



#endif
