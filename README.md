# The-Labyrinth

Este proyecto implementa un generador y resolutor de laberintos en C++ utilizando algoritmos de búsqueda en profundidad (DFS). El laberinto se genera aleatoriamente y luego se resuelve, mostrando el camino desde la entrada hasta la salida.

## Requisitos

- Compilador C++ compatible con C++11 o superior.

## Compilación y Ejecución

Para compilar y ejecutar el código, sigue estos pasos:

1. Guarda el código en un archivo llamado `laberinto.cpp`.
2. Compila el código fuente:
   ```sh
   g++ -o laberinto laberinto.cpp
## Uso
Al ejecutar el programa, se te pedirá que ingreses las dimensiones del laberinto (ancho y alto). El programa ajustará estas dimensiones a números impares si se ingresan números pares para asegurar que el laberinto se genere correctamente. 
Después de ingresar las dimensiones, el programa generará el laberinto y lo mostrará en la consola. Luego, resolverá el laberinto y mostrará el camino resuelto.

## Estructura del Código
El código está organizado en una clase Laberinto que contiene métodos para generar y resolver el laberinto, así como para mostrarlo.
## Clase Laberinto
### Constructor
Laberinto(int ancho, int alto);
Inicializa el laberinto con muros (#) y establece la semilla de números aleatorios.

### Métodos Públicos
void generar(): Genera el laberinto utilizando una pila y un algoritmo de búsqueda en profundidad.
void resolver(): Resuelve el laberinto utilizando una pila y un algoritmo de búsqueda en profundidad.
void mostrar() const: Muestra el laberinto en la consola.
### Métodos Privados
bool esValido(int x, int y): Verifica si una celda es válida para moverse.
bool dfs(int x, int y, stack<pair<int, int>>& camino, vector<vector<bool>>& visitado): Realiza una búsqueda en profundidad para encontrar un camino desde la entrada hasta la salida.

## Función main
La función main es el punto de entrada del programa. Lee las dimensiones del laberinto, ajusta las dimensiones a impares si es necesario, crea una instancia de Laberinto, genera y resuelve el laberinto, y luego muestra ambos estados (generado y resuelto).

## Ejemplo de salida
Ingrese el ancho y alto del laberinto: 10 10
Laberinto generado:
###########
#*#*#*#*#*#
#*#*#*#*#*#
#*#*#*#*#*#
#*#*#*#*#*#
#*#*#*#*#*#
#*#*#*#*#*#
#*#*#*#*#*#
#*#*#*#*#*#
#*#*#*#*#*#
#*#*#*#*#*#
###########

Laberinto resuelto:
###########
#.*#*#*#*#*
#.*#*#*#*#*
#.*#*#*#*#*
#.*#*#*#*#*
#.*#*#*#*#*
#.*#*#*#*#*
#.*#*#*#*#*
#.*#*#*#*#*
#.*#*#*#*#*
#.*#*#*#*#*
###########
En este ejemplo, * representa los caminos y # los muros. Después de resolver el laberinto, los puntos (.) indican el camino desde la entrada hasta la salida.
