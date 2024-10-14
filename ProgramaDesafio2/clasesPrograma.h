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
        int cantidadE;
        int precioSur[3];
        int precioNorte[3];
        int precioCentro[3];
        int *datos_litros;
        int *codigoEstacion;
    public:
        TanqueCentral();//listo
        TanqueCentral(int);
        void fijarPreciosCom();//listo
        void asignarcantLitros();//
        void leerCodigosEstacion();//listo
        void verificarFugas();
        void setCantidadE(int);//listo
        int getCantidadE();//listo

};

class Surtidor{
    private:
        int codigoIdentE;
        string c_ubicacion;
        int modelo;
        int estado;
    public:
        Surtidor(int,int,string _c_ubicacion = "0");//listo
        void eliminarSurtidor();//listo
        void agregarSurtidor();//listo
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
