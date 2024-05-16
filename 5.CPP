#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

void procesar_ventas(string entrada, string salidaArchivo) {
    ifstream archivo(entrada);
    ofstream salida(salidaArchivo);

    string fecha;
    int venta;
    pair<int, int> total = {0, 0}; // {total, count}
    pair<string, int> max, min;

    while (archivo >> fecha >> venta) {
        total.first += venta;
        total.second++;
        if (total.second == 1) {
            max = min = make_pair(fecha, venta);
        } else {
            if (venta > max.second) {
                max = make_pair(fecha, venta);
            }
            if (venta < min.second) {
                min = make_pair(fecha, venta);
            }
        }
    }

    double prom = static_cast<double>(total.first) / total.second;

    salida << "Venta total: " << total.first << endl;
    salida << "Promedio de ventas: " << fixed << prom << endl;
    salida << "Dia de mayor venta: " << max.first << ", " << max.second << endl;
    salida << "Dia de menor venta: " << min.first << ", " << min.second << endl;

    archivo.close();
    salida.close();
}

int main() {
    procesar_ventas("d:/ACT3/5.txt", "d:/ACT3/5salida.txt");
    cout << "Ventas procesadas con exito." << endl;
    return 0;
}