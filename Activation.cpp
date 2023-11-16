#include "Activation.h"
#include "cmath"
//namespace activation
//{
//    RELU, SOFTMAX;
//}
Matrix activation::relu(const Matrix &m){
//  Matrix n_mat = m.operator= (m);
  Matrix n_mat = m;
  for(int i = ZERO ;i < m.get_rows();i++){
      for(int j = ZERO ;j < m.get_cols();j++){
          if(n_mat(i,j) <ZERO){ //m[i][j]>=0
              n_mat(i,j) = 0;
            }
        }
    }
  return n_mat;
}


Matrix activation::softmax(const Matrix &m){
  Matrix n_mat = m;
  float sum = 0;
  for(int i=0;i < m.get_rows();i++){
      for (int j = 0; j <m.get_cols() ; j++)
        {
          n_mat(i,j) = exp (m(i,j) );
          sum += n_mat(i,j);
        }
    }
  if (sum!=0)
    {
      sum = 1/sum;
    }
  return n_mat* sum; //n_mat *sum
}


