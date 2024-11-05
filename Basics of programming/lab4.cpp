//Базаров Алмазбек Султанбаевич
// КИ20-07б(1 подгруппа)
//сложность : 100%
//2 вариант
/*Разработать, отладить, продемонстрировать и защитить преподавателю программу, которая для произвольного числа x, введенного
с клавиатуры, вычисляет значение y по следующей формуле :
y = f1(x) + f2(x),
где, f1(x) и f2(x) вычисляются по формулам из табл. 2 согласно вариантам.Вычисление f1(x) и f2(x) оформить как функции.
f1(x) - 100/2x2+1  f2(x) - корень в степени 3(50cosx2)+2.13⋅10^5  */

#include <clocale>
#include <iostream>
#include <math.h>

float f1(float x1) {
    float aa, bb;
    aa = pow(x1, 2);
    bb = 2 * aa + 1;
    x1 = 100 / bb;
    return x1;
}

float f2(float x2) {
    float a, b, c, d;
    a = x2 * x2;
    printf("%f a = x2*x2;", a);
    b = cos(a);
    printf("\n%f b = cos(a);", b);
    c = 50 * b;
    printf("\n%f c = 50 * b;", c);
    d = cbrt(c);
    printf("\nd = %f", d);
    x2 = d + 213000.0;
    printf("\n%f x2 = a1 + 213000;", x2);
    return x2;
}

int main()
{
    setlocale(LC_ALL, "russian");
    float x, y;
    printf("Введите x :");
    std::cin >> x;
    y = f1(x) + f2(x);
    printf("\nx = %f", y);
    return 0;
}
