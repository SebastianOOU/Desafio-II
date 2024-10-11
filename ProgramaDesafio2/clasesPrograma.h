#ifndef CLASESPROGRAMA_H
#define CLASESPROGRAMA_H
#include <iostream>
using namespace std;

class Estacion{
private:
    string nombre;
    int codigoIdentE;
    string gerente;
    string region;
    string ubicacion;
    int c_totalDinero;
public:
    Estacion(string,int,string,string,string);//listo
    void agregarEstacion();//listo
    void eliminarEstacion();
    void setC_totalDinero(int);//listo
    void getC_totalDinero();//listo
    void calcularMonto();
    void mostrarMonto();
    void reportarCanLitros();
};

class TanqueCentral{
private:
    int codigoIdentE;
    int c_regular[2];
    int c_premium[2];//(cantidad litros, precio)
    int c_ecoExtra[2];
public:
    TanqueCentral(int);//listo
    void fijarPreciosCom();
    void asignarcantLitros();
    void verificarFugas();
    void setC_regular(int,int);//listo
    void setC_premium(int,int);//listo
    void setC_ecoExtra(int,int);//listo
    int getC_regular1();int getC_regular2();//listo
    int getC_premium1();int getC_premium2();//listo
    int getC_ecoExtra1();int getC_ecoExtra2();//listo
};

class Surtidor{
private:
    int codigoIdentE;
    string c_ubicacion;
    int modelo;
    int estado;
public:
    void eliminarSurtidor();
    void agregarSurtidor();
    void mostrarHistorial();
};

class Transaccion{
private:
    int codigoIdentE;
    int modelo;
    int fecha[3];
    int horas[2];
    int c_cantidad;
    int categoria;
    string m_pago;
    int c_dinero;
    string dat_cliente[2];
public:
    Transaccion(string, string, string, string, int, int, int);
    void simularVenta();
    void actualizarLitros();
    void mostrarRegistroventa();
};
#endif // CLASESPROGRAMA_H
