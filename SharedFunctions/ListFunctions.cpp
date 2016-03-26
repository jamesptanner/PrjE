#include "stdafx.h"
#include "EulerShared.h"


template <class T> T _vecSum(const vector<T> vector) {
	T sum = 0;
	for (std::vector<T>::const_iterator it = vector.begin(); it != vector.end();
		++it) {
			sum += *it;
	}
	return sum;
}

template <class T> void _vecRemove(vector<T> *List,T element){
	
	for (vector<T>::iterator it = List->begin(); it != List->end();
		++it) {
			if(*it == element){
				List->erase(it);
				return;
			}
	}
}

template <class T> T _vecMax(const vector<T> vector){
	
	T max = vector.front();
	for (std::vector<T>::const_iterator it = vector.begin(); it != vector.end();
		++it) {
			if (*it > max) max = *it;
	}
	return max;
}

template <class T> T _vecMin(const vector<T> vector){
	
	T min = vector.front();
	for (std::vector<T>::const_iterator it = vector.begin(); it != vector.end();
		++it) {
			if (*it < min) min = *it;
	}
	return min;
}


int vecSum(const vector<int> vector){return _vecSum(vector);}
void vecRemove(vector<int> *vector,int element){return _vecRemove(vector,element);}
int vecMax(const vector<int> vector){return _vecMax(vector);}
int vecMin(const vector<int> vector){return _vecMin(vector);}

__int64 vecSum(const vector<__int64> vector){return _vecSum(vector);}
void vecRemove(vector<__int64> *vector,__int64 element){return _vecRemove(vector,element);}
__int64 vecMax(const vector<__int64> vector){return _vecMax(vector);}
__int64 vecMin(const vector<__int64> vector){return _vecMin(vector);}


