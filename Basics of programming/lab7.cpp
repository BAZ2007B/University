//Базаров Алмазбек Султанбаевич
// КИ20-07б(1 подгруппа)
//сложность : 100%
//2 вариант
/*Разработать программу, решающую следующую задачу: протабулировать функцию f(x) на интервале [A, B] с шагом h и
провести вычисления согласно вариантам в таблице:
Локальные минимумы* (значение функции и соответствующие значения аргумента). Если вблизи точки х0 (на отрезке [x0−h;x0+h]) 
все значения функции не меньше, чем в этой точке, то х0 — точка локального минимума
xsin3x−1
*/

#include <iostream>
#include <iomanip>
#include <clocale>
#include <stdio.h>
#include <conio.h>
#include <math.h>
using namespace std;

double f(double x) {
    double a = sin(3 * x);
    double b = (x * a) - 1;
    return b;
}

int main()
{
    setlocale(LC_ALL, "russian");
    double A, B, h, fx, fx1, fx2;
    cout << "Введите A(Начало отрезка):";
    cin >> A;
TryAgain:
    cout << "Введите B(Конец отрезка):";
    cin >> B;
    if (B <= A) {
        cout << "B не может быть больше , повторите.\n";
        goto TryAgain;
    }
    cout << "Введите h(Шаг отрезка):";
    cin >> h;
    for (A; A <= B; A = A + h) {
        fx = f(A);
        fx1 = f(A - h);
        fx2 = f(A + h);
        if ((fx <= fx1) && (fx <= fx2)) {
            cout.setf(ios::left);
            cout.setf(ios::fixed);
            cout << setw(10) << A;
            cout << " ";
            cout << setw(10) << fx;
            cout << "*" << endl;
        }
    }
    return 0;
}