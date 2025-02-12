#pragma once

#ifndef Nikitiuk
#define Nikitiuk

#include "Dar`ev.h"
#include "Protocol.h"

using namespace std;

void addtofile();
void My_Swap(PeopleInformation& p0, PeopleInformation& p1);
void My_Sort();
void ShowSmall();
double My_Min(PeopleInformation* p, int len);
double My_Max(PeopleInformation* p, int len);
void My_Sort_Min(PeopleInformation* p, int len);
void My_Sort_Max(PeopleInformation* p, int len);
void ShowArr(PeopleInformation* p, int len);

#endif