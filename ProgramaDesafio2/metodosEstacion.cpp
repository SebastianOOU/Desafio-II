#include <iostream>
#include <stdlib.h>
#include "clasesPrograma.h"
#include <fstream>
#include <string>
using namespace std;

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

Estacion::Estacion(string _codigoIdent){
    codigoIdentE = _codigoIdent;
}

void Estacion::agregarEstacion(){
    //Se abre el archivo en modo añadir texto
    const string rutaArchivo = "C://PruebaC++//datosEstaciones.txt";
    ofstream archivo(rutaArchivo, ios::app); // Abrir el archivo en modo de agregar (append)

    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo." << endl;
        return;
    }
    //Se escriben los datos de la nueva estacion
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

void Estacion::calcularMonto(bool _nacional,int _ltrsCop, bool fugas){

    ifstream archivo;
    string datos, _datos;

    int montoRegular = 0, montoPremium = 0, montoecoExtra = 0, longitud;

    //Se lee el archivo en modo lectura
    archivo.open("C://PruebaC++//archivoRegistros.txt", ios::in);

    //Se verifica que el archivo no tuvo errores
    if(!archivo.is_open()){
        cout << "El archivo no se pudo abrir.";
        return;
    }

    //Mientras no sea el final del archivo
    while(!archivo.eof()){

        getline(archivo,datos);
        longitud = datos.size();
        int contador = 0, opcion = 0;
        //Se recorre cada linea "datos"
        for(int i = 0; i < longitud; i++){

            //Se verifica que el dato fur capturado
            if (datos[i] == '/'){
                contador++;

                //Si los datos a calcular son a nivel de la redo de una estacion especifica
                if (!_nacional){

                    //Verifica si los codigo de la estacion corresponde
                    if (contador == 1 && _datos != codigoIdentE){
                        _datos = "";
                        break;
                    }
                }

                _datos = "";
            }else {
                _datos += datos[i];
            }

            //verifica que esta en el dato "tipo de combustible"
            if (contador == 2){

                //Se valida el tipo de combustible
                if(_datos == "Regular"){
                    opcion = 1;
                }else if(_datos == "Premium"){
                    opcion = 2;
                }else{
                    opcion = 3;
                }
            }

            //Verifica que este en el dato "cantidad de listros o precios" dependiento delo dato de entrada "_ltrsCop"
            if (contador == _ltrsCop){

                //Verifica que este en el dato
                if (datos[i + 1] == '/'){

                    //Se llama la funcion sumarCantidad (sumar los litros o los precios)
                    sumarCantidad(opcion,montoRegular,montoPremium,montoecoExtra,_datos);
                    _datos = "";
                    datos = "";
                    break;
                }

            }
        }
    }
    //Verifica si se necesita verificar las fugas o solo mostrar los datos calculados anteriormente
    if(!fugas){
        mostrarMonto(_ltrsCop,montoRegular,montoPremium,montoecoExtra,_nacional);
    }else{
        verificarFugas(montoRegular,montoPremium,montoecoExtra);
    }


}

void Estacion::reportarCanLitros(bool _nacional){
    //Calcular los datos solo de los litros
    calcularMonto(_nacional,3);
}

void Estacion::mostrarMonto(int opcion, int _regular, int _premium, int _ecoExtra, bool _nacional){
    //Recibe los calculos de cada una de las categorias de combustible y opcion y bool _nacional
    //(Si los datos son a nivel de red o solo de una estacion)
    string a;
    //Se asigna una cadena dependiendo del bool _nacional
    if (_nacional){
        a = "  Valores nivel Nacional TerMax";
    }else{
        a = "  La estacion Identificada: " + codigoIdentE;
    }
    //Se imprimen cada uno de los valores opcion = 4 "Datos precios" != 4 "Datos listros"
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

void Estacion::verificarFugas(int _regular, int _premium, int _ecoExtra){

    ifstream archivo;
    string datos,datosLtrs[7];
    bool opcion1 = true, opcion2 = false;

    //Se lee el archivo en modo lectura
    archivo.open("C://PruebaC++//ltrsCombustibleEs.txt", ios::in);

    //Se verifica que el archivo no tuvo errores
    if(!archivo.is_open()){
        cout << "El archivo no se pudo abrir.";
        return;
    }

    while(!archivo.eof()){
        getline(archivo, datos);
        int longitud  = datos.size(), contador = 0,cont = 0;
        string _datos;

        //Solo se ejecuta hasta que el codigo de la estacion corresponda al ingresado
        if(opcion1){

            //Recorre cada uno de los datos de la linea del archivo "datos"
            for (int i = 0; i < longitud; i++){

                //verifica si el dato se capturo
                if(datos[i] == '/'){
                    cont++;

                    //Si el codigo de la estacion corresponde
                    if(cont == 1 && _datos == codigoIdentE){
                        opcion2 = true;
                        opcion1 = false;
                    }

                    //Si el codigo de la estacion no correponde no hay necesidad de seguir verificando
                    if(cont == 1 && _datos != codigoIdentE){
                        datos = "";
                        break;
                    }
                    //Si es true la codigo de la estacion corresponde
                    if (opcion2){
                        //Captura cada uno de los datos por separado en el array
                        datosLtrs[contador] = _datos;
                        contador++;
                    }
                    _datos = "";

                }else{
                    //Se concatenan los caracteres
                    _datos += datos[i];
                }
            }
        }else{
            break;
        }
    }

    //Se crean variables, y se suma la cantidad de listrosVendidos a los restantes en la estacion
    int ltrsRegular = stoi(datosLtrs[4]) + _regular;
    int ltrsPremium = stoi(datosLtrs[5]) + _premium;
    int ltrsEcoExtra = stoi(datosLtrs[6]) + _ecoExtra;

    //Se suman la cantidad de litros totales al tanque central (informar al usuario los litros faltantes en caso de fuga)
    int resR = stoi(datosLtrs[1]) - ltrsRegular;
    int resP = stoi(datosLtrs[2]) - ltrsPremium;
    int resE = stoi(datosLtrs[3]) - ltrsEcoExtra;

    //Se realiza una regla de tres para el porcentaje de la suma de cada uno de los combustibles
    ltrsRegular = (ltrsRegular * 100) / stoi(datosLtrs[1]);
    ltrsPremium = (ltrsPremium * 100) / stoi(datosLtrs[2]);
    ltrsEcoExtra = (ltrsEcoExtra * 100) / stoi(datosLtrs[3]);

    //Se verifica el porcentaje y segun sea el caso para cada tipo de combustible de la estacion
    //Si el % es menor <= 95 se considera que hay fugas
    cout << "Para la estacion Identificada: " << codigoIdentE << endl;
    if(ltrsRegular > 95){
        cout << "Combustible Regular: no existen fugas" << endl;;
    }else{
        cout << "Combustible Regular: se han perdido " << resR << " ltrs" << endl;
    }

    if(ltrsPremium > 95){
        cout << "Combustible Premium: no existen fugas" << endl;;
    }else{
        cout << "Combustible Premium: se han perdido " << resP << " ltrs" << endl;
    }

    if(ltrsEcoExtra > 95){
        cout << "Combustible ecoExtra: no existen fugas" << endl;;
    }else{
        cout << "Combustible ecoExtra: se han perdido " << resE<< " ltrs" << endl;
    }
}

void Estacion::eliminarEstacion(string nombre){

    ifstream archivoEntrada("C://PruebaC++//datosEstaciones.txt");
    string contenido = "", linea;
    bool borrar = false;
    bool estacionEncontrada = false; // Variable para verificar si se encontró la estación

    if (archivoEntrada.is_open()) {
        while (getline(archivoEntrada, linea)) {
            // Verifica si la línea contiene el nombre de la estación a eliminar
            if (linea.find("estacion:" + nombre) != string::npos) {
                borrar = true; // Inicia el proceso de borrado
                estacionEncontrada = true; // Marca que se encontró la estación
            }

            // Detiene el proceso de borrado cuando encuentra el siguiente '#' (otra estación)
            if (linea.find("#") != string::npos && borrar) {
                borrar = false;
                continue; // Evita agregar el separador '#' después de la estación eliminada
            }

            // Si no se está borrando, añadir al contenido final
            if (!borrar) {
                contenido += linea + "\n";
            }
        }
        archivoEntrada.close();

        // Sobrescribir el archivo con las estaciones restantes
        ofstream archivoSalida("C://PruebaC++//datosEstaciones.txt");
        archivoSalida << contenido;
        archivoSalida.close();

        // Verificar si la estación fue encontrada
        if (!estacionEncontrada) {
            cout << "Estación no existe." << endl;
        }

    } else {
        cout << "No se pudo abrir el archivo." << endl;
    }
    cout << "Estacion eliminada...";

}
