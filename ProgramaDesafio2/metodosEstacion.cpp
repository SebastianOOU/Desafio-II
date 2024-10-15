#include <iostream>
#include <stdlib.h>
#include "clasesPrograma.h"
#include <fstream>
#include <string>
using namespace std;

bool codigoExiste(const string& codigo, const string& rutaArchivo) {

    ifstream archivo(rutaArchivo);
    string linea;

    while (getline(archivo, linea)) {        
        if (linea.find("--codigo:" + codigo) != string::npos) {// Busca la linea que contiene el codigo
            archivo.close();
            return true;
        }
    }
    archivo.close();
    return false;
}

void sumarCantidad(int _opcion, int &a, int &b, int &c, string cantidad){

    if(_opcion == 1){
        a += stoi(cantidad);
    }else if(_opcion == 2){
        b += stoi(cantidad);
    }else{
        c += stoi(cantidad);
    }
}

Estacion::Estacion(string _nombre, string _codigoIdentE, string _gerente, string _region, string _ubicacion){

    nombre = _nombre;
    codigoIdentE = _codigoIdentE;
    gerente = _gerente;
    region = _region;
    ubicacion = _ubicacion;
}

void Estacion::agregarEstacion(){

    const string rutaArchivo = "C://PruebaC++//archivo.txt";
    ofstream archivo(rutaArchivo, ios::app); // Abrir el archivo en modo de agregar (append)

    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo." << endl;
        return;
    }


    // Solicitar el codigo y verificar que no este en uso
    /*do {
        cout << "Ingrese el codigo de la estacion: ";
        getline(cin, codigo);

        if (codigoExiste(codigo, rutaArchivo)) {
            cout << "El codigo ya existe. Por favor, ingrese uno diferente." << endl;
        }

    } while (codigoExiste(codigo, rutaArchivo)); // Repetir si el codigo ya existe*/

    // Escribir los datos en el archivo con el mismo formato
    archivo << "#" << endl;
    archivo << "-estacion:" << nombre << endl;
    archivo << "--codigo:" << codigoIdentE << endl;
    archivo << "---gerente:" << gerente << endl;
    archivo << "----region:" << region << endl;
    archivo << "-----surtidores:" << getC_totalSurt() << endl;
    archivo << "------ubicacion:" << ubicacion << endl;

    archivo.close();
    cout << "Estacion agregada correctamente." << endl;
}

void Estacion::setC_totalSurt(int _c_surtidores){

    c_surtidores = _c_surtidores;
}

int Estacion::getC_totalSurt(){

    return c_surtidores;
}

void Estacion::calcularMonto(bool _nacional,int _ltrsCop){

    ifstream archivo;
    string datos, _datos;
    int montoRegular = 0, montoPremium = 0, montoecoExtra = 0, longitud;

    archivo.open("C://PruebaC++//archivoRegistros.txt", ios::in);

    if(!archivo.is_open()){
        cout << "El archivo no se pudo abrir.";
        return;
    }

    while(!archivo.eof()){

        getline(archivo,datos);
        longitud = datos.size();
        int contador = 0, opcion = 0;

        for(int i = 0; i < longitud; i++){

            if (datos[i] == '/'){
                contador++;

                if (!_nacional){

                    if (contador == 1 && _datos != codigoIdentE){
                        _datos = "";
                        break;
                    }
                }

                _datos = "";
            }else {
                _datos += datos[i];
            }

            if (contador == 2){

                if(_datos == "Regular"){
                    opcion = 1;
                }else if(_datos == "Premium"){
                    opcion = 2;
                }else{
                    opcion = 3;
                }
            }
            if (contador == _ltrsCop){

                if (datos[i + 1] == '/'){

                    sumarCantidad(opcion,montoRegular,montoPremium,montoecoExtra,_datos);
                    _datos = "";
                    datos = "";
                    break;
                }

            }
        }
    }

    mostrarMonto(_ltrsCop,montoRegular,montoPremium,montoecoExtra,_nacional);
}

void Estacion::reportarCanLitros(bool _nacional){

    calcularMonto(_nacional,3);
}

void Estacion::mostrarMonto(int opcion, int _regular, int _premium, int _ecoExtra, bool _nacional){

    string a;

    if (_nacional){
        a = "  Valores nivel Nacional TerMax";
    }else{
        a = "  La estacion Identificada: " + codigoIdentE;
    }

    if(opcion == 4){

        cout << a << endl;
        cout << "  Se muestra el monto de sus ventas: " << endl;
        cout << "  - Combustible Regular: " << _regular << " COP" << endl;
        cout << "  - Combustible Premium: " << _premium << " COP" << endl;
        cout << "  - Combustible ecoExtra: " << _ecoExtra << " COP" << endl;
    }else{

        cout << a << endl;
        cout << "  Se muestra la cantidad de litros vendida: " << endl;
        cout << "  - Combustible Regular: " << _regular << " Ltrs" << endl;
        cout << "  - Combustible Premium: " << _premium << " Ltrs" << endl;
        cout << "  - Combustible ecoExtra: " << _ecoExtra << " Ltrs" << endl;
    }
}
