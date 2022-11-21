#pragma once
#include "../controller/base.h"

void ShakerSort(int* a, int n) 
{
    int left = 0, right = n - 1;
    while (left < right) 
    {
        for (int i = left; i < right; i++) {
            if (a[i] > a[i + 1])
                swap(a[i], a[i + 1]);
        }
        right--;

        for (int i = right - 1; i >= left; i--) {
            if (a[i] > a[i + 1])
                swap(a[i], a[i + 1]);
        }
        left++;
    }
}

void CompareCount_ShakerSort(int* a, int n, int64_t &cmp) {
    int left = 0, right = n - 1;
    while (++cmp, left < right) {
        for (int i = left; ++cmp, i < right; i++) {
            if (++cmp, a[i] > a[i + 1])
                swap(a[i], a[i + 1]);
        }
        right--;
        for (int i = right - 1; ++cmp, i >= left; i--) {
            if (++cmp, a[i] > a[i + 1])
                swap(a[i], a[i + 1]);
        }
        left++;
    }
}

