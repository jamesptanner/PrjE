#include <EulerRunner.h>
#include <EulerShared.h>

class Euler014 : public EulerQuestion {
public:
  Euler014(std::string name, int id) : EulerQuestion(name, id) {}

  void QuestionFunc() {
    vector<unsigned long long> seq;
    unsigned int max = 0, maxchain = 0;
    for (unsigned int i = 1; i < 1000000; i++) {
      seq = genCollatz(i);
      if (seq.size() > maxchain) {
        maxchain = seq.size();
        max = i;
      }
    }
    cout << "Problem 14 answer: " << max << endl;
  }
};
REGISTER_TEST("Problem 14: Longest Collatz sequence", 14, Euler014);
