/*
 * Agenda.h
 *
 *  Created on: 3/12/2014
 *      Author: dark
 */

#ifndef AGENDA_H_
#define AGENDA_H_

#include <string>
#include <fstream>
#include <list>
#include <iostream>
#include <algorithm>

#include "Contacto.h"
#include "SGDBFichero.h"
#include <list>

namespace Dentista {

class Agenda{
public:
	Agenda();
	virtual ~Agenda();

	void insertar(Contacto &c)
	{
		std::list<Contacto>::iterator it = _pacientes.begin();
		while(it != _pacientes.end()) {
			if((*it).getApellidos().compare(c.getApellidos()) > 0)
			{
				_pacientes.insert(it, c);
				break;
			}
			it++;
		}
	}

	void eliminar(std::string dni)
	{
		std::list<Contacto>::iterator it = _pacientes.begin();

		while(it != _pacientes.end()) {
			if((*it).getDni() == dni){
				_pacientes.erase(it);
				break;
			}
			else
				it++;
		}
	}

	void modificar(std::string dni, Contacto c)
	{
		std::list<Contacto>::iterator it = _pacientes.begin();

		while(it != _pacientes.end()) {
			if((*it).getDni() == dni){
				(*it) = c;
				break;
			}
			else
				it++;
		}
	}

	std::list<Contacto> buscarFavoritos()
	{
		std::list<Contacto> favoritos;
		std::list<Contacto>::iterator it = _pacientes.begin();

		while(it != _pacientes.end()) {
			if((*it).isFavorito())
				favoritos.push_back((*it));

			it++;
		}

		return favoritos;
	}

	std::list<Contacto> buscarFrecuentes()	// Devuelve una lista de los 10 contactos usados más frecuentemente
	{
		std::list<Contacto> frecuentes;
		std::list<Contacto>::iterator it = _pacientes.begin();

		while(it != _pacientes.end()) {
			if((*it).isFavorito())
				frecuentes.push_back((*it));

			it++;
		}

		return frecuentes;
	}

	std::list<Contacto> buscarContacto(std::string apellidos)
	{
		std::list<Contacto> encontrados;
		std::list<Contacto>::iterator it = _pacientes.begin();

		while(it != _pacientes.end()) {
			if((*it).getApellidos() == apellidos)
				encontrados.push_back((*it));

			it++;
		}

		return encontrados;
	}

	bool existeDNI(std::string dni){
		std::list<Contacto>::iterator it = _pacientes.begin();
		std::string prueba;
		while(it != _pacientes.end()) {
			if((*it).getDni() == dni)
				return true;
			it++;
		}

		return false;
	}

	void borrarContacto(Contacto &c) {

	}

	void cargarLista(){
		_pacientes = _gestor.cargar();
	}

	void guardarLista(){
		_gestor.guardar(_pacientes);
	}

	void setGestor(SGDBFichero g) { _gestor = g; }
	void setPacientes(std::list<Contacto> p) {
		std::list<Contacto>::iterator it = p.begin();

		while(it != _pacientes.end()) {
			_pacientes.push_back((*it));
			it++;
		}
	}

private:
	std::list<Contacto> _pacientes;
	SGDBFichero _gestor;
};

} /* namespace Dentista */


#endif /* AGENDA_H_ */
