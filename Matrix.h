#ifndef MATRIX_H__
#define MATRIX_H__

#include <iostream>

using namespace std;

class Matrix {
  // custom << (output) operator
  friend ostream& operator<<(ostream&, const Matrix&); 

  // custom >> (input) operator
  friend istream& operator>>(istream&, Matrix&);

public:
  // constructor: dynamically allocates memory to a matrix
  Matrix(int rows, int cols);

  // copy constructor: dynamically allocates memory to a matrix using another matrix 
  Matrix(const Matrix& mat);

  // destructor: deallocates memory
  ~Matrix();

  // custom + operator for matrix addition
  Matrix operator+(const Matrix&);

  // custom - operator for matrix subtraction
  Matrix operator-(const Matrix&);

  // custom += operator for matrix addition and assignment (in place)
  Matrix& operator+=(const Matrix&);
	
  // custom -= operator for matrix subtraction and assignment (in place)
  Matrix& operator-=(const Matrix&);

  // custom * operator for matrix multiplication
  Matrix operator*(const Matrix&);

private:
  double **data; // a pointer to create a 2D array (matrix) and point to it
  int rows; // the total number of rows in a matrix
  int cols; // the total number of columns in a matrix

  const int OUTPUT_PRECISION = 2; // used in the << (output) operator
  const int OUTPUT_WIDTH = 10; // used in the << (output) operator
};
#endif
