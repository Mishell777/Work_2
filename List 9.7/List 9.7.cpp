#include <iostream>
#include <windows.h>

using namespace std;

int main(int argcs, char* pArgs[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int i;
	float f;
	char c;

	// ввод целого числа, числа с плавающей точкой и символа с stdin
	cout << "Введите i,f,c >" << endl;
	cin >> i >> f >> c;

	// вывод i, f и c на stdout
	cout << i << endl << f << endl << c << endl;

	char p[50];
	
	// приказ на удаление из ввода всех пробелов
	cin >> ws >> p;
	cout << p << endl;

	/* чтение символов с stdin,
	пока не будет нажата клавиша <Enter>
	или не будет прочтены 49 символов */
	cin.seekg(0);
	cin.getline(p, 50);

	// вывод результата на stdout
	cout << p << endl;

	system("PAUSE");
	return 0;
}
