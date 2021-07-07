#include <float.h>  //for binary inromation about double
#include <stdint.h> //for uint64_t type
#include <math.h>   //for NAN INFINITY etc.

//this struct allow to savely manipulate separate parts of double
typedef struct {
    uint64_t
        mantissa : DBL_MANT_DIG - 1,    //-1 for sign
        exponent : 64 - DBL_MANT_DIG,
        sign : 1;
}doubleStruct;

//this union allows binary access
union binaryDouble {
    double dbl;
    doubleStruct binary;
};

int getDoubleExponent(double v) {
    union binaryDouble val;
    val.dbl = v;
    //exponent is represented as unsigned int but offset is 1023
    return val.binary.exponent - 1023;
}

//returns double maximum accuracy at specific value
double getDoubleMaxAccuracy(double v) {
    //2^-52 - accuracy when exponent is 0
    int shift = -(DBL_MANT_DIG - 1);    
    double accuracy = 1;
    int exponent = getDoubleExponent(v);

    shift += exponent;  

    //infinity Nan etc.
    if (exponent == 1024) 
        return NAN;

    //Subnormals
    if (exponent == -1023)
        return DBL_TRUE_MIN;

    //computable values
    if (shift > 0) {
        // - 1/(2*2*2*2...)
        //it was used for power function testing (reason for not using pow())
        for (int i = 0; i < shift; i++) { 
            accuracy *= 2;
        }
    }
    else if (shift < 0) {
        // + 2*2*2*2...
        //it was used for power function testing (reason for not using pow())
        for (int i = 0; i > shift; i--) { 
            accuracy /= 2;
        }
    }
    return accuracy;
}

int getDoubleMaxAccuracyAsPower2(double v) {
    return getDoubleExponent(v) - (DBL_MANT_DIG - 1);
}