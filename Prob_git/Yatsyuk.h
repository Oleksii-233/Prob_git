#pragma once

#ifndef Yatsiyk
#define Yatsiyk

#include <iostream>
#include <iomanip>
#include <fstream>
#include "Dar`ev.h"
#include "Protocol.h"

void readfromfile(fstream& file);

void sortbysize(fstream& file);
double avweight(fstream& file);
double avheight(fstream& file);
void sortaverage(fstream& file);

#endif
