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
	list<Direccion> direccion;
	list<RedSocial> red;

	setNombre("");
	setApellidos("");
	setDni("");
	setTelefono1(0);
	setTelefono2(0);
	setCorreo1("");
	setCorreo2("");
	setDireccion(direccion);
	setAnotaciones("");
	setContadorAcceso(0);
	setFavorito(false);
	setRedes(red);
}

Contacto::~Contacto() {
	// TODO Auto-generated destructor stub
}

} /* namespace Dentista */
