/*
 * Contacto.cpp
 *
 *  Created on: 3/12/2014
 *      Author: Grupo7
 */

#include <iostream>
#include <string>
#include "Contacto.h"
#include "Agenda.h"

using namespace std;

namespace Dentista {

Contacto::Contacto() {
	// TODO Auto-generated constructor stub

}

Contacto::~Contacto() {
	// TODO Auto-generated destructor stub
}

bool introducirDatosContacto(Agenda &agenda, Contacto &nuevo) {
	char seguir = 'S';
	int contadorDireccion = 1;
	int contadorRed = 1;

	string nombre;
	string apellidos;
	string dni;
	int telefono1;
	int telefono2;
	string correo1;
	string correo2;
	list<Direccion> direccion;
	string anotaciones;
	list<RedSocial> redes;

	Direccion direccionAuxiliar;
	RedSocial redSocialAuxiliar;

	cout << "AÑADIR UN NUEVO CONTACTO" << endl;
	cout << "************************" << endl;

	cout << endl << "Nombre: ";
	cin >> nombre;
	nuevo.setNombre(nombre);

	cout << endl << "Apellidos: ";
	cin >> apellidos;
	nuevo.setApellidos(apellidos);

	cout << endl << "DNI: ";
	cin >> dni;
	nuevo.setDni(dni);
	if(agenda.existeDNI(dni))
	{
		cout << endl << "Error, el DNI introducido ya existe.";
		return false;
	}

	cout << endl << "Teléfono: ";
	cin >> telefono1;
	nuevo.setTelefono1(telefono1);
	fflush(stdin);

	cout << endl << "Segundo teléfono (opcional): ";
	cin >> telefono2;
	nuevo.setTelefono2(telefono2);

	cout << endl << "Correo electrónico:  ";
	cin >> correo1;
	nuevo.setCorreo1(correo1);

	cout << endl << "Segundo correo electrónico (opcional): ";
	cin >> correo2;
	nuevo.setCorreo2(correo2);

	do{
		cout << endl << "Dirección " << contadorDireccion << ": ";
		direccionAuxiliar = introducirDireccion();
		direccion.push_back(direccionAuxiliar);

		cout << endl << "¿Desea introducir otra dirección? (S/N) ";
		cin >> seguir;

		contadorDireccion++;
	}while(seguir == 's' || seguir == 'S');

	do{
		cout << endl << "Red Social " << contadorRed << ": ";
		redSocialAuxiliar = introducirRedSocial();
		redes.push_back(redSocialAuxiliar);

		cout << endl << "¿Desea introducir otra Red Social? (S/N) ";
		cin >> seguir;

		contadorRed++;
	}while(seguir == 's' || seguir == 'S');

	cout << endl << "Anotaciones: ";
	cin >> anotaciones;
	nuevo.setAnotaciones(anotaciones);

	return true;;
}

} /* namespace Dentista */
