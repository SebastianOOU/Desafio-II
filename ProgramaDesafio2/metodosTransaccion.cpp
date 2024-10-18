#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <fstream>
#include <string>
#include "clasesPrograma.h"
using namespace std;

Transaccion::Transaccion(string _codigoIdentE,string _categoria, string _m_pago){

    codigoIdentE = _codigoIdentE;
    modelo = "0";
    c_cantidad = 0;
    categoria = _categoria;
    c_dinero = 0;
    m_pago = _m_pago;
    datosLtrs = new string[200];

    time_t tiempoActual = time(nullptr);//El puntero no apunta a nada
    tm* tiempoLocal = localtime(&tiempoActual);//Se parten los datos, para su accceso individual

    fecha[0] = tiempoLocal->tm_mday;
    fecha[1]  = tiempoLocal->tm_mon + 1;
    fecha[2] = tiempoLocal->tm_year + 1900;

    horas[0] = tiempoLocal->tm_hour;
    horas[1] = tiempoLocal->tm_min;
}

void Transaccion::setDat_cliente(string _documento, string _nombre){
    dat_cliente[0] = _documento;
    dat_cliente[1] = _nombre;
}

void Transaccion::mostrarRegistroventa(){

    ofstream archivo;

    archivo.open("C://PruebaC++//archivoRegistros.txt", ios::app);

    if(!archivo.is_open()){
        cout << "No se pudo abrir el archivo";
        return;
    }

    archivo << codigoIdentE << "/";
    archivo << modelo << "/";
    archivo << categoria << "/";
    archivo << c_cantidad << "/";
    archivo << c_dinero << "/";
    archivo << m_pago << "/";
    archivo << dat_cliente[0] << "/";
    archivo << dat_cliente[1] << "/";
    archivo << fecha[0] << "-" << fecha[1] << "-" << fecha[2] << "/";
    archivo << horas[0] << ":" << horas[1] << "/" << endl;

    archivo.close();
    cout << "-----------------------" << endl;
    cout << "Codigo estacion: " << codigoIdentE << endl;
    cout << "Modelo del surtidor: " << modelo << endl;
    cout << "Tipo de gasolina: "<< categoria << endl;
    cout << "Cantidad: " <<  c_cantidad << endl;
    cout << "Dinero cobrado: " << c_dinero << endl;
    cout << "Metodo de pago: " << m_pago << endl;
    cout << "Nombre cliente: " << dat_cliente[0] << endl;
    cout << "Documento cliente: " << dat_cliente[1] << endl;
    cout << "Fecha: " << fecha[0] << "-" << fecha[1] << "-" << fecha[2] << endl;
    cout << "Hora: " << horas[0] << ":" << horas[1] << endl;
    cout << "-----------------------" << endl;

}

void Transaccion::actualizarLitros(int listrosComp){

    ifstream archivo;
    ofstream _archivo;

    string datos, datosEs[7];
    bool opcion1 = true, opcion2 = false;
    int contadorL = 0;
    //Se abre el archivo en modo lectura
    archivo.open("C://PruebaC++//ltrsCombustibleEs.txt", ios::in);

    if(!archivo.is_open()){//Verifica si el archivo no tuvo errores
        cout << "No se pudo abrir el archivo";
        return;
    }

    while(!archivo.eof()){//Mientras no sea el final del archivo
        getline(archivo, datos);//Linea por linea
        int longitud  = datos.size(), contador = 0,cont = 0, num;
        string _datos;

        if(opcion1){
            for (int i = 0; i < longitud; i++){

                if(datos[i] == '/'){
                    cont++;
                    //Si el codigo de la estacion es = al codigo ingresado
                    if(cont == 1 && _datos == codigoIdentE){
                        opcion2 = true;
                        opcion1 = false;
                    }
                    //Si el codigo de la estacion es != al codigo ingresado
                    if(cont == 1 && _datos != codigoIdentE){
                        datosLtrs[contadorL] = datos;//Agrega los datos al array
                        datos = "";//variable vacia para capturar la nueva linea
                        contadorL++;
                        break;
                    }
                    //Si el codigo de la estacion es igual
                    if (opcion2){
                        datosEs[contador] = _datos;//Agrega los datos de _datos
                        contador++;
                    }
                    _datos = "";

                }else{
                    _datos += datos[i];
                }
            }
            if(categoria == "Regular" && opcion2){
                num = stoi(datosEs[4]) - listrosComp;//Suma la cantidad vendida a Regular ltrs
                datosEs[4] = std::to_string(num);//Se convierte a string
                opcion1 = false;
            }
            if(categoria == "Premium" && opcion2){
                num = stoi(datosEs[5]) - listrosComp;//Suma la cantidad vendida a Premium ltrs
                datosEs[5] = std::to_string(num);//Se convierte a string
                opcion1 = false;
            }
            if(categoria == "ecoExtra" && opcion2){
                num = stoi(datosEs[6]) - listrosComp;//Suma la cantidad vendida a ecoExtra ltrs
                datosEs[6] = std::to_string(num);//Se convierte a string
                opcion2 = false;
            }
        }else{
            datosLtrs[contadorL] = datos;
            datos = "";
            contadorL++;
        }
    }

    archivo.close();//Cierra el archivo
    //Se abre el archivo en modo de escritura
    _archivo.open("C://PruebaC++//ltrsCombustibleEs.txt", ios::out);
    //Se escriben los datos del array dinamico
    for(int i = 0; i < contadorL; i++){
        _archivo << datosLtrs[i] << endl;
    }
    //Se escriben los datos de la estacion con los litros actualizados
    for(int i = 0; i < 7; i++){
        _archivo << datosEs[i] << "/";
    }
    _archivo << endl;
    _archivo.close();//Cierra el archivo
}

void Transaccion::simularVenta(int a, int b, int c,int e){

    ifstream archivo;

    string datos, _datos;
    bool opcion = false;
    //Se genera un numero aleatorio entre 1 y la cantidad de surtidores de la estacion
    int surtidorA = 1 + rand() % (e - 1), contador = 0, cont = 0;
    //Se genera un numero aleatorio entre 3 y 20 (generar cantidad de listros)
    c_cantidad =  3 + rand() %  + 17;
    //Se verifica la categoria de combustible
    if(categoria == "Regular" ){
        c_dinero = c_cantidad * a;//Se multiplica x los precios (a = regular COP)
    }else if(categoria == "Premium"){
        c_dinero = c_cantidad * b;//Se multiplica x los precios (b = premium COP)
    }else if(categoria == "ecoExtra" ){
        c_dinero = c_cantidad * c;//Se multiplica x los precios (c = ecoExtra COP)
    }else{
        cout << " ---->Dato tipo combustible incorrecto...";
        return;
    }

    archivo.open("C://PruebaC++//datosSurtidores.txt", ios::in);

    if(!archivo.is_open()){
        cout << "No se pudo abrir el archivo";
    }
    //Mientras no sea el final del archivo
    while(!archivo.eof()){

        getline(archivo,datos);
        int longitud = datos.size();
        //Se recorre los datos de la linea del archivo
        for (int i = 0; i < longitud; i++){
            _datos += datos[i];
            if (_datos == codigoIdentE + "/"){
                contador++;
                //Verifica si esta en el surtidor aleatorio (surtidorA)
                if (contador == surtidorA){
                    opcion = true;
                    _datos = "";
                    datos = "";
                    break;
                }
            }
        }
        //True si se esta en el surtidor aleatorio
        if(opcion){
            //Recorremos los datos de la linea del archivo
            for (int i = 0; i < longitud; i++){
                if(datos[i] == '/'){
                    cont++;
                    if(cont == 2){//Hasta optener el modelo del surtidor
                        modelo = _datos;
                        break;
                    }
                    _datos = "";
                }else{
                    _datos += datos[i];
                }
            }
            datos = "";
            break;//Se rompe el bucle while (evitar que revise las demas lineas)
        }else{
            _datos = "";
            datos = "";
        }
    }
    actualizarLitros(c_cantidad);
    mostrarRegistroventa();

}

void Transaccion::verificarEstacion(int &a, int &b){
    //Recibe dos datos enteros por referencia (a y b)
    //a = region de la estacion , b = numero de surtidores de la estacion
    ifstream archivo;
    string datos, _datos, c;

    bool opcion = false;
    //Abrir el archivo en modo lectura
    archivo.open("C://PruebaC++//datosEstaciones.txt", ios::in);

    if(!archivo.is_open()){
        cout << "No se pudo abrir el archivo";
    }
    //Mientras no sea el final del archivo
    while(!archivo.eof()){
        getline(archivo,datos);
        //Se verifica si el codigo ingresado corresponde a la estacion
        if("--codigo:" + codigoIdentE == datos){
            opcion = true;

        }
        //Si es la estacion
        if(opcion){
            //Captura la region de la estacion (sur,norte,centro)
            if(datos[3] == '-' && datos[4] != '-'){
                int a = datos.size();
                //Se captura la region
                for(int i = 11; i < a; i++){
                    _datos += datos[i];
                }
                datos = "";
            }
            //Captura la cantidad de surtidores de la estacion
            if(datos[4] == '-' && datos[5] != '-'){
                int b = datos.size();
                //Se captura los surtidores
                for(int i = 16; i < b; i++){
                    c += datos[i];
                }
                datos = "";
                break;
            }
        }else{
            datos = "";//Variable vacio, para capturar la nueva linea
        }
    }
    //Se verifica la region de la estacion
    if(_datos == "sur"){
        a= 1;
    }else if(_datos == "norte"){
        a = 2;
    }else{
        a = 3;
    }
    b = stoi(c);//Se convierte a entero el numero de surtidores
}

string Transaccion::getDat_cliente1(){
    return dat_cliente[0];
}

string Transaccion::getDat_cliente2(){
    return dat_cliente[1];
}

Transaccion::~Transaccion(){
    delete[] datosLtrs;
}
