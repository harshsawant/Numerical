/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: harsh
 *
 * Created on 10 August, 2016, 4:10 PM
 */

#include<iostream>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#include "NumericalIntegration.hpp"

int main() {
    int ch;
    float result;
    NumericalIntegration simpsonone, simpsonThree, Trapzoidal, Bools;



    do {

        cout << "\n1.Simpson's 1/3 rule \n";
        cout << "2.Simpson's 3/8 rule \n";
        cout << "3.Trapezoidal rule \n";
        cout << "4.Booles rule \n";
        cout << "5.Exit";
        cout << "\nEnter your choice \n";
        cin>>ch;
        switch (ch) {
            case 1: simpsonone.input();
                result = simpsonone.simpsonsone();
                break;
            case 2: simpsonThree.input();
                result = simpsonThree.simpsonsThree();
                break;
            case 3: Trapzoidal.input();
                result = Trapzoidal.trapezoidal();
                break;
            case 4: Bools.input();
                result = Bools.Booles();
                break;
            case 5: exit(0);
                break;
        }
    } while (ch != 6);

    return 0;
}

