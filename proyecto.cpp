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
#include "cliente.h"
using namespace std;

persona::persona(){
}

persona::persona(string _nombre, string _apellido, int _DNI){
    nombre = _nombre;
    apellido = _apellido;
    DNI = _DNI;    
}

void persona::setDNI(int _DNI){
    DNI = _DNI;
}   

void persona::setNombre(string _nombre){
    nombre = _nombre;
}

void persona::setApellido(string _apellido){
    apellido = _apellido;
}

int persona::getDNI(){
    return DNI;
}

string persona::getNombre(){
    return nombre;
}

string persona::getApellido(){
    return apellido;
}

void persona::mostrarPersona(){
    cout << "Nombre: " << nombre << endl;
    cout << "Apellido: " << apellido << endl;
    cout << "DNI: " << DNI << endl;
}

transaccion::transaccion(){
}

transaccion::transaccion(int _numeroCliente,int _numeroTransaccion, float _monto, string _tipoTransaccion, int _dia, int _mes, int _anio, string _cajaAhorro){
    numeroCliente= _numeroCliente;
    numeroTransaccion = _numeroTransaccion;
    monto = _monto;
    tipoTransaccion = _tipoTransaccion;
    dia = _dia;
    mes = _mes;
    anio = _anio;
    cajaAhorro=_cajaAhorro; 
}

void transaccion::setNumeroCliente(int _numeroCliente){
    numeroCliente = _numeroCliente;
}

void transaccion::setNumeroTransaccion(int _numeroTransaccion){
    numeroTransaccion = _numeroTransaccion;
}

void transaccion::setMonto(float _monto){
    monto = _monto;
}

void transaccion::setTipoTransaccion(string _tipoTransaccion){
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

void transaccion::setCajaAhorro(string _cajaAhorro){
    cajaAhorro = _cajaAhorro;
}

int transaccion::getNumeroCliente(){
    return numeroCliente;
}

int transaccion::getNumeroTransaccion(){
    return numeroTransaccion;
}

float transaccion::getMonto(){
    return monto;
}

string transaccion::getTipoTransaccion(){
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

string transaccion::getCajaAhorro(){
    return cajaAhorro;
}

void transaccion::mostrarTransaccion(){
    cout << endl;
    cout << "Cliente: " << numeroCliente << endl;
    cout << "Numero de transaccion: " << numeroTransaccion << endl;
    cout << "Monto: " << monto << endl;
    cout << "Tipo de transaccion: " << tipoTransaccion << endl;
    cout << "Caja de ahorro: " << cajaAhorro << endl;
    cout << "Fecha: " << dia << "/" << mes << "/" << anio << endl;
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

void tarjeta::setLimite(int _limite){
    limite = _limite;
}

int tarjeta::getLimite(){
    return limite;
}

personal::personal(){
}

personal::personal(string _nombre, string _apellido, int _DNI, string _cargo):persona(_nombre,_apellido,_DNI){
    cargo = _cargo;
}

void personal::setCargo(string _cargo){
    cargo = _cargo;
}

string personal::getCargo(){
    return cargo;
}

void personal::mostrarPersonal(){
    cout << "Nombre: " << getNombre() << endl;
    cout << "DNI: " << getDNI() << endl;
    cout << "Cargo: " << cargo << endl;
}

cliente::cliente(){
}

cliente::cliente(string _tipoCliente, int _anioIngreso, string _estado, int _numeroCliente, tarjeta _t1,float _cajaPesos,float _cajaDolares,string _nombre, string _apellido, int _DNI):persona(_nombre,_apellido,_DNI){
    tipoCliente = _tipoCliente;
    anioIngreso = _anioIngreso;
    estado = _estado;
    numeroCliente=_numeroCliente;
    t1 = _t1;
    cajaPesos = _cajaPesos;
    cajaDolares = _cajaDolares;
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

void cliente::setNumeroCliente(int _numeroCliente){
    numeroCliente = _numeroCliente;
}

void cliente::setCajaPesos(float _cajaPesos){
    cajaPesos = _cajaPesos;
}

void cliente::setCajaDolares(float _cajaDolares){
    cajaDolares = _cajaDolares;
}

float cliente::getCajaPesos(){
    return cajaPesos;
}

float cliente::getCajaDolares(){
    return cajaDolares;
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

int cliente::getNumeroCliente(){
    return numeroCliente;
}

tarjeta cliente::getTarjeta(){
    return t1;
}

void cliente::mostrarCliente(){
    cout << endl;
    mostrarPersona();
    cout << "Numero de cliente: " << numeroCliente << endl;
    cout << "Tipo de cliente: " << tipoCliente << endl;
    cout << "Anio de ingreso: " << anioIngreso << endl;
    cout << "Estado: " << estado << endl;
    cout << "Caja de ahorro en pesos: " << cajaPesos << endl;
    cout << "Caja de ahorro en dolares: " << cajaDolares << endl;
    t1.mostrarTarjeta();
}

banco::banco(){
}

banco::banco(int _numeroClientes, int _numeroTransacciones){
    numeroClientes = _numeroClientes;
    numeroTransacciones = _numeroTransacciones;
}

void banco::agregarCliente(cliente _cliente){
    clientes[numeroClientes] = _cliente;
    numeroClientes++;
}

void banco::agregarTransaccion(transaccion _transaccion){
    transacciones[numeroTransacciones] = _transaccion;
    numeroTransacciones++;
}

void banco::setNumeroClientes(int _numeroClientes){
    numeroClientes = _numeroClientes;
}

int banco::getNumeroClientes(){
    return numeroClientes;
} 

void banco::setNumeroTransacciones(int _numeroTransacciones){
    numeroTransacciones = _numeroTransacciones;
}

int banco::getNumeroTransacciones(){
    return numeroTransacciones;
}

void banco::setClientes(cliente _cliente[100]){
    for(int i = 0; i < numeroClientes; i++){
        clientes[i] = _cliente[i];
    }
}

cliente* banco::getClientes(){
    return clientes;
}

void banco::setTransacciones(transaccion _transaccion[100]){
    for(int i = 0; i < numeroTransacciones; i++){
        transacciones[i] = _transaccion[100];

    }
}

transaccion* banco::getTransacciones(){
    return transacciones;
}

void banco::darAlta(int dni){
    for(int i = 0; i < numeroClientes; i++){
        if(clientes[i].getDNI() == dni){
            clientes[i].setEstado("Activo");
        }
    } //poner cuando ya esta en alta excpecion
}

void banco::darBaja(int dni){
    for(int i = 0; i < numeroClientes; i++){
        if(clientes[i].getDNI() == dni){
            clientes[i].setEstado("Baja");
        }
    } //poner cuando ya esta de baja excpecion
}

void banco::listarClientes(){
    for(int i = 0; i < numeroClientes; i++){
        clientes[i].mostrarCliente();
    }
}

void banco::listarTransacciones(){
    for(int i = 0; i < numeroTransacciones; i++){
        transacciones[i].mostrarTransaccion();
    }
}


