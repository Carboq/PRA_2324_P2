#include<vector>
#include<iostream>

using namespace std;

int BusquedaBinaria(int X,  vector<int> V, int ini, int fin){
        if  (ini > fin){
                 cout << "No se encuentra en el array" << endl;
                 return -1;

        }
        int medio = (ini + fin) / 2;
        if (V[medio] == X){ 
                 return medio; 
        }
        else if(V[medio] > X){
                return BusquedaBinaria(X, V, ini, medio - 1);
        }
        else{ 
                 return BusquedaBinaria(X, V, medio + 1, fin);
        }
}