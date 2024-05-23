#pragma once
#include "Persona.h"
#include <iostream>
#include<string>
#include <mysql.h>
#include "ConexionBD.h"
class Estudiantes : Persona{
private: 
	string codigo;
	int id_tipos_sangre;
public: 
	Estudiantes() {
	}
	Estudiantes(string cod, string nom, string ape, string dir, string fn, int ts) : Persona(nom, ape, dir, fn) {
		codigo = cod;
		id_tipos_sangre = ts;
	}
	void setCodigo(string cod) { codigo = cod; }
	void setNombres(string nom) { nombres = nom; }
	void setApellidos(string ape) { apellidos = ape; }
	void setDireccion(string dir) { direccion = dir; }
	void setFecha_nacimiento(string fn) { fecha_nacimiento = fn; }
	void setId_tipos_sangre(int ts) { id_tipos_sangre = ts; }

	string getCodigo() { return codigo; }
	string getNombres() { return nombres; }
	string getApellidos() { return apellidos; }
	string getDireccion() { return direccion; }
	string getFecha_nacimiento() { return fecha_nacimiento; }
	int getId_tipos_sangre() { return id_tipos_sangre; }

	void Crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();

		cn.abrir_conexion();
		string t = to_string(id_tipos_sangre);
		if (cn.getConectar()) {
			string  insertar = "INSERT INTO colegiodb.estudiantes(codigo,nombres,apellidos,direccion,fecha_nacimiento,id_tipos_sangre) VALUES ('" + codigo + "','" + nombres + "','" + apellidos + "','" + direccion + "'," + fecha_nacimiento + ",'" + t + "')";
			const char* i = insertar.c_str();
			// executar el query
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Ingreso Exitoso ..." << endl;
			}
			else {
				cout << " xxx Error al Ingresar  xxx" << endl;
			}
		}
		else {
			cout << " xxx Error en la Conexion xxxx" << endl;
		}
		cn.cerrar_conexion();
	}
	void Leer() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getConectar()) {

			cout << "------------ Datos de Clientes ------------" << endl;
			string consulta = "select * from clientes";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << "," << fila[1] << "," << fila[2] << "," << fila[3] << "," << fila[4] << "," << fila[5] << "," << fila[6] << endl;
				}

			}
			else {
				cout << " xxx Error al Consultar  xxx" << endl;
			}

		}
		else {
			cout << " xxx Error en la Conexion xxxx" << endl;
		}
		cn.cerrar_conexion();
	}
	void Actualizar() {
		int q_estado;
		ConexionBD cn = ConexionBD();

		cn.abrir_conexion();
		string t = to_string(id_tipos_sangre);
		if (cn.getConectar()) {
			string actualizar = "UPDATE estudiantes SET nombres='" + nombres + "', apellidos='" + apellidos + "', direccion='" + direccion + "', fecha_nacimiento='" + fecha_nacimiento + "'', id_tipos_sangre='" + to_string(id_tipos_sangre) + " WHERE codigo='" + codigo + "'";
			const char* a = actualizar.c_str();
			q_estado = mysql_query(cn.getConectar(), a);
			if (!q_estado) {
				cout << "Actualización Exitosa ..." << endl;
			}
			else {
				cout << "Error al Actualizar: " << mysql_error(cn.getConectar()) << endl;
			}
		}
		else {
			cout << "Error en la Conexion" << endl;
		}
		cn.cerrar_conexion();
	}
	void Borrar() {
		int q_estado;
		ConexionBD cn = ConexionBD();

		cn.abrir_conexion();
		if (cn.getConectar()) {
			string borrar = "DELETE FROM estudiantes WHERE codigo='" + codigo + "'";
			const char* d = borrar.c_str();
			q_estado = mysql_query(cn.getConectar(), d);
			if (!q_estado) {
				cout << "Eliminación Exitosa ..." << endl;
			}
			else {
				cout << "Error al Eliminar: " << mysql_error(cn.getConectar()) << endl;
			}
		}
		else {
			cout << "Error en la Conexion" << endl;
		}
		cn.cerrar_conexion();
	}


};


