#pragma once
#include <mysql.h>
#include <iostream>
#include <string>
#include "Marca.h"
#include "CONEXION.h"
#include "Producto.h"
using namespace std;
class CRUD :Producto, Marca {

protected:
	int buscador;

public:
	CRUD() {}

	CRUD(string prod, string mr, int id, string desc, float pc, float pv, int ex, string fech, int busca) : Producto(prod, desc, pc, pv, ex, fech), Marca(mr, id) {
		buscador = busca;
	}
	void setProducto(string prod) { producto = prod; }
	void setMarca(string mr) { marca = mr; }
	void setidMarca(int id) { idMarca = id; }
	void setDescripcio(string desc) { descripcion = desc; }
	void setPrecio_C(float pc) { precio_costo = pc; }
	void setPrecio_V(float pv) { precio_venta = pv; }
	void setExistencia(int ex) { existencia = ex; }
	void setFecha_ingr(string fech) { fecha_ingreso = fech; }
	void setBuscador(int busca) { buscador = busca; }

	string getProducto() { return producto; }
	string getMarca() { return marca; }
	int getidMarca() { return idMarca; }
	string getDescripcion() { return descripcion; }
	float getPrecio_C() { return precio_costo; }
	float getPrecio_V() { return precio_venta; }
	int getExistencia() { return existencia; }
	string getFecha_ingr() { return fecha_ingreso; }
	int getBuscador() { return buscador; }

	void crear_Marca() {
		int q_estado;
		CONEXION cn = Conexion();

		cn.abrir_conexion();

		if (cn.getConectar()) {

			string insert = "INSERT INTO `tienda`.`marcas` (`marca`) VALUES('" + marca + "')";
			const char* i = insert.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "INGRESADO CON EXITO .... \n";

			}
			else {
				cout << "ERROR DE CONECCION.... \n";
			}
		}
		else {
			cout << "ERROR DE CONECCION.... \n";
		}
		cn.cerrar_conexion();
	}

	void leer_Marca() {
		int q_estado;
		CONEXION cn = Conexion();
		MYSQL_ROW fila = 0;
		MYSQL_RES* resultado = 0;
		cn.abrir_conexion();

		if (cn.getConectar()) {

			string consulta = "SELECT * FROM tienda.marcas";
			const char* i = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), i);

			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				cout << "         ********* PRODUCTOS ******" << endl;
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << " --> " << fila[1] << endl;
				}
			}
			else {
				cout << "ERROR DE CONECCION.... \n";
			}
		}
		else {
			cout << "ERROR DE CONECCION.... \n";
		}
		cn.cerrar_conexion();
	}



	//actualizar
	void actualizar_marca() {
		int q_estado;
		CONEXION cn = Conexion();

		cn.abrir_conexion();
		string id = to_string(idMarca);
		if (cn.getConectar()) {

			string update = "UPDATE `tienda`.`marcas` SET `marca` = '" + marca + "' WHERE (`idMarca` = " + id + ")";

			const char* i = update.c_str();

			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "INGRESADO CON EXITO .... \n";

			}
			else {
				cout << "ERROR DE CONECCION.... \n";
			}
		}
		else {
			cout << "ERROR DE CONECCION.... \n";
		}
		cn.cerrar_conexion();
	}

	//Eliminar
	void eliminar_marca() {
		int q_estado;
		CONEXION cn = Conexion();
		MYSQL_ROW fila = 0;
		MYSQL_RES* resultado = 0;

		cn.abrir_conexion();
		string id = to_string(idMarca);
		if (cn.getConectar()) {

			string delite = "DELETE FROM tienda.marcas WHERE idMarca= " + id + "";

			const char* i = delite.c_str();

			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {

				cout << "ELIMINADO CON EXITO .... \n";
				
			}
			else {
				cout << "ERROR DE CONECCION.... \n";
			}
		}
		else {
			cout << "ERROR DE CONECCION.... \n";
		}
		cn.cerrar_conexion();
	}

};

