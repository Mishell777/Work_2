#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <windows.h>

constexpr auto maxline = 1000;

using namespace std;

struct key
{
	const char* keyword;
	int keycount;

} tab[] = {"break", 0,
		   "case", 0,
		   "char", 0,
		   "continue", 0,
		   "end", 0}, * bbb;

/*	Ищет в массиве структур слово, находящееся в word,
n - размерность массива, которая не должна быть задана больше,
чем количество инициализированных элементов массива.
Возвращает указатель на структура типа key, в которой находится слово,
заданное в word, либо возвращает NULL (сигнал того,
что заданное слово в массиве структур не обнаружено) */
static key* BinaryInStruc(char* word, key tab[], int n)
{
	int cond;
	
	key* low = &tab[0];
	key* high = &tab[n - 1];
	/* здесь low и high - это указатели на первый и последний элементы таблицы */

	key* mid; // здесь будет указатель на средний элемент таблицы

	while (low <= high) // указатели можно сравнивать
	{
		/* Разность между указателями - это число элементов массива,
		которое можно делить, а поскольку операция "/" даст целое число,
		то его можно прибавить к указателю low */
		mid = low + (high - low) / 2;

		if ((cond = strcmp(word, mid->keyword)) < 0)
			high = mid - 1; // от указателя можно вычесть целое число, в результате получим указатель на предыдущий элемент
		else if (cond > 0)
			low = mid + 1;
		else
			return mid;  // возврат указателя на найденный элемент таблицы, т.е. на структуру
	}

	return NULL;
}

int main(int argcs, char* pArgs[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	char s[maxline];

	do
	{
		cout << "Введите слово: ";
		cin >> s;

		bbb = BinaryInStruc(s, tab, 5); // bbb объявлен как указатель на структуру key

		if (bbb != NULL)
			cout << "Найдена строка - " << s << " = " << bbb->keyword << " (bbb->keyword)" << endl;
		else
			cout << "Слово не найдено!!!" << endl;

	} while (strcmp(s, "exit") != 0 && strcmp(s, "EXIT") != 0);

	system("PAUSE");
	return 0;
}
