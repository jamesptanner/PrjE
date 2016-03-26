#include "stdafx.h"
#include <iostream>
#include "EulerShared.h"
vector<__int64> findAbundants(const __int64 max)
	{
	vector<__int64> abundants;
	for (__int64 i = 1; i <= max; i++)
		{
		if(isAbundant(i)){
			abundants.push_back(i);
			}
		}
	return abundants;
	}

vector<__int64> getFactors(const __int64 num) {
	vector<__int64> divisors (1,1);
	__int64 pair = 0;
	for (__int64 candidate = 2; candidate < num; candidate++) {
		if ((num % candidate) == 0) {
			if (find(divisors.begin(),divisors.end(),candidate)!=divisors.end()){
				break;
				}
			divisors.push_back(candidate);
			pair = num / candidate;

			if(pair!=candidate){divisors.push_back(pair);}
			sort(divisors.begin(), divisors.end());
			}
		}

	return divisors;
	}

vector<__int64> getPrimeFactors(const __int64 num){
	vector<__int64> factorList = getFactors(num);
	//for (vector<__int64>::iterator it = factorList.begin(); it != factorList.end();
	for (__int64 i = 0; i<factorList.size();
		i++) {
			if (!isPrime(factorList.at(i)))  {
				vecRemove(&factorList,factorList.at(i));				
				if(i!=0)i--;
				}
		}
	return factorList;
	}

bool isPrime(__int64 candidate){
	__int64 i = candidate;
	if (i==2 || i==3 || i==5 || i==7)
		return true;
	if (i<9 || i%2==0 || i%3 == 0) 
		return false;

	__int64 r = (int) floor(sqrt(candidate));
	__int64 f = 5;
	while (f<=r){
		if(i%f ==0) return false;
		if(i%(f+2)==0) return false;
		f+=6;

		}
	return true;

	}
bool isAbundant(const __int64 num) {
	return vecSum(getFactors(num)) > num;
	}

bool isPandigital(char* candidate){

	if (strlen(candidate) !=10 || !isNumeric(candidate)) return false;
	for (int i=0;i<10;i++){
		if(strchr(candidate,ASCII_NUM_START+i) == NULL){ return false;}
		}

	return true;
	}

bool isNPandigital(int n, char* candidate){
	if (n==10) return isPandigital(candidate);
	if (strlen(candidate) != n || !isNumeric(candidate)) return false;
	for (int i=1;i<=n;i++){
		if(strchr(candidate,ASCII_NUM_START+i) == NULL){ return false;}
		}
	return true;
	}

DWORD getRecipricalLength(DWORD dwNume, DWORD dwDemon)
{
	DWORD place = 1;
	LPDWORD map;
	map = (LPDWORD) calloc(dwDemon,sizeof(DWORD));
	if (map == NULL)
		return -1;
	while(dwNume !=0)
	{
		
		map[dwNume] = place; 
		dwNume = (dwNume * 10) % dwDemon;
		if(map[dwNume]!=NULL){
			return place - map[dwNume];
		}
		place++;
	}
	return 0;
}