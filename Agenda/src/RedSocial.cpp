/*
 * RedSocial.cpp
 *
 *  Created on: 3/12/2014
 *      Author: dark
 */

#include "RedSocial.h"

using namespace std;

namespace Dentista {

RedSocial::RedSocial() {
	// TODO Auto-generated constructor stub

}

RedSocial::~RedSocial() {
	// TODO Auto-generated destructor stub
}

RedSocial introducirRedSocial() {
	RedSocial insertar;

	string nombreRed;
	string usuario;

	cout << endl << "Nombre de la Red Social: ";
	cin >> nombreRed;
	insertar.setNombreRed(nombreRed);

	cout << endl << "Nombre de usuario: ";
	cin >> usuario;
	insertar.setUsuario(usuario);

	return insertar;
}

} /* namespace Dentista */
