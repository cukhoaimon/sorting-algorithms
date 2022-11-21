#pragma once
#include "../controller/base.h"


void bubbleSort(int *a, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
            if (a[j] > a[j + 1])
                swap(a[j + 1], a[j]);
    }
}

void bubbleSortCount(int *a, int n, long long &cmp_count)
{
    for (int i = 0; ++cmp_count, i < n - 1; i++)
    {
        for (int j = 0; ++cmp_count, j < n - i - 1; j++)
        {
            if (++cmp_count, a[j] > a[j + 1])
                swap(a[j + 1], a[j]);
        }
    }
}