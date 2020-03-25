#include <vector>
#include <math.h>
using namespace std;


typedef vector<float> Vector;
typedef vector <Vector> Matriz;

void zeros(Vector &v, int n){
    for (int i=0 ; i<n ; i++){
        v.push_back(0.0);
    }
    
}


void zeros(Matriz &M, int n){
    for (int i = 0; i < n; i++){
        vector<float> row(n, 0.0);
        M.push_back(row);
    }
    }


void productRealMatrix(float real, Matriz M, Matriz &R){
  zeros(R,M.size());
  for(int i=0; i<M.size();i++)
    for(int j=0; j<M.at(0).size();j++)
      R.at(i).at(j) = real*M.at(i).at(j);
}
    

Vector sumVector(Vector A, Vector B, int n){
  Vector R;
  zeros(R,n);
  for(int i=0;i<n;i++)
    R.at(i) = A.at(i)+B.at(i);
  return R;
}

Matriz sumMatrix(Matriz A, Matriz B,int n,int m){
    Matriz R;
    zeros(R,n);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            R.at(i).at(j) = A.at(i).at(j)+B.at(i).at(j);

    return R;
}


//Transponer una matriz, intercambiar filas con columnas


void transpose(Matriz M, Matriz &T){
  zeros(T,M.size());
  for(int i=0;i<M.size();i++)
    for(int j=0;j<M.at(0).size();j++)
    T.at(j).at(i) = M.at(i).at(j);
}

void getMinor(Matriz &M, int i, int j){
  M.erase(M.begin()+i);
  for(int i=0; i<M.size();i++){
    M.at(i).erase(M.at(i).begin()+j);
  }
}
void copyMatrix(Matriz A, Matriz &copy){
    zeros(copy,A.size());
    for(int i=0;i<A.size();i++)
        for(int j=0;j<A.at(0).size();j++)
            copy.at(i).at(j) = A.at(i).at(j);
}

float determinante(Matriz M){
  if(M.size()== 1)
    return M.at(0).at(0);
  else{
    float det = 0;
    for(int i=0;i<M.size();i++){
      Matriz minor;
      copyMatrix(M,minor);
      getMinor(minor,0,i);
      det += pow(-1,i) * M.at(0).at(i) * determinante(minor);
    }
    return det;
  }
  }

  void cofactors(Matriz M, Matriz &Cof){
    zeros(Cof,M.size());
    for(int i=0;i<M.size();i++){
        for(int j=0;j<M.at(0).size();j++){
            Matriz minor;
            copyMatrix(M,minor);
            getMinor(minor,i,j);
            Cof.at(i).at(j) = pow(-1,i+j)*determinante(minor);
        }
    }
}

void matrizInversa(Matriz m, Matriz &I){
  Matriz cof,trans;
  float det;
  det= determinante(m);
  if(det==0)
    cout<<"no se puede";
    exit(EXIT_FAILURE);
    //MatrizCof
    cofactors(m, cof);
    //tranpuesta
    transpose(cof,trans);
    //matrizInversa
    productRealMatrix(1/det,trans,I);
}