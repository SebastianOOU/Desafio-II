#include <iostream>
#include <fstream>
#include <string>
#include "clasesPrograma.h"
using namespace std;
int main(){
    srand (time(NULL));

    /*TanqueCentral h(101,400);
    h.setC_ecoExtra(0,com3);
    h.setC_regular(0, com1);
    h.setC_premium(0, com2);
    h.fijarPreciosCom();*/
    Surtidor surtidor(567,12345);
    surtidor.mostrarHistorial();

    //surtudor.mostrarHistorial();
    //cout << "Hello World!" << endl;
    //leer_registro_transaccion("archivoRegistros.txt");*/
    //TanqueCentral tanqueCentral;
    //tanqueCentral.fijarPreciosCom();
    //tanqueCentral.fijarPreciosCom();
    //surtidor.eliminarSurtidor();
    cout << "hola";
    return 0;
}

