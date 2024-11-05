//Базаров Алмазбек Султанбаевич
// КИ20-07б(1 подгруппа)
//сложность : 100%
//2 вариант
/*
Дано натуральное число n. Сформировать двумерный массив A[n][n], заполнив его следующим образом: на диагонали, идущей из левого верхнего в
правый нижний угол, расположить единицы; выше этой диагонали – нули, а ниже этой диагонали – двойки.
*/

#include <iostream>
using namespace std;

void FillArray(int** const arr, int const n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (j > i) arr[i][j] = 0;
			if (j == i) arr[i][j] = 1;
			if (j < i) arr[i][j] = 2;
		}
	}
}

void PrintArray(int** const arr, int const n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

int main()
{
	int n;
	cout << "Enter number:";
	cin >> n;
	cout << endl;
	int** arr = new int* [n];
	for (int i = 0; i < n; i++) {
		arr[i] = new int[n];
	}
	FillArray(arr, n);
	PrintArray(arr, n);
	for (int i = 0; i < n; i++) {
		delete[] arr[i];
	}
	delete[] arr;
	return 0;
}
