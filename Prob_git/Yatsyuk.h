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
	cout << "�� ������� ������� ����." << endl;
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
	cout << "�� ������� ������� ����." << endl;
	exit(1);
}
	
cout<<"������� �����, � ���� ���. ����� ����� 46 �� ����� ������ ����� 41:\n";		
  while (file.read((char*)&inf, sizeof(inf)))
  { 
	  if(inf.ClothesNumber>46 && inf.ShoesNumber<41){
		  cout << inf.Number << "\t" << inf.Surname << endl;
	  k++;
	  }
  }

  if (k == 0) 
	  cout << "³�����..." << endl;
  
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
		cout << "������ � ���� ������ ��� ����������� �������� ����." << endl;
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
		cout << "������ � ���� ������ ��� ����������� ���������� �����." << endl;
		return 0.;
	}
	else
		return avheight / count;
}


void sortaverage(fstream& file) {
	PeopleInformation inf;
	file.open("PeopleInformation.dat", ios::in, ios::binary);

	if (!file.is_open()) {
		cout << "���� �� ��������." << endl;
		exit(1);
	}

	double avhe = avheight(file);
	double avwe = avweight(file);

	file.clear();
	file.seekg(0);

	int k = 0;
	cout << "���� � ������ +-10% �� ���������� �����: \n";
	Shapka();
	while (file.read((char*)&inf, sizeof inf))
		if (inf.Height <avhe * 1.1 && inf.Height>avhe * 0.9) {
			ShowPeople(inf);
			k++;
		}

	if (k == 0)
		cout << "³�����." << endl;

	file.clear();
	file.seekg(0);

	k = 0;
	cout << "���� � ����� +-5% �� �������� ����: \n";
	Shapka();
	while (file.read((char*)&inf, sizeof inf))
		if (inf.Weight<avwe * 1.05 && inf.Weight>avwe * 0.95) {
			ShowPeople(inf);
			k++;
		}
	
	if (k == 0)
		cout << "³������" << endl;

	file.close();
}

#endif
