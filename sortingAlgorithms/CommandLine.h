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


void writeData(string filename, int* a, int n) {
    ofstream file;
    file.open(filename);
    file << n << endl;
    for (int i = 0; i < n; i++) file << a[i] << " ";
    file.close();
 
}


void grandData(int* data, int n, char* argv)
{
    if (strcmp(argv, "-sorted") == 0)
    {
        GenerateSortedData(data, n);
    }
    else if (strcmp(argv, "-nsorted") == 0)
    {
        GenerateNearlySortedData(data, n);
    }
    else if (strcmp(argv, "-rand") == 0)
    {
        GenerateRandomData(data, n);
    }
    else // rev case
    {
        GenerateReverseData(data, n);
    }
}

 
void command1(int argc, char* argv[])
{
    int* data = nullptr;
    int n = 0;
    int64_t compare = 0, time = 0;
    int algo = 0;

    algo = getSortIndex(argv[2]);

    std::cout << "Input file: " << argv[3] << endl;
    readInput(argv[3], data, n);
    std::cout << "Input size: " << n << endl;

    // Running Sort
    RunningSort(data, n, algo, time, compare);
    // Show infomation about sort algo
    showSortInfor(argv[4], time, compare);
    writeData("output.txt", data, n);
    delete[] data;
}


void command2(int argc, char* argv[])
{
    int* data = nullptr;
    int n = 0;
    int64_t compare = 0, time = 0;
    int algo = 0;

    algo = getSortIndex(argv[2]);
    n = atoi(argv[3]);
    data = new int[n];
    std::cout << "Input size: " << n << endl;
    
    // Getting data
    grandData(data, n, argv[4]);
    writeData("input.txt", data, n);
    // Running Sort
    RunningSort(data, n, algo, time, compare);
    
    // writedown sorted array
    writeData("output.txt", data, n);

    // Show info about sort algorithm
    showSortInfor(argv[5], time, compare);

    delete[] data;
}


void command3(int argc, char* argv[])
{
    int* data = nullptr;
    int n = 0;
    int64_t compare = 0, time = 0;
    int algo = 0;
    algo = getSortIndex(argv[2]);

    n = atoi(argv[3]);
    cout << "Input size: " << n << endl << endl;

    data = new int[n];
    for (int i = 0; i < 4; i++)
    {
        GenerateData(data, n, i);
      
        string number = to_string(i + 1);
        string filename = "input_" + number + ".txt";
      
        writeData(filename,data, n);
        RunningSort(data, n, algo, time, compare);
        // Show info about algo
        showSortInfor(argv[4], time, compare);
        std::cout << endl;
    }
    delete[] data;
}


void command4(int argc, char* argv[])
{
    int* data = nullptr, n;
    int algo1, algo2;
    int64_t time1, time2;
    int64_t compare1 = 0, compare2 = 0;

    algo1 = getSortIndex(argv[2]);
    algo2 = getSortIndex(argv[3]);
    readInput(argv[4], data, n);

    std::cout << "COMPARE MODE" << endl;
    std::cout << "Input file: " << argv[4] << endl;
    std::cout << "Input size: " << n << endl;
    std::cout << "Algorithm : " << argv[2] << "\t|\t" << argv[3] << endl;
    
    int* data2 = nullptr;
    copyArray(data, n, data2);

    // Running Time  vs Compare Time
    // run first sort
    RunningSort(data, n, algo1, time1, compare1);    
    // run second sort
    RunningSort(data2, n, algo2, time2, compare2);
    
    // Show info
    std::cout << "Running time: " << time1 * 1.0 / 1000000 << "\t|\t" << time2 * 1.0 / 1000000 << endl;
    std::cout << "Comparisions: " << compare1 << "\t|\t" << compare2 << endl;

    delete[] data;    
    delete[] data2;
}


void command5(int argc, char* argv[])
{
    int* data = nullptr, n;
    int algo1, algo2;
    int64_t time1, time2;
    int64_t compare1 = 0, compare2 = 0;

    algo1 = getSortIndex(argv[2]);
    algo2 = getSortIndex(argv[3]);

    n = atoi(argv[4]);

    std::cout << "COMPARE MODE" << endl;
    std::cout << "Input size: " << n << endl;
    std::cout << "Algorithm : " << argv[2] << "\t|\t" << argv[3] << endl;
    

    // init data
    if (data != nullptr)
        delete[] data;
    data = new int[n];

    grandData(data, n, argv[5]);
    writeData("input.txt", data, n);

    // Running Time  vs Compare Time
    int* data2 = nullptr;
    copyArray(data, n, data2);

    RunningSort(data, n, algo1, time1, compare1);
    RunningSort(data2, n, algo2, time2, compare2);
    // Show info
    std::cout << "Running time: " << time1 * 1.0 / 1000000 << "\t|\t" << time2 * 1.0 / 1000000 << endl;
    std::cout << "Comparisions: " << compare1 << "\t|\t" << compare2 << endl;
    delete[] data2;
    delete[] data;
}


void command(int argc, char* argv[])
{

    if (strcmp("-a", argv[1]) == 0)
    {
        std::cout << "ALGORITHM MODE" << endl;
        std::cout << "Algorithm : " << argv[2] << endl;
        
        // Command 1
        if (!atoi(argv[3]))
            command1(argc, argv);
        else 
            if (argc == 6 && atoi(argv[3]) )// Command 2
                command2(argc, argv);
            else 
                // Command 3
                command3(argc, argv);

    }
    else
        // Command 4
        if (!atoi(argv[4]))
            command4(argc, argv);
        else
            // Command 5
            command5(argc, argv);
        
}

