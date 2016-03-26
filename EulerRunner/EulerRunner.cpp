// EulerRunner.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "EulerRunner.h"


QUESTION questions[] = 
	{

		{1,"Problem 1: Multiples of 3 and 5",Euler001},
		{2,"Problem 2: Even Fibonacci numbers",Euler002},
		{3,"Problem 3: Largest prime factor",Euler003},
		{4,"Problem 4: Largest palindrome product",Euler004},
		{5,"Problem 5: Smallest multiple",Euler005}, 
		{6,"Problem 6: Sum square difference",Euler006},
		{7,"Problem 7: 10001st prime",Euler007},
		{8,"Problem 8: Largest product in a series",Euler008},
		{9,"Problem 9: Special Pythagoream triplet",Euler009},
		{10,"Problem 10: Summation of primes",Euler010},
		{11,"Problem 11: Largest product in a grid",Euler011},
		{12,"Problem 12: Highly divisible triangular number",Euler012},
		{14,"Problem 13: Longest Collatz sequence",Euler014},

#ifndef _DEBUG //slow debug questions.
		{14,"Problem 14: Longest Collatz sequence",Euler014},

		{23,"Problem 23: Non-abundant sums",Euler023},
#endif

		{26,"Problem 26: Reciprocal cycles",Euler026},
		
		{31,"Problem 31: Coin Sums",Euler031},
#ifndef _DEBUG //slow debug questions.
		{32,"Problem 32: Pandigital products",Euler032},
		
		{41,"Problem 41: Pandigital prime",Euler041},
#endif	

	};


int _tmain(int argc, _TCHAR* argv[])
	{
	if (argc==1){
		LARGE_INTEGER start, stop, freq;
	QueryPerformanceFrequency(&freq);
	QueryPerformanceCounter(&start);
		for(int i = 0; i<=sizeof(questions)/sizeof(QUESTION);i++){
			RunQuestion(questions[i].qID);
			}
			QueryPerformanceCounter(&stop);
	cout << "Total Program Run duration: "<< (double)(stop.QuadPart-start.QuadPart)/(double)freq.QuadPart << " seconds."<< endl<<endl; 
		}
	else
		{
		RunQuestion (_wtoi(argv[1]));
		}
	scanf_s(".",NULL);
	}
void RunQuestion(int questionNum){
	for (int i = 0; i < sizeof(questions)/sizeof(QUESTION); i++)
		{
		if (questions[i].qID==questionNum){
			run(&questions[i]);
			break;
			}
		}
	}

void run(LPQUESTION question){
	cout << question->name << endl;

	LARGE_INTEGER start, stop, freq;
	QueryPerformanceFrequency(&freq);
	void (*questionfunc)();
	questionfunc = question->function;
	QueryPerformanceCounter(&start);
	questionfunc();
	QueryPerformanceCounter(&stop);
	cout << "Total Question duration: "<< (double)(stop.QuadPart-start.QuadPart)/(double)freq.QuadPart << " seconds."<< endl<<endl; 
	}