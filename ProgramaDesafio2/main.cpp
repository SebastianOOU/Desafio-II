#include <iostream>
#include <fstream>
#include <string>
#include "clasesPrograma.h"
using namespace std;

void menu();
void pedirDatosEstacion(string &, string &, string &, string &, string &);
void pedirDatosSurtidor(string &, string &, string &);

int main(){

    char opcion;
    string codigo, modeloS, ubicacion;
    string nombreE, gerenteE, regionE;

    while(true){
        menu();
        cout << "Que accion deceas realizar?: ";
        cin >> opcion;
        if (opcion == 'a'){

            pedirDatosEstacion(nombreE,codigo,gerenteE,regionE,ubicacion);

            Estacion estacion(nombreE,codigo,gerenteE,regionE,ubicacion);
            estacion.agregarEstacion();

        }else if (opcion == 'b'){

            //estacion.eliminarEstacion();

        }else if (opcion == 'c'){//falta

            Estacion estacion("0", "120","0","0","0");
            estacion.calcularMonto(true);

        }else if (opcion == 'd'){//Falta

            Estacion estacion("0", "120","0","0","0");
            estacion.reportarCanLitros(true);

        }else if (opcion == '1'){

            pedirDatosSurtidor(codigo,modeloS,ubicacion);

            Surtidor surtidor(codigo,modeloS,ubicacion);
            surtidor.setEstado("activo");
            surtidor.agregarSurtidor();
            cout << "Surtidor agregado correctamente";

        }else if (opcion == '2'){

            pedirDatosSurtidor(codigo,modeloS,ubicacion);

            Surtidor surtidor(codigo,modeloS,ubicacion);
            surtidor.setEstado("inactivo");
            surtidor.eliminarSurtidor();

            cout << "Surtidor eliminado..." << endl;

        }else if (opcion == '3'){

            pedirDatosSurtidor(codigo,modeloS,ubicacion);

            Surtidor surtidor(codigo,modeloS,ubicacion);
            surtidor.setEstado("inactivo");
            surtidor.modificarAcIn(1);

            cout << "Surtidor activado..." << endl;

        }else if (opcion == '4'){

            pedirDatosSurtidor(codigo,modeloS,ubicacion);

            Surtidor surtidor(codigo,modeloS,ubicacion);
            surtidor.setEstado("activo");
            surtidor.modificarAcIn(0);

            cout << "Surtidor desactivado..." << endl;

        }else if (opcion == '5'){

            cout << "Ingrese el codigo de la estacion: ";
            cin >> codigo;
            cout << "Ingrese el modelo del surtidor: ";
            cin >> modeloS;

            Surtidor surtidor(codigo,modeloS);
            surtidor.mostrarHistorial();

        }else if (opcion == '6'){

            Estacion estacion("0", "120","0","0","0");
            estacion.reportarCanLitros(false);

        }else if (opcion == '7'){

            Estacion estacion("0", "120","0","0","0");
            estacion.calcularMonto(false);

        }else if (opcion == 'z'){

           // transaccion.simularVenta();
            Transaccion transaccion(120,23,20,"ecoExtra",23000,"debito");
            transaccion.setDat_cliente("Sebas", "12345566");
            transaccion.mostrarRegistroventa();

        }else if (opcion == 'w'){

         //   tanquecentral.verificarFugas();

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
    cout << "Ingrese el nombred e la region: ";
    cin >> _region;
    cout << "Ingrese la ubicacion de la estacion: ";
    cin >> _ubicacion;
}
