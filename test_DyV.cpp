#include<vector>
#include<iostream>
#include"DyV.h"

using namespace std;
#define Valor 5

int main(){
	vector<int> V = {0,1,2,3};
	cout << "Valor encontrado: " << BusquedaBinaria(Valor,V,0,V.size()) << endl;
	return 0;
}
