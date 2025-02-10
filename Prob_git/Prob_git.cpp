#include "Windows.h"

#include "Dar`ev.h"
#include "Nikitiuk.h"
#include "Yatsyuk.h"
#include "Protocol.h"

using namespace std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	fstream file;
	int ans;

	do {
		cout << "Choose what you want to do:\n0 - Create and write a file,\n1 - Read the file to the screen,\n2 - Show records of a specific gender,\n3 - Have the same weight and shoe number" << endl;
		cout << "4 - The clothing number is larger than 46 and the shoe size is smaller than 41,\n5 - People who are close to the average for weight and size" << endl;
		cout << "6 - People with the smallest shoe size and clothing number and people with the largest weight and shoe number,\n7 - Sort the file by last name or first name,\n8 - Add file" << endl;
		cout << "Enter another number to exit" << endl;

		cin >> ans;

		switch (ans) {
		case 0: {
			WriteInFile(file);
		}break;
		case 1: {
			readfromfile(file);
		}break;
		case 2: {
			ShowSex(file);
		}break;
		case 3: {
			IndenticalHeightAndShoes(file);
		}break;
		case 4: {
			sortbysize(file);
		}break;
		case 5: {
			sortaverage(file);
		}break;
		case 6: {
			ShowSmall();
		}break;
		case 7: {
			My_Sort();
		}break;
		case 8: {
			addtofile();
		}break;
		}
		system("pause");
	} while (ans >= 0 && ans <= 8);


}

