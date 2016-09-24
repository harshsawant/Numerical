using namespace std;
#define MAX 100
class matrix {
public:
	float **M;
	float solution[10], solution_new[10];
	char filename1[10],filename2[10];
	int n, m,row,col;
	int i, j;
	float F, x[10], s, temp;
	float N[20];

public:
	//void get();
	//void put();
	matrix();			//default constructor
	//matrix(int row, int col);  //parameterized constructor
	~matrix();			//destructor
	//matrix(const matrix &m);    //copy constructor
	//friend istream& operator >>(istream& din, matrix& m);
	//friend ostream& operator <<(ostream& dout, matrix& m);
	//matrix operator +(matrix m2);
	//matrix operator -(matrix m2);
	//matrix operator *(matrix m2);

	void displayMatrix(float **M, int a, int b);
	void readInputfile();
	void gaussianEllimination();
	void jacobiMethod();
	void solve(int, double);
	void print_solution(int);
	int isDiagonallyDominant(int);
	//void print_matrix(int k);
	void seidelSolve(int, double);
	void SeidelMethod();
	//void freememory(float **M);
};
