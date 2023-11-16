//
// Created by Nosiba Otman on 24/05/2022.
//
#include "Dense.h"

Dense::Dense (Matrix& weights, Matrix& bias,
              pointer_Activation_function activation)
//pointer or to softmax or to relu
{
  _weights = weights;
  _bias = bias;
  _activation = activation;
}


Matrix Dense::get_weights () const
{
  return _weights;
}
Matrix Dense::get_bias () const
{
  return _bias;
}
pointer_Activation_function Dense::get_activation () const
{
  return _activation;
}
Matrix Dense::operator()(const Matrix& m) const{
  Matrix new_mat = (_weights*m) +_bias;
  return _activation(new_mat);
}



