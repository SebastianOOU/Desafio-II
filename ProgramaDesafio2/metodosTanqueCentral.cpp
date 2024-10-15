#include <iostream>
#include <stdlib.h>
#include <fstream>
#include "clasesPrograma.h"
using namespace std;
//CLASE TANQUECENTRAL

TanqueCentral::TanqueCentral(){

    for (int i = 0; i < 3; i++){
        for (int y = 0; y < 3; y++){
            if (i == 0){
                int numero = rand() % 1000 + (1500 * (y + 1));
                precioSur[y] = numero;
            }else if (i == 1){
                int numero = rand() % 1000 + (1200 * (y + 1));
                precioNorte[y] = numero;
            }else{
                int numero = rand() % 1000 + (1600 + (y + 100));
                precioCentro[y] = numero;
            }
        }
    }

    codigoEstacion = new int[60];
    setCantidadE(0);
    //0 - regular, 1 - premium, 2 - ecoExtra
    /*for (int i = 0; i < 3; i++){
        for (int y = 0; y < 3; y++){
            if (i == 0){
                cout << precioSur[y] << endl;
            }else if (i == 1){
                cout << precioNorte[y] << endl;
            }else{
                cout << precioCentro[y] << endl;
            }
        }
    }*/
}

TanqueCentral::TanqueCentral(int capacidad){
    datos_litros = new int[capacidad * 5];
}

/*void TanqueCentral::asignarcantLitros(){

    int contador = 0;
    for(int i = 0; i < cantidadE; i++){
        int codigoE = codigoEstacion[i];
        for(int y = 0; y < 5; y++){
            int num =
        }
    }
}*/

void pedirPrecios(int &a, int &b, int &c){

    cout << "Ingrese el precio para el combustible regular: " <<endl;
    cin >> a;
    cout << "Ingrese el precio para el combustible Premium: " <<endl;
    cin >> b;
    cout << "Ingrese el precio para el combustible ecoExtra: " <<endl;
    cin >> c;
}

void TanqueCentral::fijarPreciosCom(){

    int opcion,P1, P2, P3;
    cout << "A que region quieres actulizar los preicos?\n 1. Sur\n2. Norte\n3.Centro" << endl;
    cin >> opcion;

    switch (opcion) {
        case 1:
            pedirPrecios(P1,P2,P3);
            precioSur[0] = P1;
            precioSur[1] = P2;
            precioSur[2] = P3;
            cout << "Precios para la region Sur Actualizados" << endl;
            break;
        case 2:
            pedirPrecios(P1,P2,P3);
            precioNorte[0] = P1;
            precioNorte[1] = P2;
            precioNorte[2] = P3;
            cout << "Precios para la region Norte Actualizados" << endl;
            break;
        case 3:
            pedirPrecios(P1,P2,P3);
            precioCentro[0] = P1;
            precioCentro[1] = P2;
            precioCentro[2] = P3;
            cout << "Precios para la region Centro Actualizados" << endl;
            break;
        default:
            cout << "La opcion ------> "<< opcion << " no fue encontrada." << endl;
            break;
    }

}

void TanqueCentral::leerCodigosEstacion(){

    ifstream archivo;
    string datos, _datos;

    archivo.open("C://PruebaC++//archivo.txt", ios::in);

    if(!archivo.is_open()){
        cout << "No se pudo abrir el archivo." << endl;
        return;
    }

    while(!archivo.eof()){
        getline(archivo,datos);
        int longitud = datos.size();
        _datos += datos[0];
        _datos += datos[1];
        if (_datos == "--" && datos[2] != '-'){
            _datos = "";
            for(int i = 9; i < longitud; i++){
                _datos += datos[i];
            }
            codigoEstacion[cantidadE] = stoi(_datos);
            cantidadE++;
            _datos = "";
        }else{
            _datos = "";
        }
    }

    cout << codigoEstacion[0];
    cout << codigoEstacion[1];
    archivo.close();

}

void TanqueCentral::setCantidadE(int _a){
    cantidadE = _a;
}

int TanqueCentral::getCantidadE(){
    return cantidadE;
}

/*void TanqueCentral::setC_regular(int _cantidad, int _precio){
    c_regular[0] = _cantidad;
    c_regular[1] = _precio;
}

void TanqueCentral::setC_premium(int _cantidad, int _precio){
    c_premium[0] = _cantidad;
    c_premium[1] = _precio;
}

void TanqueCentral::setC_ecoExtra(int _cantidad, int _precio){
    c_ecoExtra[0] = _cantidad;
    c_ecoExtra[1] = _precio;
}

int TanqueCentral::getC_regular1(){
    return c_regular[0];
}

int TanqueCentral::getC_regular2(){
    return c_regular[1];
}

int TanqueCentral::getC_premium1(){
    return c_premium[0];
}

int TanqueCentral::getC_premium2(){
    return c_premium[1];
}

int TanqueCentral::getC_ecoExtra1(){
    return c_ecoExtra[0];
}

int TanqueCentral::getC_ecoExtra2(){
    return c_ecoExtra[1];
}

void TanqueCentral::fijarPreciosCom(){

}*/

//void TanqueCentral::asignarcantLitros(){)}
