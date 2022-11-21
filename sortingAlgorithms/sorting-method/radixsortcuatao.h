#pragma once
#include "controller/base.h"

void radixSortCuaTao(int* a, int n)
{
	int max = getMax(a, n);

	int d = 1;
	
	vector<queue<int>> bucket(10);
	while (max / d != 0)
	{
		for (int i = 0; i < n; i++)
			bucket[(a[i] / d) % 10].push(a[i]);

		int idx = 0;
		for (int i = 0; i < 10; i++)
		{
			int64_t b_size = bucket[i].size();
			for (int j = 0; j < b_size; j++)
			{
				a[idx++] = bucket[i].front();
				bucket[i].pop();
			}
		}

		d *= 10;
	}
}
