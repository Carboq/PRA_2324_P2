#include <iostream>
#include <algorithm> 
#include <limits>

using namespace std;

//int infinito = std::numeric_limits<int>::max();


int cambio(const int V[], int N, int M, int sol[]){
    int** matrix = new int*[N];
    for(int i=0; i<N; i++){
        matrix[i] = new int[M+1];
    }
    for(int i=0; i<N; i++){
        matrix[i][0] = 0;
    }
    // Rellenamos la tabla
    for (int i = 0; i < N; i++) {
        for (int j = 1; j <= M; j++) {
            matrix[i][j] = -1;
             if (i == 0) {
                if (j % V[0] == 0) {
                    matrix[0][j] = j / V[0];
                } 
             }
            if (i > 0) {
                matrix[i][j] = matrix[i - 1][j];
            }

            if (V[i] <= j && matrix[i][j - V[i]] != -1) {
                matrix[i][j] = min(matrix[i][j], 1 + matrix[i][j - V[i]]);
            }
        }
    }
    fill(sol, sol + N, 0);  // Inicializamos el array sol con ceros
    int restante = M;
    for (int i = N - 1; i >= 0 && restante > 0; i--) {
        while (restante >= V[i] && matrix[i][restante] == 1 + matrix[i][restante - V[i]]) {
            sol[i]++;
            restante -= V[i];
        }
    }

    return matrix[N-1][M];

}
int main() {
    int monedas[] = {1, 4, 6};
    int N = sizeof(monedas) / sizeof(monedas[0]);
    int M = 64;
    int sol[N];
    int resultado = cambio(monedas, N, M, sol);
    cout << "Número mínimo de monedas para " << M << ": " << resultado << endl;
    cout << "Monedas usadas: ";
    for (int i = 0; i < N; i++) {
        cout << sol[i] << " de " << monedas[i] << " ";
    }
    cout << endl;
    return 0;
}