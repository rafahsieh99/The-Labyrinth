#include <iostream>  // Incluye la librería para las operaciones de entrada/salida.
#include <vector>    // Incluye la librería para usar el contenedor vector.
#include <stack>     // Incluye la librería para usar el contenedor stack (pila).
#include <cstdlib>   // Incluye la librería para funciones generales como rand y srand.
#include <ctime>     // Incluye la librería para obtener la hora del sistema.

using namespace std;  // Permite usar los nombres de las clases y funciones estándar sin el prefijo "std::".

// Clase que representa el Laberinto
class Laberinto {
public:
    // Constructor de la clase Laberinto
    Laberinto(int ancho, int alto) : ancho(ancho), alto(alto) {
        laberinto.resize(alto, vector<char>(ancho, '#'));  // Inicializa el laberinto con muros ('#').
        srand(time(0));  // Establece la semilla para la generación de números aleatorios.
    }

    // Función para generar el laberinto
    void generar() {
        stack<pair<int, int>> pila;  // Crea una pila para el algoritmo de generación del laberinto.
        pila.push({1, 1});  // Empieza en la posición (1, 1).
        laberinto[1][1] = '*';  // Marca el inicio del laberinto.

        // Mientras la pila no esté vacía
        while (!pila.empty()) {
            auto [x, y] = pila.top();  // Obtiene el elemento en la parte superior de la pila.
            vector<pair<int, int>> vecinos;  // Vector para almacenar vecinos válidos.

            // Obtener vecinos en las cuatro direcciones
            if (esValido(x + 2, y)) vecinos.push_back({x + 2, y});  // Abajo
            if (esValido(x - 2, y)) vecinos.push_back({x - 2, y});  // Arriba
            if (esValido(x, y + 2)) vecinos.push_back({x, y + 2});  // Derecha
            if (esValido(x, y - 2)) vecinos.push_back({x, y - 2});  // Izquierda

            // Si hay vecinos válidos
            if (!vecinos.empty()) {
                auto [nx, ny] = vecinos[rand() % vecinos.size()];  // Elige un vecino aleatorio.
                laberinto[(x + nx) / 2][(y + ny) / 2] = '*';  // Elimina la pared entre las celdas.
                laberinto[nx][ny] = '*';  // Marca la nueva celda como parte del laberinto.
                pila.push({nx, ny});  // Añade la nueva celda a la pila.
            } else {
                pila.pop();  // Si no hay vecinos, saca la celda actual de la pila.
            }
        }

        // Asegurar entrada y salida
        laberinto[0][1] = '*';  // Marca la entrada.
        laberinto[alto - 1][ancho - 2] = '*';  // Marca la salida.
    }

    // Función para resolver el laberinto
    void resolver() {
        vector<vector<bool>> visitado(alto, vector<bool>(ancho, false));  // Crea una matriz para celdas visitadas.
        stack<pair<int, int>> camino;  // Pila para almacenar el camino.
        if (dfs(0, 1, camino, visitado)) {  // Llama a la función DFS desde la entrada.
            while (!camino.empty()) {
                auto [x, y] = camino.top();  // Obtiene el elemento en la parte superior de la pila.
                camino.pop();  // Elimina el elemento de la pila.
                if (laberinto[x][y] == '*')
                    laberinto[x][y] = '.';  // Marca el camino correcto con '.'.
            }
        }
    }

    // Función para mostrar el laberinto
    void mostrar() const {
        for (const auto& fila : laberinto) {  // Recorre cada fila del laberinto.
            for (char celda : fila) {  // Recorre cada celda de la fila.
                cout << celda;  // Muestra la celda.
            }
            cout << endl;  // Salto de línea al final de cada fila.
        }
    }

private:
    int ancho, alto;  // Dimensiones del laberinto.
    vector<vector<char>> laberinto;  // Matriz para representar el laberinto.

    // Función para verificar si una celda es válida
    bool esValido(int x, int y) {
        return x > 0 && x < alto - 1 && y > 0 && y < ancho - 1 && laberinto[x][y] == '#';  // Verifica límites y si es un muro.
    }

    // Función de búsqueda en profundidad (DFS) para resolver el laberinto
    bool dfs(int x, int y, stack<pair<int, int>>& camino, vector<vector<bool>>& visitado) {
        if (x == alto - 1 && y == ancho - 2) {  // Si llega a la salida
            camino.push({x, y});  // Añade la salida al camino.
            return true;  // Laberinto resuelto.
        }

        static const vector<pair<int, int>> direcciones = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};  // Direcciones de movimiento.
        visitado[x][y] = true;  // Marca la celda como visitada.
        camino.push({x, y});  // Añade la celda al camino.

        // Recorre cada dirección posible
        for (const auto& [dx, dy] : direcciones) {
            int nx = x + dx, ny = y + dy;
            if (nx >= 0 && nx < alto && ny >= 0 && ny < ancho && !visitado[nx][ny] && laberinto[nx][ny] == '*') {
                if (dfs(nx, ny, camino, visitado)) {  // Llama a DFS recursivamente
                    return true;  // Si encuentra la salida, retorna true.
                }
            }
        }

        camino.pop();  // Si no encuentra la salida, elimina la celda del camino.
        return false;  // Retorna false si no encuentra la salida.
    }
};

int main() {
    int ancho, alto;
    cout << "Ingrese el ancho y alto del laberinto: ";
    cin >> ancho >> alto;  // Lee las dimensiones del laberinto desde la entrada estándar.

    // Asegurar dimensiones impares para la generación del laberinto
    if (ancho % 2 == 0) ancho++;  // Si el ancho es par, lo hace impar.
    if (alto % 2 == 0) alto++;  // Si el alto es par, lo hace impar.

    Laberinto laberinto(ancho, alto);  // Crea una instancia del laberinto.
    laberinto.generar();  // Genera el laberinto.
    cout << "Laberinto generado:" << endl;
    laberinto.mostrar();  // Muestra el laberinto generado.

    laberinto.resolver();  // Resuelve el laberinto.
    cout << "Laberinto resuelto:" << endl;
    laberinto.mostrar();  // Muestra el laberinto resuelto.

    return 0;  // Retorna 0 indicando que el programa finalizó correctamente.
}
