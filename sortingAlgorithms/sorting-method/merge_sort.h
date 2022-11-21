#pragma once
#include "../controller/base.h"

/**
 * Merge Sort
 * Average complexity: O(nlogn)
 * Best Case: O(nlogn)
 * Worst Case: O(nlogn)
 * Space: O(n)
 * Not Stable (Can make it Stable)
 */
// merge sort
void merge(int* a, int left, int mid, int right)
{
	int n1 = mid - left + 1;
	int n2 = right - mid;
	// tach 
	int* L = new int[n1];
	int* R = new int[n2];
	for (int i = 0; i < n1; i++) {
		L[i] = a[left + i];
	}
	for (int i = 0; i < n2; i++) {
		R[i] = a[mid + 1 + i];
	}
	// gop
	int iL = 0, iR = 0;
	int i = left;
	for (i; iL < n1 && iR < n2; i++) {
		if (L[iL] < R[iR]) {
			a[i] = L[iL];
			iL++;
		}
		else {
			a[i] = R[iR];
			iR++;
		}
	}
	while (iL < n1) {
		a[i] = L[iL];
		i++; iL++;
	}
	while (iR < n2) {
		a[i] = R[iR];
		i++; iR++;
	}
		
	delete[] L;
	delete[] R;
}
void _MergeSort(int* a, int left, int right)
{
	if (left >= right) return;
	int mid = left + (right - left) / 2;
	_MergeSort(a, left, mid);
	_MergeSort(a, mid+1, right);
	merge(a, left, mid, right);
}

void MergeSort(int* a, int n)
{
	_MergeSort(a, 0, n - 1);
}

int64_t MeasureRuningTime_mergeSort(int* a, int n)
{
	Timer t;
	t.start();

	MergeSort(a, n); 
	
	auto duration = t.duration();
	return duration;
}

long comparisons = 0;
void _merge(int* a, int left, int mid, int right)
{
	int n1 = mid - left + 1;
	int n2 = right - mid;
	// tach 
	int* L = new int[n1];
	int* R = new int[n2];
	for (int i = 0; i < n1; i++) {
		L[i] = a[i];
		comparisons++;
	}
	comparisons++;
	for (int i = 0; i < n2; i++) {
		R[i] = a[n1 + i];
		comparisons++;
	}
	comparisons++;
	// gop
	int iL = 0, iR = 0;
	int i = left;
	for (i; iL < n1 && iR < n2; i++) {
		if (L[iL] < R[iR]) {
			a[i] = L[iL];
			iL++;
		}
		else {
			a[i] = R[iR];
			iR++;
		}
		comparisons++;
	}
	comparisons++;
	while (iL < n1) {
		a[i] = L[iL];
		i++; iL++;
		comparisons++;
	}
	comparisons++;
	while (iR < n2) {
		a[i] = R[iR];
		i++; iR++;
		comparisons++;
	}
	comparisons++;
}
long countComparisonsMergeSort(int* a, int left, int right)
{
	if (left >= right) return 1;
	int mid = (left + right) / 2;
	int x = countComparisonsMergeSort(a, left, mid);
	int y = countComparisonsMergeSort(a, mid+1, right);
	_merge(a, left, mid, right);
	return comparisons;
}
