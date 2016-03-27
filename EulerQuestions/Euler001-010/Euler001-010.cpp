#include "stdafx.h"
#include "Euler001-010.h"

void Euler001()
{
	int sum = 0;
	for (int i = 3;i<1000;i++){
		if(!(i%3) || !(i%5)){
			sum +=i;
		}
	}
	cout << "Answer: "<< sum<< endl ;
}

void Euler002(){

	int fibterm = 0;
	int i=1;
	int sumfibterm = (int) getFibTerm(i);
	do {

		if(fibterm % 2 == 0){ sumfibterm+=fibterm;}
		i++;
		fibterm = (int) getFibTerm(i);
	
	}while(fibterm<FIB_LIMIT);

	cout<<"Euler002 Answer: "<< sumfibterm << endl;
}

void Euler003(){
__int64 maxprime = vecMax(getPrimeFactors(FACTORER));
	cout<<"Problem 3 answer:" <<maxprime<<endl;
	}

void Euler004(){
	int palindromeCandidate;
	int max = 0;
	for (int i = PALINDROME_PRODUCT_START; i < PALINDROME_PRODUCT_END; i++)
	{
		for (int j = PALINDROME_PRODUCT_START; j < PALINDROME_PRODUCT_END; j++)
		{
			palindromeCandidate = i*j;
			if(palindromeCandidate<max) continue;
			char strPalindromeCandidate[PALINDROME_MAX_LENGTH];
			sprintf_s(strPalindromeCandidate,"%d",palindromeCandidate);

			if(isPalindrome(strPalindromeCandidate) && palindromeCandidate>max){
				max = palindromeCandidate;
			}
		}
	}
	cout<< "Problem 4 answer: " << max << endl;
}
void Euler005(){
	bool complete = false;
	int candidate = 1;
	while(!complete){

		for (int i =1 ;i<=20;i++){
			if(candidate % i!=0) break;
			if (i==20) {candidate--; complete=true;}
			}
		candidate++;
		}
	cout << "Problem 5 answer: " << candidate << endl;
	}

void Euler006()
{
	int sqrSum = 0;
	int sumSqr = 0;
	for ( int i = 1 ; i <=100 ; i ++)
	{
		sqrSum += i;
		sumSqr += (i*i);
	}
	sqrSum *= sqrSum;

	cout << "Problem 6 answer: " << sqrSum - sumSqr << endl;
}
void Euler007()
{
	int primeCount = 0;
	int num = -1;
	while (primeCount < 10000)
	{
		num += 2;
		if(isPrime(num))
			primeCount++;
	}
	cout << "Answer: "<< num << endl ;


}

void Euler008(){
	long long max = 0;
	string s = NUM;
	while(s.length() >= 13)
	{
		long long val = atoi(s.substr(0,1).c_str());
		for (int index = 1; index < 13; index++)
		{
			if (s.length() < 13)
			{
				break;
			}
			val *= atoi(s.substr(index,1).c_str()); 
		}
		max = (val > max) ? val : max;
		s = s.substr(1);
	}
	cout << "Answer: "<< max << endl ;
	
}
void Euler009(){
	for ( int a = 1 ; a < 1000 ; a++)
	{
		for ( int b = a + 1 ; b < 1000 ; b++)
		{
			for ( int c = b + 1 ; c < 1000 ; c++)
			{
				if ((a + b + c) > 1000) break;
				else if ((a + b + c) < 1000) continue;
				if(pow(a,2)+pow(b,2) == pow(c,2))
				{
					cout << "Answer: "<< a*b*c << endl ;
					return;
				}
			}
		}
	}


	cout << "Failed" << endl ;
	
}
void Euler010(){
	long long sum = 2;
	for ( int i = 3; i <2000000; i=i+2){
		if(isPrime(i)){
			sum += i;
			if (sum<0) cout << sum << endl;
		}
	}
	cout << "Problem 10 answer: " << sum << endl;
	}