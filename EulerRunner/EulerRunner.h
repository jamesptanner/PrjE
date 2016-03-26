#include "windows.h"

#include "Euler001-010.h"
#include "Euler011.h"
#include "Euler012.h"

#include "Euler014.h"

#include "Euler023.h"

#include "Euler026.h"

#include "Euler031.h"
#include "Euler032.h"

#include "Euler041.h"

#include <iostream>

using namespace std;

typedef struct
	question{
		int qID;
		char* name;
		void  (*function)();
	} *LPQUESTION, QUESTION;

void RunQuestion(int questionNum);

void run(LPQUESTION question);