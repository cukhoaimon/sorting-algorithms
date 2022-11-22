#ifndef base_h
#define base_h

#include <iostream>
#include <vector>
#include <queue>
#include <chrono>
#include <fstream>
#include <string>

using namespace std;

class Timer 
{
private:
	chrono::high_resolution_clock::time_point start_time;
	
public:
	Timer()
	{
		this->start_time = chrono::high_resolution_clock::now();
	}
	void start()
	{
		this->start_time = chrono::high_resolution_clock::now();
	}

	// tra ve thoi gian chay, don vi la milisecond
	int64_t getRunTime()
	{
		auto now = chrono::high_resolution_clock::now();
		auto runtime = chrono::duration_cast<chrono::milliseconds>(now - this->start_time).count();
		return runtime;
	}
};

int getRandom(int l, int r)
{
	return l + rand() % (r - l + 1);
}

void swap(int& a, int& b)
{
	int temp = a;
	a = b; 
	b = temp;
}

int min(int const a, int const b)
{
	return a > b ? b : a;
}

int getMax(int array[], int n)
{
	int max = array[0];
	for (int i = 1; i < n; i++)
		if (array[i] > max)
			max = array[i];
	return max;
}

void readInput(char* filename, int*& data, int& n)
{
    ifstream filein;
    filein.open(filename);
    filein >> n;

	if (data != nullptr)
		delete[] data;

    data = new int[n];
    int index = 0;
    while (index != n)
    {
        filein >> data[index++];
    }
    filein.close();
}


void copyArray(int* a, int n, int*& b)
{
	b = new int[n];
	for (int i = 0; i < n; i++)
		b[i] = a[i];
}


void showSortInfor(char* inf, int64_t time, int64_t compare)
{
	cout << "\n" << inf << endl;
	if (strcmp(inf, "-both") == 0)
	{
		cout << "Running time: " << time << endl;
		cout << "Comparisions: " << compare << endl;
	}
	else if (strcmp(inf, "-time") == 0)
	{
		cout << "Running time: " << time << endl;
	}
	else if (strcmp(inf, "-comp") == 0)
	{
		cout << "Comparisions: " << compare << endl;
	}
}



#endif // !base_h
