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

	cout << endl << "Numero: ";
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

	cout << endl << "Codigo Postal: ";
	cin >> cp;
	insertar.setCp(cp);

	cout << endl << "Localidad: ";
	cin >> localidad;
	insertar.setLocalidad(localidad);

	return insertar;
}

void mostrarDireccion(Direccion d) {
	cout << d.getCalle() << ", Numero: " << d.getNumero() << endl;
	if(d.getEscalera() != "-")
		cout << "Escalera: "  << d.getEscalera();
	if(d.getPiso() != '-')
		cout << "Piso: "  << d.getPiso();
	if(d.getPuerta() != '-')
		cout << "Escalera: "  << d.getPuerta();
	cout << endl;
	cout << "CP: " << d.getCp() << "\t" << d.getLocalidad();
	cout << endl;
}

} /* namespace Dentista */
