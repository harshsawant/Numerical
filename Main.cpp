#include<iostream>
#include<cstdlib>
#include "Matrix.hpp"
using namespace std;
int main() {
	int ch;

	matrix m1, m2, m3;

	do {
               // cout<<"Enter the 1st Matrix \n";
                //cin>>m1;
                //cout<<"Enter the 2nd Matrix \n";
                //cin>>m2;
		cout << "***********Assignment 2nd************ \n";
		cout
				<< "enter your choice \n: \n1.gaussElimination \n2.jacobiMethod \n3.SeidelaMethod \n";
		cin >> ch;
		switch (ch) {
		case 1:
			//Gaussian
			m1.readInputfile();
			m1.displayMatrix(m1.M, m1.n, m1.m);
			m1.gaussianEllimination();
			break;
		case 2:
			m1.readInputfile();
			m1.jacobiMethod();
			//need some memory clean up operations4

			break;

		case 3:
			m1.readInputfile();
			m1.SeidelMethod();
			break;
		}
	} while (1);
	return 0;
}
