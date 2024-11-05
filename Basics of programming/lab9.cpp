//Базаров Алмазбек Султанбаевич
// КИ20-07б(1 подгруппа)
//сложность : 100%
//2 вариант
/*Разработать программу, использующую динамическое выделение памяти под массив, которая вводит одномерный массив A[N],
формирует из элементов массива A новый массив B[N] по правилам, указанным в табл. 2, и выводит его.
Разбить решение задачи на функции следующим образом:
Ввод массива оформить как функцию int *read_array(int len), которая создаёт новый динамический массив из len элементов, вводит его и возвращает указатель на него.
Вывод массива в прямом порядке оформить как функцию void print_array(int arr[], int len), где len — количество элементов массива.
Выполнение задания по варианту оформить как функцию int my_task(int A[], int lenA, int B[], int lenB), где lenA, lenB — количество элементов массивов A, B, которая
заполняет массив B в соответствии с вариантом, и возвращает количество заполненных элементов.
Также оформить как функцию действие, указанное в табл. 2.
Массив B из элементов A за исключением последнего отрицательного. Оформить как функцию поиск индекса последнего отрицательного элемента
*/


#include <clocale>
#include <iostream>
using namespace std;

int* read_array(int len) {
    int* arr = new int[len];
    for (int i = 0; i < len; i++) cin >> *(arr + i);
    return arr;
}

void print_array(int* arr, int len) {
    for (int i = 0; i < len; i++) cout << *(arr + i) << " ";
    cout << endl;
}

int PoslOtr(int* arr, int len) {
    int index = -1;
    for (int i = 0; i < len; i++) if (*(arr + i) < 0) index = i;
    return index;
}

int my_task(int* A, int lenA, int* B, int lenB, int index) {
    if (index > -1) {
        for (int i = 0; i < index; i++) *(B + i) = *(A + i);
        for (int i = index + 1; i < lenA; i++)
        {
            int j = i - 1;
            *(B + j) = *(A + (j + 1));
        }
    }
    else for (int i = 0; i < lenB; i++) *(B + i) = *(A + i);
    return index;
}

int main()
{
    setlocale(LC_ALL, "russian");
    cout << "Введите размер массива:";
    int len;
    cin >> len;
    int* A = read_array(len);
    print_array(A, len);
    int index = PoslOtr(A, len);
    int lenB;
    if (index > -1) lenB = len - 1;
    else lenB = len;
    int* B = new int[lenB];
    index = my_task(A, len, B, lenB, index);
    print_array(B, lenB);
    return 0;
}