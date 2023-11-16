#include <cmath>
#include <string>
#include "Matrix.h"
void Matrix::initilaize (int _row, int _col)
{
  if( _row <= 0 || _col <= 0)
    {
      throw std::length_error (LENGTH_ERROR);
    }
  this->mat = new float* [_row]; //pointer to float in num of rows
  for (int i = 0; i < _row; i++)
    {
      this->mat[i] = new float[_col];
      // in each row there is a float members in num of cols
      for (int j = 0; j < _col; j++)
        {
          this->mat[i][j] = 0;
        }
    }
  this->rows = _row;
  this->cols = _col;
}
Matrix::Matrix (int rows, int cols)//constructor
{
  initilaize (rows, cols);
}
Matrix::Matrix () //default constructor
{
  this->initilaize(ONE, ONE);
}

Matrix::Matrix (const Matrix &oth_mat) //copy constructor
{
  rows = oth_mat.rows;
  cols = oth_mat.cols;
  mat = new float *[rows];
  for (int i = 0; i < rows; i++)
    {
      mat[i] = new float[cols];
    }
  for (int i = 0; i < rows; i++)
    {
      for (int j = 0; j < cols; j++)
        {
          mat[i][j] = oth_mat.mat[i][j];
        }
    }
}
Matrix::~Matrix()
{
  if (mat)
    {
      for (int i = 0; i < rows; i++)
        {
          delete[] mat[i];
        }
      delete[] mat;
    }
}
int Matrix::get_rows() const
{
  return rows;
}
int Matrix::get_cols() const
{
  return cols;
}
Matrix &Matrix::transpose()
{
  auto **trans_mat = new float *[cols];
  for (int i = 0; i < this->get_cols (); i++)
    {
      trans_mat[i] = new float[rows];
      for (int j = 0; j < this->get_rows (); j++)
        {
          trans_mat[i][j] = this->mat[j][i];
        }
        }
  for (int i = 0; i < rows; i++)
  {
      delete[] mat[i];
  }
  delete[] mat;
  this->mat = trans_mat;
  int t= this->rows;
  this->rows = this->get_cols ();
  this->cols = t;
  return *this;
}
Matrix &Matrix::vectorize()
{

  int num_cor_in_vec = this->get_rows () * this->get_cols ();
  auto **vec_mat = new float *[num_cor_in_vec];
  for (int i = 0; i < num_cor_in_vec; i++)
    {
      vec_mat[i] = new float[1];
    }
  for (int i = 0; i < this->get_rows(); i++)
    {
      for (int j = 0; j < this->get_cols (); j++)
        {
          vec_mat[i*cols+j][0] = mat[i][j];
        }
    }
  for (int i = 0; i < rows; i++)
    {

      delete[] mat[i];
    }
  delete[] mat;
  this->mat = vec_mat;
  this->rows = num_cor_in_vec;
  this->cols = 1;
  return *this;
}
void Matrix::plain_print () const
{
  for (int i = 0; i < this->get_rows (); i++)
    {
      for (int j = 0; j < this->get_cols (); j++)
        {
          cout << mat[i][j] << " "; //
        }
      cout << endl;
    }
}
Matrix Matrix::dot (const Matrix &m) const
{
  if (rows != m.rows || cols != m.cols)
    {
      throw std::length_error (LENGTH_ERROR);
    }
  Matrix new_mat(this->rows, this->cols);
  for (int i = 0; i < this->get_rows (); i++)
    {
      for (int j = 0; j < this->get_cols (); j++)
        {
          new_mat.mat[i][j] = this->mat[i][j] * m.mat[i][j];
        }
    }
  return new_mat;
}
float Matrix::norm () const
{
  float sum = 0;
  for (int i = 0; i < this->get_rows (); i++)
    {
      for (int j = 0; j < this->get_cols (); j++)
        {
          float num = (mat[i][j]) * (mat[i][j]);
          sum += num;
        }
    }
  return sqrt (sum);
}
Matrix Matrix::operator+ (const Matrix &m) const
{
  if (rows != m.rows || cols != m.cols)
    {
      throw std::length_error (LENGTH_ERROR);
    }
  Matrix new_mat (rows, cols);
  for (int i = 0; i < rows; i++)
    {
      for (int j = 0; j < cols; j++)
        {
          new_mat.mat[i][j] = mat[i][j] + m.mat[i][j];
        }
    }
  return new_mat;
}
Matrix &Matrix::operator= (const Matrix &m)
{
  if(this == &m){
      return *this;
    }
  for (int i = 0; i < rows; i++)
    {
      delete[] mat[i];
    }
  delete[] mat;
  rows = m.rows;
  cols = m.cols;
  mat = new float *[rows];
  for (int i = 0; i < rows; i++)
    {
      mat[i] = new float[cols];
    }
  for (int i = 0; i < rows; i++)
    {
      for (int j = 0; j < cols; j++)
        {
          mat[i][j] = m.mat[i][j];
        }
    }
  return *this;
}
Matrix Matrix::operator* (const Matrix &m) const
{
  if (this->cols != m.rows)
    {
      throw std::length_error (LENGTH_ERROR);
    }
  Matrix new_mat (this->get_rows (), m.get_cols ());
  for (int i = 0; i < rows; i++)
    {
      for (int j = 0; j < m.cols; j++)
        {
          new_mat(i,j) = 0;
          for (int n = 0; n < cols; ++n)
            {
              new_mat.mat[i][j] += mat[i][n] * m.mat[n][j];
            }
        }
    }
  return new_mat;
}

Matrix operator* (const float &c, const Matrix& m)
{
  return m*c;
}
Matrix Matrix::operator* (const float &c) const
//scalar multiplication on the left
{
  Matrix new_mat (rows, cols);
  for (int i = 0; i < rows; i++)
    {
      for (int j = 0; j < cols; j++)
        {
          new_mat.mat[i][j] = mat[i][j] * c;
        }
    }
  return new_mat;
}
int Matrix::argmax() const
{
  int index = 0;
  float max_val = mat[0][0];

  for (int i = 0; i < rows; i++)
    {
      for (int j = 0; j < cols; j++)
        {
          if (mat[i][j] > max_val)
            {
              max_val = mat[i][j];
              index = i * cols + j;
            }
        }
    }
  return index;
}
int Matrix::sum() const
{
  float result = 0;
  for (int i = 0; i < rows; i++)
    {
      for (int j = 0; j < cols; j++)
        {
          result +=  mat[i][j];
        }
    }
  return int(result);
}

Matrix &Matrix::operator+= (const Matrix &m)
{
  if (rows != m.rows || cols != m.cols)
    {
      throw std::length_error (LENGTH_ERROR);
    }
  for (int i = 0; i < rows; i++)
    {
      for (int j = 0; j < cols; j++)
        {
          mat[i][j] = mat[i][j] + m.mat[i][j];
        }
    }
  return *this;
}
float Matrix::operator() ( int i,  int j) const
{
  if ( 0 > i || i >= this->get_rows () || 0 > j || j >= this->get_cols ())
    {
      throw std::out_of_range (RANGE_ERROR);
    }
  return this->mat[i][j];
}

float &Matrix::operator()( int i,  int j)
{
  if ( 0 > i || i >= this->get_rows () || 0 > j || j >= this->get_cols ())
    {
      throw std::out_of_range (RANGE_ERROR);
    }
  return this->mat[i][j];
}

float Matrix::operator[] ( int i) const
{
  if (i < 0 || i >= this->get_rows() * this->get_cols())
    {
      throw std::out_of_range (RANGE_ERROR);
    }
  return this->mat[i / this->get_cols ()][i % this->get_cols ()];
}

float &Matrix::operator[] ( int i)
{
  if (i < 0 || i >= this->get_rows() * this->get_cols())
    {
      throw std::out_of_range (RANGE_ERROR);
    }
  return this->mat[i / this->get_cols ()][i % this->get_cols ()];
}

std::ostream &operator<< (std::ostream &os, Matrix &m)
{
  for (int i = 0; i <m.get_rows() ; i++)
    {
      for(int j =0;j<m.get_cols();j++)
        {
          if(m(i,j) >NUM01) //NUM01=0.1
            {
              os << DOUBLESTAR ;
            }
          else
            {
              os<< DOUBLESPACE ;
            }
        }
      os<< "\n";

    }
  return os;
}
std::istream &operator>> (std::istream &is,  Matrix &m)
{
//  if(! is.good())
//  {
//    throw std::runtime_error(RUN_ERROR);
//  }
//  for(int i=0;i<m.get_cols()*m.get_rows();i++)
//  {
//    is>>m[i];
//  }
//  return is;
//##########################
  float * arr = new float[m.get_cols() * m.get_rows()];
  long long  array_size_bytes = m.get_rows()*m.get_cols()*sizeof(float );
  is.seekg (0, std::istream ::end);
  long long file_size_bytes = is.tellg();
  if (file_size_bytes != array_size_bytes)
    {
      throw std::runtime_error (RUN_ERROR);
    }
  is.seekg (0, std::ifstream ::beg);
  if (!is.read ((char *) arr, array_size_bytes))
    {
      throw std::runtime_error (RUN_ERROR);
    }
  if (!is)
    {
      throw std::runtime_error (RUN_ERROR);
    }
  for(int i =0;i<m.rows;i++)
    {
      for(int j =0;j<m.cols;j++)
        {
          m(i,j)=arr[i*m.cols+j];
        }
    }
  delete[] arr;
  return is;
}














