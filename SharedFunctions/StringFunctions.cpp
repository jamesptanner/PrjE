#include "stdafx.h"
#include "EulerShared.h"

bool isPalindrome(char* palindrome){

	char* revPalindrome = strReverse(palindrome);
	return (strcmp(palindrome,revPalindrome)==0);
}

char* strReverse(char* str){
	if (str == NULL) return NULL;
	char* reverse = (char*) calloc((strlen(str)+1),sizeof(char));
	assert(reverse!=NULL);
	int j=0;
	for(int i = strlen(str)-1 ; i >=0 ; i--,j++)
	{
		reverse[j]=str[i];

	}
	reverse[j++] = '\0';
	return reverse;

}

bool isNumeric(char* number){
	while(*number!='\0'){
		if(!isDigit(*number)){return false;}
		number++;
		}
	return true;
	}

bool isDigit(char digit){
	if (digit < ASCII_NUM_START || digit > ASCII_NUM_END){ return false;}
	return true;
	}