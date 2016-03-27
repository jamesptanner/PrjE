#include "stdafx.h"
#include "Euler014.h"

void Euler014(){
	vector<unsigned long long> seq;
	unsigned int max = 0, maxchain = 0;
	for(unsigned int i = 1; i < 1000000; i++)
	{
		seq = genCollatz(i);
		if (seq.size() > maxchain)
		{
			maxchain = seq.size();
			max = i;
		}
	}
	cout << "Problem 14 answer: " << max << endl;
	}