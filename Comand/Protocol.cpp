#include "Protocol.h"

#include <iomanip>

char name[] = "protocol.txt";
fstream protocol;
void p_Inic() {
	protocol.open(name, ios::out | ios::app);
}

void p_Close() {
	protocol.close();
}

void IsOpen(fstream& file) {
	if (!file.is_open()) {
		cout << "���� ��� ��������� �� ��������." << endl;
		exit(1);;
	}
}

void p_Add() {
	IsOpen(protocol);
	protocol << setw(3) << "N" << setw(20) << "�������" << setw(20) << "��'�" << setw(8) << "�����" << setw(5) << "г��" << setw(5) << "����" << setw(7) << "����" << setw(7) << "������" << endl;
}

void p_Add(string text) {
	IsOpen(protocol);
	protocol << text << endl;
}

void p_Add(PeopleInformation p) {
	IsOpen(protocol);
	protocol << setw(3) << p.Number << setw(20) << p.Surname << setw(20) << p.Name << setw(8) << p.Sex << setw(5) << p.Height << setw(5) << p.Weight << setw(7) << p.ClothesNumber << setw(8) << p.ShoesNumber << endl;
}

void p_Add_Arr(PeopleInformation* p, int l) {

	IsOpen(protocol);

	for (int i = 0; i < l; i++)
		p_Add(*(p + i));

}

void p_Read() {
	string line;

	protocol.open(name, ios::in);

	IsOpen(protocol);

	while (getline(protocol, line))
		cout << line << endl;

	p_Close();
}