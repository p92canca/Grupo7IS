/*
 * Paciente.h
 *
 *  Created on: 3/12/2014
 *      Author: dark
 */

#ifndef CONTACTO_H_
#define CONTACTO_H_

#include <list>
#include <string>
#include "RedSocial.h"
#include "Direccion.h"

namespace Dentista {

class Contacto {
public:
	Contacto(){

		setNombre("");
		setApellidos("");
		setDni("");
		setTelefono1(0);
		setTelefono2(0);
		setCorreo1("");
		setCorreo2("");
		//setDireccion(direccion);
		setAnotaciones("");
		setContadorAcceso(0);
		setFavorito(false);
		//setRedes(red);
	}

	const std::string& getAnotaciones() const {
		return anotaciones;
	}

	void setAnotaciones(const std::string& anotaciones) {
		this->anotaciones = anotaciones;
	}

	const std::string& getApellidos() const {
		return apellidos;
	}

	void setApellidos(const std::string& apellidos) {
		this->apellidos = apellidos;
	}

	int getContadorAcceso() const {
		return contadorAcceso;
	}

	void setContadorAcceso(int contadorAcceso) {
		this->contadorAcceso = contadorAcceso;
	}

	const std::string& getCorreo1() const {
		return correo1;
	}

	void setCorreo1(const std::string& correo1) {
		this->correo1 = correo1;
	}

	const std::string& getCorreo2() const {
		return correo2;
	}

	void setCorreo2(const std::string& correo2) {
		this->correo2 = correo2;
	}

	// const std::list<Direccion>& getDireccion() const {
	// 	return direccion;
	// }

	// void setDireccion(const std::list<Direccion>& direccion) {
	// 	this->direccion = direccion;
	// }

	const std::string& getDni() const {
		return dni;
	}

	void setDni(const std::string& dni) {
		this->dni = dni;
	}

	bool isFavorito() const {
		return favorito;
	}

	void setFavorito(bool favorito) {
		this->favorito = favorito;
	}

	const std::string& getNombre() const {
		return nombre;
	}

	void setNombre(const std::string& nombre) {
		this->nombre = nombre;
	}

	// const std::list<RedSocial>& getRedes() const {
	// 	return redes;
	// }

	// void setRedes(const std::list<RedSocial>& redes) {
	// 	this->redes = redes;
	// }

	int getTelefono1() const {
		return telefono1;
	}

	void setTelefono1(int telefono1) {
		this->telefono1 = telefono1;
	}

	int getTelefono2() const {
		return telefono2;
	}

	void setTelefono2(int telefono2) {
		this->telefono2 = telefono2;
	}

private:
	std::string nombre;
	std::string apellidos;
	std::string dni;
	int telefono1;
	int telefono2;
	std::string correo1;
	std::string correo2;
	//std::list<Direccion> direccion;
	std::string anotaciones;
	int contadorAcceso;
	bool favorito;
	//std::list<RedSocial> redes;
};



} /* namespace Dentista */

#endif /* CONTACTO_H_ */
