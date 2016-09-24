#include<iostream>
#include<stdio.h>
#include<cmath>
#include<cstdlib>
#include "Matrix.hpp"
#include<fstream>
using namespace std;


/**default constructor*/
matrix::matrix() {
//nothing
}
/**destructor*/
matrix::~matrix() {

}
/**function for "Extraction" operator
istream& operator >>(istream& in, matrix& m) {
	cout << "Enter the order of row\n";
	in >> m.row;
	cout << "Enter the order of column\n";
	in >> m.col;

	cout << "Enter the elements\n";
	for (int i = 0; i < m.row; i++)
		for (int j = 0; j < m.col; j++)
			in >> m.M[i][j];

	return in;
}

/**function for "Insertion" operator
ostream& operator <<(ostream& out, matrix& m) {
	for (int i = 0; i < m.row; i++) {
		for (int j = 0; j < m.col; j++) {
			out << m.M[i][j] << "\t";
		}
		out << endl;
	}
	return out;
}

/** function for Addtion of two matrix
matrix matrix::operator +(matrix m2) {
	matrix m3;
	m3.row = m3.col = row;

	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			m3.M[i][j] = M[i][j] + m2.M[i][j];
	return m3;
}
/** function for substraction of two matrix
matrix matrix::operator -(matrix m2) {
	matrix m3;
	m3.row = m3.col = row;

	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			m3.M[i][j] = M[i][j] - m2.M[i][j];
	return m3;
}
/** function for multiplication of two matrix
matrix matrix::operator *(matrix m2) {
	matrix m3;
	m3.row = m3.col = row;

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			m3.M[i][j] = 0;
			for (int k = 0; k < m2.row; k++)
				m3.M[i][j] += M[i][k] * m2.M[k][j];
		}
	}
	return m3;
}

void matrix::freememory(float **M)
{
	int i;
	for (i = 0; i < m; i++)
	{ 
		free(M[i]);
	}
	free(M);
}*/
void matrix::displayMatrix(float **M, int n, int m) {
	int i, j;
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			cout << M[i][j] << "\t";
		}
		cout << "\t" << M[i][j];
		cout << "\n";
	}
}

void matrix::readInputfile() {
	matrix::M={0};
	cout << "Enter matrix filename : \n";
	cin >> filename1;
	ifstream readThisFile(filename1);

	if (readThisFile == NULL) {
		cout << "Error in reading file !";
		exit(0);
	}

	cout << "Enter vector filename : \n";
	cin >> filename2;
	ifstream readThisFile2(filename2);

	readThisFile >> m;
	readThisFile >> n;

	for (j = 0; j < m; ++j)
		readThisFile2 >> N[j];

	//allocate memory dynamically

	 M=new float*[m];
	for(int alloc=0;alloc<=m;alloc++)
	{
		M[alloc]=new float[n];
}
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			readThisFile >> M[i][j];
		}
		M[i][j] = N[i];
	}

}

void matrix::gaussianEllimination() {

	int p, i, j;

	for (i = 1; i <= m; i++) {
		if (M[i][i] == 0) {
			for (p = i + 1; p <= n; p++) {
				if (M[p][i] > M[i][i]) {
					for (int r = 1; r <= m + 1; r++) {
						temp = M[p][r];
						M[p][r] = M[i][r];
						M[i][r] = temp;
					}
				}
			}
		}
	}

	//After Row Interchange..
	cout << "Row interchange this matrix..\n\n";
	for (i = 0; i < m; i++) {
		for (j = 0; j < n + 1; j++) {
			cout << M[i][j] << "\t";
		}
		cout << "\n";
	}

	//upper triangular matrix..
	int k;
	for (j = 0; j < m + 1; j++) {
		for (i = 0; i < n; i++) {
			if (i > j) {
				F = M[i][j] / M[j][j];
				for (k = 0; k < n + 1; k++) {
					M[i][k] = M[i][k] - F * M[j][k];
				}
			}
		}
	}

	// print upper triangular marix..
	cout << "upper triangular matrix..\n\n";
	for (i = 0; i < m; i++) {
		for (j = 0; j <= n; j++) {
			cout << M[i][j] << "\t";
		}
		cout << "\n";
	}
	//LU decomposition//
	// For solution of equation..//

	for (i = m - 1; i >= 0; i--) {
		s = 0;
		for (j = i; j < n; j++) {
			s = s + M[i][j] * x[j];
		}
		x[i] = (M[i][n] - s) / M[i][i];
	}

	cout << "\nThe solution is: \n";
	for (i = 0; i < m; i++) {
		cout << "\nx" << i << "=" << x[i] << "\n";
	}
}

void matrix::SeidelMethod() {
	int i, j, k, a;
	double c=1e-6;
	/*displayMatrix(M, m, matrix::n);
	printf("\nEnter Tol:\n");
	scanf("%lf", &c);

	printf("\nEnter initial values:");
	for (i = 0; i < m; i++) {
		printf("\nEnter x%d", i);
		scanf("%f", &solution[i]);
		solution_new[i] = solution[i];
	}*/

	a = isDiagonallyDominant(m);
	if (a == 0)
		printf("unable to solve");
	else {
		seidelSolve(m, c);
		//print_solution(m);
		for (j = 0; j < m; j++) {
					printf("\nx%d = %lf \n", j, solution[j]);
				}
	}
}
///To find solution using ...method
///var1 : 
///var2 :

void matrix::seidelSolve(int k, double n) {
	int j, l, z, count = 0;
	float temp;
	double diff, sum1, sum2;
	printf("\n Tol is %lf", n);
	do   //loop for iteration
	{
		for (j = 0; j < k; j++) {
			temp = M[j][k];
			for (l = 0; l < k; l++) {
				if (j != l) {
					temp = temp - (M[j][l] * solution_new[l]);
				}
			}
			solution_new[j] = temp / M[j][j];
		}
		sum1 = 0.0;
		sum2 = 0.0;
		for (z = 0; z < k; z++) {
			sum1 += solution[z] * solution[z];
			sum2 += solution_new[z] * solution_new[z];
		}
		diff = sum2 - sum1;
		diff = sqrt(diff);
		for (z = 0; z < k; z++)
			solution[z] = solution_new[z];   //update value for solution
		count++;
	} while (diff >= n);

	printf("\nNumber of iteration = %d", count);
}

void matrix::jacobiMethod() {
	int i, j, k, a;
	double n=1e-6;

	/*printf("\nEnter Tol:\n");
	scanf("%lf", &n);
	printf("\nEnter initial values:");

	for (i = 0; i < m; i++) {
		printf("\nEnter x%d", i);
		scanf("%f", &solution[i]);

	}*/
	a = isDiagonallyDominant(m);
	if (a == 0)
		printf("Given matrix is NOT diagonally dominant !");
	else {
		solve(m, n);
		for (j = 0; j < m; j++) {
			printf("\nx%d = %lf \n", j, solution[j]);
		}
	}
}

int matrix::isDiagonallyDominant(int k) {
	int i, j, m, n, y;
	float temp, temp1;
	printf("\nIn function");
	for (i = 0; i < k; i++) {

		temp = fabs(M[i][i]);
		temp1 = 0;
		for (j = 0; j < k; j++) {

			if (i != j)
				temp1 = temp1 + fabs(M[i][j]);
		}
		if (temp < temp1) {
			temp = 0.0;
			temp1 = 0.0;

			for (m = 0; m < k; m++) {
				if (m != i) {
					temp = fabs(M[m][i]);
					temp1 = 0;
					for (j = 0; j < k; j++) {

						if (j != i)
							temp1 = temp1 + fabs(M[m][j]);
					}

					if (temp >= temp1) {
						n = m;
						break;
					}
				}
			}
			if (m == k)
				return 0;

			//replacing the next pivot elements row

			for (y = i; y < k + 1; y++) {
				float t;
				t = M[i][y];
				M[i][y] = M[n][y];
				M[n][y] = t;
			}
			i = -1;
		}

	}
	if (i == k)
		return 1;
	return 0;
}

void matrix::solve(int k, double n) {
	int j, l, z, count = 0;
	float temp;
	double diff, sum1, sum2;
	do  //loop for iteration
	{
		for (j = 0; j < k; j++) {
			temp = M[j][k];
			for (l = 0; l < k; l++) {
				if (j != l) {
					temp = temp - (M[j][l] * solution[l]);
				}
			}
			solution_new[j] = temp / M[j][j];
		}
		sum1 = 0.0;
		sum2 = 0.0;
		for (z = 0; z < k; z++) {
			sum1 += solution[z] * solution[z];
			sum2 += solution_new[z] * solution_new[z];
		}
		diff = sum2 - sum1;
		diff = sqrt(diff);
		for (z = 0; z < k; z++)
			{
				solution[z] = solution_new[z];  //update value for solution
			}

		count++;
	} while (diff >= n);

	printf("\nNumber of iteration = %d", count);
}
