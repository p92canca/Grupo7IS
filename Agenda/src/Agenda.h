/*
 * Agenda.h
 *
 *  Created on: 3/12/2014
 *      Author: dark
 */

#ifndef AGENDA_H_
#define AGENDA_H_

#include <string>
#include <list>

#include "Contacto.h"
#include "SGDB.h"
#include <list>

namespace Dentista {

class Agenda{
public:
	Agenda();
	virtual ~Agenda();

	void insertar(Contacto &c)
	{

	}

	void eliminar(std::string dni)
	{

	}

	void modificar(std::string dni, Contacto c)
	{

	}

	std::list<Contacto> buscarFavoritos()
	{

	}
private:
	std::list<Contacto> pacientes;
	SGDB gestor;
};
} /* namespace Dentista */


#endif /* AGENDA_H_ */
