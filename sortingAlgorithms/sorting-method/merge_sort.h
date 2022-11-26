#pragma once
#include "../controller/base.h"


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
		if (L[iL] < R[iR]) 
		{
			a[i] = L[iL];
			iL++;
		}
		else 
		{
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
	if (left >= right) 
		return;

	int mid = left + (right - left) / 2;

	_MergeSort(a, left, mid);
	_MergeSort(a, mid+1, right);
	merge(a, left, mid, right);
}


void MergeSort(int* a, int n)
{
	_MergeSort(a, 0, n - 1);
}


void CompareCount_merge(int* a, int left, int mid, int right, int64_t &comparisons)
{
	int n1 = mid - left + 1;
	int n2 = right - mid;

	// tach 
	int* L = new int[n1];
	int* R = new int[n2];

	for (int i = 0;comparisons++, i < n1; i++) 
		L[i] = a[i];
	
	for (int i = 0; comparisons++, i < n2; i++) 
		R[i] = a[n1 + i];

	// gop
	int iL = 0, iR = 0;
	int i = left;

	for (i;(iL < n1 ? comparisons+=2 : comparisons++), iL < n1 && iR < n2; i++) {
		if (comparisons++, L[iL] < R[iR]) {
			a[i] = L[iL];
			iL++;
		}
		else {
			a[i] = R[iR];
			iR++;
		}
	}
	while (comparisons++, iL < n1) 
	{
		a[i] = L[iL];
		i++; iL++;
	}

	while (comparisons++, iR < n2) {
		a[i] = R[iR];
		i++; iR++;
	}
}


void CompareCount_MergeSort(int* a, int left, int right, int64_t &comparisons)
{
	if (left >= right) 
		return;

	int mid = (left + right) / 2;
	CompareCount_MergeSort(a, left, mid, comparisons);
	CompareCount_MergeSort(a, mid+1, right, comparisons);
	CompareCount_merge(a, left, mid, right, comparisons);
}


void CompareCount_MergeSort(int* a, int n, int64_t& comparisons)
{
	CompareCount_MergeSort(a, 0, n - 1, comparisons);
}