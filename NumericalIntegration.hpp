/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NumericalIntegration.hpp
 * Author: harsh
 *
 * Created on 10 August, 2016, 4:09 PM
 */
#ifndef SIMPSONS_H
#define SIMPSONS_H

using namespace std;

class NumericalIntegration {
public:

    float a, b, h, addition, result;
    int i, n;
public:
    void input();
    float simpsonsone();
    float simpsonsThree();
    float trapezoidal();
    float Booles();

};


#endif	// SIMPSONS_H

