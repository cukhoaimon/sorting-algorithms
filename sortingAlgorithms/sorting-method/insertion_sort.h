#pragma once
#include "../controller/base.h"

/**
 * Insertion Sort
 * Average complexity: O(n^2)
 * Best Case: O(n)
 * Worst Case: O(n^2)
 * Space: O(1)
 * Stable
 */ 
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
int64_t MeasureRuningTime_insertionSort(int* a, int n)
{
	Timer t;
	t.start();
	InsertionSort(a, n); 
	
	auto duration = t.duration();
	return duration;
}

// insertion sort
int64_t countComparisonsInsertionSort(int* a, int n)
{
	int64_t comparisons = 0;

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

	return comparisons;
}