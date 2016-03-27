#include "EulerShared.h"

vector<int> genFibSequence(int maxTerm){
	vector<int> fibSequence;
	for (int i=0;i<=maxTerm;i++){
		fibSequence.push_back(getFibTerm(i));
	}
	return fibSequence;
}

int getFibTerm(int term){
	if (term<0) return -1;
	
	
	return round(pow(GOLDRATIO,term)/(sqrt(5)));
	

}

unsigned long long getTriangle(unsigned long num)
{
	return (num*(num+1))/2;
}
unsigned long long getPentagonal(unsigned long num)
{
	return (num*((3*num)+1))/2;
}
unsigned long long getHexagonal(unsigned long num)
{
	return num*((2*num)+1);
}

static map<unsigned long long, vector<unsigned long long>> collatzMap;
vector<unsigned long long> genCollatz(const unsigned long long num)
{
	unsigned long long term = num;
	vector<unsigned long long> collatzSequence;
	collatzSequence.push_back(term);
	do
	{
		if (collatzMap.find(term) != collatzMap.end())
		{
			vector<unsigned long long> foundSequence = collatzMap[term];
			collatzSequence.insert(collatzSequence.end(),foundSequence.begin(), foundSequence.end());
			break;
		}
		if(term % 2 == 0)
		{
			term /= 2;
		}
		else
		{			
			term = (term * 3) + 1;
		}
			collatzSequence.push_back(term);

	} while(term > 1);
	collatzMap.insert(std::pair<unsigned long long, vector<unsigned long long>>(num,collatzSequence));
	return collatzSequence;
}
