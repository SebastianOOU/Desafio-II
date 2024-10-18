#ifndef CLASESPROGRAMA_H
#define CLASESPROGRAMA_H
#include <iostream>
using namespace std;

class Estacion{
    private:
        string nombre;
        string codigoIdentE;
        string gerente;
        string region;
        string ubicacion;
        int c_surtidores;
    public:
        Estacion(string);
        Estacion(string,string,string,string,string);
        void agregarEstacion();
        void eliminarEstacion(string);
        void verificarFugas(int,int,int);//
        void calcularMonto(bool, int _ltrsCop = 4, bool = false);
        void mostrarMonto(int,int,int,int,bool);//
        void reportarCanLitros(bool);
        void setC_totalSurt(int num = 0);
        int getC_totalSurt();
};

class TanqueCentral{
    private:
        string codigoIdentE;
        int precioSur[3];
        int precioNorte[3];
        int precioCentro[3];
        string *codigoEstacion;
    public:
        TanqueCentral();
        TanqueCentral(string);  
        void fijarPreciosCom();
        void asignarcantLitros();
        void setPrecioSur1(int);int getPrecioSur1();
        void setPrecioSur2(int);int getPrecioSur2();
        void setPrecioSur3(int);int getPrecioSur3();
        void setPrecioNorte1(int);int getPrecioNorte1();
        void setPrecioNorte2(int);int getPrecioNorte2();
        void setPrecioNorte3(int);int getPrecioNorte3();
        void setPrecioCentro1(int);int getPrecioCentro1();
        void setPrecioCentro2(int);int getPrecioCentro2();
        void setPrecioCentro3(int);int getPrecioCentro3();
        ~TanqueCentral();
};

class Surtidor{
    private:
        string codigoIdentE;
        string c_ubicacion;
        string modelo;
        string estado;
    public:
        Surtidor(string,string,string _c_ubicacion = "0");
        string *datosA, *datosH;
        void eliminarSurtidor();
        void agregarSurtidor();
        void mostrarHistorial();
        void modificarAcIn(int);
        void actualizarDatosE(int);
        void setEstado(string);
        string getEstado();
        ~Surtidor();
};

class Transaccion{
    private:
        string codigoIdentE;
        string modelo;
        int fecha[3];
        int horas[2];
        int c_cantidad;
        string categoria;
        string m_pago;
        int c_dinero;
        string dat_cliente[2];
    public:
        string *datosLtrs;
        Transaccion(string,string,string);
        void simularVenta(int,int,int,int);
        void verificarEstacion(int &, int &);
        void actualizarLitros(int);
        void mostrarRegistroventa();
        void setDat_cliente(string,string);
        string getDat_cliente1();
        string getDat_cliente2();
        ~Transaccion();
};
#endif // CLASESPROGRAMA_H
