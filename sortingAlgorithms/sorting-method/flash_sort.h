#pragma once
#include "../controller/base.h"


void FlashSort(int a[], int n) {

    // step 1: CLASS FORMATION
    if (n <= 1) 
        return;

    // tong so phan doan
    int m = int(n * 0.43);
    if (m <= 2) m = 2;
    
    int* __L = new int[m];
    for (int i = 0; i < m; ++i)
        __L[i] = 0;

    int Mx = a[0], Mn = a[0];
    for (int i = 1; i < n; ++i) 
    {
        if (Mx < a[i]) Mx = a[i]; // max value
        if (Mn > a[i]) Mn = a[i]; // min value
    }
    if (Mx == Mn)
        return;

#define getK(x) 1ll * (m - 1) * (x - Mn) / (Mx - Mn)
    
    // dem so phan tu cua moi phan doan
    for (int i = 0; i < n; ++i)
    {
        int cur_segment = getK(a[i]);
        __L[cur_segment] += 1;
    
    }
    for (int i = 1; i < m; ++i)
        __L[i] += __L[i - 1];

    // step 2: PERMUTATION
    int count = 0;
    int i = 0;
    while (count < n) {
        int k = getK(a[i]);
        while (i >= __L[k])
            k = getK(a[++i]);

        int z = a[i];
        while (i != __L[k]) {
            k = getK(z);
            int y = a[__L[k] - 1];
            a[--__L[k]] = z;
            z = y;
            ++count;
        }
    }

    // step 3: STRAIGHT INSERTION
    for (int k = 1; k < m; ++k)
    {
        for (int i = __L[k] - 2; i >= __L[k - 1]; --i)
        {
            if (a[i] > a[i + 1])
            {
                int t = a[i], j = i;
                while (t > a[j + 1])
                {
                    a[j] = a[j + 1];
                    ++j;
                }
                a[j] = t;
            }
        }
    }

    delete[] __L;
}