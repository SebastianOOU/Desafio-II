#include <iostream>
#include <fstream>
#include <string>
#include "clasesPrograma.h"
using namespace std;

void menu();
void simularVentaEstacion();
void pedirDatosEstacion(string &, string &, string &, string &, string &);
void pedirDatosSurtidor(string &, string &, string &);

int main(){
    srand (time(NULL)); //Para la funcion rand()
    TanqueCentral tanqueCentral;
    char opcion;
    string codigo, modeloS, ubicacion;
    string nombreE, gerenteE, regionE;

    while(true){

        menu();//Mostrar menú
        cout << "Que accion deceas realizar?: ";
        cin >> opcion;

        if (opcion == 'a'){
            //Agregar una nueva estacion
            pedirDatosEstacion(nombreE,codigo,gerenteE,regionE,ubicacion);
            Estacion estacion(nombreE,codigo,gerenteE,regionE,ubicacion);
            estacion.agregarEstacion();

        }else if (opcion == 'b'){

            //estacion.eliminarEstacion();

        }else if (opcion == 'c'){
            //Cantidad COP nivel nacional
            Estacion estacion("none");
            estacion.calcularMonto(true);//True datos Nacionales, 4 verificar solo precios, false verificar fugas

        }else if (opcion == 'd'){
            //Cantidad ltrs nivel nacional
            Estacion estacion("none");
            estacion.reportarCanLitros(true);//True datos Nacionales, 3 verificar solo listros, false verificar fugas

        }else if (opcion == 'e'){
            //Precios nuevos para cada region (Sur,Norte,centro)
            tanqueCentral.fijarPreciosCom();

        }else if (opcion == '1'){
            //Agregar un nuevo surtidor;
            pedirDatosSurtidor(codigo,modeloS,ubicacion);
            Surtidor surtidor(codigo,modeloS,ubicacion);
            surtidor.setEstado("activo");
            surtidor.agregarSurtidor();

        }else if (opcion == '2'){
            //Eliminar surtidor (solo si esta inactivo)
            pedirDatosSurtidor(codigo,modeloS,ubicacion);
            Surtidor surtidor(codigo,modeloS,ubicacion);
            surtidor.setEstado("inactivo");
            surtidor.eliminarSurtidor();

        }else if (opcion == '3'){
            //Activar surtidor (solo si esta inactivo)
            pedirDatosSurtidor(codigo,modeloS,ubicacion);
            Surtidor surtidor(codigo,modeloS,ubicacion);
            surtidor.setEstado("inactivo");
            surtidor.modificarAcIn(1);

        }else if (opcion == '4'){
            //Desactivar surtidor (solo si esta incativo)
            pedirDatosSurtidor(codigo,modeloS,ubicacion);
            Surtidor surtidor(codigo,modeloS,ubicacion);
            surtidor.setEstado("activo");
            surtidor.modificarAcIn(0);

        }else if (opcion == '5'){
            //Muestra el historial del surtidor en un archivo.txt
            cout << "Ingrese el codigo de la estacion: ";
            cin >> codigo;
            cout << "Ingrese el modelo del surtidor: ";
            cin >> modeloS;
            Surtidor surtidor(codigo,modeloS);
            surtidor.mostrarHistorial();

        }else if (opcion == '6'){
            //Cantidad ltrs de cada estacion pedida
            cout << "Ingrese el codigo de la estacion: ";
            cin >> codigo;
            Estacion estacion(codigo);
            estacion.reportarCanLitros(false);//Falso datos Nacionales, 3 verificar solo precios, false para verificar fugas

        }else if (opcion == '7'){
            //cantidad COP de cada estacion pedida
            cout << "Ingrese el codigo de la estacion: ";
            cin >> codigo;
            Estacion estacion(codigo);
            estacion.calcularMonto(false);//Falso datos Nacionales, 4 verificar solo precios, false para verificar fugas

        }else if (opcion == '8'){
            //Se asigna un numero aleatorio para el combustible
            cout << "Ingrese el codigo de la estacion: ";
            cin >> codigo;
            TanqueCentral tanquecentral(codigo);
            tanquecentral.asignarcantLitros();

        }else if (opcion == 'z'){
            //Se simula una venta de combustible
            int a, b;
            string codigo, categoria, metodoPa, nombre, documento;

            cout << "Ingrese el codigo de la estacion: ";
            cin >> codigo;
            cout << "Que combustible quieres usar (Regular, Premium, ecoExtra): ";
            cin >> categoria;
            cout << "Ingrese su metodo de pago: ";
            cin >> metodoPa;
            cout << "Ingrese su nombre: ";
            cin >> nombre;
            cout << "Ingrese su documento: ";
            cin >> documento;

            Transaccion transaccion(codigo,categoria,metodoPa);
            transaccion.setDat_cliente(nombre, documento);

            transaccion.verificarEstacion(a,b);

            if(a == 1){
                transaccion.simularVenta(tanqueCentral.getPrecioSur1(),tanqueCentral.getPrecioSur2(),tanqueCentral.getPrecioSur3(),b);
            }else if(a == 2){
                transaccion.simularVenta(tanqueCentral.getPrecioNorte1(),tanqueCentral.getPrecioNorte2(),tanqueCentral.getPrecioNorte3(),b);
            }else{
                transaccion.simularVenta(tanqueCentral.getPrecioCentro1(),tanqueCentral.getPrecioCentro2(),tanqueCentral.getPrecioCentro3(),b);
            }

        }else if (opcion == 'w'){
            //Se revisa si hay posibles fugas
            cout << "Ingrese el codigo de la estacion: ";
            cin >> codigo;
            Estacion estacion(codigo);
            estacion.calcularMonto(false,3,true);//Falso datos Nacionales,3 verificar solo litros, true para verificar fugas

        }else if (opcion == '0'){

            cout << "Hasta pronto!" << endl;
            break;

        }else{
            cout << "La accion ------> " << opcion << " No fue encontrada..." << endl;
        }
    }
    return 0;
}

void menu(){

    cout << " -----------------------------------------------------------------" << endl;
    cout << "|                  ------>  TerMax  <------                       |" << endl;
    cout << " -----------------------------------------------------------------" << endl;
    cout << "|    Gestion de la red         |       Gestion estacion           |" << endl;
    cout << " -----------------------------------------------------------------" << endl;
    cout << "|  a. Agregar estacion         |    1. Agregar surtidor           |" << endl;
    cout << "|  b. ELiminar estacion        |    2. Eliminar surtidor          |" << endl;
    cout << "|  c. Calcular ventas          |    3. Activar surtidor           |" << endl;
    cout << "|  d. Cantidad listros ventas  |    4. Desactivar surtidor        |" << endl;
    cout << "|  e. Fijar precios com-       |    5. Historico transacciones    |" << endl;
    cout << "|     bustible                 |    6. Cantidad litros vendida    |" << endl;
    cout << "|                              |    7. Calcular Ventas            |" << endl;
    cout << "|                              |    8. Asignar cantidad de litros |" << endl;
    cout << " -----------------------------------------------------------------" << endl;
    cout << "|  z. Simular venta              w. Verificar fugas               |" << endl;
    cout << "|                 - 0. Cerrar programa -                          |" << endl;
    cout << " -----------------------------------------------------------------" << endl;

}

void pedirDatosSurtidor(string &_codigo, string &_modeloS, string &_ubicacion){

    cout << "Ingrese el codigo de la estacion: ";
    cin >> _codigo;
    cout << "Ingrese el modelo del surtidor: ";
    cin >> _modeloS;
    cout << "Ingrese la obicacion del surtidor: ";
    cin >> _ubicacion;
}

void pedirDatosEstacion(string &_nombre, string &_codigo, string &_gerente, string &_region, string &_ubicacion){

    cout << "Ingrese el nombre de la estacion: ";
    cin >> _nombre;
    cout << "Ingrese el codigo Identificador de la estacion: ";
    cin >> _codigo;
    cout << "Ingrese el nombre del gerente: ";
    cin >> _gerente;
    cout << "Ingrese el nombre de la region: ";
    cin >> _region;
    cout << "Ingrese la ubicacion de la estacion: ";
    cin >> _ubicacion;
}


