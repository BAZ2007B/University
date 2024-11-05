//Базаров Алмазбек Султанбаевич
// КИ20-07б(1 подгруппа)
//сложность : 100%
//2 вариант
/*
Разработать программу, которая на основе введённых целочисленных массивов A и B формирует массив C в соответствии с табл. 3.
Итоговые массивы вывести сначала в исходном, затем в отсортированном виде. Порядок сортировки (по возрастанию/убыванию) задаётся
пользователем.
Массив C из чисел, которые входят в массив A, но при этом не входят в массив B (без повторения)
Дополнительные указания:оформить как функцию поиск заданного числа в массиве
*/


#include <clocale>
#include <iostream>
using namespace std;

int* read_array(int len) {
    int* arr = new int[len];
    for (int i = 0; i < len; i++) cin >> arr[i];
    return arr;
}

void print_array(int* arr, int len) {
    for (int i = 0; i < len; i++) cout << arr[i] << " ";
    cout << endl;
}

bool True_Numeric(int* A, int* B, int lenB, int i) {
    bool x = true;
    for (int j = 0; j < lenB; j++)
        if (A[i] == B[j]) {
            x = false;
            break;
        }
    if (x == true)
        for (int j = 0; j < i; j++)
            if (A[i] == A[j]) {
                x = false;
                break;
            }
    return x;
}

void sort(int arr[], int len, bool asc) {
    int t;
    if (asc == true)
        for (int i = 0; i < len; i++)
            for (int j = 0; j < (len - 1); j++)
                if (arr[j] > arr[j + 1]) {
                    t = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = t;
                }
    if (asc == false)
        for (int i = 0; i < len; i++)
            for (int j = 0; j < (len - 1); j++)
                if (arr[j] < arr[j + 1]) {
                    t = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = t;
                }
}

int* Array_Sort(int* A, int lenA, int* B, int lenB) {
    int len = 0;
    bool x;
    for (int i = 0; i < lenA; i++) {
        x = True_Numeric(A, B, lenB, i);
        if (x == true) len = len + 1;
    }
    int* C = new int[len];
    int a = 0;
    for (int i = 0; i < lenA; i++) {
        x = True_Numeric(A, B, lenB, i);
        if (x == true) {
            C[a] = A[i];
            a = a + 1;
        }
    }
    return C;
}

int main()
{
    setlocale(LC_ALL, "russian");
    cout << "Введите размер массива A:";
    int lenA;
    cin >> lenA;
    cout << "Введите массив A:";
    int* A = read_array(lenA);
    cout << "Введите размер массива B:";
    int lenB;
    cin >> lenB;
    cout << "Введите массив B:";
    int* B = read_array(lenB);
    int len = 0;
    bool x;
    for (int i = 0; i < lenA; i++) {
        x = True_Numeric(A, B, lenB, i);
        if (x == true) len = len + 1;
    }
    int* C = Array_Sort(A, lenA, B, lenB);
    delete[]A;
    delete[]B;
    if (len > 0) cout << "Новый массив : ";
    print_array(C, len);
    bool asc;
    cout << "Как отсортировать массив?(1 - по возрастанию,0 - по убыванию):";
    cin >> asc;
    sort(C, len, asc);
    print_array(C, len);
    delete[]C;
    return 0;
}