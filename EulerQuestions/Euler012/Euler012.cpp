#include "Euler012.h"

void Euler012(){
	unsigned long i = 1;
	unsigned long tri;
	while(true){
		tri = getTriangle(i) ;
		if (getFactors(tri).size() > 500)
			break;
		i++;

	}
	cout << "Problem 12 answer: " << tri << endl;
	}
