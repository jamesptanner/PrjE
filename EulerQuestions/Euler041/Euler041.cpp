#include "Euler041.h"
#include <iostream>

void Euler041(){
	char numstr[11];
	__int64_t max = 0;
	__int64_t i = 1;
	while(ceil(log10(i))<=7){
		sprintf(numstr,"%lld",i);
		if (isNPandigital(((int)log10(i))+1,numstr) && isPrime(i)){
			max = i;
			}
		i++;
		}
	cout << "Problem 41 answer: " << max << endl;\
	}
