#include "Euler031.h"

void Euler031(){
	int target = 200;
	__int64_t coins[] = {1,2,5,10,20,50,100,200};
	cout << "Problem 31 answer: " << SetPartions(target,coins,sizeof(coins)/sizeof(__int64_t)) << endl;

	}
