#include <string>
#include <fstream>
#include <iostream>
#include <windows.h>

constexpr auto DelKey = ' '; // это символ будет удаляться из потока
constexpr auto maxline = 1000;

using namespace std;

int main(int argcs, char* pArgs[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	// Проверка вывода
	ofstream FILE;

	FILE.open("a.txt", ios::out);
	if (!FILE.is_open()) return 5;
	
	string p;
	int i = 0, pos = 0;

	for (i = 0; i < 3; i++)
		FILE << "строка " << i; // << endl;

	FILE.close();

	// Проверка ввода (чтения по записям)
	ifstream FILE1;

	FILE1.open("a.txt", ios::in);
	if (!FILE1.is_open()) return 7;

	while (!FILE1.eof()) // так проверяется конец файла
	{
		FILE1 >> p >> i;
		cout << p << ' ' << i << endl;
	}
	FILE1.close();

	// Проверка посимвольного чтения
	ifstream FILE2;
	char c;

	FILE2.open("a.txt", ios::in);
	if (!FILE2.is_open()) return 9;

	while (true)
	{
		/* смотрит, какой следующий символ будет считан,
		но указатель позиционирования при этом не сдвигается:
		остается на этом символе */
		c = FILE2.peek();
		streampos cgp = FILE2.tellg(); // так определяется текущая позиция в файле

		if (c == DelKey) // выбрасываются все символы DelKey из читаемого потока
		{
			pos = (int)cgp + 1; // готовимся пропустить символ по seekg()
			FILE2.seekg(pos); // передвинули указатель позиционирования на один символ дальше, чтобы пропустить символ
			continue; // на продолжение цикла
		}
		FILE2.get(c); // чтение символа в c 
		if (FILE2.eof()) break; // последний символ -1('я'), это как раз и есть конец файла, EOF=-1'я', и только после его прочтения срабатывает сам eof()
		cout << c;
	}

	cout << endl;
	FILE2.close();

	system("PAUSE");
	system("DEL A.TXT");
	return 0;
}
