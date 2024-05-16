#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

struct RegistroEmpleado {
    string nombre;
    int horas_trabajadas;
};

void registroHoras(string entrada, string salidaArchivo) {
    ifstream archivo(entrada);
    ofstream salida(salidaArchivo);

    string nombre;
    int horas;
    string linea;

    while (getline(archivo, linea)) {
        istringstream iss(linea);
        iss >> nombre >> horas;
        salida << nombre << " Horas Totales: " << horas << endl;
    }

    archivo.close();
    salida.close();
}

int main() {
    registroHoras("d:/ACT3/6.txt", "d:/ACT3/6salida.txt");
    cout << "Informe de horas generado exitosamente." << endl;
    return 0;
}