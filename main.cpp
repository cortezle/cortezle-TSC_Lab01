#include <iostream>
#include "math_tools.h"
#include "display_tools.h"

int main (void){

  Matriz ex, inv,cof,tran;

  zeros(ex, 3);
  ex.at(0).at(0) = 2;
  ex.at(0).at(1) = 2;
  ex.at(0).at(2) = 3;
  ex.at(1).at(0) = 4;
  ex.at(1).at(1) = 5;
  ex.at(1).at(2) = 6;
  ex.at(2).at(0) = 7;
  ex.at(2).at(1) = 8;
  ex.at(2).at(2) = 9;
  
  show_matriz(ex);
  cout<<endl;
  matrizInversa(ex, inv);
  show_matriz(inv);


    return 0;
}

