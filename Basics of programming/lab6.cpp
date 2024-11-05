//Базаров Алмазбек Султанбаевич
// КИ20-07б(1 подгруппа)
//сложность : 100%
//2 вариант
/*Разработать программу, решающую следующую задачу: вычислить функцию, заданную как сумму ряда с заданной точностью δ>0
(δ, х — вещественные числа, вводятся с клавиатуры). При подсчёте суммы функцию возведения в степень (стандартную pow() или её
самописный аналог) не использовать.
Программа должна выводить: 1) сумму ряда; 2) значение соответствующей математической функции, подсчитанное с помощью стандартных функций
из стандартной библиотеки (#include <cmath>); 3) разность этих величин.*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <clocale>
#include <iostream>
#include <math.h>

int main()
{
    setlocale(LC_ALL, "russian");
    float b, x, a, arkkotangens, raz, w, y, q;
    float z = 1;
    int z1 = 1;
    y = 1;
    printf("Введите x :");
Tryagain:
    scanf("%f", &x);
    if ((abs(x) >= 1) || (abs(x) == 0))
    {
        printf("Введите x еще раз :");
        goto Tryagain;
    }
    printf("Введите b :");
    scanf("%f", &b);
    a = asin(1);// PI/2
    arkkotangens = atan(x);
    arkkotangens = 1 / arkkotangens;
    if (b > x) { printf(""); }
    else {
        do {
            z = 1;
            for (float i = 1; i <= y; i++) {
                z = z * x;
            }
            w = z / y;
            if (z1 % 2 == 1) w = w * (-1);
            printf("\n%f", w);
            a = a + w;
            y = y + 2;
            q = w;
            w = abs(w);
            z1 = z1 + 1;
        } while (b < w);
        if (q >= 0) a = a - q;
        else a = a + w;
    }
    raz = a - arkkotangens;
    printf("\na(сумма) - %f", a);
    printf("\nарккотангенс - %f", arkkotangens);
    printf("\nВот сумма = %f", raz);
    return 0;
}

