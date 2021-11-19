#include <iostream>
#include <iomanip>
using namespace std;

void CreateRow(int** a, const int rowNo, const int N, int colNo, const int Low, const int High);
void CreateRows(int** a, const int N1, int rowNo, const int N2, const int Low = -10, const int High = 10);
void PrintRow(int** a, const int rowNo, const int N, int colNo);
void PrintRows(int** a, const int N1, int rowNo, const int N2);

void FindMaxMinElem(int** a, const int rowNo, const int N, int colNo, int& min_index);
void FindMaxMinElem(int** a, const int rowNo, const int rowCount, int colNo, int colCount, int& max);
void FindFirstMaxMinElem(int** a, const int rowNo, const int rowCount, int colNo, int colCount, int& max_index);

void FindFirstMinMaxElem(int** a, const int rowNo, const int rowCount, int colNo, int colCount, int& min);
void FindMaxMinElem(int** a, const int rowNo, const int N, int colNo, int& max_index);
void FindMaxMinElem(int** a, const int rowNo, const int rowCount, int colNo, int colCount, int& min);
void FindMinMaxElem(int** a, const int rowNo, const int rowCount, int colNo, int colCount, int& min);

int main()
{
	srand((unsigned)time(NULL));

	int n, k;
	cout << "k(row) = "; cin >> k;
	cout << "n(col) = "; cin >> n;
	int** a = new int* [n];
	for (int i = 0; i < n; i++)
		a[i] = new int[k];
	CreateRows(a, k, n, 0);
	PrintRows(a, k, n, 0);

	int max;
	FindFirstMaxMinElem(a, 0, n, 0, k, max);
	FindMaxMinElem(a, 0, n, 0, k, max);

	cout << "max from min = " << max << endl;

	int min;
	FindFirstMinMaxElem(a, 0, n, 0, k, min);
	FindMinMaxElem(a, 0, n, 0, k, min);

	cout << "min from max = " << min << endl;

	for (int i = 0; i < n; i++)
		delete[] a[i];
	delete[] a;

	return 0;
}

void CreateRow(int** a, const int rowNo, const int N, int colNo, const int Low, const int High)
{
	a[rowNo][colNo] = Low + rand() % (High - Low + 1);
	if (colNo < N - 1)
		CreateRow(a, rowNo, N, colNo + 1, Low, High);
}

void CreateRows(int** a, const int colCount, const int rowCount, int rowNo, const int Low, const int High)
{
	CreateRow(a, rowNo, colCount, 0, Low, High);
	if (rowNo < rowCount - 1)
		CreateRows(a, colCount, rowCount, rowNo + 1, Low, High);
}

void PrintRow(int** a, const int rowNo, const int N, int colNo)
{
	cout << setw(4) << a[rowNo][colNo];
	if (colNo < N - 1)
		PrintRow(a, rowNo, N, colNo + 1);
	else
		cout << endl;
}

void PrintRows(int** a, const int colCount, const int rowCount, int rowNo)
{
	PrintRow(a, rowNo, colCount, 0);
	if (rowNo < rowCount - 1)
		PrintRows(a, colCount, rowCount, rowNo + 1);
	else
		cout << endl;
}


void FindFirstMaxMinElem(int** a, const int rowNo, const int rowCount, int colNo, int colCount, int& max)
{
	if (colNo % 2 == 0)
	{
		int min_index = 0;
		FindMaxMinElem(a, rowNo, rowCount, colNo, min_index);
		max = a[min_index][colNo];
		return;
	}
	if (colNo < colCount - 1)
		FindFirstMaxMinElem(a, rowNo, rowCount, colNo + 1, colCount, max);
}

void FindMaxMinElem(int** a, const int rowNo, const int N, int colNo, int& min_index)
{
	if (a[rowNo][colNo] < a[min_index][colNo])
		min_index = rowNo;
	if (rowNo < N - 1)
		FindMaxMinElem(a, rowNo + 1, N, colNo, min_index);
}

void FindMaxMinElem(int** a, const int rowNo, const int rowCount, int colNo, int colCount, int& max)
{
	if (colNo % 2 == 0)
	{
		int min_index = 0;
		FindMaxMinElem(a, rowNo, rowCount, colNo, min_index);

		if (a[min_index][colNo] > max)
		{
			max = a[min_index][colNo];
		}
	}
	if (colNo < colCount - 1)
		FindMaxMinElem(a, rowNo, rowCount, colNo + 1, colCount, max);
}

void FindFirstMinMaxElem(int** a, const int rowNo, const int rowCount, int colNo, int colCount, int& min)
{
	if (colNo % 2 != 0)
	{
		int max_index = 0;
		FindMaxMinElem(a, rowNo, rowCount, colNo, max_index);
		min = a[max_index][colNo];
		return;
	}
	if (colNo < colCount - 1)
		FindFirstMaxMinElem(a, rowNo, rowCount, colNo + 1, colCount, min);
}

void FindMinMaxElem(int** a, const int rowNo, const int N, int colNo, int& max_index)
{
	if (a[rowNo][colNo] < a[max_index][colNo])
		max_index = rowNo;
	if (rowNo < N - 1)
		FindMinMaxElem(a, rowNo + 1, N, colNo, max_index);
}

void FindMinMaxElem(int** a, const int rowNo, const int rowCount, int colNo, int colCount, int& min)
{
	if (colNo % 2 != 0)
	{
		int max_index = 0;
		FindMinMaxElem(a, rowNo, rowCount, colNo, max_index);

		if (a[max_index][colNo] > min)
		{
			min = a[max_index][colNo];
		}
	}
	if (colNo < colCount - 1)
		FindMinMaxElem(a, rowNo, rowCount, colNo + 1, colCount, min);
}