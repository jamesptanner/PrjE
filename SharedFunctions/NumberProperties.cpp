#include "EulerShared.h"
#include <iostream>
vector<__int64_t> findAbundants(const __int64_t max) {
  vector<__int64_t> abundants;
  for (__int64_t i = 1; i <= max; i++) {
    if (isAbundant(i)) {
      abundants.push_back(i);
    }
  }
  return abundants;
}

vector<__int64_t> getFactors(const __int64_t num) {
  vector<__int64_t> divisors(1, 1);
  __int64_t pair = 0;
  for (__int64_t candidate = 2; candidate < ((num / 2) + 1); candidate++) {
    if ((num % candidate) == 0) {
      if (find(divisors.begin(), divisors.end(), candidate) != divisors.end()) {
        break;
      }
      divisors.push_back(candidate);
      pair = num / candidate;

      if (pair != candidate) {
        divisors.push_back(pair);
      }
    }
  }

  sort(divisors.begin(), divisors.end());
  return divisors;
}

vector<__int64_t> getPrimeFactors(__int64_t num) {
  vector<__int64_t> factorList;
  for (__int64_t i = 2; (num != 1); i++) {
    if (((num % i) == 0) && isPrime(i)) {
      do {
        num /= i;
      } while ((num % i) == 0);

      factorList.push_back(i);
    }
  }
  return factorList;
}

bool isPrime(__int64_t candidate) {
  __int64_t i = candidate;
  if (i == 2 || i == 3 || i == 5 || i == 7)
    return true;
  if (i < 9 || i % 2 == 0 || i % 3 == 0)
    return false;

  __int64_t r = (int)floor(sqrt(candidate));
  __int64_t f = 5;
  while (f <= r) {
    if (i % f == 0)
      return false;
    if (i % (f + 2) == 0)
      return false;
    f += 6;
  }
  return true;
}
bool isAbundant(const __int64_t num) {
  vector<__int64_t> factors = getFactors(num);
  __int64_t sum = 0;
  for (vector<__int64_t>::iterator iter = factors.begin();
       iter != factors.end(); iter++) {
    sum += *iter;
  }
  return sum > num;
}

bool isPandigital(char *candidate) {

  if (strlen(candidate) != 10 || !isNumeric(candidate))
    return false;
  for (int i = 0; i < 10; i++) {
    if (strchr(candidate, ASCII_NUM_START + i) == NULL) {
      return false;
    }
  }

  return true;
}

bool isNPandigital(int n, char *candidate) {
  if (n == 10)
    return isPandigital(candidate);
  if (strlen(candidate) != n || !isNumeric(candidate))
    return false;
  for (int i = 1; i <= n; i++) {
    if (strchr(candidate, ASCII_NUM_START + i) == NULL) {
      return false;
    }
  }
  return true;
}

int getRecipricalLength(int dwNume, int dwDemon) {
  int place = 1;
  int *map;
  map = (int *)calloc(dwDemon, sizeof(int));
  if (map == NULL)
    return -1;
  while (dwNume != 0) {

    map[dwNume] = place;
    dwNume = (dwNume * 10) % dwDemon;
    if (map[dwNume] != 0) {
      return place - map[dwNume];
    }
    place++;
  }
  return 0;
}
