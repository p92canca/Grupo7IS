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


#include "SGDBFichero.h"

namespace Dentista {

class Agenda{
public:

	std::list<Contacto> * getPacientes()
	{

		return &_pacientes;
	}

	void insertar(Contacto &c)
	{
		bool insertado = false;

		std::list<Contacto>::iterator it = _pacientes.begin();
		while(it != _pacientes.end()) {
			if((*it).getApellidos().compare(c.getApellidos()) > 0)
			{
				_pacientes.insert(it, c);
				insertado = true;
				break;
			}
			it++;
		}
		if(not insertado)
			_pacientes.insert(it, c);
	}

	void eliminar(Contacto &c)
	{
		std::list<Contacto>::iterator it = _pacientes.begin();

		while(it != _pacientes.end()) {
			if((*it).getDni() == c.getDni()){
				_pacientes.erase(it);
				break;
			}
			else
				it++;
		}
	}

	void modificar(Contacto c)
	{
		std::list<Contacto>::iterator it = _pacientes.begin();

		while(it != _pacientes.end()) {
			if((*it).getDni() == c.getDni()){
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

	static bool compararFrecuentes(const Contacto& a,const Contacto& b)  {

		return a.getContadorAcceso() > b.getContadorAcceso();

	}

	std::list<Contacto> buscarFrecuentes()	// Devuelve una lista de los 10 contactos usados más frecuentemente
	{
		std::list<Contacto> frecuentes;
		std::list<Contacto>::iterator it = _pacientes.begin();

		while(it != _pacientes.end()) {
			
			if((*it).getContadorAcceso() != 0) frecuentes.push_back((*it));
			it++;
		}

		frecuentes.sort(compararFrecuentes);

		return frecuentes;
	}

	
	std::list<Contacto> buscarContacto(std::string apellidos)
	{
		std::list<Contacto> encontrados;
		std::list<Contacto>::iterator it = _pacientes.begin();
		int contador;

		while(it != _pacientes.end()) {
			if((*it).getApellidos() == apellidos){
				encontrados.push_back((*it));
				contador = (*it).getContadorAcceso() + 1;
				(*it).setContadorAcceso(contador);
			}
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
