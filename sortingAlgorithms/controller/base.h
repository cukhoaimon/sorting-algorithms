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
    data = new int[n];
    int index = 0;
    while (index != n)
    {
        filein >> data[index++];
    }
    filein.close();
}



#endif // !base_h
