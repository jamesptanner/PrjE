#include "stdafx.h"

#include "EulerShared.h"


__int64 SetPartions(__int64 n, __int64 *a, __int64 k){	if (n < 0 || k < 1) return 0;	if (n == 0) return 1;		return SetPartions(n,a,k-1) + SetPartions(n-(a[k-1]),a,k);	}