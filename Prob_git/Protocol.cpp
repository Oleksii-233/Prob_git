#include "Protocol.h"

void p_Inic() {
	protocol.open("protocol.txt", ios::out | ios::app);
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
	protocol << text << endl;
}

void p_Add(PeopleInformation p) {
	IsOpen(protocol);
	protocol << setw(3) << p.Number << setw(25) << p.Surname << setw(25) << p.Name << setw(8) << p.Sex << setw(5) << p.Height << setw(5) << p.Weight << setw(7) << p.ClothesNumber << setw(8) << p.ShoesNumber << endl;
}

void p_Add() {
	IsOpen(protocol);
	protocol << setw(3) << "N" << setw(25) << "Прiзвище" << setw(25) << "Iм'я" << setw(8) << "Стать" << setw(5) << "Рiст" << setw(5) << "Вага" << setw(7) << "N одежі" << setw(8) << "N взуття" << endl;
}

void p_Add_Arr(PeopleInformation* p, int l) {

	IsOpen(protocol);

	for (int i = 0; i < l; i++)
		p_Add(*(p + i));

}