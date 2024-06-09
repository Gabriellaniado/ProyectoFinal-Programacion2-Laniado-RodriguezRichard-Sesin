#include <iostream>
using namespace std;

class cliente{
    private:
        int dni;
        string nombre;
        string tipoCliente;
        int anioIngreso;
        string estado;
    public:
        cliente(int, string, string, int, string);
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
};
