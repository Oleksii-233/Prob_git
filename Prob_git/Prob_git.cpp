#include "Dar`ev.h"

#include "Nikitiuk.h"
#include "Yatsyuk.h"

using namespace std;

int main() {
	
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int ans;

	fstream file, file_reg("reg.dat", ios::binary);

	do {
		cout << "Виберіть, що ви бажаєте зробити:\n0 - створення та запис до файлу,\n1 - прочитати данi iз файлу на екран,\n2 - Вивести записи за введеною статею,\n3 - Вивести прізвища, що мають однакову вагу і однаковий номер взуття" << endl;
		cout << "4 - Вивести прізвища, що мають номер одежі більший за 46 і номер взуття менший 41,\n5 - Вивести середню вагу та ріст людей, які мають похибку ваги в межах 5% та людей, які мають похибку в ростові в межах 10 %" << endl;
		cout << "6 - Вивести прізвище людини, що має найменший ріст з найменшим номером одежі та людину з найбільшим номером взуття і найбільшою масою,\n7 - впорядкувати записи в файлі за вибором (прізвище чи ім'я),\n8 - дозаписати файл" << endl;
		cout << "Вихід - Будь - яке інше значення; " << endl;

		cin >> ans;

		switch (ans) {
		case 0: {
			CreateFile(file);
			WriteInFile(file);
		}break;
		case 1: {
			readfromfile(file);
		}break;
		case 2: {
			// Функція
		}break;
		case 3: {
			// Функція
		}break;
		case 4: {
			// Функція
		}break;
		case 5: {
			// Функція
		}break;
		case 6: {
			// Функція
		}break;
		case 7: {
			// Функція
		}break;
		case 8: {
			// Функція
		}break;
		}
	} while (ans >= 0 && ans <= 8);


}