// Matrix.h
#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include <fstream>
#define ZERO 0
#define ONE 1
#define TWO 2
#define THREE 3
#define TEN 10
#define NUM01 0.1
#define  LENGTH_ERROR "the length is un valid"
#define  RANGE_ERROR "the range is un valid"
#define RUN_ERROR "run time error"
#define DOUBLESTAR "**"
#define DOUBLESPACE "  "
using namespace std;


/**
 * @struct matrix_dims
 * @brief Matrix dimensions container. Used in MlpNetwork.h and main.cpp
 */
typedef struct matrix_dims
{
    int rows, cols;
} matrix_dims;

// Insert Matrix class here...
class Matrix
{
 private : //variable
  int rows = ZERO;
  int cols = ZERO;
  float **mat = nullptr;
  void initilaize (int _row, int _col); //allocate matrix
 public:
  Matrix (int rows, int cols);//constructor
  Matrix ();//default constructor
  Matrix (const Matrix &mat);//copy constructor
  ~Matrix ();//destructor
  int get_rows() const;
  int get_cols() const;
  Matrix &transpose();
  Matrix &vectorize();
  void plain_print () const;
  Matrix dot (const Matrix &m) const;
  float norm () const;
  int argmax() const;
  Matrix operator+ (const Matrix &m) const;
  Matrix& operator= (const Matrix &m);
  Matrix operator* (const Matrix &m) const;
  Matrix operator* (const float &c) const; //left
  friend Matrix operator* (const float &c, const Matrix& m);
  int sum() const;
  Matrix &operator+= (const Matrix &m);
  float &operator() (int i,  int j) ;
  float operator() (int i,  int j) const;
  float operator[] ( int i) const;
  float& operator[](int i);
  friend std::ostream &operator<< (std::ostream &os,  Matrix &m);
  friend std::istream &operator>> (std::istream &is,  Matrix &m);

};

#endif //MATRIX_H
////functions

//static void plain_print (Matrix mat);
////  Matrix dot(Matrix m);
////  float norm();
////operators
////   operator> (Matrix a, const Matrix b ){ return a + b; }