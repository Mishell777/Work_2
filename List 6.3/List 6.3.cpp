#pragma hdrstop

#include <stdio.h>
#include <conio.h>
#include <windows.h>

int bitcount(unsigned n)
{
	int b;
	for (b = 0; n != 0; n >>= 1)
		if (n & 01) b++;
	return b;
}

int main(int argcs, char* pArgs[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int n = 0177;
	printf("Количество бит в числе: %d\n", bitcount(n));

	return 0;
}
