#pragma once

#include "./controller/base.h"
#include "./sorting-method/all.h"
#include <stdio.h>

typedef void (*sortPtr)(int*, int);
sortPtr sortMethod[] = {
    SelectionSort,
    InsertionSort,
    BubbleSort,
    HeapSort,
    MergeSort,
    QuickSort,
    RadixSort,
    ShakerSort,
    ShellSort,
    CountingSort,
    FlashSort
};

typedef void (*CountSortPtr)(int*, int, int64_t&);
CountSortPtr CountSortMethod[] = {
    CompareCount_SelectionSort,
    CompareCount_InsertionSort,
    CompareCount_BubbleSort,
    CompareCount_HeapSort,
    CompareCount_MergeSort,
    CompareCount_QuickSort,
    CompareCount_RadixSort,
    CompareCount_ShakerSort,
    CompareCount_ShellSort,
    CompareCount_CountingSort,
    CompareCount_FlashSort
};


string const sort_names[] = {
    "selection-sort",
    "insertion-sort",
    "bubble-sort",
    "heap-sort",
    "merge-sort",
    "quick-sort",
    "radix-sort",
    "shaker-sort",
    "shell-sort",
    "counting-sort",
    "flash-sort"
};

int const data_range[] = {
    10000,
    30000,
    50000,
    100000,
    300000,
    500000
};

string const file_name[] = {
    "input_1.txt", // random
    "input_2.txt", // nealy sorted
    "input_3.txt", // sorted
    "input_4.txt"  // reversed
};

string getFileType(int type)
{
    switch (type)
    {
        case 0: return "random";
        case 1: return "nearly-sorted";
        case 2: return "sorted";
        case 3: return "reversed";
        default: return "unknow";
    }
}

int getSortIndex(string argv)
{
    for (int i = 0; i < 11; i++)
        if (argv == sort_names[i])
            return i;
}


void Experiment()
{
    cout << "Program is running..." << endl;
    freopen("output.csv", "w", stdout);
    
    // write header
    cout << "sort_name" << ","
        << "data_type" << ","
        << "data_range" << ","
        << "sort_time" << ","
        << "compare" << endl;

    // each data range
    for (int range : data_range)
    {
        // each type of data
        for (int type = 0; type < 4; type++)
        {
            int* arr = nullptr, n = range;

            arr = new int[n];
            GenerateData(arr, n, type);

            // each sort type
            for (int i = 0; i < 11; i++)
            {
                Timer t;
                t.start();
                sortMethod[i](arr, n);
                auto sort_time = t.getRunTime() * 1.0 / 1000000;
                
                string cur_data_type = getFileType(type);

                int64_t compare = 0;
                CountSortMethod[i](arr, n, compare);
                
                cout << sort_names[i] << ","
                    << cur_data_type << ","
                    << range << ","
                    << sort_time << ","
                    << compare << endl;
            }

            delete[] arr;
        }
    }
}
