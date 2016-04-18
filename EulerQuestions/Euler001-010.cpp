#include <EulerRunner.h>
#include <EulerShared.h>
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
    const int FIB_LIMIT = 4000000;
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
    long long FACTORER = 600851475143L;
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
    const int PALINDROME_PRODUCT_START = 100;
    const int PALINDROME_PRODUCT_END = 999;
    const int PALINDROME_MAX_LENGTH = 8;
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
   string s = "73167176531330624919225119674426574742355349194934"\
   			"96983520312774506326239578318016984801869478851843"\
   			"85861560789112949495459501737958331952853208805511"\
   			"12540698747158523863050715693290963295227443043557"\
   			"66896648950445244523161731856403098711121722383113"\
   			"62229893423380308135336276614282806444486645238749"\
   			"30358907296290491560440772390713810515859307960866"\
   			"70172427121883998797908792274921901699720888093776"\
   			"65727333001053367881220235421809751254540594752243"\
   			"52584907711670556013604839586446706324415722155397"\
   			"53697817977846174064955149290862569321978468622482"\
   			"83972241375657056057490261407972968652414535100474"\
   			"82166370484403199890008895243450658541227588666881"\
   			"16427171479924442928230863465674813919123162824586"\
   			"17866458359124566529476545682848912883142607690042"\
   			"24219022671055626321111109370544217506941658960408"\
   			"07198403850962455444362981230987879927244284909188"\
   			"84580156166097919133875499200524063689912560717606"\
   			"05886116467109405077541002256983155200055935729725"\
   			"71636269561882670428252483600823257530420752963450"
;
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
REGISTER_TEST("Problem 7: 10001st prime",7, Euler007);
REGISTER_TEST("Problem 8: Largest product in a series",8, Euler008);
REGISTER_TEST("Problem 9: Special Pythagorean triplet",9, Euler009);
REGISTER_TEST("Problem 10: Summation of primes",10, Euler010);
