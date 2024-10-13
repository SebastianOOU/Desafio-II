#include <iostream>
#include <stdlib.h>
#include "clasesPrograma.h"
#include <fstream>
#include <string>
using namespace std;
//CLASE SURTIDOR
Surtidor::Surtidor(int _codigoIdentE,int _modelo, string _c_ubicacion){

    codigoIdentE = _codigoIdentE;
    c_ubicacion = _c_ubicacion;
    modelo = _modelo;
}

void Surtidor::agregarSurtidor(){

    ofstream archivo;

    archivo.open("C://PruebaC++//datosSurtidores.txt", ios::app);

    archivo << std::to_string(codigoIdentE) << "/";
    archivo << std::to_string(modelo) << "/";
    archivo << c_ubicacion << "/";
    archivo << "activo" << endl;

    archivo.close();
    //Falta actualizar el numero de surtidores en la estacion correspondiente.
}

void Surtidor::eliminarSurtidor(){

    ifstream archivo;
    ofstream _archivo;

    string datos, caracteres;
    string *datos_archivo = new string[300];
    int contador = 0;
    bool opcion;

    archivo.open("C://PruebaC++//datosSurtidores.txt");

    if (archivo.is_open()){
        while(!archivo.eof()){
            getline(archivo, datos);
            datos_archivo[contador] = datos;
            datos = "";
            contador++;
        }
    }else{
        cout << "El archivo no se pudo abrir...";
        return;
    }
    archivo.close();
    _archivo.open("C://PruebaC++//datosSurtidores.txt");
    for (int i = 0; i < contador; i++){
        datos = datos_archivo[i];
        int longitud = datos.size();
        for (int y = 0; y < longitud; y++){
            if (opcion && datos[y] == '/'){
                if (caracteres == std::to_string(modelo)){
                    caracteres = "";
                    opcion = false;
                    break;
                }else{
                    _archivo << datos << endl;
                    caracteres = "";
                    opcion = false;
                    break;
                }
            }
            if (datos[y] == '/'){
                if (caracteres == std::to_string(codigoIdentE)){
                    opcion = true;
                    caracteres = "";
                }else{
                    _archivo << datos << endl;
                    caracteres = "";
                    break;
                }
            }else{
                caracteres += datos[y];
            }
        }
    }
    _archivo.close();
    delete[] datos_archivo;//Falta actulizare el numero de surtidores en la estacion correspondiente
}
void Surtidor::setEstado(int _estado){
    estado = _estado;
}

int Surtidor::getEstado(){
    return estado;
}

void Surtidor::mostrarHistorial(){

    ifstream archivo;
    ofstream _archivo;
    string datos, datostemporal, arcdata[30] = {""};

    archivo.open("C://PruebaC++//archivoRegistros.txt");
    _archivo.open("C://PruebaC++//historial.txt", ios::app);

    string array[10] = {"Codigo estacion", "Modelo","Tipo combustible", "Litros", "Precio combustible","Metodo de pago",
                        "Nombre","Documento", "Fecha", "Hora"};

    bool opcion = false, opcion2 = false;
    int cont = 0, longitud;

    if (archivo.is_open()){

        while(!archivo.eof()){
            getline(archivo,datos);
            longitud = datos.length();

            for (int x = 0; x < longitud; x++){
                datostemporal += datos[x];
                if (datos[x] == '#'){
                    datostemporal = "";

                }else if (datostemporal == std::to_string(codigoIdentE)){
                    opcion = true;
                    datostemporal = "";

                }else if (datostemporal == "/"){
                    datostemporal = "";

                }else if(datostemporal == std::to_string(modelo)){
                    opcion2 = true;
                }
                if (opcion && opcion2){

                    arcdata[cont] = datos;
                    cont++;
                    opcion = false;
                    opcion2 = false;
                    break;
                }
            }
        }
    }else{
        cout << "no se pudo abrir el archivo";
    }
    archivo.close();

    if (arcdata[0] == ""){
        cout << "Datos no encontrados... " << endl;
        return;
    }

    int contador = 0;
    for (int i = 0; i < cont; i++){
        datostemporal = "";
        datos = arcdata[i];
        longitud = datos.length();
        for (int y = 0; y < longitud;y++){
            if (datostemporal == "#"){
                datostemporal = "";
            }else if (datostemporal == "/"){
                datostemporal = "";
            }else{
                if (datos[y] == '/'){
                    _archivo << array[contador] << ": " << datostemporal << endl;
                    datostemporal = "";
                    contador++;
                }
            }
            if (contador == 10){
                contador = 0;
            }
            datostemporal += datos[y];
        }
        _archivo << "\n";
    }
    _archivo.close();
}
