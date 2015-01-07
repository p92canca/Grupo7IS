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
	virtual ~MenuTerminal();
};

void visualizarContacto(Contacto &c);
void visualizarAgenda(Agenda &a);
void modificarContacto();
void eliminarContacto(std::string dni);

} /* namespace Dentista */

#endif /* MENUTERMINAL_H_ */
