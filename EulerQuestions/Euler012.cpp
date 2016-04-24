#include <EulerRunner.h>
#include <EulerShared.h>

class Euler012 : public EulerQuestion {
public:
  Euler012(std::string name, int id) : EulerQuestion(name, id) {}

  void QuestionFunc() {
    unsigned long i = 1;
    unsigned long tri;
    while (true) {
      tri = getTriangle(i);
      if (getFactors(tri).size() > 500)
        break;
      i++;
    }
    cout << "Problem 12 answer: " << tri << endl;
  }
};
REGISTER_TEST("Problem 12: Highly divisible triangular number", 12, Euler012);
