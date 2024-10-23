#include<vector>
#include<iostream>
#include"DyV.h"

using namespace std;
#define Valor 5

int main(){
	vector<int> V = {4,3,6,2,77,22,-3,4};
	QuickSort(V,0,V.size()-1);
	for (int i = 0; i < V.size(); i++){
		cout << V[i] << " ";
	}
	cout << endl;
	return 0;
}
