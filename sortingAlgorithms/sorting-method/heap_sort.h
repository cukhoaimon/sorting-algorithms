#pragma once
#include "../controller/base.h"

/**
 * Heap Sort
 * Average complexity: O(nlogn)
 * Best Case: O(nlogn)
 * Worst Case: O(nlogn)
 * Space: O(1)
 * Not Stable
 */ 
// heap sort 
void heapify(int* a, int n, int i)
{
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < n && a[largest] < a[left]) 
		largest = left;

	if (right < n && a[largest] < a[right]) 
		largest = right;

	if (largest != i) 
	{
		swap(a[i], a[largest]);
		heapify(a, n, largest);
	}

}

void HeapSort(int* a, int n)
{
	// tao 1 max heap 
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(a, n, i);

	for (int i = n - 1; i >= 0; i--) 
	{
		swap(a[0], a[i]);
		n--;
		heapify(a, n, 0);
	}
}

int64_t MeasureRuningTime_heapSort(int* a, int n)
{
	Timer t;
	t.start();
	HeapSort(a, n); 
	auto duration = t.duration();
	
	return duration;
}

void _heapify(int* a, int n, int i, int & comparisons)
{
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;


	left < n ? comparisons += 2 : comparisons++;
	if (left < n && a[largest] < a[left]) 
		largest = left;
	
	right < n ? comparisons += 2 : comparisons++;
	if (right < n && a[largest] < a[right]) 
		largest = right;

	comparisons++;
	if (largest != i) {
		swap(a[i], a[largest]);
		_heapify(a, n, largest, comparisons);
	}

}

long countComparisonsHeapSort(int* a, int n)
{
	int comparisons = 0;
	for (int i = n / 2 - 1; comparisons++, i >= 0; i--) {
		_heapify(a, n, i, comparisons);
	}
	
	for (int i = n - 1;comparisons++, i >= 0; i--) {
		swap(a[0], a[i]);
		n--;
		_heapify(a, n, 0, comparisons);
	}

	return comparisons;
}
