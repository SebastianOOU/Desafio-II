#include <iostream>
#include <stdlib.h>
#include "clasesPrograma.h"
#include <fstream>
#include <string>
using namespace std;
//CLASE ESTACION.
/*bool codigoExiste(const string& codigo, const string& rutaArchivo) {
    ifstream archivo(rutaArchivo);
    string linea;

    while (getline(archivo, linea)) {
        // Busca la linea que contiene el codigo
        if (linea.find("--codigo:" + codigo) != string::npos) {
            archivo.close(); // Cierra el archivo despues de leer
            return true; // El codigo ya existe
        }
    }
    archivo.close(); // Cierra el archivo si no se encontro el codigo
    return false; // El codigo no existe
}*/

Estacion::Estacion(string _nombre, int _codigoIdentE, string _gerente, string _region, string _ubicacion){

    nombre = _nombre;
    codigoIdentE = _codigoIdentE;
    gerente = _gerente;
    region = _region;
    ubicacion = _ubicacion;
}

/*void Estacion::agregarEstacion(){

    const string rutaArchivo = "C:\\Users\\LENOVO\\Documents\\termax_proyecto\\datos.txt";
    ofstream archivo(rutaArchivo, ios::app); // Abrir el archivo en modo de agregar (append)

    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo." << endl;
        return;
    }

    // Solicitar los datos de la nueva estacion
    cout << "Ingrese el nombre de la estacion: ";
    getline(cin, estacion);

    // Solicitar el codigo y verificar que no este en uso
    do {
        cout << "Ingrese el codigo de la estacion: ";
        getline(cin, codigo);

        if (codigoExiste(codigo, rutaArchivo)) {
            cout << "El codigo ya existe. Por favor, ingrese uno diferente." << endl;
        }
    } while (codigoExiste(codigo, rutaArchivo)); // Repetir si el codigo ya existe

    cout << "Ingrese el nombre del gerente: ";
    getline(cin, gerente);
    cout << "Ingrese la region: ";
    getline(cin, region);
    cout << "Ingrese la ubicacion (coordenadas): ";
    getline(cin, ubicacion);

    // Escribir los datos en el archivo con el mismo formato
    archivo << "#" << endl;
    archivo << "-estacion:" << nombre << endl;
    archivo << "--codigo:" << codigoIdentE << endl;
    archivo << "---gerente:" << gerente << endl;
    archivo << "----region:" << region << endl;
    archivo << "-----mont_dinero:" << getC_totalDinero(); << endl;
    archivo << "------ubicacion:" << ubicacion << endl;
    archivo << "#" << endl;

    archivo.close();
    cout << "Estacion agregada correctamente." << endl;
}
*/
void Estacion::setC_totalSurt(int _c_surtidores){

    c_surtidores = _c_surtidores;
}

int Estacion::getC_totalSurt(){

    return c_surtidores;
}
