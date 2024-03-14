#include <assert.h>
#include <iomanip>

#include "Matrix.h"

Matrix::Matrix(int rows, int cols) : rows(rows), cols(cols) {
  // TODO: create a 2D dynamic array (matrix) using the member "data" in Matrix.h
  // TODO: and initialize element values with 0
}

Matrix::Matrix(const Matrix& mat) : rows(mat.rows), cols(mat.cols) {
  // TODO: create a 2D dynamic array (matrix) using the member "data" in Matrix.h
  // TODO: and initialize element values with the element values of the parameter mat 
}

Matrix::~Matrix() {
  // TODO: deallocate the 2D dynamic array (matrix)
}

ostream& operator<<(ostream& output, const Matrix& mat) {
  output.precision(mat.OUTPUT_PRECISION); // set the precision
  
  // TODO: output the element values of the parameter mat
}

istream& operator>>(istream& input, Matrix& mat) {
  // TODO: receive and store element values of the parameter mat
}

Matrix Matrix::operator+(const Matrix& mat) {
  // matrix dimension check using assert()
  // assert that the rows and cols must match
  // otherwise, the program terminates and an error message is printed
  assert( (rows == mat.rows) && (cols == mat.cols) );

  // TODO: perform matrix addition
}

Matrix Matrix::operator-(const Matrix& mat) {
  // TODO: matrix dimension check using assert() (refer to the operator+ code)
	
  // TODO: perform matrix subtraction
}

Matrix& Matrix::operator+=(const Matrix& mat) {
  // TODO: matrix dimension check using assert() (refer to the operator+ code)

  // TODO: perform matrix addition in place
}

Matrix& Matrix::operator-=(const Matrix& mat) {
  // TODO: matrix dimension check using assert() (refer to the operator+ code)

  // TODO: perform matrix subtraction in place
}

Matrix Matrix::operator*(const Matrix& mat) {
  // TODO: matrix dimension check using assert() (what is needed?)
	
  // TODO: perform matrix multiplication
}
