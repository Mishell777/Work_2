/* List 7.8 - упрощенный расчет зарплаты */
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <windows.h>

using namespace std;

struct zrp // структура данных по зарплате
{
	const char* name; // имя работника
	float stavka;	  // оплата за один рабочий день
	float nalog;	  // величина налога

}emp[] = {"Иванов",  200, 0.1,
		  "Петров",  300, 0.2,
		  "Сидоров", 400, 0.3
		 };

/* Функция начисления зарплаты одному работнику,
RabDn - количество отработанных дней*/
static float zarplata(struct zrp *z, int RabDn)
{
	return z->stavka * RabDn * (1 - z->nalog);
}

int main(int argcs, char* pArgs[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int i = 0;
	struct zrp* pl = NULL;

	/* определение размера массива: */
	int RazmMas = sizeof(emp) / sizeof(zrp);

	for (;;)
	{
		cout << "Введите номер работника (отрицательное число - для выхода): ";
		cin >> i;

		if (i < 0) break;

		if (i < RazmMas) // контроль количества заданных элементов массива
			pl = &emp[i];
		else
			continue;
		
		cout << "Введите количество отработанных дней: ";
		cin >> i;

		float zp = zarplata(pl, i); // обращение к функции расчета зарплаты
		cout << pl->name << ", " << zp << endl;
	}

	system("PAUSE");
	return 0;
}
