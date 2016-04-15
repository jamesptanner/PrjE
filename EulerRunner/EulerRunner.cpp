// EulerRunner.cpp : Defines the entry point for the console application.
//

#include "EulerRunner.h"
#include <vector>
#include <algorithm>
#include <boost/progress.hpp>

static vector<EulerQuestion*> eulerQuestions;
void registerEulerQuestion(EulerQuestion & question)
{
    eulerQuestions.push_back(&question);
}

bool EulerQuestion::compare(EulerQuestion* i, EulerQuestion* j )
{
    return i->questionID < j->questionID;
}

void EulerQuestion::runQuestion()
{
    boost::progress_timer timer;
    QuestionFunc();
}

int main(int argc, char** argv)
{
    if(!eulerQuestions.empty())
    {
	sort(eulerQuestions.begin(),eulerQuestions.end(),EulerQuestion::compare);
        for(vector<EulerQuestion*>::iterator iter = eulerQuestions.begin(); iter != eulerQuestions.end(); iter++)
        {
             (*iter)->runQuestion();
        }
    }
    

}
