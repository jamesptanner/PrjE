// Euler23-Non Abundant Sums.cpp : Defines the entry point for the console application.
//


//Problem 23: Non-abundant sums
//A perfect number is a number for which the sum of its proper divisors is exactly equal to the number. For example, the sum of the proper divisors of 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number.
//
//A number n is called deficient if the sum of its proper divisors is less than n and it is called abundant if this sum exceeds n.
//
//As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest number that can be written as the sum of two abundant numbers is 24. By mathematical analysis, it can be shown that all integers greater than 28123 can be written as the sum of two abundant numbers. However, this upper limit cannot be reduced any further by analysis even though it is known that the greatest number that cannot be expressed as the sum of two abundant numbers is less than this limit.
//
//Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.

#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>

#include <EulerShared.h>
#include <EulerRunner.h>

using namespace std;

class Euler023 : public EulerQuestion {
private:
	const int64_t LIMIT = 28123;
    vector<int64_t> findAllNonAbundantVals(const vector<int64_t> abundants){
        vector<int64_t> results;
        vector<int64_t> tempAbundants = abundants;

        for (int i = 1; i <= LIMIT; i++)
        {
            results.push_back(i);
        }

        for (vector<int64_t>::const_iterator ita = abundants.begin(); ita != abundants.end();ita++){
            for (vector<int64_t>::iterator itb = tempAbundants.begin(); itb != tempAbundants.end();itb++){

                if ((*ita + *itb) > LIMIT){
                    break;
                }
                vector<int64_t>::iterator abundantSum =find(results.begin(),results.end(),*ita + *itb);

                if (abundantSum != results.end()){
                    results.erase( abundantSum);
                }
            }

            tempAbundants.erase(tempAbundants.begin());
        }
        return results;
    }
public:
    Euler023(string name, int id) : EulerQuestion(name, id) {}

    void QuestionFunc(){
        clock_t start = 0, abundanceIdentification=0,nonAbundantValsIdentification=0,end = 0;


        start = clock();

        vector<int64_t> abundants = findAbundants(LIMIT);
        abundanceIdentification = clock();
        cout<< "Abundant numbers idenfied. "<<abundants.size()<<" abundant numbers found."<< endl;


        vector<int64_t> nonAbundantPairVal = findAllNonAbundantVals(abundants);
        nonAbundantValsIdentification = clock();
        cout << "Idenified all number that are not the sum of two abundants. " << nonAbundantPairVal.size() << " numbers found." << endl;


        int64_t result = 0;
        for(vector<int64_t>::const_iterator iter = nonAbundantPairVal.begin(); iter != nonAbundantPairVal.end(); iter++)
            {
                result += *iter;
            }
        cout<<"sum of the values is "<< result << endl << endl;
        end = clock();

        cout << "calculating abundant Numbers: " << (double) (abundanceIdentification - start)/CLOCKS_PER_SEC << " seconds." << endl;
        cout << "identifying all number not the product of two abundants: " 
            << (double) (nonAbundantValsIdentification - abundanceIdentification)/CLOCKS_PER_SEC << " seconds." << endl;
        cout << "calculating the sum of the numbers identified: " 
            << (double) (end - nonAbundantValsIdentification)/CLOCKS_PER_SEC << " seconds."<< endl;
        cout << "Total Calculations took "<< (double) (end - start)/CLOCKS_PER_SEC << " seconds."<< endl; 

    }
};

REGISTER_TEST("Problem 23: Non-abundant sums",23,Euler023);