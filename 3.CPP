#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip> 

using namespace std;

double convertirADolares(double preciosoles) {
    const double conversion = 1 / 3.85; 
    return preciosoles * conversion;
}

int main() {
    ifstream inputFile("d:/ACT3/3.txt");  
    ofstream outputFile("d:/ACT3/3salida.txt"); 

    string line;
    while (getline(inputFile, line)) {
        istringstream iss(line);
        string producto;
        double soles;
		char delim;
		getline(iss, producto, ',');
		iss >> soles;
        double precioDolares = convertirADolares(soles);
        outputFile << producto << ", " << fixed << setprecision(2) << precioDolares << endl;
    }

    inputFile.close();
    outputFile.close();

    cout << "Ok, revisa '3salida.txt'." << endl;

    return 0;
}