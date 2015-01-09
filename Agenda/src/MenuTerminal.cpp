/*
 * MenuTerminal.cpp
 *
 *  Created on: 7/1/2015
 *      Author: Federico
 */

#include "MenuTerminal.h"

using namespace std;

namespace Dentista {

MenuTerminal::MenuTerminal() {
	// TODO Auto-generated constructor stub

}

MenuTerminal::~MenuTerminal() {
	// TODO Auto-generated destructor stub
}

void visualizarContacto(Contacto &c) {
	list<Direccion> auxDir;
	list<RedSocial> auxRed;

	cout << endl << endl << "Datos de " << c.getNombre() << " " << c.getApellidos() << ":" << endl;
	cout << "---------------------------------------------------------------------" << endl;

	cout << "DNI:\t" << c.getDni() << endl;
	cout << "Teléfono 1:\t" << c.getTelefono1() << "\t| Teléfono 2:\t" << c.getTelefono2() << endl;
	cout << "Correo 1:\t" << c.getCorreo1() << "\t| Correo 2:\t" << c.getCorreo2() << endl;
	cout << "Direcciones:" << endl;
	auxDir = c.getDireccion();
	list<Direccion>::iterator it = auxDir.begin();
	while(it != auxDir.end()) {
		mostrarDireccion(*it);
		it++;
	}
	cout << "Redes Sociales:" << endl;
	auxRed = c.getRedes();
	list<RedSocial>::iterator itr = auxRed.begin();
	while(itr != auxRed.end()) {
		mostrarRedSocial(*itr);
		itr++;
	}
	cout << "Anotaciones:" << endl;
	cout << "\t" << c.getAnotaciones() << endl;

}

void visualizarAgenda(Agenda &a) {

}

bool modificarContacto(Contacto &c, Agenda &agenda) {

	if(introducirDatosContacto(agenda, c))
		cout << endl << "Usuario modificado con éxito.";
	return true;
}

bool eliminarContacto(std::string dni) {

	return true;
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
	fflush(stdin);

	cout << endl << "Correo electrónico:  ";
	cin >> correo1;
	nuevo.setCorreo1(correo1);
	fflush(stdin);

	cout << endl << "Segundo correo electrónico (opcional): ";
	cin >> correo2;
	nuevo.setCorreo2(correo2);
	fflush(stdin);

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

	nuevo.setFavorito(false);
	nuevo.setContadorAcceso(0);

	return true;
}

} /* namespace Dentista */
