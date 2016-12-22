// Euler23-Non Abundant Sums.cpp : Defines the entry point for the console application.
//


#include "Euler023.h"
#include <EulerRunner.h>
#include <vector>

using namespace std;
class Euler023 : public EulerQuestion {
private:
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

    Euler023(std::string name, int id) : EulerQuestion(name, id) {}

    void questionFunc(){
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
}
REGISTER_TEST("Problem 23: Non-abundant sums",23,Euler023);