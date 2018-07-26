#include "vecteur.h"
#include "matrice.h"
#include <iostream>

int main(int argc, char **argv) {
  std::cout << "\tDEBUT des tests du programme MEF2D..." << std::endl;
  std::cout << "\t------> DEBUT des tests sur VECTEUR..." << std::endl;
  MPE::Vect<double> u,v;
  u.dim=2;
  u.setVal(0,0.5);u.setVal(1,-1.5);
  u.affichage("u");
  v.dim=2;
  v.setVal(0,1.5);v.setVal(1,0.5);
  v.affichage("v");
  cout << "\t som(u)=" << innerProduct(u,v)<< endl;

  std::cout << "\t------> FIN   des tests sur VECTEUR..." << std::endl;
  std::cout << " " << std::endl;
  std::cout << "\t------------------> DEBUT des tests sur MATRICE..." << std::endl;
  Matrice<double> A,B(2,2),C,D,E,F,G,H,M;
  B.setCoeffMat(0,0.,1.);B.setCoeffMat(0,1.,2.);
  B.setCoeffMat(1,0.,0.);B.setCoeffMat(1,1.,-1.);
  B.affichageMat("B");
  C.operator=(B);
  C.affichageMat("C");
  D = C.operator+=(B);
  D.affichageMat("D");
  E = B.operator+(B);
  E.affichageMat("E");
  cout << E.getCoeffMat(0,1) << endl;
  F = E.operator-(B);
  F.affichageMat("F"); 
  int c = 0.0;
  G = F.operator*(c);
  G.affichageMat("G");
  H = B.operator*(B);
  H.affichageMat("H");
  double d = 2.0;
  M = H.operator/(d);
  M.affichageMat("M");
  cout << "\tNbre Ligne= " << E.NbreLigne() << ", Nbre Colonne= " << E.NbreColonne() << endl;
  std::cout << "\t------------------> FIN   des tests sur MATRICE..." << std::endl;
  std::cout << "\tFIN des tests du programme MEF2D..." << std::endl;
  return 0;
}
