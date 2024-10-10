#include <iostream>
using namespace std;

class Estacion{
    private:
        int montoTotal;
        int codigo_iden;
        string nombre;
        string gerente;
        string region;
        string ubicacion;
        int *surtidores = new int[6];//coordenadas 41°24'12.2"N 2°10'26.5"E.
    public:
        void agregarEstacion();
        void eliminarEstacion();
        void calcularMonto();
        void fijarPrecios();
};

class TanqueCentral : public Estacion{
    private:
        int regular;//1
        int premium;//2
        int ecoExtra;//3
    public:
        void agregarLitros();
};

class Surtidor : public TanqueCentral{
    private:
        string codigoIden;
        string modelo;
        string estado;
    public:
        void capturar_datos();
        void agregarSurtidor();
        void eliminarSurtidor();
};

class Transaccion{
    private:
        string metodoPag;
        string fecha;
        string hora;
        string datosCliente;
        int cantCombustible;
        int tipoCombustible;
        int cantDinero;
    public:
        Transaccion(string, string, string, string, int, int, int);
        void capturarDatos();
        void actualizardatos();
        void mostrarTransaccion();
};


int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
