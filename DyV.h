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
int Partition(vector<int> &V, int ini, int fin){
         int x = V[fin];
         int i = ini;
         for (int j = ini; j < fin; j++){
               if( V[j] <= x){
		     swap(V[i],V[j]);
                     i = i + 1;
	       }
	 }
	 swap(V[i],V[fin]);
         return i;
}
void QuickSort(vector<int> &V, int ini, int fin){
        if( ini < fin){
                 int pivot = Partition(V, ini, fin);
                 QuickSort(V, ini, pivot - 1);
                 QuickSort(V, pivot + 1, fin);
		}
}
