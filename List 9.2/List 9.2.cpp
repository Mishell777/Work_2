#include <fstream>
#include <iostream>
#include <windows.h>

using namespace std;

int main(int argcs, char* pArgs[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	fstream inout; // ("fstream.out");

	inout.open("fstream.out", ios::out | ios::in);
	if (!inout.is_open())
	{
		return 7;
	}
	
	// вывод в файл
	inout << "Строка номер 1" << endl;
	inout << "Строка номер 2" << endl;
	inout << "Строка номер 3" << endl;

	char p[100]{};

	// установка указателя файла (позиционирование) в его начало
	inout.seekg(0);

	// чтение 1-ой строки (длиной не более 100 символов)
	inout.getline(p, 100);
	// вывод 1-ой строки на экран (stdout)
	cout << "Строка №1:\n" << p;

	// чтение 2-ой строки из файла
	inout.getline(p, 100);
	// вывод 2-ой строки на экран (stdout)
	cout << endl << "Строка №2:\n" << p;

	// запоминание текущей позии в файле после 2-го вывода
	fstream::pos_type pos = inout.tellg();

	// чтение 3-ей строки из файла
	inout.getline(p, 100);
	// вывод 3-ей строки на экран (stdout)
	cout << endl << "Строка №3:\n" << p;

	// установка указателя перед 2-й строкой
	inout.seekp(pos);
	// запись на место 2-ой строки
	inout << "Строка №2_2" << endl;
	// запись на место 3-ей строки
	inout << "Строка №3_2" << endl;

	// установка на начало файла
	inout.seekg(0);

	// вывод всего содержимого потока на экран (stdout)
	cout << endl << endl << inout.rdbuf();
	inout.close();

	system("PAUSE");
	return 0;
}
