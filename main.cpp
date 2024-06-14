#include <iostream>
#include "cliente.h"
#include <fstream>
using namespace std;

void anadirCliente(banco &b1)
{
    int dni1, anioIngreso1, numeroCliente1, numeroTarjeta1;
    string nombre1, apellido1, tipoCliente1, estado1;

    cout << "Ingresar nombre de cliente" << endl;
    cin >> nombre1;
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

    tarjeta t2(numeroTarjeta1);
    cliente c1(tipoCliente1, anioIngreso1, estado1, numeroCliente1, t2, nombre1, apellido1, dni1);
    b1.agregarCliente(c1);
    cout << "Cliente agregado exitosamente" << endl;
}

transaccion agregar()
{
    int numeroCliente1, numeroTransaccion1, monto1, dia1, mes1, anio1;
    string tipoTransaccion1;

    cout << "Ingrese el numero de cliente que realiza la transaccion: " << endl;
    cin >> numeroCliente1;

    cout << "Ingrese el numero de transaccion: " << endl;
    cin >> numeroTransaccion1;

    cout << "Ingrese el tipo de transaccion (Deposito o Extraccion): " << endl;
    cin >> tipoTransaccion1;

    cout << "Ingrese el monto: " << endl;
    cin >> monto1;

    cout << "Ingrese el dia: " << endl;
    cin >> dia1;

    cout << "Ingrese el mes: " << endl;
    cin >> mes1;

    cout << "Ingrese el anio: " << endl;
    cin >> anio1;

    transaccion tran1(numeroCliente1, numeroTransaccion1 ,monto1, tipoTransaccion1, dia1, mes1, anio1);

    cout << "Agregando transacciones..." << endl;
    tran1.mostrarTransaccion();
    return tran1;
}

void detalleCliente(banco &b1)
{
    int numeroCliente1;
    cout<<"Ingrese numero de cliente"<<endl;
    cin>>numeroCliente1;

    cout<<"Detalle de cliente por numero de cliente"<<endl;
    
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
    cout<<"Ingrese el numero de cliente para ver sus transacciones:";
    cin>>numeroCliente1;

    cout<<"Detalle de cliente por numero de cliente"<<endl;
    
    for (int i = 0; i < b1.getNumeroClientes(); i++)
    {
        if (b1.getTransacciones()[i].getNumeroCliente() == numeroCliente1)
        {
            b1.getTransacciones()[i].mostrarTransaccion();
            cout << "--------------------"<<endl;
        }

    }

}

void mostrarInformes()
{
    cout << "Informes de extracciones y depositos " << endl;
}

void menu()
{
    cout << "1. Agregar cliente" << endl;
    cout << "2. Registrar transacciones" << endl;
    cout << "3. Detalle de cliente por numero de cliente" << endl;
    cout << "4. Listado de todos los clientes del banco" << endl;
    cout << "5. Listado de transacciones por cliente" << endl;
    cout << "6. Informes de extracciones y depositos" << endl;
    cout << "7. Salir" << endl;
}

void cargar(banco &b1){
    ifstream archivoClientes("clientes.txt");
    ifstream archivoTransacciones("transacciones.txt");
    cliente c1;
    transaccion t1;
    int dni1, anioIngreso1, numeroCliente1, numeroTarjeta1;
    string nombre1, apellido1, tipoCliente1, estado1;
    int numeroCliente2,numeroTransaccion1, monto1, dia1, mes1, anio1;
    string tipoTransaccion1;

    while(archivoClientes >> nombre1 >> apellido1 >> dni1 >> tipoCliente1 >> anioIngreso1 >> estado1 >> numeroCliente1 >> numeroTarjeta1){
        tarjeta t2(numeroTarjeta1);
        cliente c1(tipoCliente1, anioIngreso1, estado1, numeroCliente1, t2, nombre1, apellido1, dni1);
        b1.agregarCliente(c1);
        if (tipoCliente1 =="Oro"){
                t2.setLimite(250000);
        } else if (tipoCliente1=="Platino"){
                t2.setLimite(500000);
        } else {
                t2.setLimite(0);
        }
    }

    while(archivoTransacciones >> numeroCliente2 >> numeroTransaccion1 >> monto1 >> tipoTransaccion1 >> dia1 >> mes1 >> anio1){
        transaccion tran1(numeroCliente2, numeroTransaccion1, monto1, tipoTransaccion1, dia1, mes1, anio1);
        b1.agregarTransaccion(tran1);
    }
}

int main()
{
    banco b1(0,0);
    cargar(b1);

    int opcion;
    do
    {
        menu();
        cin >> opcion;
        switch (opcion)
        {
        case 1:
            anadirCliente(b1);
            break;
        case 2:
            agregar();
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
            mostrarInformes();
            break;
        case 7:
            cout << "Saliendo del programa" << endl;
            break;
        default:
            cout << "Opcion no valida" << endl;
            break;
        }
    } while (opcion != 7);

    /*ofstream archivoClientes("clientes.txt");
    ofstream archivoTransacciones("transacciones.txt");*/
}
