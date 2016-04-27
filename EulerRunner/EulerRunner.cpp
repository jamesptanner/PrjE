// EulerRunner.cpp : Defines the entry point for the console application.
//

#include "EulerRunner.h"
#include <algorithm>
#include <boost/progress.hpp>
#include <list>
#include <vector>

static vector<EulerQuestion *> eulerQuestions;

bool EulerQuestion::compare(EulerQuestion *i, EulerQuestion *j) {
  return i->questionID < j->questionID;
}

void EulerQuestion::runQuestion() {
  std::clock_t start;

  start = std::clock();

  QuestionFunc();
  std::cout << "Time: "
            << (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms"
            << std::endl;
}

void TestRegistry::addTest(EulerQuestion *question) {
  eulerQuestions.push_back(question);
}
int main(int argc, char **argv) {
  std::clock_t start;
  std::list<int> questionsToRun;
  if (argc > 1) {
    for (int i = 1; i < argc; i++) {
      questionsToRun.push_back(atoi(argv[i]));
    }
  }
  questionsToRun.unique();
  questionsToRun.sort();

  start = std::clock();
  if (!eulerQuestions.empty()) {
    sort(eulerQuestions.begin(), eulerQuestions.end(), EulerQuestion::compare);
    for (vector<EulerQuestion *>::iterator iter = eulerQuestions.begin();
         iter != eulerQuestions.end(); iter++) {
      if (argc == 1 || questionsToRun.front() == (*iter)->getQuestionID()) {
        std::cout << "Running " << (*iter)->getDesc() << std::endl;
        (*iter)->runQuestion();
        if (questionsToRun.size() > 0) {
          questionsToRun.pop_front();
        }
      }
    }
  }
  std::cout << "Total Time: "
            << (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000) / 1000
            << " s" << std::endl;
}
