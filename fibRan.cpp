
#include "fRan.h"

static unsigned long long F0 = 0;
static unsigned long long  F1 = 1;
static unsigned long long  M = 3;

void fRan::newValues(unsigned long long  first, unsigned long long  second, unsigned long long  Key)
{
	F0 = first;
	F1 = second;
	M = Key;
}

unsigned long long fRan::f()
{
	unsigned long long t = F0 + F1;
	F0 = F1 % M;
	F1 = t;
	return F0;
}

