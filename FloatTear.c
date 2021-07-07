// FloatTear.cpp: definiuje punkt wejścia dla aplikacji.
//

#include "FloatTear.h"

//get accuracy as double
void example1() {
	double acc;
	double val = INFINITY;

	acc = getDoubleMaxAccuracy(val);
	printf("%g accuracy is %g\n", val, acc);

	val = NAN;
	acc = getDoubleMaxAccuracy(val);
	printf("%g accuracy is %g\n", val, acc);

	val = DBL_TRUE_MIN * 5;
	acc = getDoubleMaxAccuracy(val);
	printf("%g accuracy is %g\n", val, acc);

	val = DBL_MAX;
	acc = getDoubleMaxAccuracy(val);
	printf("%g accuracy is %g\n", val, acc);
}

//get accuracy as power of 2
void example2() {
	double val;

	val = INFINITY;
	printf("%g accuracy is 1*2^%i\n", val, getDoubleMaxAccuracyAsPower2(val));

	val = NAN;
	printf("%g accuracy is 1*2^%i\n", val, getDoubleMaxAccuracyAsPower2(val));

	val = DBL_TRUE_MIN * 5;
	printf("%g accuracy is 1*2^%i\n", val, getDoubleMaxAccuracyAsPower2(val));

	val = DBL_MAX;
	printf("%g accuracy is 1*2^%i\n", val, getDoubleMaxAccuracyAsPower2(val));
}

int main()
{ 
	example1();
	printf("\n");
	example2();
 
	return 0;
}
