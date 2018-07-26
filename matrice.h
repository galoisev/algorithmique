#ifndef _MAT_
#define _MAT_

/*  HEADER */
#include <iostream>
#include <cassert>
#include "assert.h"

using namespace std;

/**************************************************************************************************************************************
 * NAME:    matrice.h
 * AUTHOR:  J BARRET
 * SOURCE:  GNU C++
 * PURPOSE: classe "Matrice" définissant une matrice et toutes les operations: trace, determinant, produit, somme, inverse, ...
 * BUILD:   cf main.cpp
**************************************************************************************************************************************/





template<class T>
class Matrice{
  private:
    int m,n;
    T **x;
    void allocMatrice();
  public:    
    Matrice(){//constructeur par defaut
      m=0;n=0;x=NULL;
    }
    
    Matrice(int nx,int ny);
    Matrice(const Matrice& mat);//copie du constructeur
    ~Matrice();//destructeur
    Matrice& operator=(const Matrice& mat);//copie par affectation
    Matrice  operator+(const Matrice& mat);
    Matrice  operator-(const Matrice& mat);
    Matrice  operator*(const Matrice& mat);
    Matrice  operator*(const T& c);
    Matrice  operator/(const T& c);
    
    Matrice& operator+=(const Matrice& mat);
    
    
    void affichageMat(const char*msg);
    void setCoeffMat(int i,int j, T coef);
    T getCoeffMat(int i,int j);
    inline int NbreLigne();
    inline int NbreColonne();
};





template<class T>
Matrice<T> Matrice<T>::operator/(const T& c)
{
  assert(c!=0);
  int d=1./c;

  Matrice<T> temp(*this);  
  for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
      temp.x[i][j] = (1./c)*x[i][j];
    }
  }   
  return temp;
}



template<class T>
Matrice<T> Matrice<T>::operator*(const Matrice& mat)
{
  assert(m==n);
  Matrice<T> temp(*this);
  
  for(int i=0;i<m;i++){
    for(int j=0;j<m;j++){
      T s(0);
      for(int k=0;k<m;k++){
	 s+= x[i][k]*mat.x[k][j];
      }
      temp.x[i][j] = s;  
    }
  }
  return temp;
}


template<class T>
Matrice<T> Matrice<T>::operator*(const T& c)
{
  Matrice<T> temp(*this);
  for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
      temp.x[i][j] = c*x[i][j];
    }
  }
  return temp;
}



template<class T>
int Matrice<T>::NbreLigne()
{
  return m;
}
template<class T>
int Matrice<T>::NbreColonne()
{
  return n;
}



template<class T>
Matrice<T> Matrice<T>::operator+(const Matrice& mat)
{
  Matrice<T> temp(*this);
  return temp += mat;
}
template<class T>
Matrice<T> Matrice<T>::operator-(const Matrice& mat)
{
  Matrice temp(*this);
  for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
      temp.x[i][j] = x[i][j] - mat.x[i][j];
    }
  }
  return temp;  
}




template<class T>
Matrice<T>& Matrice<T>::operator+=(const Matrice& mat)
{
  for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
      x[i][j] += mat.x[i][j];      
    }
  }
  return (*this);
}




template<class T>
void Matrice<T>::setCoeffMat(int i, int j, T coef)
{
  assert(i>=0 && i<n);
  assert(j>=0 && j<m);
  x[i][j] = coef;
}

template<class T>
T Matrice<T>::getCoeffMat(int i, int j)
{
  assert(i>=0 && i<n);
  assert(j>=0 && j<m);
  return x[i][j];
}




template<class T>
void Matrice<T>::affichageMat(const char* msg)
{
  std::cout<< " " << std::endl;
  for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
      std::cout<< "\t" << msg << "(" << i+1 << "," << j+1 << ")= " << x[i][j];
    }
    std::cout<< " " << std::endl;
  }
  std::cout<< " " << std::endl;
}


template<class T>
void Matrice<T>::allocMatrice()
{
  x=new T*[m];
  for(int i=0;i<m;i++){
    x[i]=new T[n];
  }
}


template<class T>
Matrice<T>::Matrice(int nx, int ny):m(nx),n(ny)
{
  allocMatrice();
  for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
      x[i][j]=0;
    }
  }
}

template<class T>
Matrice<T>::Matrice(const Matrice& mat):m(mat.m),n(mat.n)
{
  allocMatrice();
  for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
      x[i][j]=mat.x[i][j];
    }
  }

}

template<class T>
Matrice<T>::~Matrice()
{
  for(int i=0;i<m;i++){
    delete []x[i];
  }
  delete[]x;
}


template<class T>
Matrice<T>& Matrice<T>::operator=(const Matrice<T>& mat)// attention a bien mettre <T> dans Matrice<T>& Matrice<T>
{
  if(this == &mat){
    return *this;
  }else{
    if(m != mat.m || n != mat.n){
      this->~Matrice();
      m=mat.m;
      n=mat.n;
      allocMatrice();
    }
    for(int i=0;i<m;i++){
      for(int j=0;j<n;j++){
	x[i][j]=mat.x[i][j];
      }
    }
    return (*this);
  }  
}


















#endif //endif _MAT_