
#include <iostream>

using namespace std;

class EulerQuestion 
{
    public:
        EulerQuestion();
        ~EulerQuestion();
        void runQuestion();
	static bool compare(EulerQuestion* i, EulerQuestion* j );
    private:
	int questionID;
    protected:
        virtual void QuestionFunc() = 0;

};

void registerEulerQuestion(EulerQuestion &);

