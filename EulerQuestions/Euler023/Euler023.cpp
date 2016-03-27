// Euler23-Non Abundant Sums.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "Euler023.h"


vector<_int64> findAllNonAbundantVals(const vector<_int64> abundants){
	vector<_int64> results;
	vector<_int64> tempAbundants = abundants;

	for (int i = 1; i <= LIMIT; i++)
	{
		results.push_back(i);
	}

	for (vector<_int64>::const_iterator ita = abundants.begin(); ita != abundants.end();ita++){
		for (vector<_int64>::iterator itb = tempAbundants.begin(); itb != tempAbundants.end();itb++){

			if ((*ita + *itb) > LIMIT){
				break;
			}
			vector<_int64>::iterator abundantSum =find(results.begin(),results.end(),*ita + *itb);

			if (abundantSum != results.end()){
				results.erase( abundantSum);
			}
		}

		tempAbundants.erase(tempAbundants.begin());
	}
	return results;
}

void Euler023(){
	clock_t start = 0, abundanceIdentification=0,nonAbundantValsIdentification=0,end = 0;


	start = clock();

	vector<_int64> abundants = findAbundants(LIMIT);
	abundanceIdentification = clock();
	cout<< "Abundant numbers idenfied. "<<abundants.size()<<" abundant numbers found."<< endl;


	vector<_int64> nonAbundantPairVal = findAllNonAbundantVals(abundants);
	nonAbundantValsIdentification = clock();
	cout << "Idenified all number that are not the sum of two abundants. " << nonAbundantPairVal.size() << " numbers found." << endl;


	unsigned _int64 result = vecSum(nonAbundantPairVal);
	cout<<"sum of the values is "<< result << endl << endl;
	end = clock();

	cout << "calculating abundant Numbers: " << (double) (abundanceIdentification - start)/CLOCKS_PER_SEC << " seconds." << endl;
	cout << "identifying all number not the product of two abundants: " 
		<< (double) (nonAbundantValsIdentification - abundanceIdentification)/CLOCKS_PER_SEC << " seconds." << endl;
	cout << "calculating the sum of the numbers identified: " 
		<< (double) (end - nonAbundantValsIdentification)/CLOCKS_PER_SEC << " seconds."<< endl;
	cout << "Total Calculations took "<< (double) (end - start)/CLOCKS_PER_SEC << " seconds."<< endl; 

}

