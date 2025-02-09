#pragma once

#ifndef PROTOCOL_H
#define PROTOCOL_H

#include <iostream>
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
void p_Inic();
void p_Close();

void p_Inic() {
	protocol.open("protocol.dat", ios::out | ios::binary | ios::app);
}

void p_Close() {
	protocol.close();
}

void IsOpen(fstream& file) {
	if (!file.is_open()) {
		cout << "Файл для протоколу не відкритий." << endl;
		exit(1);;
	}
}

void p_Add(const char* text) {

	IsOpen(protocol);

	protocol.write(text, strlen(text));
	protocol.put('\n');

}

void p_Add(PeopleInformation p) {
	
	IsOpen(protocol);

	protocol.write((char*)&p, sizeof(p));
	protocol.put('\n');

}

#endif


