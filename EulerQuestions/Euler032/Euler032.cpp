#include "Euler032.h"
#include <iostream>
void Euler032(){
	int sum = 0;
	int divisor = 0;
	vector<__int64_t> factors;
	char pandigitalCandidate[15];
	for( int i=1;i<=PANDIGITAL_PRODUCT_LIMIT;i++){

		factors = getFactors(i);
		for(vector<__int64_t>::iterator it = factors.begin(); it !=factors.end();it++){
			divisor = i / *it;
			sprintf(pandigitalCandidate,"%d%d%lld",i,divisor,*it);
			if(isNPandigital(9,pandigitalCandidate)){
				sum+=i;
				break;
				}
			}

		}
	cout << "Problem 32 answer: " << sum << endl;
	}
