#include <iostream>
#include "cliente.h"
#include <fstream>
#include <stdexcept>
#include <limits>
#include <unistd.h>
using namespace std;

void esperar(float segundos)
{
    for (int i = 0; i < 5; i++)
    {
        usleep(segundos * 200000);
    }

    cout << endl;
}

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

            size_t pos;
            resultado = stoi(input, &pos);

            if (pos != input.length()) /* para que no pongan nros combinados con caracteres*/
            {
                throw invalid_argument("Entrada no válida. No es un número entero natural.");
            }

            if (resultado < 0) /*p que no pongan nros negativos*/
            {
                throw out_of_range("Numero debe ser un entero natural (mayor o igual a cero).");
            }
            break;
        }
        catch (invalid_argument &e)
        {
            cerr << "Error: Entrada no valida. \nPor favor, ingrese un numero valido" << endl;
        }
        catch (out_of_range &e)
        {
            cerr << "Error: Entrada fuera de rango. \nPor favor, ingrese un numero valido" << endl;
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
            cout << "Error: Entrada incorrecta. \nPor favor, intentelo de nuevo:" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

void anadirCliente(banco &b1)
{
    int dni1, anioIngreso1, numeroCliente1, numeroTarjeta1;
    string nombre1, apellido1, tipoCliente1, estado1;
    float cajaPesos1, cajaDolares1;
    bool band;
    cout << "Ingresar nombre de cliente:" << endl;
    leerPalabras(nombre1);
    cout << "Ingresar apellido de cliente:" << endl;
    leerPalabras(apellido1);

    do
    {
        band = false;
        cout << "Ingrese numero de cliente:" << endl;
        leerEntero(numeroCliente1);
        for (int i = 0; i < b1.getNumeroClientes(); i++)
        {
            if (b1.getClientes()[i].getNumeroCliente() == numeroCliente1)
            {
                cout << "Numero de cliente ya existe. Por favor, ingrese un numero de cliente valido" << endl;
                band = true;
                break;
            }
        }
    } while (band);

    do
    {
        cout << "Ingresar tipo de cliente (Plata, Oro o Platino):" << endl;
        leerPalabras(tipoCliente1);
        if (tipoCliente1 != "Plata" && tipoCliente1 != "Oro" && tipoCliente1 != "Platino" && tipoCliente1 != "plata" && tipoCliente1 != "oro" && tipoCliente1 != "platino")
        {
            cout << "Tipo de cliente no valido. Por favor, ingrese un tipo de cliente valido" << endl;
        }
    } while (tipoCliente1 != "Plata" && tipoCliente1 != "Oro" && tipoCliente1 != "Platino" && tipoCliente1 != "plata" && tipoCliente1 != "oro" && tipoCliente1 != "platino");

    bool bandera1;
    do
    {
        bandera1 = false;
        do
        {
            cout << "Ingresar DNI de cliente:" << endl;
            leerEntero(dni1);
            if (dni1 < 1000000 || dni1 > 99999999)
            {
                cout << "DNI no valido. Por favor, ingrese un DNI valido" << endl;
            }
        } while (dni1 < 1000000 || dni1 > 99999999);
        for (int i = 0; i < b1.getNumeroClientes(); i++)
        {
            if (b1.getClientes()[i].getDNI() == dni1)
            {
                cout << "Ya existe un cliente con ese DNI. Por favor, ingrese un DNI valido" << endl;
                bandera1 = true;
                break;
            }

        }
    } while (bandera1);

    do
    {
        cout << "Ingresar anio de ingreso:" << endl;
        leerEntero(anioIngreso1);
        if (anioIngreso1 < 1900 || anioIngreso1 > 2024)
        {
            cout << "Anio no valido. Por favor, ingrese un anio valido" << endl;
        }
    } while (anioIngreso1 < 1900 || anioIngreso1 > 2024);

    do
    {
        cout << "Ingresar estado del cliente (Activo, Baja):" << endl;
        leerPalabras(estado1);
        if (estado1 != "Activo" && estado1 != "Baja" && estado1 != "activo" && estado1 != "baja")
        {
            cout << "Estado no valido. Por favor, ingrese un estado valido" << endl;
        }
    } while (estado1 != "Activo" && estado1 != "Baja" && estado1 != "activo" && estado1 != "baja");

    bool bandera2;
    do
    {
        bandera2 = false; /*asumo que si pasa, asi entra al for. asumo que si y desp cambio a no */
        cout << "Ingresar numero de tarjeta del cliente:" << endl;
        leerEntero(numeroTarjeta1);
        for (int i = 0; i < b1.getNumeroClientes(); i++)
        {
            if (b1.getClientes()[i].getTarjeta().getNumeroTarjeta() == numeroTarjeta1)
            {
                cout << "Numero de tarjeta ya existe. Por favor, ingrese un numero de tarjeta valido" << endl;
                bandera2 = true;
                break;
            }
        }
    } while (bandera2);

    cout << "Ingrese el saldo de la caja de ahorro en pesos:" << endl;
    leerFlotante(cajaPesos1);
    cout << "Ingrese el saldo de la caja de ahorros en dolares: " << endl;
    leerFlotante(cajaDolares1);

    tarjeta t2(numeroTarjeta1);
    if (tipoCliente1 == "Oro" || tipoCliente1 == "oro")
    {
        t2.setLimite(250000);
    }
    else if (tipoCliente1 == "Platino" || tipoCliente1 == "platino")
    {
        t2.setLimite(500000);
    }
    else
    {
        t2.setLimite(0);
    }
    cliente c1(tipoCliente1, anioIngreso1, estado1, numeroCliente1, t2, cajaPesos1, cajaDolares1, nombre1, apellido1, dni1);
    b1.agregarCliente(c1);

    cout << "Cliente agregado exitosamente..." << endl;
    esperar(1);
    c1.mostrarCliente();
}

void agregar(banco &b1, fstream &archivoTransacciones)
{
    int numeroCliente1, numeroTransaccion1, dia1, mes1, anio1;
    string tipoTransaccion1, cajaAhorro1;
    float monto1;
    int band = 1;
    do
    {
        cout << "Ingrese el numero de cliente que realiza la transaccion: " << endl;
        leerEntero(numeroCliente1);
        for (int i = 0; i < b1.getNumeroClientes(); i++)
        {
            if (b1.getClientes()[i].getNumeroCliente() == numeroCliente1)
            {
                band = 0;
            }
        }
        if (band == 1)
        {
            cout << "Numero de cliente no valido. Por favor, ingrese un numero de cliente valido" << endl;
        }
        else if (band == 1 && b1.getNumeroClientes() == 0)
        {
            cout << "No hay clientes registrados." << endl;
            break;
        }
    } while (band == 1 && b1.getNumeroClientes() != 0);

    for (int i = 0; i < b1.getNumeroClientes(); i++)
    {
        if (b1.getClientes()[i].getNumeroCliente() == numeroCliente1 && (b1.getClientes()[i].getEstado() == "Baja" || b1.getClientes()[i].getEstado() == "baja"))
        {
            cout << "El cliente se encuentra dado de baja. No se pueden realizar transacciones." << endl;
            break;
        }
        else if (b1.getClientes()[i].getNumeroCliente() == numeroCliente1 && (b1.getClientes()[i].getEstado() == "Activo" || b1.getClientes()[i].getEstado() == "activo"))
        {

            int bandera = 1;
            do
            {
                cout << "Ingrese el numero de transaccion: " << endl;
                leerEntero(numeroTransaccion1);

                for (int i = 0; i < b1.getNumeroTransacciones(); i++)
                {
                    if (b1.getTransacciones()[i].getNumeroTransaccion() == numeroTransaccion1)
                    {
                        cout << "Numero de transaccion ya existe. Por favor, ingrese un numero de transaccion valido" << endl;
                        bandera = 1;
                        break;
                    }
                    else
                    {
                        bandera = 0;
                    }
                }
            } while (bandera == 1);

            do
            {
                cout << "Ingrese el tipo de transaccion (Deposito o Extraccion): " << endl;
                leerPalabras(tipoTransaccion1);
                if (tipoTransaccion1 != "Deposito" && tipoTransaccion1 != "Extraccion" && tipoTransaccion1 != "deposito" && tipoTransaccion1 != "extraccion")
                {
                    cout << "Tipo de transaccion no valido. Por favor, ingrese un tipo de transaccion valido" << endl;
                }
            } while (tipoTransaccion1 != "Deposito" && tipoTransaccion1 != "Extraccion" && tipoTransaccion1 != "deposito" && tipoTransaccion1 != "extraccion");

            do
            {
                cout << "Ingrese el tipo de caja donde desea realizar la operacion (Dolares o Pesos): " << endl;
                leerPalabras(cajaAhorro1);
                if (cajaAhorro1 != "Dolares" && cajaAhorro1 != "Pesos" && cajaAhorro1 != "dolares" && cajaAhorro1 != "pesos")
                {
                    cout << "Tipo de caja de ahorro no valido. Por favor, ingrese un tipo de caja de ahorro valido" << endl;
                }
            } while (cajaAhorro1 != "Dolares" && cajaAhorro1 != "Pesos" && cajaAhorro1 != "dolares" && cajaAhorro1 != "pesos");

            cout << "Ingrese el monto: " << endl;
            leerFlotante(monto1);

            if (tipoTransaccion1 == "Extraccion" || tipoTransaccion1 == "extraccion")
            {
                if (cajaAhorro1 == "Pesos" || cajaAhorro1 == "pesos")
                {
                    for (int i = 0; i < b1.getNumeroClientes(); i++)
                    {
                        if (b1.getClientes()[i].getNumeroCliente() == numeroCliente1)
                        {
                            do
                            {
                                if (monto1 > b1.getClientes()[i].getCajaPesos())
                                {
                                    cout << "No se puede realizar la extraccion. Saldo insuficiente" << endl;
                                    cout << "Saldo actual: " << b1.getClientes()[i].getCajaPesos() << endl;
                                    cout << "Monto a extraer: " << endl;
                                    leerFlotante(monto1);
                                }

                            } while (monto1 > b1.getClientes()[i].getCajaPesos());
                            b1.getClientes()[i].setCajaPesos(b1.getClientes()[i].getCajaPesos() - monto1);
                        }
                    }
                }
                else if (cajaAhorro1 == "Dolares" || cajaAhorro1 == "dolares")
                {
                    for (int i = 0; i < b1.getNumeroClientes(); i++)
                    {
                        if (b1.getClientes()[i].getNumeroCliente() == numeroCliente1)
                        {
                            do
                            {
                                if (monto1 > b1.getClientes()[i].getCajaDolares())
                                {
                                    cout << "No se puede realizar la extraccion. Saldo insuficiente" << endl;
                                    cout << "Saldo actual: " << b1.getClientes()[i].getCajaDolares() << endl;
                                    cout << "Monto a extraer: " << endl;
                                    leerFlotante(monto1);
                                }

                            } while (monto1 > b1.getClientes()[i].getCajaDolares());
                            b1.getClientes()[i].setCajaDolares(b1.getClientes()[i].getCajaDolares() - monto1);
                        }
                    }
                }
            }
            else if (tipoTransaccion1 == "Deposito" || tipoTransaccion1 == "deposito")
            {
                if (cajaAhorro1 == "Pesos" || cajaAhorro1 == "pesos")
                {
                    for (int i = 0; i < b1.getNumeroClientes(); i++)
                    {
                        if (b1.getClientes()[i].getNumeroCliente() == numeroCliente1)
                        {
                            b1.getClientes()[i].setCajaPesos(b1.getClientes()[i].getCajaPesos() + monto1);
                        }
                    }
                }
                else if (cajaAhorro1 == "Dolares" || cajaAhorro1 == "dolares")
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

            archivoTransacciones.clear();            // Limpia el flag de error del archivo
            archivoTransacciones.seekp(0, ios::end); /*empieza a escribir al final del archivo , en vez de sobreescribir*/
            archivoTransacciones << " " << endl;
            archivoTransacciones << numeroCliente1 << " " << numeroTransaccion1 << " " << cajaAhorro1 << " " << monto1 << " " << tipoTransaccion1 << " " << dia1 << " " << mes1 << " " << anio1 << endl;

            b1.agregarTransaccion(tran1);
            cout << "Agregando transacciones..." << endl;
            esperar(1);
            tran1.mostrarTransaccion();
        }
    }
}

void detalleCliente(banco &b1)
{
    int numeroCliente1, band = 1;

    do
    {
        cout << "Ingrese numero de cliente: " << endl;
        leerEntero(numeroCliente1);
        for (int i = 0; i < b1.getNumeroClientes(); i++)
        {
            if (b1.getClientes()[i].getNumeroCliente() == numeroCliente1)
            {
                band = 0;
            }
        }
        if (band == 1)
        {
            cout << "Numero de cliente no valido." << endl;
        }
        else if (band == 1 && b1.getNumeroClientes() == 0)
        {
            cout << "No hay clientes registrados." << endl;
            break;
        }
    } while (band == 1 && b1.getNumeroClientes() != 0);

    cout << "Detalle de cliente por numero de cliente:" << endl
         << endl;

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
        cout << "--------------------" << endl;
        cout << "Cliente " << i + 1 << endl;
        b1.getClientes()[i].mostrarCliente();
    }
}

void listarTrans(banco b1)
{
    int numeroCliente1;
    bool band;
    do
    {   band = true;
        cout << "Ingrese el numero de cliente para ver sus transacciones:";
        leerEntero(numeroCliente1);
        for (int i = 0; i < b1.getNumeroClientes(); i++)
        {
            if (b1.getClientes()[i].getNumeroCliente() == numeroCliente1)
            {
                band = false;
                cout << "Detalle de cliente por numero de cliente" << endl;

                for (int i = 0; i < b1.getNumeroTransacciones(); i++)
                {
                    if (b1.getTransacciones()[i].getNumeroCliente() == numeroCliente1)
                    {
                        b1.getTransacciones()[i].mostrarTransaccion();
                        cout << "--------------------" << endl;
                    }
                }
            }
        }
        if (band)
        {
            cout << "Numero de cliente no valido." << endl;
        }
        else if (band && b1.getNumeroClientes() == 0)
        {
            cout << "No hay clientes registrados." << endl;
            break;
        }

    } while (band && b1.getNumeroClientes() != 0);
}

void mostrarInformes(banco &b1)
{
    int criterio, mes, anio, band;

    do
    {
        cout << "Seleccione el criterio de informe: " << endl;
        cout << "1. En un mes particular" << endl;
        cout << "2. Por anio" << endl;
        cout << "3. Todas las operaciones " << endl;

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
        band = 1;
        do
        {
            cout << "Ingrese el mes: " << endl;
            leerEntero(mes);
            if (mes < 1 || mes > 12)
            {
                cout << "Mes no valido. Por favor, ingrese un mes valido" << endl;
            }
        } while (mes < 1 || mes > 12);

        do
        {
            cout << "Ingrese el anio: " << endl;
            leerEntero(anio);
            if (anio < 1900 || anio > 2024)
            {
                cout << "Anio no valido. Por favor, ingrese un anio valido" << endl;
            }
        } while (anio < 1900 || anio > 2024);

        for (int i = 0; i < b1.getNumeroTransacciones(); i++)
        {
            if (b1.getTransacciones()[i].getMes() == mes && b1.getTransacciones()[i].getAnio() == anio)
            {
                b1.getTransacciones()[i].mostrarTransaccion();
                band = 0;
            }
        }
        if (band == 1)
        {
            cout << "No hay transacciones en el mes y anio seleccionado." << endl;
        }
        break;
    case 2:
        cout << "Informe de transacciones por anio" << endl;
        band = 1;
        do
        {
            cout << "Ingrese el anio: " << endl;
            leerEntero(anio);
            if (anio < 1900 || anio > 2024)
            {
                cout << "Anio no valido. Por favor, ingrese un anio valido" << endl;
            }
        } while (anio < 1900 || anio > 2024);

        for (int i = 0; i < b1.getNumeroTransacciones(); i++)
        {
            if (b1.getTransacciones()[i].getAnio() == anio)
            {
                b1.getTransacciones()[i].mostrarTransaccion();
                band = 0;
            }
        }
        if (band == 1)
        {
            cout << "No hay transacciones en el anio seleccionado." << endl;
        }
        break;
    case 3:
        cout << "Todas las operaciones: " << endl;
        b1.listarTransacciones();

        if (b1.getNumeroTransacciones() == 0)
        {
            cout << "No hay transacciones registradas." << endl;
        }
        break;
    }
}

void bajaAlta(banco &b1)
{
    // Check if there are no clients and exit the function if true
    if (b1.getNumeroClientes() == 0)
    {
        cout << "No hay clientes registrados." << endl;
        return; // Exits the function
    }

    int numeroCliente1, band = 1;

    do
    {
        cout << "Ingrese el numero de cliente que desea dar de baja/alta: " << endl;
        leerEntero(numeroCliente1);

        for (int i = 0; i < b1.getNumeroClientes(); i++)
        {
            if (b1.getClientes()[i].getNumeroCliente() == numeroCliente1)
            {
                band = 0;
                int opcion;
                while (opcion > 2 || opcion < 1)
                {
                    cout << "Seleccione la opcion que desea realizar: " << endl;
                    cout << "1. Dar de baja" << endl;
                    cout << "2. Dar de alta" << endl;
                    leerEntero(opcion);

                    if (opcion > 2 || opcion < 1)
                    {
                        cout << "Opcion no valida. Por favor, seleccione una opcion valida." << endl;
                    }
                }

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
                            b1.getClientes()[i].setEstado("Activo");
                        }
                    }
                    cout << "Dando de alta..." << endl;
                    break;
                }
            }
        }
        if (band == 1)
        {
            cout << "Numero de cliente no valido." << endl;
        }

    } while (band == 1);
}

void consultarLimite(banco &b1)
{
    if (b1.getNumeroClientes() == 0)
    {
        cout << "No hay clientes registrados." << endl;
        return;
    }

    int numeroCliente, band = 1;

    do
    {
        cout << "Ingrese el numero de cliente de la tarjeta: " << endl;
        leerEntero(numeroCliente);

        for (int i = 0; i < b1.getNumeroClientes(); i++)
        {
            if (b1.getClientes()[i].getNumeroCliente() == numeroCliente)
            {
                band = 0;
                if (b1.getClientes()[i].getNumeroCliente() == numeroCliente)
                {
                    cout << "El cliente es de tipo: " << b1.getClientes()[i].getTipoCliente() << endl;

                    if (b1.getClientes()[i].getTipoCliente() == "Plata" || b1.getClientes()[i].getTipoCliente() == "plata")
                    {
                        cout << "El cliente no tiene opcion de credito." << endl;
                    }
                    else if (b1.getClientes()[i].getTipoCliente() == "Oro" || b1.getClientes()[i].getTipoCliente() == "oro")
                    {
                        cout << "Tiene la tarjeta Credix" << endl;
                        cout << "El limite de la tarjeta es de 250000" << endl;
                    }
                    else if (b1.getClientes()[i].getTipoCliente() == "Platino" || b1.getClientes()[i].getTipoCliente() == "platino")
                    {
                        cout << "Tiene la tarjeta Premium" << endl;
                        cout << "El limite de la tarjeta es de 500000" << endl;
                    }
                }
            }
        }
        if (band == 1)
        {
            cout << "Numero de cliente no valido." << endl;
        }

    } while (band == 1);
}

void menu()
{
    cout << endl;
    cout << "1. Agregar cliente" << endl;
    cout << "2. Registrar transacciones" << endl;
    cout << "3. Detalle de cliente por numero de cliente" << endl;
    cout << "4. Listado de todos los clientes del banco" << endl;
    cout << "5. Listado de transacciones por cliente" << endl;
    cout << "6. Informes de extracciones y depositos" << endl;
    cout << "7. Dar de baja/alta" << endl;
    cout << "8. Consultar limite de tarjeta" << endl;
    cout << "9. Salir" << endl;
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
        cout<<"Hola"<<endl;
        tarjeta t2(numeroTarjeta1);
        cliente c1(tipoCliente1, anioIngreso1, estado1, numeroCliente1, t2, cajaPesos1, cajaDolares1, nombre1, apellido1, dni1);
        b1.agregarCliente(c1);
        if (tipoCliente1 == "Oro" || tipoCliente1 == "oro")
        {
            t2.setLimite(250000);
        }
        else if (tipoCliente1 == "Platino" || tipoCliente1 == "platino")
        {
            t2.setLimite(500000);
        }
        else
        {
            t2.setLimite(0);
        }
    }
    while (!archivoTransacciones.eof() && archivoTransacciones >> numeroCliente2 >> numeroTransaccion1 >> cajaAhorro1 >> monto1 >> tipoTransaccion1 >> dia1 >> mes1 >> anio1)
    {
        transaccion tran1(numeroCliente2, numeroTransaccion1, monto1, tipoTransaccion1, dia1, mes1, anio1, cajaAhorro1);
        b1.agregarTransaccion(tran1);
    }
}

int main()
{
    srand(time(NULL));
    banco b1(0, 0);
    fstream archivoClientes("clientes.txt", ios::in | ios::out);
    fstream archivoTransacciones("transacciones.txt", ios::in | ios::out);

    cargar(b1, archivoClientes, archivoTransacciones);
    cout << "\n------------- Bienvenido a Banco UCC --------------" << endl;

    int opcion;
    do
    {
        menu();
        leerEntero(opcion);
        switch (opcion)
        {
        case 1:
            anadirCliente(b1);
            esperar(1);
            break;
        case 2:
            agregar(b1, archivoTransacciones);
            esperar(1);
            break;
        case 3:
            detalleCliente(b1);
            esperar(1);
            break;
        case 4:
            listarClientes(b1);
            esperar(1);
            break;
        case 5:
            listarTrans(b1);
            esperar(1);
            break;
        case 6:
            mostrarInformes(b1);
            esperar(1);
            break;
        case 7:
            bajaAlta(b1);
            esperar(1);
            break;
        case 8:
            consultarLimite(b1);
            esperar(1);
            break;
        case 9:
            cout << "Saliendo del programa..." << endl;
            esperar(1);
            break;
        default:
            cout << "Opcion no valida" << endl;
            break;
        }
    } while (opcion != 9);

    ofstream archivoNuevoClientes("clientes.txt");

    for (int i = 0; i < b1.getNumeroClientes(); i++)
    {
        archivoNuevoClientes << b1.getClientes()[i].getNombre() << " " << b1.getClientes()[i].getApellido() << " " << b1.getClientes()[i].getDNI() << " " << b1.getClientes()[i].getTipoCliente() << " " << b1.getClientes()[i].getAnioIngreso() << " " << b1.getClientes()[i].getEstado() << " " << b1.getClientes()[i].getNumeroCliente() << " " << b1.getClientes()[i].getTarjeta().getNumeroTarjeta() << " " << b1.getClientes()[i].getCajaPesos() << " " << b1.getClientes()[i].getCajaDolares() << endl;
    }

    archivoNuevoClientes.close();
    archivoTransacciones.close();
    return 0;
}
