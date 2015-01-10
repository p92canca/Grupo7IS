/*
 * MenuTerminal.h
 *
 *  Created on: 7/1/2015
 *      Author: Federico
 */

#ifndef MENUTERMINAL_H_
#define MENUTERMINAL_H_

#include <iostream>
#include <string>

#include "Agenda.h"

namespace Dentista {

class MenuTerminal {
public:
	MenuTerminal();
	virtual ~MenuTerminal(){};
};

void visualizarContacto(Contacto &c);
void visualizarAgenda(Agenda &a);
bool modificarContacto(Contacto &c, Agenda &agenda);
bool eliminarContacto(std::string dni, Agenda &agenda);
bool modificarContacto(Agenda &agenda, Contacto &c);
bool introducirDatosContacto(Agenda &agenda, Contacto &nuevo);
bool agregarFavorito(Agenda &agenda, Contacto &nuevo);
bool crearInforme(list<Contacto> contacto_);

} /* namespace Dentista */

#endif /* MENUTERMINAL_H_ */
