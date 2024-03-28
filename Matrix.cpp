#include <assert.h>
#include <iomanip>

#include "Matrix.h"

Matrix::Matrix(int rows, int cols) : rows(rows), cols(cols) {
  // TODO: create a 2D dynamic array (matrix) using the member "data" in Matrix.h
  // TODO: and initialize element values with 0
  Matrix::rows = rows;
  Matrix::cols = cols;
  data = new double* [Matrix::rows];
  for (int i = 0; i< Matrix::rows; i++){
    data[i] = new double [cols];
  }
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
  output<<fixed;
  // TODO: output the element values of the parameter mat
  for (int i = 0; i<mat.rows; i++){
    //output<<"     ";
    for (int j = 0; j<mat.cols; j++){
      output<<std::setfill(' ')<<std::setw(10)<<mat.data[i][j];
      //cout<<mat.data[i][j];

    }
    output<<endl;
  }
  return(output);
}

istream& operator>>(istream& input, Matrix& mat) {
  // TODO: receive and store element values of the parameter mat
  for (int i = 0; i<mat.rows; i++){
    for (int j = 0; j<mat.cols; j++){
      input>>mat.data[i][j];
      //cout<<i<<j<<endl;
    }
  }

  return input;
}

Matrix Matrix::operator+(const Matrix& mat) {
  // matrix dimension check using assert()
   assert( (rows == mat.rows) && (cols == mat.cols) );
  
  // TODO: perform matrix addition
   Matrix result(rows, cols);

  for (int i = 0; i < rows; i++){
    for (int j = 0; j < cols; j++){
      result.data[i][j] = mat.data[i][j]+data[i][j];
    }
  }
  return result;
}

Matrix Matrix::operator-(const Matrix& mat) {
  // TODO: matrix dimension check using assert() (refer to the operator+ code)
  assert( (rows == mat.rows) && (cols == mat.cols) );
  // TODO: perform matrix subtraction
  Matrix result(rows, cols);

  for (int i = 0; i<rows; i++){
    for (int j = 0; j<cols; j++){
      result.data[i][j] = data[i][j]-mat.data[i][j];
    }

  }
  return result;
}

Matrix& Matrix::operator+=(const Matrix& mat) {
  // TODO: matrix dimension check using assert() (refer to the operator+ code)
 assert( (rows == mat.rows) && (cols == mat.cols) );
  // TODO: perform matrix addition in place

  for (int i = 0; i<rows; i++){
    for (int j = 0; j<cols; j++){
      data[i][j] = data[i][j]+mat.data[i][j];
    }

  }
  return(*this);
  
}

Matrix& Matrix::operator-=(const Matrix& mat) {
  // TODO: matrix dimension check using assert() (refer to the operator+ code)
 assert( (rows == mat.rows) && (cols == mat.cols) );
  // TODO: perform matrix subtraction in place
  for (int i = 0; i<rows; i++){
    for (int j = 0; j<cols; j++){
      data[i][j] = data[i][j]-mat.data[i][j];
    }

  }
  return(*this);
}

Matrix Matrix::operator*(const Matrix& mat) {
  // TODO: matrix dimension check using assert() (what is needed?)
    assert(cols == mat.rows);
  // TODO: perform matrix multiplication
  
    Matrix result(rows,mat.cols); // needed for matrix c (in the result.txt)

    for(int i = 0; i < rows; i++){
      for (int j = 0; j < mat.cols; j++){
        for (int k = 0; k < cols; k++){
          result.data[i][j] += data[i][k] * mat.data[k][j];
        }
      }
    }
    return result;
}