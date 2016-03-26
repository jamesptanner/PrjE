#include "stdafx.h"
#include "EulerShared.h"
int round (double num){
	if (((int)(num*10.0) % 10)<5 ) return (int) floor(num);
	return (int) ceil(num);
}