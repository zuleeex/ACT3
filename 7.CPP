#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>

using namespace std;

void resumen_errores(string entrada, string salidaArchivo) {
    ifstream archivo(entrada);
    ofstream salida(salidaArchivo);

    unordered_map<string, int> conteo_errores;

    string error;

    while (getline(archivo, error)) {
        conteo_errores[error]++;
    }

    for (const auto& par : conteo_errores) {
        salida << par.first << ": " << par.second << endl;
    }

    archivo.close();
    salida.close();
}

int main() {
    resumen_errores("d:/ACT3/7.log", "d:/ACT3/7salida.txt");
    cout << "Resumen de errores generado exitosamente." << endl;
    return 0;
}