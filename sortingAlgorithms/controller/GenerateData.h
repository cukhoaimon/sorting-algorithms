#ifndef GENERATE_DATA_H
#define GENERATE_DATA_H

#include "controller/base.h"

template <class T>
void HoanVi(T& a, T& b)
{
	T x = a;
	a = b;
	b = x;
}

//-------------------------------------------------
// Hàm phát sinh mảng dữ liệu ngẫu nhiên
void GenerateRandomData(int a[], int n)
{
	srand((unsigned int)time(NULL));

	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % n;
	}
}

// Hàm phát sinh mảng dữ liệu có thứ tự tăng dần
void GenerateSortedData(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = i;
	}
}

// Hàm phát sinh mảng dữ liệu có thứ tự ngược (giảm dần)
void GenerateReverseData(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = n - 1 - i;
	}
}

// Hàm phát sinh mảng dữ liệu gần như có thứ tự
void GenerateNearlySortedData(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = i;
	}
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 10; i++)
	{
		int r1 = rand() % n;
		int r2 = rand() % n;
		HoanVi(a[r1], a[r2]);
	}
}

void GenerateData(int a[], int n, int dataType)
{
	switch (dataType)
	{
	case 0:	// ngẫu nhiên
		cout << "Input order: Randomize" << endl;
		GenerateRandomData(a, n);
		break;
	case 1:	// gần như có thứ tự
		cout << "Input order: Nearly sorted" << endl;
		GenerateNearlySortedData(a, n);
		break;
	case 2:	// có thứ tự
		cout << "Input order: Sorted" << endl;
		GenerateSortedData(a, n);
		break;
	case 3:	// có thứ tự ngược
		cout << "Input order: Reverse" << endl;
		GenerateReverseData(a, n);
		break;
	
	default:
		printf("Error: unknown data type!\n");
	}
}

#endif // !GENERATE_DATA_H
