#include "Euler001-010.h"
#include <EulerRunner.h>
class Euler001 : public EulerQuestion
{
public:
    Euler001(std::string name, int id) : EulerQuestion(name,id){}

    void QuestionFunc()
    {
       int sum = 0;
       for (int i = 3;i<1000;i++){
          if(!(i%3) || !(i%5)){
             sum +=i;
          }
       }
       cout << "Answer: "<< sum<< endl ;
    }
};

class Euler002 : public EulerQuestion
{
public:
    Euler002(std::string name, int id) : EulerQuestion(name,id){}

    void QuestionFunc() {

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
};

class Euler003 : public EulerQuestion
{
public:
    Euler003(std::string name, int id) : EulerQuestion(name,id){}

    void QuestionFunc()
    {
       std::vector<__int64_t> primes = getPrimeFactors(FACTORER);
   std::sort(primes.begin(),primes.end());
   cout<<"Problem 3 answer:" << *(primes.end()) << endl;
   }
};

class Euler004 : public EulerQuestion
{
public:
    Euler004(std::string name, int id) : EulerQuestion(name,id){}

    void QuestionFunc()
    {
   int palindromeCandidate;
   int max = 0;
   for (int i = PALINDROME_PRODUCT_START; i < PALINDROME_PRODUCT_END; i++)
   {
      for (int j = PALINDROME_PRODUCT_START; j < PALINDROME_PRODUCT_END; j++)
      {
         palindromeCandidate = i*j;
         if(palindromeCandidate<max) continue;
         char strPalindromeCandidate[PALINDROME_MAX_LENGTH];
         sprintf(strPalindromeCandidate,"%d",palindromeCandidate);

         if(isPalindrome(strPalindromeCandidate) && palindromeCandidate>max){
            max = palindromeCandidate;
         }
      }
   }
   cout<< "Problem 4 answer: " << max << endl;
}
};

class Euler005 : public EulerQuestion
{
public:
    Euler005(std::string name, int id) : EulerQuestion(name,id){}

    void QuestionFunc()
    {
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
};

class Euler006 : public EulerQuestion
{
public:
    Euler006(std::string name, int id) : EulerQuestion(name,id){}

    void QuestionFunc()
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
};

class Euler007 : public EulerQuestion
{
public:
    Euler007(std::string name, int id) : EulerQuestion(name,id){}

    void QuestionFunc()
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
};
class Euler008 : public EulerQuestion
{
public:
    Euler008(std::string name, int id) : EulerQuestion(name,id){}

    void QuestionFunc()
    {
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
};
class Euler009 : public EulerQuestion
{
public:
    Euler009(std::string name, int id) : EulerQuestion(name,id){}

    void QuestionFunc()
    {
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
};
class Euler010 : public EulerQuestion
{
public:
    Euler010(std::string name, int id) : EulerQuestion(name,id){}

    void QuestionFunc()
    {
   long long sum = 2;
   for ( int i = 3; i <2000000; i=i+2){
      if(isPrime(i)){
         sum += i;
         if (sum<0) cout << sum << endl;
      }
   }
   cout << "Problem 10 answer: " << sum << endl;
}
};
REGISTER_TEST("Problem 1: Multiples of 3 and 5",1, Euler001);
REGISTER_TEST("Problem 2: Even Fibonacci numbers",2, Euler002);
//REGISTER_TEST("Problem 3: Largest prime factor",3, Euler003);
REGISTER_TEST("Problem 4: Largest palindrome product",4, Euler004);
REGISTER_TEST("Problem 5: Smallest multiple",5, Euler005);
REGISTER_TEST("Problem 6: Sum square difference",6, Euler006);
REGISTER_TEST("Problem 3: Largest prime factor",7, Euler007);
REGISTER_TEST("Problem 3: Largest prime factor",8, Euler008);
REGISTER_TEST("Problem 3: Largest prime factor",9, Euler009);
REGISTER_TEST("Problem 3: Largest prime factor",10, Euler010);
