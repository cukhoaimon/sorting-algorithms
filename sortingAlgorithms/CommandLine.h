#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include "./controller/base.h"
#include "./controller/GenerateData.h"
#include "Experiment.h"

                        
void RunningSort(int* data, int n, int algo, int64_t& time, int64_t& compare)
{
    Timer t;
    t.start();
    sortMethod[algo](data, n);
    time = t.getRunTime();

    int* cpy = nullptr;
    copyArray(data, n, cpy);

    compare = 0;
    CountSortMethod[algo](cpy, n, compare);

    delete[] cpy;
}

void command(int argc, char* argv[])
{
    int* data = nullptr;
    int n = 0;
    int64_t compare = 0, time = 0;
    int algo = 0;
    if (strcmp("-a", argv[1]) == 0)
    {
        std::cout << "ALGORITHM MODE" << endl;
        std::cout << "Algorithm : " << argv[2] << endl;
        
        algo = getSortIndex(argv[2]);
        // Command 1
        if (!atoi(argv[3]))
        {
            std::cout << "Input file: " << argv[3] << endl;
            readInput(argv[3], data, n);

            // Running Sort
            RunningSort(data, n, algo, time, compare);
            // Show infomation about sort algo
            showSortInfor(argv[4], time, compare);
        }
        else
        {
            // Command 2
            n = atoi(argv[3]);
            data = new int[n];
            std::cout << "Input size: " << n << endl;
            if (argc == 6)
            {
                // Getting data
                if (strcmp(argv[4], "-rand") == 0)
                {
                    GenerateRandomData(data, n);
                }
                else if (strcmp(argv[4], "-nsorted") == 0)
                {
                    GenerateNearlySortedData(data, n);
                }
                else if (strcmp(argv[4], "-sorted") == 0)
                {
                    GenerateSortedData(data, n);
                }
                else if (strcmp(argv[4], "-rev") == 0)
                {
                    GenerateReverseData(data, n);
                }
                // Running Sort
                RunningSort(data, n, algo, time, compare);
                // Show info about sort algorithm
                showSortInfor(argv[5], time, compare);
            }
            else
                // Command 3
                if (argc == 5)
                {
                    n = atoi(argv[3]);
                    data = new int[n];
                    for (int i = 0; i < 4; i++)
                    {
                        GenerateData(data, n, i);
                        RunningSort(data, n, algo, time, compare);
                        // Show info about algo
                        showSortInfor(argv[4], time, compare);
                        std::cout << endl;
                    }
                }
        }
    }
    else
    {
        int algo1, algo2;
        int64_t time1, time2;
        int64_t compare1 = 0, compare2 = 0;
        
        algo1 = getSortIndex(argv[2]);
        algo2 = getSortIndex(argv[3]);

        // Command 4
        if (!atoi(argv[4]))
        {
            std::cout << "COMPARE MODE" << endl;
            std::cout << "Algorithm : " << argv[2] << "\t|\t" << argv[3] << endl;
            std::cout << "Input file: " << argv[4] << endl;
            readInput(argv[4], data, n);

            // Running Time  vs Compare Time
            RunningSort(data, n, algo1, time1, compare1);
            readInput(argv[4], data, n);
            RunningSort(data, n, algo2, time2, compare2);
            // Show info
            std::cout << "Running time: " << time1 << "\t|\t" << time2 << endl;
            std::cout << "Comparisions: " << compare1 << "\t|\t" << compare2 << endl;
        }
        else
            // Command 5
        {
            std::cout << algo1 << " " << algo2 << endl;
            n = atoi(argv[4]);

            // init data
            if (data != nullptr)
                delete[] data;
            data = new int[n];

            if (strcmp(argv[5], "-sorted") == 0)
            {
                GenerateSortedData(data, n);
            }
            else if (strcmp(argv[5], "-nsorted") == 0)
            {
                GenerateNearlySortedData(data, n);
            }
            else if (strcmp(argv[5], "-rand") == 0)
            {
                GenerateRandomData(data, n);
            }
            else // rev case
            {
                GenerateReverseData(data, n);
            }
            // Running Time  vs Compare Time
            int* data2 = nullptr;
            copyArray(data, n, data2);

            RunningSort(data, n, algo1, time1, compare1);
            RunningSort(data2, n, algo2, time2, compare2);
            // Show info
            std::cout << "Running time: " << time1 << "\t|\t" << time2 << endl;
            std::cout << "Comparisions: " << compare1 << "\t|\t" << compare2 << endl;
            delete[] data2;
        }
    }
    delete[] data;
}

