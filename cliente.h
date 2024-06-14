#include <iostream>
using namespace std;

class persona{
    private:
        string nombre;
        string apellido;
        int DNI;
    public: 
        persona();
        persona(string, string, int);
        void setNombre(string);
        void setApellido(string);
        void setDNI(int);
        string getNombre();
        string getApellido();
        int getDNI();
        void mostrarPersona();
};

class tarjeta
{
private:
    int numeroTarjeta;
    int limite;

public:
    tarjeta();
    tarjeta(int);

    void setNumeroTarjeta(int);
    void setLimite(int);

    int getNumeroTarjeta();
    int getLimite();

    void mostrarTarjeta();
};

class personal : public persona
{
private:
    string cargo;
public:
    personal();
    personal(string,string,int,string);
    void setCargo(string);
    string getCargo();
    void mostrarPersonal();
};

class cliente : public persona
{
private:
    string tipoCliente;
    int anioIngreso;
    string estado;
    int numeroCliente;
    tarjeta t1;

public:
    cliente();
    cliente(string, int, string, int, tarjeta, string, string, int);
    void setTipoCliente(string);
    void setAnioIngreso(int);
    void setEstado(string);
    void setNumeroCliente(int);
    string getTipoCliente();
    int getAnioIngreso();
    int getNumeroCliente();
    string getEstado();
    void mostrarCliente();
};

class transaccion
{
private:
    int numeroCliente;
    int numeroTransaccion;
    int monto;
    string tipoTransaccion;
    int dia;
    int mes;
    int anio;

public:
    transaccion();
    transaccion(int,int, int, string, int, int, int);
    void setNumeroCliente(int);
    void setNumeroTransaccion(int);
    void setMonto(int);
    void setTipoTransaccion(string);
    void setDia(int);
    void setMes(int);
    void setAnio(int);

    int getNumeroCliente();
    int getNumeroTransaccion();
    int getMonto();
    string getTipoTransaccion();
    int getDia();
    int getMes();
    int getAnio();

    void mostrarTransaccion();
};

class banco
{
private:
    int numeroClientes;
    int numeroTransacciones;
    cliente clientes[100];
    transaccion transacciones[100];
    int limite;

public:
    banco();
    banco(int, int);
    void agregarCliente(cliente);
    void agregarTransaccion(transaccion);

    void setNumeroClientes(int);
    int getNumeroClientes();
    void setNumeroTransacciones(int);
    int getNumeroTransacciones();
    void setClientes(cliente _cliente[100]);
    cliente *getClientes();
    void setTransacciones(transaccion _transaccion[100]);
    transaccion *getTransacciones();
    void setLimite(int);
    int getLimite();
    
    void darAlta(int);
    void darBaja(int);
    void listarClientes();
    void listarTransacciones();
    void mostrarInformes();
};
