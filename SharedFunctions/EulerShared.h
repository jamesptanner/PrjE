
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <cString>
#include <cassert>

using namespace std;


#define ASCII_NUM_START 48
#define ASCII_NUM_END 57

// list Functions
template <class T> T _vecSum(const vector<T> vector) ;
template <class T> void _vecRemove(vector<T> *List,T element);
template <class T> T _vecMax(const vector<T> vector);
template <class T> T _vecMin(const vector<T> vector);


int vecSum(const vector<int> vector);
void vecRemove(vector<int> *vector,int element);
int vecMax(const vector<int> vector);
int vecMin(const vector<int> vector);
__int64_t vecSum(const vector<__int64_t> vector);
void vecRemove(vector<__int64_t> *vector,__int64_t element);
__int64_t vecMax(const vector<__int64_t> vector);
__int64_t vecMin(const vector<__int64_t> vector);


// number Properties

vector<__int64_t> findAbundants(const __int64_t max);
vector<__int64_t> getFactors(const __int64_t num);
vector<__int64_t> getPrimeFactors(const __int64_t num);

bool isPrime(__int64_t candidate);
bool isAbundant(const __int64_t num);
bool isPandigital( char* candidate);
bool isNPandigital(int n, char* candidate);

int getRecipricalLength(int dwNume, int dwDemon);

// number Generation
vector<int> genFibSequence(int maxTerm);
int getFibTerm(int term);

unsigned long long getTriangle(unsigned long num);
unsigned long long getPentagonal(unsigned long num);
unsigned long long getHexagonal(unsigned long num);

vector<unsigned long long> genCollatz(unsigned long long num);


// string functions
bool isPalindrome(char* palindrome);
char* strReverse(char* str); 
bool isDigit(char digit);
bool isNumeric(char * number);

// combinatorics
__int64_t SetPartions(__int64_t n, __int64_t *a, __int64_t k);

// constants
#define GOLDRATIO 1.6180339887
