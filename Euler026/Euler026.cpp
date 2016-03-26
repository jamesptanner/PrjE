#include "stdafx.h"
#include "Euler026.h"

void Euler026(void)
{
	int max = 0, temp = 0, parent = 0;
	for(int i = 1; i<=1000; i++)
	{
		temp = getRecipricalLength(1,i);
		if (temp>max) {
		
			max = temp;
			parent = i;

		}

	}

	cout << "Problem 26 answer: " << parent << endl;

}