#define _CRT_SECURE_NO_WARNINGS

#include "./sorting-method/all.h"
#include "./controller/base.h"
#include <stdio.h>


typedef void (*sortPtr)(int*, int);
sortPtr sortMethod[] = {
    SelectionSort,
    InsertionSort,
    bubbleSort,
    HeapSort,
    MergeSort,
    QuickSort,
    radixSortCuaTao,
    ShakerSort,
    ShellSort,
    FlashSort
};

string const sort_name[] = {
    "Selection-Sort",
    "Insertion-Sort",
    "bubble-Sort",
    "Heap-Sort",
    "Merge-Sort",
    "Quick-Sort",
    "radixSortCuaTao",
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

int main()
{  
    freopen("output.csv", "w", stdout);

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
                cout << "Sai roi lam lai di.";

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
                auto sort_time = t.duration();

                string cur_data_type = getFileType(name);

                std::cout << sort_name[i] << ","
                    << cur_data_type << ","
                    << getDataRange(range) << ","
                    << sort_time << endl;
            }
        }
    }

    return 6969;
}
