#include <iostream>
#include <fstream>
#include <string>
#include "clasesPrograma.h"
void menu();
using namespace std;
int main(){

    Estacion estacion;
    TanqueCentral tanquecentral;
    Surtidor surtidor;
    Transaccion transaccion;

    string opcion;

    while(true){
        menu();
        cout << "Que accion deceas realizar?: ";
        cin >> opcion;
        if (opcion == "a"){

            estacion.agregarEstacion();

        }else if (opcion == "b"){

            estacion.eliminarEstacion();

        }else if (opcion == "c"){//falta

        }else if (opcion == "d"){//Falta

        }else if (opcion == "1"){

            surtidor.agregarSurtidor();

        }else if (opcion == "2"){

            surtidor.eliminarSurtidor();

        }else if (opcion == "3"){

            surtidor.modificarAc();

        }else if (opcion == "4"){

            surtidor.modificarIn();

        }else if (opcion == "5"){

            surtidor.mostrarHistorial();

        }else if (opcion == "6"){//Falta

        }else if (opcion == "z"){

            transaccion.simularVenta();

        }else if (opcion == "w"){

            tanquecentral.verificarFugas();

        }else if (opcion == "0"){

            cout << "Hasta pronto!" << endl;
            break;

        }else{
            cout << "La accion ------> " << opcion << " No fue encontrada..." << endl;
        }
    }


    return 0;
}

void menu(){

    cout << " -------------------------------------------------------" << endl;
    cout << "|                        TerMax                         |" << endl;
    cout << " -------------------------------------------------------" << endl;
    cout << "|  Gestion de la red      |     Gestion estacion        |" << endl;
    cout << " -------------------------------------------------------" << endl;
    cout << "| a. Agregar estacion     |  1. Agregar surtidor        |" << endl;
    cout << "| b. ELiminar estacion    |  2. Eliminar surtidor       |" << endl;
    cout << "| c. Calcular ventas      |  3. Activar surtidor        |" << endl;
    cout << "| d. Fijar precios com-   |  4. Desactivar surtidor     |" << endl;
    cout << "|    bustible             |  5. Historico transacciones |" << endl;
    cout << "|                         |  6. Cantidad litros vendida |" << endl;
    cout << " -------------------------------------------------------" << endl;
    cout << "| z. Simular venta           w. Verificar fugas         |" << endl;
    cout << "|               | 0. Cerrar programa |                  |" << endl;
    cout << " -------------------------------------------------------" << endl;

}
