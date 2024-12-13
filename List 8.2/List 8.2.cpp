/* List 8.2 - Пример создания классов. Создание и использование класса "не компонента" */
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <windows.h>

using namespace std;

class A
{
protected:
	/* к этим данным имеют доступ только методы данного класса и производных */
	int x;
	int y;

public:
	int a;
	int b;
	int f1(int x, int y) { return (x - y); }
};

class B :A // это объявляет класс, производный от A
{
public:
	int f2(int x)
	{
		A::x = 20; // здесь могут использоваться члены-данные базового класса из секции protected
		return (x + A::x);
	}
};

int main(int argcs, char* pArgs[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	A min;
	B max;

	/* работа с элементами класса A из секции public */
	min.a = 10;
	min.b = 20;

	int x1 = min.f1(min.a, min.b);
	int x2 = max.f2(10); // Работа с элементом класса B

	cout << "x1 = " << x1 << "\nx2 = " << x2 << endl;

	system("PAUSE");
	return 0;
}
