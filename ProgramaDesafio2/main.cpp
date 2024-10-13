#include <iostream>
#include <fstream>
#include <string>
#include "clasesPrograma.h"
using namespace std;
int main(){

    //Surtidor surtudor(104,1234);
    string region;
    int com1, com2, com3;
    cout << "Para que region deceas actualizar los precios: ";
    cin >> region;
    cout << "Precio para regular: ";
    cin >> com1;
    cout << "Precio para Premium: ";
    cin >> com2;
    cout << "Precio para ecoExtra: ";
    cin >> com3;

    TanqueCentral h(101,400);
    h.setC_ecoExtra(0,com3);
    h.setC_regular(0, com1);
    h.setC_premium(0, com2);
    h.fijarPreciosCom();

    //surtudor.mostrarHistorial();
    cout << "Hello World!" << endl;
    //leer_registro_transaccion("archivoRegistros.txt");
    cout << "hola";
    return 0;
}

