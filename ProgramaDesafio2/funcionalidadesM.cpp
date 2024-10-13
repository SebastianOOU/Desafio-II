#include <iostream>
#include "clasesPrograma.h"
#include <fstream>
#include <string>
using namespace std;//En el main se piden los datos.

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
//------------------
//CLASE TANQUECENTRAL
TanqueCentral::TanqueCentral(int _codigoIdentE, int capacidad){

    codigoIdentE = _codigoIdentE;
    datos_litros = new int[capacidad];

}

void TanqueCentral::asignarcantLitros(){

    datos_litros = new int[100];

    datos_litros = {123,150,120,200,342,100,110,145};
}
void TanqueCentral::setC_regular(int _cantidad, int _precio){
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

//void TanqueCentral::asignarcantLitros(){



void TanqueCentral::fijarPreciosCom(){

    ifstream archivo;
    ofstream _archivo;
    string array[12] = {"centro", std::to_string(getC_regular2()), std::to_string(getC_premium2()), std::to_string(getC_ecoExtra2())};
    string datos;
    int cont = 4, a = 0;

    archivo.open("C://PruebaC++//preciosCombustible.txt");

    if (archivo.is_open()){

        while(!archivo.eof()){
            getline(archivo,datos);

            if (datos == "centro"){
                a = 3;
                datos = "";
            }else{

                if (a == 0){
                    array[cont] = datos;
                    datos = "";
                    cont++;
                }else{
                    a--;
                }
            }
            if (cont == 12){
                break;
            }
        }
    }else{
        cout << "No se pudo abrir el archivo";
        return;
    }
    archivo.close();

    _archivo.open("C://PruebaC++//preciosCombustible.txt", ios::out);

    for (int i = 0; i < 12; i++){
        _archivo << array[i] << endl;
    }
    _archivo.close();


}
//--------------------
//CLASE SURTIDOR
Surtidor::Surtidor(int _codigoIdentE,int _modelo, string _c_ubicacion){

    codigoIdentE = _codigoIdentE;
    c_ubicacion = _c_ubicacion;
    modelo = _modelo;
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
//----------------
//CLASE TRANSACCION
Transaccion::Transaccion(int _codigoIdentE, int _modelo, int _c_cantidad, int _categoria, int _c_dinero, string _m_pago){
    codigoIdentE = _codigoIdentE;
    modelo = _modelo;
    c_cantidad = _c_cantidad;
    categoria = _categoria;
    c_dinero = _c_dinero;
    m_pago = _m_pago;
}

Transaccion::Transaccion(int _dia, int _mes, int _año, int _horas, int _minutos){
    fecha[0] = _dia;
    fecha[1] = _mes;
    fecha[2] = _año;
    horas[0] = _horas;
    horas[1] = _minutos;
}

void Transaccion::setDat_cliente(string _documento, string _nombre){
    dat_cliente[0] = _documento;
    dat_cliente[1] = _nombre;
}

string Transaccion::getDat_cliente1(){
    return dat_cliente[0];
}

string Transaccion::getDat_cliente2(){
    return dat_cliente[1];
}







