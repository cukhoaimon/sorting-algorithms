#pragma once
#include "../controller/base.h"


void InsertionSort(int* a, int n)
{
	for (int i = 1; i < n; i++) 
	{
		int x = a[i];
		int pos = i - 1;
	
		while (pos >= 0 && x < a[pos]) {
			a[pos + 1] = a[pos];
			pos--;
		}
		
		a[pos + 1] = x;
	}
}

// insertion sort
void CompareCount_InsertionSort(int* a, int n, int64_t& comparisons)
{	
	for (int i = 1; comparisons++, i < n; i++) 
	{
		int x = a[i];
		int pos = i - 1;
	
		while ((pos >= 0 ? comparisons += 2 : comparisons++), pos >= 0 && x < a[pos]) 
		{
			a[pos + 1] = a[pos];
			pos--;
		}
	
		a[pos + 1] = x;
	}
}