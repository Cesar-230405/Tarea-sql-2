#include <iostream>
#include "ConexionBD.h"
#include "Estudiantes.h" 

using namespace std;

int main() {
    string codigo, nombres, apellidos, direccion, fecha_nacimiento;
    int id_tipos_sangre;

    cout << "Ingrese Codigo: ";
    getline(cin, codigo);
    cout << "Ingrese Nombres: ";
    getline(cin, nombres);
    cout << "Ingrese Apellidos: ";
    getline(cin, apellidos);
    cout << "Ingrese Dirección: ";
    getline(cin, direccion);
    cout << "Ingrese Fecha de Nacimiento (YYYY-MM-DD): ";
    getline(cin, fecha_nacimiento);
    cout << "Ingrese Tipo de sangre: ";
    cin >> id_tipos_sangre;
    cin.ignore();

    Estudiantes estudiante(codigo, nombres, apellidos, direccion, fecha_nacimiento, id_tipos_sangre);

    
    estudiante.Crear();

    
    cout << "Ingrese nuevos Nombres: ";
    getline(cin, nombres);
    cout << "Ingrese nuevos Apellidos: ";
    getline(cin, apellidos);
    cout << "Ingrese nueva Dirección: ";
    getline(cin, direccion);
    cout << "Ingrese nueva Fecha de Nacimiento (YYYY-MM-DD): ";
    getline(cin, fecha_nacimiento);
    cout << "Ingrese nuevo tipo de sangre: ";
    cin >> id_tipos_sangre;
    cin.ignore();

    estudiante.setNombres(nombres);
    estudiante.setApellidos(apellidos);
    estudiante.setDireccion(direccion);
    estudiante.setFecha_nacimiento(fecha_nacimiento);
    estudiante.setId_tipos_sangre(id_tipos_sangre);

    estudiante.Actualizar();

    estudiante.Leer();

    estudiante.Borrar();

    estudiante.Leer();

    return 0;
}
