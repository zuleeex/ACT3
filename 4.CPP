#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

void temperaturas(string entrada, string salidaArchivo) {
    ifstream archivo(entrada);
    ofstream salida(salidaArchivo);

    string fecha;
    double temperatura;
    pair<string, double> max, min;

    archivo >> fecha >> temperatura;
    max = min = make_pair(fecha, temperatura);

    while (archivo >> fecha >> temperatura) {
        if (temperatura > max.second) {
            max = make_pair(fecha, temperatura);
        }
        if (temperatura < min.second) {
            min = make_pair(fecha, temperatura);
        }
    }

    salida << "Dia de temperatura maxima: " << max.first << ", " << max.second << endl;
    salida << "Dia de temperatura minima: " << min.first << ", " << min.second << endl;

    archivo.close();
    salida.close();
}

int main() {
    temperaturas("d:/ACT3/4.txt", "d:/ACT3/4salida.txt");
    cout << "Temperaturas extremas procesadas con exito." << endl;
    return 0;
}