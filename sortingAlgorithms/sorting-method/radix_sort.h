#pragma once 
#include "../controller/base.h"


void countingSort(int array[], int size, int place)
{
    const int max = 10;
    int *output = new int[size];
    int *count = new int[max];

    for (int i = 0; i < max; ++i)
        count[i] = 0;

    for (int i = 0; i < size; i++)
        count[(array[i] / place) % 10]++;

    for (int i = 1; i < max; i++)
        count[i] += count[i - 1];

    for (int i = size - 1; i >= 0; i--)
    {
        output[count[(array[i] / place) % 10] - 1] = array[i];
        count[(array[i] / place) % 10]--;
    }

    for (int i = 0; i < size; i++)
        array[i] = output[i];

    delete[] output;
    delete[] count;
}


void RadixSort(int array[], int size)
{
    int max = getMax(array, size);
    for (int place = 1; max / place > 0; place *= 10)
        countingSort(array, size, place);
}


int _getMaxCompare(int array[], int n, long long &compare)
{
    int max = array[0];
    for (int i = 1; ++compare, i < n; i++)
        if (++compare, array[i] > max)
            max = array[i];
    return max;
}


void _countingSortCompare(int array[], int size, int place, long long &compare)
{
    const int max = 10;
    int *output = new int[size];
    int *count = new int[max];

    for (int i = 0; ++compare, i < max; ++i)
        count[i] = 0;

    for (int i = 0; ++compare, i < size; i++)
        count[(array[i] / place) % 10]++;

    for (int i = 1; ++compare, i < max; i++)
        count[i] += count[i - 1];

    for (int i = size - 1; ++compare, i >= 0; i--)
    {
        output[count[(array[i] / place) % 10] - 1] = array[i];
        count[(array[i] / place) % 10]--;
    }

    for (int i = 0; ++compare, i < size; i++)
        array[i] = output[i];

    delete[] output;
    delete[] count;
}


void CompareCount_RadixSort(int array[], int size, int64_t &compare)
{
    int max = _getMaxCompare(array, size, compare);
    for (int place = 1; ++compare, max / place > 0; place *= 10)
        _countingSortCompare(array, size, place, compare);
}