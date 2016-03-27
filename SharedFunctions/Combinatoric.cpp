
#include "EulerShared.h"


__int64_t SetPartions(__int64_t n, __int64_t *a, __int64_t k){
	if (n < 0 || k < 1) return 0;
	if (n == 0) return 1;
	
	return SetPartions(n,a,k-1) + SetPartions(n-(a[k-1]),a,k);

	}
