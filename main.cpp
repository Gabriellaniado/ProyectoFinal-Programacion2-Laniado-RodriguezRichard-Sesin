#include <iostream>
#include "cliente.h"
#include <fstream>
using namespace std;

void anadirCliente(banco &b1, fstream &archivoClientes)
{
    int dni1, anioIngreso1, numeroCliente1, numeroTarjeta1;
    string nombre1, apellido1, tipoCliente1, estado1;
    float cajaPesos1, cajaDolares1;

    cout << "Ingresar nombre de cliente" << endl;
    cin >> nombre1;
    cout << "Ingresar apellido de cliente" << endl;
    cin >> apellido1;
    cout << "Ingrese numero de cliente" << endl;
    cin >> numeroCliente1;
    cout << "Ingresar tipo de cliente" << endl;
    cin >> tipoCliente1;
    cout << "Ingresar DNI de cliente" << endl;
    cin >> dni1;
    cout << "Ingresar anio de ingreso" << endl;
    cin >> anioIngreso1;
    cout << "Ingresar estado del cliente" << endl;
    cin >> estado1;
    cout << "Ingrese el numero de tarjeta del cliente" << endl;
    cin >> numeroTarjeta1;
    cout << "Ingrese el saldo de la caja de ahorro en pesos:" << endl;
    cin >> cajaPesos1;
    cout << "Ingrese el saldo de la caja de ahorros en dolares: " << endl;
    cin >> cajaDolares1;

    tarjeta t2(numeroTarjeta1);
    if (tipoCliente1 == "Oro")
    {
        t2.setLimite(250000);
    }
    else if (tipoCliente1 == "Platino")
    {
        t2.setLimite(500000);
    }
    else
    {
        t2.setLimite(0);
    }
    cliente c1(tipoCliente1, anioIngreso1, estado1, numeroCliente1, t2, cajaPesos1, cajaDolares1, nombre1, apellido1, dni1);
    b1.agregarCliente(c1);
    archivoClientes <<endl;
    archivoClientes << nombre1 << " " << apellido1 << " " << dni1 << " " << tipoCliente1 << " " << anioIngreso1 << " " << estado1 << " " << numeroCliente1 << " " << numeroTarjeta1 << " " << cajaPesos1 << " " << cajaDolares1 << endl;
    cout << "Cliente agregado exitosamente" << endl;
}

transaccion agregar(banco &b1, fstream &archivoTransacciones)
{
    int numeroCliente1, numeroTransaccion1, monto1, dia1, mes1, anio1;
    string tipoTransaccion1, cajaAhorro1;

    cout << "Ingrese el numero de cliente que realiza la transaccion: " << endl;
    cin >> numeroCliente1;

    cout << "Ingrese el numero de transaccion: " << endl;
    cin >> numeroTransaccion1;

    cout << "Ingrese el tipo de transaccion (Deposito o Extraccion): " << endl;
    cin >> tipoTransaccion1;

    cout << "Ingrese el tipo de caja donde desea realizar la operacion: " << endl;
    cin >> cajaAhorro1;

    cout << "Ingrese el monto: " << endl;
    cin >> monto1;

    cout << "Ingrese el dia: " << endl;
    cin >> dia1;

    cout << "Ingrese el mes: " << endl;
    cin >> mes1;

    cout << "Ingrese el anio: " << endl;
    cin >> anio1;

    transaccion tran1(numeroCliente1, numeroTransaccion1, monto1, tipoTransaccion1, dia1, mes1, anio1, cajaAhorro1);

    archivoTransacciones <<"\n" << numeroCliente1 << " " << numeroTransaccion1 << " " << cajaAhorro1 << " " << monto1 << " " << tipoTransaccion1 << " " << dia1 << " " << mes1 << " " << anio1 << endl;

    b1.agregarTransaccion(tran1);
    cout << "Agregando transacciones..." << endl;
    tran1.mostrarTransaccion();
    return tran1;
}

void detalleCliente(banco &b1)
{
    int numeroCliente1;
    cout << "Ingrese numero de cliente" << endl;
    cin >> numeroCliente1;

    cout << "Detalle de cliente por numero de cliente" << endl;

    for (int i = 0; i < b1.getNumeroClientes(); i++)
    {
        if (b1.getClientes()[i].getNumeroCliente() == numeroCliente1)
        {
            b1.getClientes()[i].mostrarCliente();
        }
    }
}

void listarClientes(banco b1)
{
    cout << "Listado de clientes: " << endl;

    for (int i = 0; i < b1.getNumeroClientes(); i++)
    {
        cout << "Cliente " << i + 1 << endl;
        b1.getClientes()[i].mostrarCliente();
    }
}

void listarTrans(banco b1)
{
    int numeroCliente1;
    cout << "Ingrese el numero de cliente para ver sus transacciones:";
    cin >> numeroCliente1;

    cout << "Detalle de cliente por numero de cliente" << endl;

    for (int i = 0; i < b1.getNumeroClientes(); i++)
    {
        if (b1.getTransacciones()[i].getNumeroCliente() == numeroCliente1)
        {
            b1.getTransacciones()[i].mostrarTransaccion();
            cout << "--------------------" << endl;
        }
    }
}

void mostrarInformes(banco &b1)
{
    int criterio, mes, anio;
    cout << "Seleccione el criterio de informe: " << endl;
    cout << "1. En un mes particular" << endl;
    cout << "2. Por anio" << endl;
    cout << "3. Todas las operaciones " << endl;
    cin >> criterio;

    switch (criterio)
    {
    case 1:
        cout << "Informe de transacciones por mes: " << endl;
        cout << "Ingrese el mes: " << endl;
        cin >> mes;
        cout << "Ingrese el anio: " << endl;
        cin >> anio;
        for (int i = 0; i < b1.getNumeroTransacciones(); i++)
        {
            if (b1.getTransacciones()[i].getMes() == mes && b1.getTransacciones()[i].getAnio() == anio)
            {
                b1.getTransacciones()[i].mostrarTransaccion();
            }
        }
        break;
    case 2:
        cout << "Informe de transacciones por anio" << endl;
        cout << "Ingrese el anio: " << endl;
        cin >> anio;
        for (int i = 0; i < b1.getNumeroTransacciones(); i++)
        {
            if (b1.getTransacciones()[i].getAnio() == anio)
            {
                b1.getTransacciones()[i].mostrarTransaccion();
            }
        }
        break;
    case 3:
        cout << "Todas las operaciones: " << endl;
        b1.listarTransacciones();
        break;
    }
}

void bajaAlta(banco &b1)
{
    int numeroCliente1;
    cout << "Ingrese el numero de cliente que desea dar de baja/alta: " << endl;
    cin >> numeroCliente1;

    cout << "Seleccione la opcion que desea realizar: " << endl;
    cout << "1. Dar de baja" << endl;
    cout << "2. Dar de alta" << endl;

    int opcion;
    cin >> opcion;

    switch (opcion)
    {
    case 1:
        for (int i = 0; i < b1.getNumeroClientes(); i++)
        {
            if (b1.getClientes()[i].getNumeroCliente() == numeroCliente1)
            {
                b1.getClientes()[i].setEstado("Baja");
            }
        }
        cout << "Dando de baja..." << endl;
        break;
    case 2:
        for (int i = 0; i < b1.getNumeroClientes(); i++)
        {
            if (b1.getClientes()[i].getNumeroCliente() == numeroCliente1)
            {
                b1.getClientes()[i].setEstado("Alta");
            }
        }
        cout << "Dando de alta..." << endl;
        break;
    }
}
void menu()
{
    cout << "1. Agregar cliente" << endl;
    cout << "2. Registrar transacciones" << endl;
    cout << "3. Detalle de cliente por numero de cliente" << endl;
    cout << "4. Listado de todos los clientes del banco" << endl;
    cout << "5. Listado de transacciones por cliente" << endl;
    cout << "6. Informes de extracciones y depositos" << endl;
    cout << "7. Dar de baja/alta" << endl;
    cout << "8. Salir" << endl;
}

void cargar(banco &b1, fstream &archivoClientes, fstream &archivoTransacciones)
{
    cliente c1;
    transaccion t1;
    int dni1, anioIngreso1, numeroCliente1, numeroTarjeta1;
    string nombre1, apellido1, tipoCliente1, estado1, tipoTransaccion1, cajaAhorro1;
    float cajaPesos1, cajaDolares1;
    int numeroCliente2, numeroTransaccion1, monto1, dia1, mes1, anio1;

    while (archivoClientes >> nombre1 >> apellido1 >> dni1 >> tipoCliente1 >> anioIngreso1 >> estado1 >> numeroCliente1 >> numeroTarjeta1 >> cajaPesos1 >> cajaDolares1)
    {
        tarjeta t2(numeroTarjeta1);
        cliente c1(tipoCliente1, anioIngreso1, estado1, numeroCliente1, t2, cajaPesos1, cajaDolares1, nombre1, apellido1, dni1);
        b1.agregarCliente(c1);
        if (tipoCliente1 == "Oro")
        {
            t2.setLimite(250000);
        }
        else if (tipoCliente1 == "Platino")
        {
            t2.setLimite(500000);
        }
        else
        {
            t2.setLimite(0);
        }
    }
    while (archivoTransacciones >> numeroCliente2 >> numeroTransaccion1 >> cajaAhorro1 >> monto1 >> tipoTransaccion1 >> dia1 >> mes1 >> anio1)
    {
        transaccion tran1(numeroCliente2, numeroTransaccion1, monto1, tipoTransaccion1, dia1, mes1, anio1, cajaAhorro1);
        b1.agregarTransaccion(tran1);
    }
}

int main()
{
    banco b1(0, 0);
    fstream archivoClientes;
    if (archivoClientes.fail())
    {
        cout << "No hay clientes registrados" << endl;
        ofstream archivoClientes("clientes.txt");
    }
    fstream archivoTransacciones("transacciones.txt", ios::in | ios::out | ios::app);
    if (archivoTransacciones.fail())
    {
        cout << "No hay transacciones registradas" << endl;
        ofstream archivoTransacciones("transacciones.txt");

    }

    cargar(b1, archivoClientes, archivoTransacciones);

    int opcion;
    do
    {
        menu();
        cin >> opcion;
        switch (opcion)
        {
        case 1:
            archivoClientes.open("clientes.txt", ios::in | ios::out | ios::app);
            anadirCliente(b1, archivoClientes);
            archivoClientes.close();
            break;
        case 2:
            archivoTransacciones.open("transacciones.txt");
            agregar(b1, archivoTransacciones);
            archivoTransacciones.close();
            break;
        case 3:
            detalleCliente(b1);
            break;
        case 4:
            listarClientes(b1);
            break;
        case 5:
            listarTrans(b1);
            break;
        case 6:
            mostrarInformes(b1);
            break;
        case 7:
            bajaAlta(b1);
        case 8:
            cout << "Saliendo del programa" << endl;
            break;
        default:
            cout << "Opcion no valida" << endl;
            break;
        }
    } while (opcion != 8);
}
