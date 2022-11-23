#pragma once
#include "../controller/base.h"


void CountingSort(int* a, int n) {
    int max = a[0];
    for (int i = 0; i < n; i++)
        if (max < a[i])
            max = a[i];
    int* count = new int[max + 1]{0};
    for (int i = 0; i < n; i++)
        count[a[i]]++;
    int j = 0;
    for (int i = 0; i <= max; i++) {
        for (; count[i] > 0; count[i]--) {
            a[j] = i;
            j++;
        }
    }
    delete[] count;
}

void CompareCount_CountingSort(int* a, int n, int64_t &cmp) {
    int max = a[0];
    for (int i = 0; ++cmp, i < n; i++)
        if (++cmp, max < a[i])
            max = a[i];

    int* count = new int[max + 1]{0};
    for (int i = 0; ++cmp, i < n; i++)
        count[a[i]]++;

    int j = 0;
    for (int i = 0; ++cmp, i <= max; i++) {
        for (;++cmp, count[i] > 0; count[i]--) {
            a[j] = i;
            j++;
        }
    }
    delete[] count;
}
