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
    "Selection-Sort",
    "Insertion-Sort",
    "bubble-Sort",
    "Heap-Sort",
    "Merge-Sort",
    "Quick-Sort",
    "Radix-Sort",
    "Shaker-Sort",
    "Shell-Sort",
    "Counting-Sort",
    "Flash-Sort"
};

string const data_range[] = {
    "10K",
    "30K",
    "50K",
    "100K",
    "300K",
    "500K"
};

string const file_name[] = {
    "input_1.txt",
    "input_2.txt",
    "input_3.txt",
    "input_4.txt"
};

string getFileType(string name)
{
    if (name == file_name[0])
        return "random";
    else if (name == file_name[1])
        return "nearly-sorted";
    else if (name == file_name[2])
        return "sorted";
    else
        return "reversed";
}

string getDataRange(string range)
{
    return  range.replace(range.find("K"), 3, "000");
}

void Experiment()
{
    freopen("output.csv", "w", stdout);
    cout << "sort_name" << ","
        << "data_type" << ","
        << "data_range" << ","
        << "sort_time(miliseconds)" << ","
        << "compare" << endl;

    string path = "data/input";
    // each data range
    for (string range : data_range)
    {
        // each type of data
        for (string name : file_name)
        {
            string directory = path + "/" + range + "/" + name;
            ifstream f;
            f.open(directory);

            if (!f.is_open())
            {
                cout << "Sai roi lam lai di.";
            }
            int* arr = nullptr, n = 0;

            f >> n;
            arr = new int[n];
            for (int i = 0; i < n; i++)
                f >> arr[i];

            // each sort type
            for (int i = 0; i < 11; i++)
            {
                Timer t;
                t.start();
                sortMethod[i](arr, n);
                auto sort_time = t.getRunTime();
                
                string cur_data_type = getFileType(name);

                int64_t compare = 0;
                CountSortMethod[i](arr, n, compare);
                cout << sort_names[i] << ","
                    << cur_data_type << ","
                    << getDataRange(range) << ","
                    << sort_time << ","
                    << compare << endl;
            }

            delete[] arr;
        }
    }
}