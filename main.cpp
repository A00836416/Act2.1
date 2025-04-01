/*
 * Algoritmo de hash, herramienta para calcular valores hash de cadenas de texto.
 * Copyright (C) 2024 Harold Andres Lancheros Alvarez
 * A00836416
 *
 * Este programa es software libre; puede redistribuirlo y/o
 * modificarlo bajo los términos de la Licencia Pública General Reducida GNU
 * tal como está publicada por la Free Software Foundation; ya sea
 * la versión 3 de la Licencia, o (a su elección) cualquier versión posterior.
 *
 * Este programa se distribuye con la esperanza de que sea útil,
 * pero SIN NINGUNA GARANTÍA; sin siquiera la garantía implícita de
 * COMERCIABILIDAD o IDONEIDAD PARA UN PROPÓSITO PARTICULAR. Consulte la GNU
 * Lesser General Public License para más detalles.
 *
 * Debería haber recibido una copia de la Licencia Pública General Reducida GNU
 * junto con este programa; si no es así, escriba a la Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
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

/*
 * Función principal que lee una cadena de texto y muestra su valor hash
 * @return 0 si el programa se ejecutó correctamente
 */
int main()
{
    string entrada;

    getline(cin, entrada);

    cout << calcularHash(entrada) << endl;

    return 0;
}