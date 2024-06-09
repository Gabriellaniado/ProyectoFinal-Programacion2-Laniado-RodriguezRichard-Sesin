/*
Sistema de Gestión Bancaria
Banco UCC, necesita desarrollar un sistema de gestión que permita realizar el registro y
control de actividades que se llevan a cabo en la institución.
El sistema debe contemplar las siguientes consideraciones:
● Mantener la lista de Clientes. Altas y Bajas (En este caso considerar cambiar el estado
de ACTIVO a BAJA)
● Se deben registrar los siguientes datos correspondientes a los clientes y personal del
banco con sus correspondientes datos:
Clientes (DNI, Nombre, Tipo de Cliente, Año Ingreso, Estado)
● Los datos de Clientes se guardan en archivos de texto.
● Los clientes pueden realizar transacciones en sus cuentas de Caja de Ahorro en Pesos
o en Dólares.
● Las transacciones realizadas por los clientes deben ser registradas en un archivo de
texto.
● Los tipos de transacciones que se pueden realizar en ambas cajas de ahorro pueden
ser:
○ Depósitos
○ Extracciones
● Los clientes pueden acceder a tarjetas de crédito en función de las características del
mismo.
○ Clientes Plata, No tienen acceso a tarjeta de crédito.
○ Clientes Oro, acceden a la tarjeta de crédito Credix con límite de crédito
250000
○ Clientes Platino, acceden a la tarjeta de crédito Premium con límite de crédito
500000
Consideraciones:
El programa debe permitir realizar las siguientes operaciones:
● Registrar las transacciones generadas por Clientes (Extracciones y/o Depósitos).
● Realizar las siguiente consultas:
○ Detalle de Cliente por número de Cliente
○ Listado de todos los clientes del banco
○ Listado de transacciones por clientes
○ Informes de extracciones y depósitos según los siguiente criterios:
■ En un mes determinado
■ En un año determinado
■ Todas las operaciones
*/

#include <iostream>
using namespace std;


class tarjeta{
    private:
        int numeroTarjeta;
    public:
        tarjeta();
        tarjeta(int);
        void setNumeroTarjeta(int);
        int getNumeroTarjeta();
        void mostrarTarjeta();
};

class cliente{
    private:
        int dni;
        string nombre;
        string tipoCliente;
        int anioIngreso;
        string estado;
        tarjeta t1;
    public:
        cliente();
        cliente(int, string, string, int, string, tarjeta);
        void setDni(int);
        void setNombre(string);
        void setTipoCliente(string);
        void setAnioIngreso(int);
        void setEstado(string);
        int getDni();
        string getNombre();
        string getTipoCliente();
        int getAnioIngreso();
        string getEstado();
        void mostrarCliente();
};

class transaccion{
    private:
    int numeroTransaccion;
    int monto;
    int tipoTransaccion;
    int dia;
    int mes;
    int anio;
    int numeroCliente;

    public:
    transaccion();
    transaccion(int, int, int, int, int, int, int);
    void setNumeroTransaccion(int);
    void setMonto(int);
    void setTipoTransaccion(int);
    void setDia(int);
    void setMes(int);
    void setAnio(int);
    void setNumeroCliente(int);

    int getNumeroTransaccion();
    int getMonto();
    int getTipoTransaccion();
    int getDia();
    int getMes();
    int getAnio();
    int getNumeroCliente();

    void mostrarTransaccion();
};

class banco{
    private:
        int numeroClientes;
        int numeroTransacciones;
        cliente clientes[100];
        transaccion transacciones[100];
    public:
        banco();
        banco(int, int);
        void agregarCliente(cliente);
        void agregarTransaccion(transaccion);
        void set
        void listarClientes();
        void listarTransacciones();
        void mostrarInformes();
};

transaccion::transaccion(){
}

transaccion::transaccion(int _numeroTransaccion, int _monto, int _tipoTransaccion, int _dia, int _mes, int _anio, int _numeroCliente){
    numeroTransaccion = _numeroTransaccion;
    monto = _monto;
    tipoTransaccion = _tipoTransaccion;
    dia = _dia;
    mes = _mes;
    anio = _anio;
    numeroCliente = _numeroCliente;
}

void transaccion::setNumeroTransaccion(int _numeroTransaccion){
    numeroTransaccion = _numeroTransaccion;
}

void transaccion::setMonto(int _monto){
    monto = _monto;
}

void transaccion::setTipoTransaccion(int _tipoTransaccion){
    tipoTransaccion = _tipoTransaccion;
}

void transaccion::setDia(int _dia){
    dia = _dia;
}

void transaccion::setMes(int _mes){
    mes = _mes;
}

void transaccion::setAnio(int _anio){
    anio = _anio;
}

void transaccion::setNumeroCliente(int _numeroCliente){
    numeroCliente = _numeroCliente;
}

int transaccion::getNumeroTransaccion(){
    return numeroTransaccion;
}

int transaccion::getMonto(){
    return monto;
}

int transaccion::getTipoTransaccion(){
    return tipoTransaccion;
}

int transaccion::getDia(){
    return dia;
}

int transaccion::getMes(){
    return mes;
}

int transaccion::getAnio(){
    return anio;
}

int transaccion::getNumeroCliente(){
    return numeroCliente;
}

void transaccion::mostrarTransaccion(){
    cout << "Numero de transaccion: " << numeroTransaccion << endl;
    cout << "Monto: " << monto << endl;
    cout << "Tipo de transaccion: " << tipoTransaccion << endl;
    cout << "Fecha: " << dia << "/" << mes << "/" << anio << endl;
    cout << "Numero de cliente: " << numeroCliente << endl;
}


tarjeta::tarjeta(){
}

tarjeta::tarjeta(int _numeroTarjeta){
    numeroTarjeta = _numeroTarjeta;
}

void tarjeta::setNumeroTarjeta(int _numeroTarjeta){
    numeroTarjeta = _numeroTarjeta;
}

int tarjeta::getNumeroTarjeta(){
    return numeroTarjeta;
}

void tarjeta::mostrarTarjeta(){
    cout << "Numero de tarjeta: " << numeroTarjeta << endl;
}

cliente::cliente(){
}

cliente::cliente(int _dni, string _nombre, string _tipoCliente, int _anioIngreso, string _estado, tarjeta _t1){
    dni = _dni;
    nombre = _nombre;
    tipoCliente = _tipoCliente;
    anioIngreso = _anioIngreso;
    estado = _estado;
    t1 = _t1;
}

void cliente::setDni(int _dni){
    dni = _dni;
}

void cliente::setNombre(string _nombre){
    nombre = _nombre;
}

void cliente::setTipoCliente(string _tipoCliente){
    tipoCliente = _tipoCliente;
}

void cliente::setAnioIngreso(int _anioIngreso){
    anioIngreso = _anioIngreso;
}

void cliente::setEstado(string _estado){
    estado = _estado;
}

int cliente::getDni(){
    return dni;
}

string cliente::getNombre(){
    return nombre;
}

string cliente::getTipoCliente(){
    return tipoCliente;
}

int cliente::getAnioIngreso(){
    return anioIngreso;
}

string cliente::getEstado(){
    return estado;
}

void cliente::mostrarCliente(){
    cout << "DNI: " << dni << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Tipo de cliente: " << tipoCliente << endl;
    cout << "Anio de ingreso: " << anioIngreso << endl;
    cout << "Estado: " << estado << endl;
    t1.mostrarTarjeta();
}

 void agregar(){
    int opc2;
    cout<<"Ingrese 1 para deposito o 2 para extraccion:"<<endl;
    cin>>opc2;

    switch(opc2){
        case 1:
        cout<<"Deposito"<<endl;
        break;
        case 2:
        cout<<"Extraccion"<<endl;
        break;
        default:
        cout<<"Opcion no valida"<<endl;
    }
    
    cout<<"Agregando transacciones "<<endl; 
 }

 void detalleCliente(){
    cout<<"Detalle de cliente "<<endl; 
 }

void listarCliente(){
    cout<<"Listado de clientes "<<endl; 
}

void listarTrans(){
    cout<<"Listado de transacciones por cliente "<<endl; 
}

void mostrarInformes(){
    cout<<"Informes de extracciones y depositos "<<endl;
}

int main(){
    tarjeta t1(123456);
    cliente c1(12345678, "Juan Perez", "Plata", 2020, "Activo", t1);
    c1.mostrarCliente();

    int opcion; 
    do{
        cout << "1.Registrar transacciones"<<endl; 
        cout << "2. Detalle de cliente por numero de cliente" << endl;
        cout << "3. Listado de todos los clientes del banco" << endl;
        cout << "4. Listado de transacciones por cliente" << endl;
        cout << "5. Informes de extracciones y depositos" << endl;
        cout << "6. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin>>opcion;
        
        switch (opcion){
            case 1: 
            agregar(); 
            break; 
            case 2: 
            detalleCliente(); 
            break; 
            case 3: 
            listarCliente(); 
            break; 
            case 4:
            listarTrans(); 
            break; 
            case 5: 
            mostrarInformes();
            break; 
            case 6: 
            cout<<"Saliendo del programa "<<endl; 
            break; 
            default: 
            cout<<"Opcion no valida. Intente de nuevo "<<endl;
        } 
        cout<<endl; 
    } while (opcion !=4);
}


