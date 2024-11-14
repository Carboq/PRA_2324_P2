#include <iostream>
#include <limits>
#include <vector>
#include <algorithm> // Para std::min

using namespace std;

// Función que devuelve el número mínimo de monedas necesarias para devolver M
int cambio(const vector<int>& monedas, int N, int M) {
    // Definir un valor infinito
    int infinito = numeric_limits<int>::max();

    // Crear la tabla con N filas (monedas) y M+1 columnas (0..M)
    vector<vector<int>> tabla(N, vector<int>(M+1, infinito));

    // Inicializamos la primera columna con 0 (0 monedas para devolver cantidad 0)
    for (int i = 0; i < N; i++) {
        tabla[i][0] = 0;
    }

    // Rellenamos la tabla
    for (int i = 0; i < N; i++) {
        for (int j = 1; j <= M; j++) {
            // Si no tomamos la moneda i
            if (i > 0) {
                tabla[i][j] = tabla[i-1][j];
            }

            // Si tomamos la moneda i (si cabe en el valor actual)
            if (monedas[i] <= j) {
                tabla[i][j] = min(tabla[i][j], 1 + tabla[i][j - monedas[i]]);
            }
        }
    }

    // El resultado será el valor de la última fila y columna de la tabla
    return tabla[N-1][M] == infinito ? -1 : tabla[N-1][M];
}

// Función para obtener el vector solución (cuántas monedas de cada tipo usamos)
vector<int> vectorSolucion(const vector<int>& monedas, int N, int M) {
    int infinito = numeric_limits<int>::max();
    vector<vector<int>> tabla(N, vector<int>(M+1, infinito));

    // Inicializar la primera columna con 0
    for (int i = 0; i < N; i++) {
        tabla[i][0] = 0;
    }

    // Rellenar la tabla
    for (int i = 0; i < N; i++) {
        for (int j = 1; j <= M; j++) {
            if (i > 0) {
                tabla[i][j] = tabla[i-1][j];
            }
            if (monedas[i] <= j) {
                tabla[i][j] = min(tabla[i][j], 1 + tabla[i][j - monedas[i]]);
            }
        }
    }

    // Si no es posible devolver el cambio, devolvemos un vector vacío
    if (tabla[N-1][M] == infinito) return {};

    // Reconstruir la solución (cuántas monedas de cada tipo se usaron)
    vector<int> solucion(N, 0);
    int i = N - 1, j = M;
    while (j > 0 && i >= 0) {
        // Si usamos la moneda i
        if (i == 0 || tabla[i][j] != tabla[i-1][j]) {
            solucion[i]++;
            j -= monedas[i];
        } else {
            i--;  // No se usó la moneda i, pasamos a la anterior
        }
    }
    
    return solucion;
}

int main() {
    vector<int> monedas = {1, 4, 6};  // Tipos de monedas
    int N = monedas.size();            // Número de tipos de monedas
    int M = 8;                         // Cantidad a devolver

    // Obtener el número mínimo de monedas
    int minMonedas = cambio(monedas, N, M);
    cout << "Número mínimo de monedas necesarias: " << minMonedas << endl;

    // Obtener el vector solución (cuántas monedas de cada tipo usamos)
    vector<int> solucion = vectorSolucion(monedas, N, M);
    cout << "Monedas usadas de cada tipo: ";
    for (int i = 0; i < N; i++) {
        cout << monedas[i] << "c: " << solucion[i] << " ";
    }
    cout << endl;

    return 0;
}
