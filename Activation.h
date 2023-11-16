#ifndef ACTIVATION_H // Header guard
#define ACTIVATION_H

#include "Matrix.h"

// Insert Activation class here...
typedef Matrix (*pointer_Activation_function)(const Matrix &m);
namespace activation
{
    Matrix relu(const Matrix &m);
    Matrix softmax(const Matrix &m);
}

#endif // ACTIVATION_H
