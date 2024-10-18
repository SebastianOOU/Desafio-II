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
    //Se le el arhcivo en modo de añadir texto
    archivo.open("C://PruebaC++//datosSurtidores.txt", ios::app);
    //Se escriben los datos del nuevo surtidor
    archivo << codigoIdentE << "/";
    archivo << modelo << "/";
    archivo << c_ubicacion << "/";
    archivo << getEstado() << endl;

    archivo.close();
    actualizarDatosE(1);//Se actualiza el numero de sustidores
    cout << "Surtidor agregado correctamente..." << endl;
}

void Surtidor::eliminarSurtidor(){

    ifstream archivo, arcHis;
    ofstream _archivo, _arcHis;

    //Se inicializan las variables _datos = datos surtidor a eliminar
    string datos, _datos = codigoIdentE + "/" + modelo + "/" + c_ubicacion + "/" + estado;
    string codigoModelo = codigoIdentE + "/" + modelo + "/", datosHis;

    int contador1 = 0, contador2 = 0, longitud;
    bool a = false;

    //Se abren los archivos en modo lectura
    archivo.open("C://PruebaC++//datosSurtidores.txt", ios::in);
    arcHis.open("C://PruebaC++//archivoRegistros.txt", ios::in);

    //verifica que el archivo no tuvo errores
    if (!archivo.is_open()){
        cout << "No se pudo abrir le archivo" << endl;
        return;
    }
    //verifica que el archivo no tuvo errores
    if (!arcHis.is_open()){
        cout << "No se pudo abrir le archivo" << endl;
        return;
    }

    //Mientras no sea el final del archivo
    while(!archivo.eof()){

        getline(archivo,datos);
        //Verifica si la linea de datos corresponde al surtidor que se decea eliminar
        if (datos == _datos){
            a = true;
            datos = "";
        }else{
            //Si no es igual capturamos esa linea de datos
            datosA[contador1] = datos;
            datos = "";
        }
        contador1++;
    }

    //Si no se encontro el susrtidor, se informa al usuario (no se elimina si esta activo)
    if(!a){
        cout << "----> El surtidor no existe o esta activo, verifique su entrada" << endl;
        return;
    }

    //Mientras no sea el final del archivo
    while(!arcHis.eof()){
        //Se guarda cada linea del archivo en "datos"
        getline(arcHis,datos);
        longitud = datos.length();
        int cont = 0;
        //Se recorre la linea del archivo "datos"
        for (int i = 0; i < longitud; i++){
            //Se verifica el dato
            if (datos[i] == '/'){
                cont++;
            }

            datosHis += datos[i];
            //Indica que esta en el dato que corresponde al modelo del surtidor
            if(cont == 2){
                //Si el dato corresponde no se capturan sus datos
                if(datosHis == codigoModelo){
                    //variable vacia, para nuevos datos
                    datosHis = "";
                    datos = "";
                    break;
                }else{
                    //Si es diferente se capruran esos datos (Hay que eliminar el historial del surtidor)
                    datosH[contador2] = datos;
                    contador2++;
                    //variable vacia, para nuevos datos
                    datosHis = "";
                    datos = "";
                    break;
                }
            }
        }
    }
    //Se cierran los archivos
    archivo.close();
    arcHis.close();
    //Se abren los archivos en modo escritura
    _archivo.open("C://PruebaC++//datosSurtidores.txt", ios::out);
    _arcHis.open("C://PruebaC++//archivoRegistros.txt", ios::out);
    //Se escriben los datos (el surtidor, ha sido eliminado)
    for (int i = 0; i < contador1; i++){
        _archivo << datosA[i] << endl;
    }
    //Se escriben los datos (el historial del surtidor, ha sido eliminado)
    for (int i = 0; i < contador2; i++){
        _arcHis << datosH[i] << endl;
    }

    _archivo.close();
    _arcHis.close();
    actualizarDatosE(-1);//Se actualoiza el numero de sustidores en la estacion
    cout << "Surtidor eliminado..." << endl;
}

void Surtidor::mostrarHistorial(){

    ifstream archivo;
    ofstream _archivo;

    //Se inicializan las variables, codigoModelo = dos primeros datos surtidor
    string datos, _datos, codigoModelo = codigoIdentE + "/" + modelo + "/";
    int contador = 0, longitud;

    //Array con los indicadores que se tienen que mostrar
    string array[10] = {"- Codigo estacion", "- Modelo surtidor","- Tipo combustible", "- Litros vendidos", "- Precio combustible","- Metodo de pago",
                        "- Nombre cliente","- Documento cliente", "- Fecha", "- Hora"};

    //Se lee el archivo en modo lectura
    archivo.open("C://PruebaC++//archivoRegistros.txt", ios::in);


    if (!archivo.is_open()){
        cout << "no se pudo abrir el archivo";
    }
    //Mientras no sea el final del archivo
    while(!archivo.eof()){

        //Se captura cada linea y se guarda en "datos"
        getline(archivo,datos);
        longitud = datos.length();
        int cont = 0;

        //Se recorre la linea de "datos"
        for (int i = 0; i < longitud; i++){

            //Se verifica cada uno de los datos
            if (datos[i] == '/'){
                cont++;
            }

            _datos += datos[i];

            //Se han capturado los primeros dos datos
            if(cont == 2){

                //Se verifican con los datos dos ingresados por usuario
                if(_datos == codigoModelo){

                    //Se capturan los datos (corresponden al surtidor pedido)
                    datosA[contador] = datos;
                    contador++;
                    _datos = "";
                    datos = "";
                    break;
                }else{

                    //No son iguales, No se deben capturar
                    _datos = "";
                    datos = "";
                    break;
                }
            }
        }
    }
    archivo.close();

    //Se abre el archivo en modo escritura.
    //IMPORTANTE: el historial se escribe en un archivo.txt (La consola muestra problemas al imprimir muchos datos)
    _archivo.open("C://PruebaC++//historial.txt", ios::out);

    //Se recorre el array y se escriben los datos
    for (int i = 0; i < contador; i++){

        //Se inicializan las varibles con cada linea de datos y su longitud
        datos = datosA[i];
        longitud = datos.size();
        int _cont = 0;

        //Se recorre la linea
        for (int x = 0; x < longitud; x++){

            //Verifica que se ha capturado el dato
            if(datos[x] == '/'){

                //Se escribe el datos con su respectivo indicador del array
                _archivo << array[_cont] << ": " << _datos << endl;
                _datos = "";
                _cont++;
            }else{

                //Se concatena cada carater de la linea
                _datos += datos[x];
            }
        }
        _archivo << "------------------" << endl;
    }
    _archivo.close();
}

void Surtidor::modificarAcIn(int b){
    //Recibe un identificador para imprimir en pantalla
    ifstream archivo;
    ofstream _archivo;

    //Se inicializan las variables _datos = datos del surtidor
    string datos, _datos = codigoIdentE + "/" + modelo + "/" + c_ubicacion + "/" + getEstado(), _estado, mostrar = "";
    int contador = 0;
    bool a = false;

    //Se alamcena en "mostrar" informacion al usuario y el estado del surtidor
    if (b == 1){
        _estado = "activo";
        mostrar = "Surtidor activado...";
    }else{
        _estado = "inactivo";
        mostrar = "Surtidor desactivado...";
    }

    //Se abre el archivo en modo lectura
    archivo.open("C://PruebaC++//datosSurtidores.txt", ios::in);

    if (!archivo.is_open()){
        cout << "No se pudo abrir le archivo" << endl;
        return;
    }

    while(!archivo.eof()){
        getline(archivo,datos);

        //verifica que la linea "datos" corresponda a los datos del surtidor
        if (datos == _datos){

            //Se cambia el estado del surtidor
            datosA[contador] = codigoIdentE + "/" + modelo + "/" + c_ubicacion + "/" + _estado;
            a = true;
            datos = "";
        }else{
            //Se capturan los datos difrentes
            datosA[contador] = datos;
            datos = "";
        }
        contador++;
    }
    //Si el surtidor no corresponde, se informa
    if(!a){
        cout << "-----> El surtidor no existe o esta " << _estado;
        return;
    }

    archivo.close();

    //Se abre el archivo en modo escritura
    _archivo.open("C://PruebaC++//datosSurtidores.txt", ios::out);

    //Se escriben los datos en el _archivo
    for (int i = 0; i < contador; i++){
        _archivo << datosA[i] << endl;
    }

    _archivo.close();
    cout << mostrar << endl;
}

void Surtidor::actualizarDatosE(int sumRes){

    ifstream archivo;
    ofstream _archivo;

    string datos, _datos;
    bool opcion1 = false, opcion2 = true;
    int contador = 0;

    //Se abre el archivo en modo lectura
    archivo.open("C://PruebaC++//datosEstaciones.txt", ios::in);

    if(!archivo.is_open()){
        cout << "No fue posible abrir el archivo." << endl;
        return;
    }

    while(!archivo.eof()){

        getline(archivo,datos);
        int longitud = datos.size(), cont = 0, numSur;
        string __datos;

        if (opcion1){
            //Se recorre la linea de "datos"
            for(int i = 0; i < longitud; i++){

                //Se verifican cadan uno de los "-" hasta cierta cantidad
                if(datos[i] == '-'){
                    cont++;
                    _datos = "";

                    //Se verifica que la linea corresponda al dato que se busca
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
    _archivo.open("C://PruebaC++//datosEstaciones.txt", ios::out);

    for (int i = 0; i < contador; i++){
        _archivo << datosA[i] << endl;
    }
    _archivo.close();
}

void Surtidor::setEstado(string _estado){
    estado = _estado;
}

string Surtidor::getEstado(){
    return estado;
}

Surtidor::~Surtidor(){
    delete[] datosA;
    delete[] datosH;
}
