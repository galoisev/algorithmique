#ifndef _VECT_
#define _VECT_

#define NMAX 1000
#include <iostream>
#include "assert.h"

namespace MPE{//ModexProgramEfficace
  template<class T>
  struct Vect{
    int dim;
    T x[NMAX];
    void setVal(int i,T val){
      assert(i>=0 && i<dim);
      x[i]=val;      
    }
    int getVal(int i){
      assert(i>=0 && i<dim);
      return x[i];      
    }
    void affichage(const char*msg){
      std::cout<< "\t" <<std::endl;
      for(int i=0;i<dim;i++)
	std::cout<< "\t" << msg << "[" << i << "]= " << x[i] <<std::endl;
      std::cout<< "\t" <<std::endl;
    }
  };
  
  template<class T>
  T innerProduct(const Vect<T>& a,const Vect<T>& b){
    T sum=0;
    assert(a.dim==b.dim);
    for(int i=0;i<a.dim;i++)
      sum += a.x[i] * b.x[i];
    return sum;
  }
  
}



#endif //_VECT_