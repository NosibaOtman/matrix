#ifndef DENSE_H
#define DENSE_H

#include "Activation.h"

// Insert Dense class here...
class Dense{
 private:
  Matrix _weights;
  Matrix _bias;
  pointer_Activation_function _activation;
 public:
  //Dense_constructor
  Dense(Matrix& weights,Matrix& bias,
        pointer_Activation_function activation);
  //getters
  Matrix get_weights() const;
  Matrix get_bias() const;
  pointer_Activation_function get_activation() const;
  //operators
  Matrix operator()(const Matrix& m) const;

};

#endif //DENSE_H