#include "stdafx.h"

#ifdef DLL_EXPORT_EX
   #define DLL_EXPORT  __declspec(dllexport)   // export DLL information
#else
   #define DLL_EXPORT  __declspec(dllimport)    // import DLL information
#endif 


#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <cString>
#include <cassert>
#include <Windows.h>

using namespace std;


#define ASCII_NUM_START 48
#define ASCII_NUM_END 57

// list Functions
template <class T> T _vecSum(const vector<T> vector) ;
template <class T> void _vecRemove(vector<T> *List,T element);
template <class T> T _vecMax(const vector<T> vector);
template <class T> T _vecMin(const vector<T> vector);


DLL_EXPORT int vecSum(const vector<int> vector);
DLL_EXPORT void vecRemove(vector<int> *vector,int element);
DLL_EXPORT int vecMax(const vector<int> vector);
DLL_EXPORT int vecMin(const vector<int> vector);
DLL_EXPORT __int64 vecSum(const vector<__int64> vector);
DLL_EXPORT void vecRemove(vector<__int64> *vector,__int64 element);
DLL_EXPORT __int64 vecMax(const vector<__int64> vector);
DLL_EXPORT __int64 vecMin(const vector<__int64> vector);


// number Properties

DLL_EXPORT vector<__int64> findAbundants(const __int64 max);
DLL_EXPORT vector<__int64> getFactors(const __int64 num);
DLL_EXPORT vector<__int64> getPrimeFactors(const __int64 num);

DLL_EXPORT bool isPrime(__int64 candidate);
DLL_EXPORT bool isAbundant(const __int64 num);
DLL_EXPORT bool isPandigital( char* candidate);
DLL_EXPORT bool isNPandigital(int n, char* candidate);

DLL_EXPORT DWORD getRecipricalLength(DWORD dwNume, DWORD dwDemon);

// number Generation
DLL_EXPORT vector<int> genFibSequence(int maxTerm);
DLL_EXPORT int getFibTerm(int term);

DLL_EXPORT unsigned long long getTriangle(unsigned long num);
DLL_EXPORT unsigned long long getPentagonal(unsigned long num);
DLL_EXPORT unsigned long long getHexagonal(unsigned long num);

DLL_EXPORT vector<unsigned long long> genCollatz(unsigned long long num);

// missing math functions
DLL_EXPORT int round(double num);

// string functions
DLL_EXPORT bool isPalindrome(char* palindrome);
DLL_EXPORT char* strReverse(char* str); 
DLL_EXPORT bool isDigit(char digit);
DLL_EXPORT bool isNumeric(char * number);

// combinatorics
DLL_EXPORT __int64 SetPartions(__int64 n, __int64 *a, __int64 k);

// constants
#define GOLDRATIO 1.6180339887