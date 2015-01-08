/*
 * Direccion.h
 *
 *  Created on: 3/12/2014
 *      Author: dark
 */

#ifndef DIRECCION_H_
#define DIRECCION_H_

#include <string>
#include <iostream>
#include <cstdio>

namespace Dentista {

class Direccion {
public:
	Direccion();
	virtual ~Direccion();

	const std::string& getCalle() const {
		return calle;
	}

	void setCalle(const std::string& calle) {
		this->calle = calle;
	}

	int getCp() const {
		return cp;
	}

	void setCp(int cp) {
		this->cp = cp;
	}

	const std::string& getEscalera() const {
		return escalera;
	}

	void setEscalera(const std::string& escalera) {
		this->escalera = escalera;
	}

	const std::string& getLocalidad() const {
		return localidad;
	}

	void setLocalidad(const std::string& localidad) {
		this->localidad = localidad;
	}

	int getNumero() const {
		return numero;
	}

	void setNumero(int numero) {
		this->numero = numero;
	}

	char getPiso() const {
		return piso;
	}

	void setPiso(char piso) {
		this->piso = piso;
	}

	char getPuerta() const {
		return puerta;
	}

	void setPuerta(char puerta) {
		this->puerta = puerta;
	}

private:
	std::string calle;
	int numero;
	std::string escalera;
	char piso;
	char puerta;
	int cp;
	std::string localidad;
};

Direccion introducirDireccion();
void mostrarDireccion(Direccion d);

} /* namespace Dentista */

#endif /* DIRECCION_H_ */
