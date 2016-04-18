
#include <iostream>

using namespace std;

class EulerQuestion {
public:
  EulerQuestion(std::string desc, int id) : questionID(id), desc(desc) {}
  ~EulerQuestion() {}
  void runQuestion();
  int getQuestionID() { return questionID; }
  std::string getDesc() { return desc; }
  static bool compare(EulerQuestion *i, EulerQuestion *j);

private:
  int questionID;
  std::string desc;

protected:
  virtual void QuestionFunc() = 0;
};

class TestRegistry {
public:
  static void addTest(EulerQuestion *);
};

class RegisterTest {
public:
  inline RegisterTest(EulerQuestion *pUnitTest) {
    TestRegistry::addTest(pUnitTest);
  }
};

// shortcut macro
#define REGISTER_TEST(name, id, c_type)                                        \
  RegisterTest test_##c_type(new c_type(name, id))
