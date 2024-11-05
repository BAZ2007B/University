//Базаров Алмазбек Султанбаевич
// КИ20-07б(1 подгруппа)
//сложность : 100%
//2 вариант
/*
Напишите рекурсивную функцию, осуществляющую печать всех перестановок в строке из n символов.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <clocale>
#include <cstring>
#include <algorithm>
using namespace std;

int factorial(int n) { // метод факториала
    if (n == 1) { return 1; }
    else { return n * factorial(n - 1); }
}

int TabuTask1(char arr[]) {// метод возвращения алфавита строки
    int total = 0;
    bool x;
    for (int i = 0; i < strlen(arr); i++) {
        x = false;
        for (int j = 0; j < i; j++)
            if (arr[j] == arr[i]) { x = true; break; }
        if (x == true) continue;
        total++;
    }
    return total;
}

int TabuTask2(int x, char arr[], char arr2[]) { // определение количества перстановок
    // используется комбинаторика
    int var = 0;
    // если алфавит строки равен количеству символов в строке, то просто ищем факториал - количество всех перестановок
    if (x == strlen(arr)) var = factorial(strlen(arr));
    // иначе используем формулу перестановки с повторениями
    //P(n1,n2,...,nk)=n!/(n1!*n2!*...*nk!)
    else {
        int* arri = new int[x]; // числовой эквивалент встречаемости каждого символа алфавита строки
        for (int i = 0; i < x; i++) {
            arri[i] = 0;
            for (int j = 0; j < strlen(arr); j++)
                if (arr[j] == arr2[i]) arri[i]++;
        }
        int sumfac = 1; // ищем знаменатель
        for (int i = 0; i < x; i++) {
            sumfac = sumfac * factorial(arri[i]);
        }
        var = factorial(strlen(arr));
        var = var / sumfac; // перестановки с повторениями
    }
    return var; // возвращаем количество перестановок
}

void Cout(int x, int y, int z, char arr[]) {// реурсивная функция вывода перестановок
    int i = z; // проверка номера перестановки
    cout << i << "-ая перестановка:" << arr << endl; // вывод перестановки
    next_permutation(arr, arr + x); // использование встроенной функции для перестановки
    if (i < y) Cout(x, y, z + 1, arr); // вызов функции самой себя
}

int main()
{
    setlocale(LC_ALL, "russian");
    char arr[64];// создание строки ддля считывания
    int a;
    cin >> arr;// пишем строку
    a = strlen(arr); // размер строки
    a = factorial(a);// находим факториал размера строки
    int b = TabuTask1(arr); // находим алфавит строки
    bool s; // вспомогательная переменная
    int z = 0;
    char* arr2 = new char[b];// создаем алфавит встречаемости каждого символа
    for (int i = 0; i < strlen(arr); i++) {
        s = false;
        for (int j = 0; j < i; j++)
            if (arr[j] == arr[i]) { s = true; break; }
        if (s == true) continue;
        arr2[z] = arr[i]; z++;
    }
    cout << "Алфавит этой строки состоит из " << b << " букв" << endl;
    int c = TabuTask2(b, arr, arr2);// находим количество всех перестановок
    cout << "Всего " << c << " вариантов перестановок" << endl;
    sort(arr, arr + strlen(arr));// сортировка символов строки по порядку
    cout << "Отсортированная строка :" << arr << endl;
    Cout(strlen(arr), c, 1, arr);
    return 0;
}
