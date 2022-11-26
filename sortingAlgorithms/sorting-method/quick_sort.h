#pragma once
#include "../controller/base.h"


void QuickSort(int a[], int left, int right)
{
    int i = left, j = right;
    int pivot = a[(left + right) / 2];
    while (i <= j)
    {
        while (a[i] < pivot) ++i;
        while (a[j] > pivot) --j;

        if (i <= j)
        {
            swap(a[i], a[j]);
            ++i;
            --j;
        }
    }

    if (left < j)
        QuickSort(a, left, j);
    if (i < right)
        QuickSort(a, i, right);
}


void QuickSort(int* a, int n)
{
    QuickSort(a, 0, n - 1);
}


void CompareCount_QuickSort(int a[], int left, int right, int64_t &count)
{
    int i = left, j = right;
    int pivot = a[(left + right) / 2];
    while (++count, i <= j)
    {
        while (++count, a[i] < pivot)
            ++i;
        while (++count, a[j] > pivot)
            --j;

        if (++count, i <= j)
        {
            swap(a[i], a[j]);
            ++i;
            --j;
        }
    }
    if (++count, left < j)
        CompareCount_QuickSort(a, left, j, count);
    if (++count, i < right)
        CompareCount_QuickSort(a, i, right, count);
}


void CompareCount_QuickSort(int* a, int n, int64_t&count)
{
    CompareCount_QuickSort(a, 0, n - 1, count);
}