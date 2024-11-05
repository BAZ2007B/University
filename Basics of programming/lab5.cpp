//Базаров Алмазбек Султанбаевич
// КИ20-07б(1 подгруппа)
//сложность : 100%
//2 вариант
/*Два простых числа называются «близнецами», если они отличаются друг от друга на 2 (например, 41 и 43).
Напечатать все пары «близнецов» из отрезка [n, 2n], где n — заданное натуральное число больше 2.
Простое число – это натуральное число, имеющее ровно два различных натуральных делителя, то есть простое число делится нацело только на самого
себя и единицу. Является ли число простым, оформить как функцию.*/

#include <iostream>
#include <clocale>
using namespace std;

int ProstoeChislo(int x) {
	int sump = 0;
	for (int i = 2; i < x; i++)
	{
		if (x % i == 0) sump = sump + 1;
	}
	if (sump == 0) return 1;
	else return 0;
}

int main()
{
	setlocale(LC_ALL, "russian");
	int a, n, x, y, m1, m, total;
	cout << "Введите натуральное число n (n > 2):";
TryAgain:
	cin >> n;
	if (n <= 2) {
		cout << "Ой, что-то пошло не так. Введите n заново:";
		goto TryAgain;
	}
	total = 0;
	m = 2 * n;
	m1 = m - 2;
	for (int b = n; b <= m1; b++) {
		x = ProstoeChislo(b);
		if (x == 1) {
			y = b + 2;
			a = ProstoeChislo(y);
			if (a == 1) {
				total = total + 1;
				cout << b << " и " << y << endl;
			}
		}
	}
	if (total == 0) cout << "В данной последовательности пар нет.";
	return 0;
}