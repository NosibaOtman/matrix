#include "MlpNetwork.h"

MlpNetwork::MlpNetwork (Matrix wights[], Matrix bias[]) :
    new_arr{Dense (wights[ZERO], bias[ZERO], activation::relu),
            Dense (wights[ONE], bias[ONE], activation::relu),
            Dense (wights[TWO], bias[TWO], activation::relu),
            Dense (wights[THREE], bias[THREE], activation::softmax)}
{}

digit MlpNetwork::operator() (const Matrix &m)
{
  Matrix new_mat = m;
  new_mat.vectorize();
  for (const auto & d : new_arr)
    {
      new_mat = d(new_mat);
    }
  digit result = {0,0};
  // Find the index of the maximum value in the output matrix
  int maxIndex = new_mat.argmax();

  // Create a digit struct with the identified digit and its probability
  result.value = maxIndex;
  result.probability = new_mat[maxIndex];

//  for(int i=0;i<new_mat.get_rows()*new_mat.get_cols();i++)
//    {
//      if(new_mat[i]>result.probability)
//        {
//          result.value=i;
//          result.probability=new_mat[i];
//        }
//    }




//  for(int counter =ZERO;counter<TEN||
//  counter<new_mat.get_rows()*new_mat.get_cols();counter++)
//  {
//    if(new_mat[counter]>value)
//    {
//
//      value = new_mat[counter];
//      key = counter;
//    }
//  }
//  result={key,value};
  return result;
}

