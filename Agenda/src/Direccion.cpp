/*
 * Direccion.cpp
 *
 *  Created on: 3/12/2014
 *      Author: dark
 */

#include "Direccion.h"

using namespace std;

namespace Dentista {

Direccion::Direccion() {
	// TODO Auto-generated constructor stub

}

Direccion::~Direccion() {
	// TODO Auto-generated destructor stub
}

Direccion introducirDireccion() {
	Direccion insertar;
	string calle;
	int numero;
	string escalera;
	char piso;
	char puerta;
	int cp;
	string localidad;

	cout << endl << "Calle: ";
	cin >> calle;
	insertar.setCalle(calle);
	fflush(stdin);

	cout << endl << "Número: ";
	cin >> numero;
	insertar.setNumero(numero);

	cout << endl << "Escalera: ";
	cin >> escalera;
	insertar.setEscalera(escalera);

	cout << endl << "Piso: ";
	cin >> piso;
	insertar.setPiso(piso);

	cout << endl << "Puerta: ";
	cin >> puerta;
	insertar.setPuerta(puerta);

	cout << endl << "Código Postal: ";
	cin >> cp;
	insertar.setCp(cp);

	cout << endl << "Localidad: ";
	cin >> localidad;
	insertar.setLocalidad(localidad);

	return insertar;
}

} /* namespace Dentista */
