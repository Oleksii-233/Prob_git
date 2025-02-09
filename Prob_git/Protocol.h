#pragma once

#ifndef PROTOCOL_H
#define PROTOCOL_H

#include <iostream>
#include <fstream>

using namespace std;

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
void p_Add(char* text, fstream& protocol);
void p_Add(PeopleInformation p, fstream& protocol);
void p_Inic(fstream& protocol);
void p_Close(fstream& protocol);

void p_Inic(fstream& protocol) {
	protocol.open("protocol.dat", ios::out | ios::binary | ios::app);
}

void p_Close(fstream& protocol) {
	protocol.close();
}

void IsOpen(fstream& file) {
	if (!file.is_open()) {
		cout << "Файл для протоколу не відкритий." << endl;
		exit(1);;
	}
}

void p_Add(char* text, fstream& protocol) {

	IsOpen(protocol);

	protocol.write(text, strlen(text));

}

void p_Add(PeopleInformation p, fstream& protocol) {
	
	IsOpen(protocol);

	protocol.write((char*)&p, sizeof(p));

}

#endif


