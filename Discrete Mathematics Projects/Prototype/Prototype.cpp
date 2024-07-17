#include <cmath>
#include <clocale>
#include <fstream>
#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    unsigned short N = 0; // размерность матрицы ребер, количество вершин
    unsigned short min = 0; // минимальное ребро и вспомогательная меременная
    unsigned short EdgeCount = 0; // количество минимальных ребер EdgeCount = N - 1;
    int sum = 0; // стоимость дороги (первоначальная, затем обновленная)
    unsigned short Line = -1; // вспомогательная строка
    unsigned short Column = -1; // вспомогательный столбец
    ifstream in;
    in.open("H1.txt"); // открываем файл для опредделения размерности матрицы ребер
    while (in >> min) { ++N; } // определяем количество элементов в квадрате, min используем как вспомогательную переменную
    in.close(); // закрываем файл для обновления
    N = sqrt(N); // количество элементов
    unsigned short** vertex = new unsigned short* [N]; // матрица, где показывают ребра
    for (int i = 0; i < N; i++)
        vertex[i] = new unsigned short[N];
    unsigned short** vertexT = new unsigned short* [N]; // матрица, где показывают ребра
    for (int i = 0; i < N; i++)
        vertexT[i] = new unsigned short[N];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            vertexT[i][j] = 0;
    in.open("H1.txt"); // нова открываем файл, на этот раз для чтения
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            in >> vertex[i][j]; // считываем переменную в i строку j столбец
    in.close(); // закрываем за ненадобностью
    for (int i = 0; i < N; i++) { // выводим матрицу ребер в консоль
        for (int j = 0; j < N; j++)
            cout << vertex[i][j] << " ";
        cout << endl;
    }
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            sum = sum + vertex[i][j]; // определение начальной цены содержания
    cout << "Начальная сумма содержания = " << sum / 2 << endl; // вывод начальной цены
    sum = 0; // обновляем цену для новой цены
    bool* NumWhat = new bool[N]; // задействованные вершины (по мере алгоритма false заменяется на true)
    unsigned short* EdgeMinValue = new unsigned short[N - 1]; // значения минимальных ребер
    for (int i = 0; i < N; i++) NumWhat[i] = false;

    // РАЗДЕЛЕНИЕ

    // далее идет первый шаг алгоритма Прима : определение минимального ребра
    min = 65535; // присваиваем максимальное значение для нахождения минимального ребра
    for (int i = 0; i < N; i++) // начинаем искать самое минимальное ребро ищем по главной диагонали
        for (int j = i + 1; j < N; j++) // если ребро равно, то игнорим
            if ((vertex[i][j] < min) && (vertex[i][j] != 0)) { // если ребро меньше минимального значения и не равно нулю
                min = vertex[i][j];
                Line = i; // присваиваем значение вспомогательной строке
                Column = j; // присваиваем значение вспомогательному столбцу
            }
    if (Line != -1 && Column != -1) { // если нашли минимальное ребро
        EdgeCount++; // увеличиваем количество минимальных ребер на 1
        NumWhat[Line] = true;
        NumWhat[Column] = true;
        EdgeMinValue[0] = vertex[Line][Column]; // первое значение минимального ребра
        vertexT[Line][Column] = vertex[Line][Column];
        sum = sum + EdgeMinValue[0]; // увеличиваем цену на первое минимальное ребро
    }
    // первый шаг алгоритма окончен

    // РАЗДЕЛЕНИЕ

    // дальше начинается основное веселье (второй(основной) этап алгоритма Прима)
    while (EdgeCount < N - 1) { // пока ребер меньше вершин (пока ребер не станет ровно вершин - 1)
        // теперь ищем новые минимальные ребра
        min = 65535; // присваиваем максимальное значение для нахождения минимального ребра
        // опять будем искать по главной диагонали
        for (int i = 0; i < N; i++)
            if (NumWhat[i] == true) // если вершина задействована, то есть состоит в обновленном графе
                for (int j = 0; j < N; j++)
                    if ((vertex[i][j] < min) && (vertex[i][j] != 0) && (NumWhat[j] == false)) { // если ребро меньше минимального значения и не равно нулю 
                                                                       //и не задействована
                        min = vertex[i][j];
                        Line = i; // присваиваем значение вспомогательной строке
                        Column = j; // присваиваем значение вспомогательному столбцу
                    }
        NumWhat[Line] = true;
        NumWhat[Column] = true;
        EdgeMinValue[EdgeCount] = vertex[Line][Column]; // первое значение минимального ребра
        vertexT[Line][Column] = vertex[Line][Column];
        sum = sum + EdgeMinValue[EdgeCount]; // увеличиваем цену на первое минимальное ребро
        EdgeCount++; // увеличиваем количество минимальных ребер на 1
    }
    cout << endl;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if( vertexT[i][j] != 0) vertexT[j][i] = vertexT[i][j];
    for (int i = 0; i < N; i++) { // выводим матрицу ребер в консоль
        for (int j = 0; j < N; j++)
            cout << vertexT[i][j] << " ";
        cout << endl;
    }
    cout << "Новая сумма содержания = " << sum << endl << endl; // вывод начальной цены
    for (int i = 0; i < N - 1; i++)
        cout << EdgeMinValue[i] << " ";
    cout << endl;
    for (int i = 0; i < N; i++)
        cout << NumWhat[i] << " ";
    for (int i = 0; i < N; i++)
        delete[] vertex[i];
    delete[] vertex;
    return 0;
}