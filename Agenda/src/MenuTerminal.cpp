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

void modificarContacto() {

}

void eliminarContacto(std::string dni) {

}

} /* namespace Dentista */
