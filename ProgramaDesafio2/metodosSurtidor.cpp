#include <iostream>
#include <stdlib.h>
#include "clasesPrograma.h"
#include <fstream>
#include <string>
using namespace std;



Surtidor::Surtidor(string _codigoIdentE,string _modelo, string _c_ubicacion){

    codigoIdentE = _codigoIdentE;
    c_ubicacion = _c_ubicacion;
    modelo = _modelo;
    datosA = new string [400];
    datosH = new string [400];
}

void Surtidor::agregarSurtidor(){

    ofstream archivo;

    archivo.open("C://PruebaC++//datosSurtidores.txt", ios::app);

    archivo << codigoIdentE << "/";
    archivo << modelo << "/";
    archivo << c_ubicacion << "/";
    archivo << getEstado() << endl;

    archivo.close();
    actualizarDatosE(1);
    //Falta actualizar el numero de surtidores en la estacion correspondiente.
}

void Surtidor::eliminarSurtidor(){

    ifstream archivo, arcHis;
    ofstream _archivo, _arcHis;

    string datos, _datos = codigoIdentE + "/" + modelo + "/" + c_ubicacion + "/" + estado;
    string codigoModelo = codigoIdentE + "/" + modelo + "/", datosHis;
    int contador1 = 0, contador2 = 0, longitud;
    bool a = false;

    archivo.open("C://PruebaC++//datosSurtidores.txt", ios::in);
    arcHis.open("C://PruebaC++//archivoRegistros.txt", ios::in);

    if (!archivo.is_open()){
        cout << "No se pudo abrir le archivo" << endl;
        return;
    }

    if (!arcHis.is_open()){
        cout << "No se pudo abrir le archivo" << endl;
        return;
    }

    while(!archivo.eof()){

        getline(archivo,datos);
        if (datos == _datos){
            a = true;
            datos = "";
        }else{
            datosA[contador1] = datos;
            datos = "";
        }
        contador1++;
    }

    if(!a){
        cout << "----> El surtidor no existe o esta activo, verifique su entrada" << endl;
        return;
    }

    while(!arcHis.eof()){

        getline(arcHis,datos);
        longitud = datos.length();
        int cont = 0;
        for (int i = 0; i < longitud; i++){

            if (datos[i] == '/'){
                cont++;
            }

            datosHis += datos[i];

            if(cont == 2){

                if(datosHis == codigoModelo){

                    datosHis = "";
                    datos = "";
                    break;
                }else{

                    datosH[contador2] = datos;
                    contador2++;
                    datosHis = "";
                    datos = "";
                    break;
                }
            }
        }
    }

    archivo.close();
    archivo.close();

    _archivo.open("C://PruebaC++//datosSurtidores.txt", ios::out);
    _arcHis.open("C://PruebaC++//archivoRegistros.txt", ios::out);

    for (int i = 0; i < contador1; i++){
        _archivo << datosA[i] << endl;
    }

    for (int i = 0; i < contador2; i++){
        _arcHis << datosH[i] << endl;
    }

    _archivo.close();
    _arcHis.close();
    actualizarDatosE(-1);
}

void Surtidor::setEstado(string _estado){
    estado = _estado;
}

string Surtidor::getEstado(){
    return estado;
}

void Surtidor::mostrarHistorial(){

    ifstream archivo;
    ofstream _archivo;

    string datos, _datos, codigoModelo = codigoIdentE + "/" + modelo + "/";

    string array[10] = {"- Codigo estacion", "- Modelo surtidor","- Tipo combustible", "- Litros vendidos", "- Precio combustible","- Metodo de pago",
                        "- Nombre cliente","- Documento cliente", "- Fecha", "- Hora"};

    archivo.open("C://PruebaC++//archivoRegistros.txt");

    int contador = 0, longitud;

    if (!archivo.is_open()){
        cout << "no se pudo abrir el archivo";
    }

    while(!archivo.eof()){

        getline(archivo,datos);
        longitud = datos.length();
        int cont = 0;
        for (int i = 0; i < longitud; i++){

            if (datos[i] == '/'){
                cont++;
            }

            _datos += datos[i];

            if(cont == 2){

                if(_datos == codigoModelo){

                    datosA[contador] = datos;
                    contador++;
                    _datos = "";
                    datos = "";
                    break;
                }else{

                    _datos = "";
                    datos = "";
                    break;
                }
            }
        }
    }
    archivo.close();

    _archivo.open("C://PruebaC++//historial.txt", ios::out);

    /*if (arcdata[0] == ""){
        cout << "Datos no encontrados... " << endl;
        return;
    }*/

    for (int i = 0; i < contador; i++){

        datos = datosA[i];
        longitud = datos.size();
        int _cont = 0;

        for (int x = 0; x < longitud; x++){

            if(datos[x] == '/'){

                _archivo << array[_cont] << ": " << _datos << endl;
                _datos = "";
                _cont++;
            }else{
                _datos += datos[x];
            }
        }
        _archivo << "------------------" << endl;
    }
    _archivo.close();
}

void Surtidor::modificarAcIn(int b){

    ifstream archivo;
    ofstream _archivo;

    string datos, _datos = codigoIdentE + "/" + modelo + "/" + c_ubicacion + "/" + estado, _estado;
    int contador = 0;
    bool a = false;

    if (b == 1){
        _estado = "activo";
    }else{
        _estado = "inactivo";
    }

    archivo.open("C://PruebaC++//datosSurtidores.txt", ios::in);

    if (!archivo.is_open()){
        cout << "No se pudo abrir le archivo" << endl;
        return;
    }

    while(!archivo.eof()){
        getline(archivo,datos);
        if (datos == _datos){
            datosA[contador] = codigoIdentE + "/" + modelo + "/" + c_ubicacion + "/" + _estado;
            a = true;
            datos = "";
        }else{
            datosA[contador] = datos;
            datos = "";
        }
        contador++;
    }

    if(!a){
        cout << "-----> El surtidor no existe o esta " << _estado;
        return;
    }

    archivo.close();
    _archivo.open("C://PruebaC++//datosSurtidores.txt", ios::out);

    for (int i = 0; i < contador; i++){
        _archivo << datosA[i] << endl;
    }

    _archivo.close();
}

void Surtidor::actualizarDatosE(int sumRes){

    ifstream archivo;
    ofstream _archivo;
    string datos, _datos;
    bool opcion1 = false, opcion2 = true;
    int contador = 0;
    archivo.open("C://PruebaC++//archivo.txt", ios::in);

    if(!archivo.is_open()){
        cout << "No fue posible abrir el archivo." << endl;
        return;
    }

    while(!archivo.eof()){

        getline(archivo,datos);
        int longitud = datos.size(), cont = 0, numSur;
        string __datos;
        if (opcion1){

            for(int i = 0; i < longitud; i++){

                if(datos[i] == '-'){
                    cont++;
                    _datos = "";
                    if (datos[i + 1] != '-' && cont != 5){
                        datosA[contador] = datos;
                        datos = "";
                        break;
                    }
                }


                if (opcion2){
                    __datos += datos[i];
                }

                _datos += datos[i];

                if (cont == 5){

                    if (datos[i] == ':'){

                        _datos = "";
                        opcion2 = false;
                    }
                    if (i == longitud - 1){

                        numSur = stoi(_datos);
                        numSur = numSur + sumRes;
                        __datos += std::to_string(numSur);
                        datosA[contador] = __datos;
                        opcion1 = false;
                        datos = "";
                    }
                }
            }
            contador++;
        }else if(datos == "--codigo:" + codigoIdentE){
            opcion1 = true;
            datosA[contador] = datos;
            contador++;
            datos = "";
        }else{
            datosA[contador] = datos;
            contador++;
            datos = "";
        }

    }

    archivo.close();
    _archivo.open("C://PruebaC++//archivo.txt", ios::out);

    for (int i = 0; i < contador; i++){
        _archivo << datosA[i] << endl;
    }
    _archivo.close();
}

Surtidor::~Surtidor(){
    delete[] datosA;
    delete[] datosH;
}
