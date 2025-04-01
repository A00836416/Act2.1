/*
 * Algoritmo de hash para cadenas de texto
 * Copyright (C) 2024 Harold Andres Lancheros Alvarez
 * A00836416
 *
 * Este programa es software libre; puede redistribuirlo y/o modificarlo
 * bajo los términos establecidos para trabajos académicos. Este programa
 * se distribuye con la esperanza de que sea útil, pero SIN NINGUNA GARANTÍA.
 *
 * El programa implementa un algoritmo de hash (polynomial rolling hash function)
 * para calcular el valor hash de cadenas de texto ingresadas por el usuario.
 *
 * Fecha: 06-03-2025
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