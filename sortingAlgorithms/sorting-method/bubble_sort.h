#pragma once
#include "../controller/base.h"


void BubbleSort(int *a, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
            if (a[j] > a[j + 1])
                swap(a[j + 1], a[j]);
    }
}

void CompareCount_BubbleSort(int *a, int n, int64_t &compare)
{
    for (int i = 0; ++compare, i < n - 1; i++)
    {
        for (int j = 0; ++compare, j < n - i - 1; j++)
        {
            if (++compare, a[j] > a[j + 1])
                swap(a[j + 1], a[j]);
        }
    }
}