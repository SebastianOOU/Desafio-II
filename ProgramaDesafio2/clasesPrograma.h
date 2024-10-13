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
        int c_surtidores;
    public:
        Estacion(string,int,string,string,string);//listo
        void agregarEstacion();//listo
        void eliminarEstacion();
        void setC_totalSurt(int);//listo
        int getC_totalSurt();//listo
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
        int *datos_litros;
    public:
        TanqueCentral(int, int);//listo
        int precioSur[3];
        int precioNorte[3];
        int precioCentro[3];
        void fijarPreciosCom();//listo
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
        Surtidor(int,int,string _c_ubicacion = "0");//listo
        void eliminarSurtidor();
        void agregarSurtidor();
        void mostrarHistorial();//listo
        void setEstado(int);//listo
        int getEstado();//listo
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
        Transaccion(int,int,int,int,int,string);//listo
        Transaccion(int,int,int,int,int);//listo
        void simularVenta();
        void actualizarLitros();
        void mostrarRegistroventa();
        void setDat_cliente(string,string);//listo
        string getDat_cliente1();//listo
        string getDat_cliente2();//listo
};
#endif // CLASESPROGRAMA_H
