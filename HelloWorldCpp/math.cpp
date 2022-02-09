#include <iostream>
#include <cmath>
using namespace std;

/*
 *      Potentially useful Math operations:
 *  max(x, y)
 *  min(x, y)
 *  sqrt(x)
 *  abs(x)
 *  round(x)
 *  exp(x)
 *  pow(x, y)
 *  
 */

int main() {
    int num1 = 8;
    int num2 = 4+7;
    cout << "There are two numbers: 8 and 4+7\n";
    cout << "The max() is: " << max(num1, num2) << "\n";
    cout << "The min() is: " << min(num1, num2) << "\n\n";

    // The following are operations performed using the <cmath> header.
    cout << "The square root of 49 is performed using \"sqrt(49)\" : " << sqrt(49) << endl;
    cout << "Rounding the float 2.6 to the nearest whole number is performed using \"round(2.6)\" : " << round(2.6) << endl;
    cout << "The log of 2 is performed using \"log(2)\" : " << log(2) << "\n\n";
    cout << "Here are some more mathematical operations: \n\n"
        "abs(x) 	Returns the absolute value of x \n"
        "acos(x) 	Returns the arccosine of x \n"
        "asin(x) 	Returns the arcsine of x \n"
        "atan(x) 	Returns the arctangent of x \n"
        "cbrt(x) 	Returns the cube root of x \n"
        "ceil(x) 	Returns the value of x rounded up to its nearest integer \n"
        "cos(x) 	Returns the cosine of x \n"
        "cosh(x) 	Returns the hyperbolic cosine of x \n"
        "exp(x) 	Returns the value of E^x \n"
        "expm1(x) 	Returns ex -1 \n"
        "fabs(x) 	Returns the absolute value of a floating x \n"
        "fdim(x, y) 	Returns the positive difference between x and y \n"
        "floor(x) 	Returns the value of x rounded down to its nearest integer \n"
        "hypot(x, y) 	Returns sqrt(x2 +y2) without intermediate overflow or underflow \n"
        "fma(x, y, z) 	Returns x*y+z without losing precision \n"
        "fmax(x, y) 	Returns the highest value of a floating x and y \n"
        "fmin(x, y) 	Returns the lowest value of a floating x and y \n"
        "fmod(x, y) 	Returns the floating point remainder of x/y \n"
        "pow(x, y) 	Returns the value of x to the power of y \n"
        "sin(x) 	Returns the sine of x (x is in radians) \n"
        "sinh(x) 	Returns the hyperbolic sine of a double value \n"
        "tan(x) 	Returns the tangent of an angle \n"
        "tanh(x) 	Returns the hyperbolic tangent of a double value \n\n";
    return 0;
}