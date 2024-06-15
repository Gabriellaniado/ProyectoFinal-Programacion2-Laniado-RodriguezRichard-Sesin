#include <iostream>
#include "cliente.h"
#include <fstream>
#include <stdexcept>
#include <limits>
using namespace std;

bool validar_fecha(int dia, int mes, int anio)
{
    bool b = anio > 1900 && anio <= 2024 && dia > 0;

    switch (mes)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        return b && dia <= 31;
    case 4:
    case 6:
    case 9:
    case 11:
        return b && dia <= 30;
    case 2:
        return b && dia <= 28;
    default:
        return false;
    }
}

void leerEntero(int &resultado)
{
    while (true)
    {
        try
        {
            string input;
            cin >> input;
            resultado = stoi(input);

            size_t pos;
            resultado = stoi(input, &pos);

            if (pos != input.length())
            {
                throw invalid_argument("Entrada no válida. No es un número entero natural.");
            }

            if (resultado < 0)
            {
                throw out_of_range("Número debe ser un entero natural (mayor o igual a cero).");
            }
            break;
        }
        catch (invalid_argument &e)
        {
            cout << "Error: Entrada no valida. \nPor favor, ingrese un numero valido" << endl;
        }
        catch (out_of_range &e)
        {
            cout << "Entrada fuera de rango. \nPor favor, ingrese un numero valido" << endl;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

void leerFlotante(float &resultado)
{
    while (true)
    {
        try
        {
            string input;
            cin >> input;
            resultado = stof(input);

            size_t pos;
            resultado = stof(input, &pos);

            if (pos != input.length())
            {
                throw invalid_argument("Entrada no válida. No es un número flotante.");
            }

            if (resultado < 0)
            {
                throw out_of_range("Número debe ser un flotante natural (mayor o igual a cero).");
            }
            break;
        }
        catch (invalid_argument &e)
        {
            cout << "Error: Entrada no valida. \nPor favor, ingrese un numero valido" << endl;
        }
        catch (out_of_range &e)
        {
            cout << "Entrada fuera de rango. \nPor favor, ingrese un numero valido" << endl;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

void leerPalabras(string &resultado)
{
    while (true)
    {
        cin >> resultado;

        bool contieneNumeros = false;
        for (char c : resultado)
        {
            if (isdigit(c))
            {
                contieneNumeros = true;
                break;
            }
        }

        if (!contieneNumeros)
        {
            break;
        }
        else
        {
            cout << "Error: Entrada incorrecta. \nPor favor, inténtelo de nuevo:" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

void anadirCliente(banco &b1, fstream &archivoClientes)
{
    int dni1, anioIngreso1, numeroCliente1, numeroTarjeta1;
    string nombre1, apellido1, tipoCliente1, estado1;
    float cajaPesos1, cajaDolares1;

    cout << "Ingresar nombre de cliente" << endl;
    leerPalabras(nombre1);
    cout << "Ingresar apellido de cliente" << endl;
    leerPalabras(apellido1);
    cout << "Ingrese numero de cliente" << endl;
    leerEntero(numeroCliente1);
    cout << "Ingresar tipo de cliente" << endl;
    leerPalabras(tipoCliente1);
    cout << "Ingresar DNI de cliente" << endl;
    leerEntero(dni1);
    cout << "Ingresar anio de ingreso" << endl;
    leerEntero(anioIngreso1);
    cout << "Ingresar estado del cliente" << endl;
    leerPalabras(estado1);
    cout << "Ingrese el numero de tarjeta del cliente" << endl;
    leerEntero(numeroTarjeta1);
    cout << "Ingrese el saldo de la caja de ahorro en pesos:" << endl;
    leerFlotante(cajaPesos1);
    cout << "Ingrese el saldo de la caja de ahorros en dolares: " << endl;
    leerFlotante(cajaDolares1);

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

    cout << "Cliente agregado exitosamente" << endl;
}

transaccion agregar(banco &b1, fstream &archivoTransacciones)
{
    int numeroCliente1, numeroTransaccion1, dia1, mes1, anio1;
    string tipoTransaccion1, cajaAhorro1;
    float monto1;

    cout << "Ingrese el numero de cliente que realiza la transaccion: " << endl;
    leerEntero(numeroCliente1);

    cout << "Ingrese el numero de transaccion: " << endl;
    leerEntero(numeroTransaccion1);

    cout << "Ingrese el tipo de transaccion (Deposito o Extraccion): " << endl;
    leerPalabras(tipoTransaccion1);

    cout << "Ingrese el tipo de caja donde desea realizar la operacion: " << endl;
    leerPalabras(cajaAhorro1);

    cout << "Ingrese el monto: " << endl;
    leerFlotante(monto1);

    if (tipoTransaccion1 == "Extraccion")
    {
        if (cajaAhorro1 == "Pesos")
        {
            for (int i = 0; i < b1.getNumeroClientes(); i++)
            {
                if (b1.getClientes()[i].getNumeroCliente() == numeroCliente1)
                {
                    if (monto1 > b1.getClientes()[i].getCajaPesos())
                    {
                        cout << "No se puede realizar la extraccion. Saldo insuficiente" << endl;
                        cout << "Saldo actual: " << b1.getClientes()[i].getCajaPesos() << endl;
                        cout << "Monto a extraer: " << endl;
                        leerFlotante(monto1);
                    }
                    else
                    {
                        b1.getClientes()[i].setCajaPesos(b1.getClientes()[i].getCajaPesos() - monto1);
                    }
                }
            }
        }
        else if (cajaAhorro1 == "Dolares")
        {
            for (int i = 0; i < b1.getNumeroClientes(); i++)
            {
                if (b1.getClientes()[i].getNumeroCliente() == numeroCliente1)
                {
                    if (monto1 > b1.getClientes()[i].getCajaDolares())
                    {
                        cout << "No se puede realizar la extraccion. Saldo insuficiente" << endl;
                        cout << "Saldo actual: " << b1.getClientes()[i].getCajaDolares() << endl;
                        cout << "Monto a extraer: " << endl;
                        leerFlotante(monto1);
                    }
                    else
                    {
                        b1.getClientes()[i].setCajaDolares(b1.getClientes()[i].getCajaDolares() - monto1);
                    }
                }
            }
        }
    }
    else if (tipoTransaccion1 == "Deposito")
    {
        if (cajaAhorro1 == "Pesos")
        {
            for (int i = 0; i < b1.getNumeroClientes(); i++)
            {
                if (b1.getClientes()[i].getNumeroCliente() == numeroCliente1)
                {
                    b1.getClientes()[i].setCajaPesos(b1.getClientes()[i].getCajaPesos() + monto1);
                }
            }
        }
        else if (cajaAhorro1 == "Dolares")
        {
            for (int i = 0; i < b1.getNumeroClientes(); i++)
            {
                if (b1.getClientes()[i].getNumeroCliente() == numeroCliente1)
                {
                    b1.getClientes()[i].setCajaDolares(b1.getClientes()[i].getCajaDolares() + monto1);
                }
            }
        }
    }

    do
    {
        cout << "Ingrese el dia: " << endl;
        leerEntero(dia1);

        cout << "Ingrese el mes: " << endl;
        leerEntero(mes1);

        cout << "Ingrese el anio: " << endl;
        leerEntero(anio1);
        if (!validar_fecha(dia1, mes1, anio1))
        {
            cout << " ADVERTENCIA " << endl;
            cout << "No es una fecha valida! Por favor, vuelva a ingresar una fecha" << endl;
        }
    } while (!validar_fecha(dia1, mes1, anio1));

    transaccion tran1(numeroCliente1, numeroTransaccion1, monto1, tipoTransaccion1, dia1, mes1, anio1, cajaAhorro1);

    archivoTransacciones.clear();
    archivoTransacciones.seekp(0, ios::end);

    archivoTransacciones << "\n"
                         << numeroCliente1 << " " << numeroTransaccion1 << " " << cajaAhorro1 << " " << monto1 << " " << tipoTransaccion1 << " " << dia1 << " " << mes1 << " " << anio1 << endl;

    b1.agregarTransaccion(tran1);
    cout << "Agregando transacciones..." << endl;
    tran1.mostrarTransaccion();
    return tran1;
}

void detalleCliente(banco &b1)
{
    int numeroCliente1;
    cout << "Ingrese numero de cliente" << endl;
    leerEntero(numeroCliente1);

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
    leerEntero(numeroCliente1);

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
    do
    {
        leerEntero(criterio);
        if (criterio > 3 || criterio < 1)
        {
            cout << "Opción no válida. Por favor, seleccione una opción válida." << endl;
        }
    } while (criterio > 3 || criterio < 1);

    switch (criterio)
    {
    case 1:
        cout << "Informe de transacciones por mes: " << endl;
        cout << "Ingrese el mes: " << endl;
        leerEntero(mes);
        cout << "Ingrese el anio: " << endl;
        leerEntero(anio);
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
        leerEntero(anio);
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
    leerEntero(numeroCliente1);

    cout << "Seleccione la opcion que desea realizar: " << endl;
    cout << "1. Dar de baja" << endl;
    cout << "2. Dar de alta" << endl;

    int opcion;
    do
    {
        leerEntero(opcion);
        if (opcion > 2 || opcion < 1)
        {
            cout << "Opción no válida. Por favor, seleccione una opción válida." << endl;
        }
    } while (opcion > 2 || opcion < 1);

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

    while (!archivoClientes.eof() && archivoClientes >> nombre1 >> apellido1 >> dni1 >> tipoCliente1 >> anioIngreso1 >> estado1 >> numeroCliente1 >> numeroTarjeta1 >> cajaPesos1 >> cajaDolares1)
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
    while (!archivoClientes.eof() && archivoTransacciones >> numeroCliente2 >> numeroTransaccion1 >> cajaAhorro1 >> monto1 >> tipoTransaccion1 >> dia1 >> mes1 >> anio1)
    {
        transaccion tran1(numeroCliente2, numeroTransaccion1, monto1, tipoTransaccion1, dia1, mes1, anio1, cajaAhorro1);
        b1.agregarTransaccion(tran1);
    }
}

int main()
{
    banco b1(0, 0);
    fstream archivoClientes("clientes.txt", ios::in | ios::out | ios::app);
    fstream archivoTransacciones("transacciones.txt", ios::in | ios::out | ios::app);

    cargar(b1, archivoClientes, archivoTransacciones);

    int opcion;
    do
    {
        menu();
        leerEntero(opcion);
        switch (opcion)
        {
        case 1:
            anadirCliente(b1, archivoClientes);
            break;
        case 2:
            agregar(b1, archivoTransacciones);
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

    ofstream archivoNuevoClientes("clientes.txt");

    for (int i = 0; i < b1.getNumeroClientes(); i++)
    {
        archivoNuevoClientes << b1.getClientes()[i].getNombre() << " " << b1.getClientes()[i].getApellido() << " " << b1.getClientes()[i].getDNI() << " " << b1.getClientes()[i].getTipoCliente() << " " << b1.getClientes()[i].getAnioIngreso() << " " << b1.getClientes()[i].getEstado() << " " << b1.getClientes()[i].getNumeroCliente() << " " << b1.getClientes()[i].getTarjeta().getNumeroTarjeta() << " " << b1.getClientes()[i].getNumeroCliente() << " " << b1.getClientes()[i].getCajaPesos() << " " << b1.getClientes()[i].getCajaDolares() << endl;
    }

    archivoNuevoClientes.close();
    archivoTransacciones.close();
    return 0;
}
