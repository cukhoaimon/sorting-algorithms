#pragma once
#include "../controler/base.h"

/**
 * Section Sort
 * Average complexity: O(n^2)
 * Best Case: O(n^2)
 * Worst Case: O(n^2)
 * Space: O(1)
 * Stable
 */ 
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
double MeasureRuningTime_selectionSort(int* a, int n)
{
	clock_t start, end;
	double time_use;
	start = clock();
	SelectionSort(a, n); 
	end = clock();
	time_use = end - start;
	return time_use;
}

long comparisons = 0;
// seclection sort
long countComparisonsSelectionSort(int* a, int n)
{
	comparisons = 0;
	for (int i = 0; i < n; i++) {
		int min_index = i;
		for (int j = i + 1; j < n; j++) {
			if (a[min_index] > a[j]) min_index = j;
			comparisons += 2;
		}
		comparisons++;
		swap(a[i], a[min_index]);
	}
	comparisons++;
	return comparisons;
}