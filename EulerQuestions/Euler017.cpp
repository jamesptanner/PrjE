#include <map>
#include <string>

std::map<int,std::string> numbers;

std::string getNumStringNoSpaces(int number)
{
    std::string response;
    if(number >= 1000)
    {
        response += numbers[number/1000] + numbers[1000];
	number -= (number/1000)*1000;
    }
    if(number >= 100)
    {
        response += numbers[number/100] + numbers[100];
	number -= (number/100)*100;
    }
    if (number > 0)
    {
	if(response.length() > 0)
        	response += "and";
        for (std::map<int,std::string>::reverse_iterator iter = numbers.rbegin(); iter != numbers.rend(); iter++)
        {
            if(number >= iter->first)
            {
                response+=iter->second;
                number -= iter->first; 
            }
        }
    }
    return response;
}


void Euler017()
{
    numbers[1000]="thousand";
    numbers[100]="hundred";
    numbers[90]="ninety";
    numbers[80]="eighty";
    numbers[70]="seventy";
    numbers[60]="sixty";
    numbers[50]="fifty";
    numbers[40]="forty";
    numbers[30]="thirty";
    numbers[20]="twenty";
    numbers[19]="nineteen";
    numbers[18]="eighteen";
    numbers[17]="seventeen";
    numbers[16]="sixteen";
    numbers[15]="fifteen";
    numbers[14]="fourteen";
    numbers[13]="thirteen";
    numbers[12]="twelve";
    numbers[11]="eleven";
    numbers[10]="ten";
    numbers[9]="nine";
    numbers[8]="eight";
    numbers[7]="seven";
    numbers[6]="six";
    numbers[5]="five";
    numbers[4]="four";
    numbers[3]="three";
    numbers[2]="two";
    numbers[1]="one";
    int letterCount = 0;
    for( int i = 0 ; i <= 1000; i++)
    {
        letterCount += getNumStringNoSpaces(i).length();
    }

}

