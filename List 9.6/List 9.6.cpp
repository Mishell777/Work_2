#include <fstream>
#include <iostream>
#include <windows.h>

using namespace std;

struct Blocknotes
{
	char name[30];
	char phone[25];
	int age;
}b[3] = {"Василиса", "123457", 10,
		 "Наталия", "9875321", 50,
		 "Михаил", "754321", 55};

int main(int argcs, char* pArgs[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	// запись данных в файл
	ofstream file;
	file.open("block.bin", ios::binary);
	if (!file.is_open()) return 5;

	for (int i = 0; i < 3; i++) file.write((char*)&b[i], sizeof(b[i]));
	file.close();

	// чтение данных из файла
	ifstream file1;
	file1.open("block.bin", ios::binary);
	if (!file1) return 7;

	Blocknotes bb[3]{};
	int i = 0;
	while (!file1.eof())
	{
		if (i == 3) break;

		file1.read((char*)&bb[i], sizeof(bb[i]));
		cout << "Строка" << i << " " << bb[i].name << " " << bb[i].phone << " " << bb[i].age << endl;
		i++;
	}
	
	file1.close();

	system("PAUSE");
	system("DEL BLOCK.BIN");
	return 0;
}
