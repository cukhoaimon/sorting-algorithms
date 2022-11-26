#pragma once
#include "../controller/base.h"


int gaps[] = { 1750, 701, 301, 132, 57, 23, 10, 4, 1 };

void ShellSort(int a[], int n) {
    for (int gap : gaps) {
        for (int i = gap; i < n; ++i) {
            int cur = a[i];
            int j;
            for (j = i; j >= gap && a[j - gap] > cur; j -= gap)
                a[j] = a[j - gap];

            a[j] = cur;
        }
    }
}


void CompareCount_ShellSort(int *a, int n, int64_t &compare) {
    for (int gap : gaps) {
        for (int i = gap; compare++, i < n; ++i) {
            int cur = a[i];
            int j;
            for (j = i;(j >= gap ? compare +=2 : compare++), j >= gap && a[j - gap] > cur; j -= gap)
                a[j] = a[j - gap];

            a[j] = cur;
        }
    }
}