#include <iostream>
#include <stdlib.h>
#include "clasesPrograma.h"
#include <fstream>
#include <string>
using namespace std;

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
