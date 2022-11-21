#pragma once
#include "../controller/base.h"


void SelectionSort(int* a, int n)
{
	for (int i = 0; i < n; i++) {
		int min_index = i;
		for (int j = i + 1; j < n; j++) {
			if (a[min_index] > a[j]) min_index = j;
		}
		swap(a[i], a[min_index]);
	}
}


void CompareCount_SelectionSort(int* a, int n, int64_t &comparisons)
{
	for (int i = 0;comparisons++, i < n; i++) {
		int min_index = i;
		for (int j = i + 1;comparisons++, j < n; j++) {
			if (comparisons++, a[min_index] > a[j]) 
				min_index = j;
		}
		swap(a[i], a[min_index]);
	}
}