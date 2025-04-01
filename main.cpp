/*
 * Harold Andres Lancheros Alvarez A00836416
 *
 * Instrucciones:
 * Utilizando la técnica de programación de "algoritmos avaros" y "programación dinámica",
 * escribe en equipos de máximo dos personas, en C++ un programa que resuelve el problema del cambio de monedas.
 *
 * El programa recibe un número entero N, seguido de N valores enteros (uno en cada línea)
 * que representan las diferentes denominaciones disponibles de las monedas.
 * Seguido de esto, el programa recibe dos números enteros: P y Q,
 * (uno en cada línea) por la entrada estándar,
 * que representan P: el precio de un producto dado y Q: es el billete o moneda con el que se paga dicho producto.
 *
 * La salida del programa es una lista de N valores correspondientes
 * al número de monedas de cada denominación, de mayor a menor, una en cada línea,
 * que se tienen que dar para dar el cambio por el producto pagado,
 * primero utilizando programación dinámica y luego utilizando un algoritmo avaro.
 *
 * Complejidad computacional:
 * - El algoritmo de programación dinámica tiene una complejidad de O(N * cambio), donde:
 *   - N es la cantidad de denominaciones de monedas.
 *   - cambio es la cantidad a devolver.
 * - El algoritmo avaro tiene una complejidad de O(N), ya que recorre las denominaciones una sola vez.
 *
 * Correr con:
 * g++ -std=c++17 -o main main.cpp
 * ./main
 *
 */

#include <iostream>
#include <string>

using namespace std;

/**
 * Calcula el valor hash de una cadena utilizando el método polynomial rolling hash function
 * @param cadena La cadena de entrada para calcular el hash
 * @return El valor hash de la cadena
 */
long long calcularHash(string cadena)
{
    int longitud = cadena.length();
    const int PRIMO = 31;
    const int MODULO = 1e9 + 9;
    long long valorHash = 0;
    long long potencia = 1;

    for (int i = 0; i < longitud; i++)
    {
        valorHash = (valorHash + (cadena[i] - 'a' + 1) * potencia) % MODULO;
        potencia = (potencia * PRIMO) % MODULO;
    }

    return valorHash;
}

/**
 * Función principal que lee una cadena de texto y muestra su valor hash
 * @return 0 si el programa se ejecutó correctamente
 */
int main()
{
    string entrada;

    // Leer la cadena de entrada
    getline(cin, entrada);

    // Calcular y mostrar el valor hash
    cout << calcularHash(entrada) << endl;

    return 0;
}