/*  */
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <windows.h>

constexpr auto maxline = 1000;

using namespace std;

static void swap(int *a, int *b)
{
	int c = *a;
	*a = *b;
	*b = c;
}

int main(int argcs, char* pArgs[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int A[maxline] = {0,1,2,3,4,5,6,7,8,9};
	int* Pa = &A[0];
	int i = 0;

	for (;;)
	{
		cout << "Введите номер элемента <0-9> (другое число - выход): ";
		cin >> i;

		if (i < 0 || i>9) break;

		cout << "i = " << i << ", A[i] = " << A[i] << ", Pa[i] = " << Pa[i] << endl;
		cout << "*(A + i) = " << *(A + i) << ", *(Pa + i) = " << *(Pa + i) << endl << endl;
	}

	cout << "----------------------------------------------------------------------------------\n";
	int a = 0;
	int b = 0;

	cout << "Введите первое число: ";
	cin >> a;
	cout << "Введите второе число: ";
	cin >> b;

	cout << "a = " << a << ", b = " << b << endl;
	cout << "Обмен!!!" << endl;
	swap(&a, &b);
	cout << "a = " << a << ", b = " << b << endl;

	system("PAUSE");
	return 0;
}
