
#include <iostream>

using namespace std;

class EulerQuestion
{
    public:
        EulerQuestion(int id) : questionID(id){}
        ~EulerQuestion(){}
        void runQuestion();
        int getQuestionID(){return questionID;}
	    static bool compare(EulerQuestion* i, EulerQuestion* j );
    private:
        int questionID;
    protected:
        virtual void QuestionFunc() = 0;
};

class TestRegistry
{
    public:
         static void addTest (EulerQuestion*);
};

class RegisterTest
{
public:
    inline RegisterTest(EulerQuestion * pUnitTest)
    {
        TestRegistry::addTest(pUnitTest );
    }
};

//shortcut macro
#define REGISTER_TEST(c_type) RegisterTest test_##c_type(new c_type())
