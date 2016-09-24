
/* 
 * File:   NumericalIntegration.cpp
 * Author: harsh
 *
 * Created on 4 August, 2016, 3:49 PM
 */

#include <iostream>
#include <math.h>
#include<stdlib.h>
#include "NumericalIntegration.hpp"

using namespace std;


float ans = 0.0;

void NumericalIntegration::input() {

    cout << "Enter the no of iterations\n";
    cin>>n;

    cout << "Enter the interval of a and b:\n";
    cin >> a>>b;
    h = (b - a) / n;
    /* cout<<"value of h: <<\n"<<h;*/
}

float function(float x) {

    return sqrt(1 + (9 * x * x * x * x));
    //return 1/(1+x*x);
}

float NumericalIntegration::simpsonsone() {
    addition = function(a) + function(b);
    for (i = 1; i < n; i++) {
        if (i % 2 == 0) {
            addition = addition + 2 * function(a + i * h); // 
        } else {
            addition = addition + 4 * function(a + i * h);
        }
    }
    result = (h / 3) * addition;
    cout << "Answer is :" << result;
    return result;
}

float NumericalIntegration::simpsonsThree() {

    addition = function(a) + function(b);
    for (i = 1; i < n; i++) {
        if (i % 3 == 0) {
            addition = addition + 2 * function(a + i * h); // 
        } else {
            addition = addition + 3 * function(a + i * h);
        }
    }
    result = (3 * h / 8) * addition;
    cout << "Answer is :" << result;
    return result;

}

float NumericalIntegration::trapezoidal() {
    addition=0;
    addition = function(a) + function(b);
    for (i = 1; i < n; i++) {
        addition = addition + 2 * function(a + i * h);


    }
    result = (h / 2) * addition;
    cout << "Answer is :" << result;
    return result;
}

float NumericalIntegration::Booles() {


    for (i = 0; i < n+1; i++) {

        if ((i == 0) || (i == n)) {
            addition = addition + 7 * function(a + i * h);
        } else
            if (i % 2 == 0) {
            addition = addition + 12 * function(a + i * h);
        } else {
            addition = addition + 32 * function(a + i * h);
        }
    }

    result = addition * (2 * h / 45);
    cout << "Answer is :" << result;
    return result;
}


