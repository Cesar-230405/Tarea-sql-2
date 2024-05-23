#pragma once
#include<iostream>
using namespace std;
class Persona {
protected: string nombres, apellidos, direccion, fecha_nacimiento;
		 
protected:
	Persona() {
	}
	Persona(string nom, string ape, string dir, string fn) {
		nombres = nom;
		apellidos = ape;
		direccion = dir;
		fecha_nacimiento = fn;
	}
};

