#include <iostream>
#include <stdlib.h>
#include <fstream>
#include "clasesPrograma.h"
using namespace std;
//CLASE TANQUECENTRAL

TanqueCentral::TanqueCentral(){
    //Se generan numeros aleatorios para los precios combustible Sur
    for (int i = 0; i < 3; i++){
        //Se genera el numero a medida que i cambie
        int numero = rand() % 1000 + (1500 * (i + 1));
        if(i == 0){
            setPrecioSur1(numero);
        }else if(i == 1){
            setPrecioSur2(numero);
        }else{
            setPrecioSur3(numero);
        }
    }
    //Se generan numeros aleatorios para los precios combustible Norte
    for (int i = 0; i < 3; i++){
        //Se genera el numero a medida que i cambie
        int numero = rand() % 1000 + (1200 * (i + 1));
        if(i == 0){
            setPrecioNorte1(numero);
        }else if(i == 1){
            setPrecioNorte2(numero);
        }else{
            setPrecioNorte3(numero);
        }
    }
    //Se generan numeros aleatorios para los precios combustible Centro
    for (int i = 0; i < 3; i++){
        //Se genera el numero a medida que i cambie
        int numero = rand() % 1000 + (1000 * (i + 1));
        if(i == 0){
            setPrecioCentro1(numero);
        }else if(i == 1){
            setPrecioCentro2(numero);
        }else{
            setPrecioCentro3(numero);
        }
    }
    //Se inicializa el array dinamico
    codigoEstacion = new string[50];
}

TanqueCentral::TanqueCentral(string _codigoIdent){
    codigoIdentE = _codigoIdent;
}

void TanqueCentral::asignarcantLitros(){

    ifstream archivo;
    ofstream _archivo;

    int contador  = 0;
    string datos;
    //Se abre el archivo en modo lectura
    archivo.open("C://PruebaC++//ltrsCombustibleEs.txt", ios::in);
    //Verifica si el archivo no tuvo problemas
    if(!archivo.is_open()){
        cout << "No se pudo abrir el archivo";
        return;
    }
    //Mientras no sea el final del archivo
    while(!archivo.eof()){
        //Se capturan los datos del archivo en datos
        getline(archivo, datos);
        int longitud  = datos.size();
        string _datos;
        //Se recorre la linea de datos de "datos"
        for (int i = 0; i < longitud; i++){
            //Se verifica un nuevo dato
            if(datos[i] == '/'){
                //Si el codigo de la estacion ingresada es diferente
                if( _datos != codigoIdentE){
                    //Se capturan los datos que no corresponden a la estacion seleccionda
                    codigoEstacion[contador] = datos;
                    contador++;
                    datos =  "";
                    break;
                }else{
                    //Si el codigo es igual,los datos son igules No se capturan
                    datos =  "";
                    break;
                }
            }else{
                //Se concatena cada caracter
                _datos += datos[i];
            }
        }
    }
    archivo.close();
    //Se abre el archivo en forma de escritura
    _archivo.open("C://PruebaC++//ltrsCombustibleEs.txt", ios::out);
    //Numeros aleatorios entre 100 y 200
    int num1 = 100 + rand() % 100;
    int num2 = 100 + rand() % 100;
    int num3 = 100 + rand() % 100;

    _archivo << codigoIdentE << "/";
    //Se escribe en el archivo los nuevos listros de combustible para la estacion
    _archivo << std::to_string(num1) << "/" << std::to_string(num2) << "/" << std::to_string(num3) << "/";
    _archivo << std::to_string(num1) << "/" << std::to_string(num2) << "/" << std::to_string(num3) << "/" << endl;
    //Se escriben los datos del arreglo (Los que son diferentes a la estacion seleccionada)
    for (int i = 0; i < contador; i++){
        _archivo << codigoEstacion[i] << endl;
    }
    _archivo.close();
    //Se le informa al usuario la nueva cantidad de litros.
    cout << "Se ha llenado el tanque central: " << endl;
    cout << "Combustible Regular: " << num1 << " ltrs" << endl;
    cout << "Combustible Premium: " << num2 << " ltrs" << endl;
    cout << "Combustible ecoExtra: " << num3 << " ltrs" << endl;
}

void TanqueCentral::fijarPreciosCom(){

    int opcion,P1, P2, P3;
    //Se pide al usuario los nuevos precios para la region (Sur, Norte o centro)
    cout << "A que region quieres actulizar los preicos?\n 1. Sur\n2. Norte\n3.Centro" << endl;
    cin >> opcion;
    cout << "Ingrese el precio para el combustible regular: " <<endl;
    cin >> P1;
    cout << "Ingrese el precio para el combustible Premium: " <<endl;
    cin >> P2;
    cout << "Ingrese el precio para el combustible ecoExtra: " <<endl;
    cin >> P3;

    switch (opcion) {
        case 1:
            //Se actualizan los precios segun la region
            setPrecioSur1(P1);
            setPrecioSur2(P2);
            setPrecioSur3(P3);
            cout << "Precios para la region Sur Actualizados" << endl;
            break;
        case 2:
            //Se actualizan los precios segun la region
            setPrecioNorte1(P1);
            setPrecioNorte2(P2);
            setPrecioNorte3(P3);
            cout << "Precios para la region Norte Actualizados" << endl;
            break;
        case 3:
            //Se actualizan los precios segun la region
            setPrecioCentro1(P1);
            setPrecioCentro2(P2);
            setPrecioCentro3(P3);
            cout << "Precios para la region Centro Actualizados" << endl;
            break;
        default:
            cout << "La opcion ------> "<< opcion << " no fue encontrada." << endl;
            break;
    }

}

//SE INICIALIZAN LOS SETTERS

void TanqueCentral::setPrecioSur1(int a){
    precioSur[0] = a;
}

void TanqueCentral::setPrecioSur2(int a){
    precioSur[1] = a;
}

void TanqueCentral::setPrecioSur3(int a){
    precioSur[2] = a;
}

void TanqueCentral::setPrecioNorte1(int a){
    precioNorte[0] = a;
}

void TanqueCentral::setPrecioNorte2(int a){
    precioNorte[1] = a;
}

void TanqueCentral::setPrecioNorte3(int a){
    precioNorte[2] = a;
}

void TanqueCentral::setPrecioCentro1(int a){
    precioCentro[0] = a;
}

void TanqueCentral::setPrecioCentro2(int a){
    precioCentro[1] = a;
}

void TanqueCentral::setPrecioCentro3(int a){
    precioCentro[2] = a;
}

int TanqueCentral::getPrecioSur1(){
    return precioSur[0];
}

int TanqueCentral::getPrecioSur2(){
    return precioSur[1];
}

int TanqueCentral::getPrecioSur3(){
    return precioSur[2];
}

int TanqueCentral::getPrecioNorte1(){
    return precioNorte[0];
}

int TanqueCentral::getPrecioNorte2(){
    return precioNorte[1];
}

int TanqueCentral::getPrecioNorte3(){
    return precioNorte[2];
}

int TanqueCentral::getPrecioCentro1(){
    return precioCentro[0];
}

int TanqueCentral::getPrecioCentro2(){
    return precioCentro[1];
}

int TanqueCentral::getPrecioCentro3(){
    return precioCentro[2];
}

TanqueCentral::~TanqueCentral(){
    delete[] codigoEstacion;
}
