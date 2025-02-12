#pragma once

#ifndef PROTOCOL_H
#define PROTOCOL_H

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

fstream protocol;

struct PeopleInformation {
	int Number = 0;
	char Name[100] = "\0";
	char Surname[100] = "\0";
	char Sex[50] = "\0";
	int Height = 0;
	int Weight = 0;
	int ClothesNumber = 0;
	int ShoesNumber = 0;
};

void IsOpen(fstream& file);
void p_Add(char* text);
void p_Add(PeopleInformation p);
void p_Add();
void p_Inic();
void p_Close();
void p_Add_Arr(PeopleInformation* p, int l);


#endif


