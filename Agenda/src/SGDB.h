/*
 * SGDB.h
 *
 *  Created on: 10/12/2014
 *      Author: dark
 */
#ifndef SGDB_H_
#define SGDB_H_

#include <list>
#include "Contacto.h"

namespace Dentista {

class SGDB {
public:
	virtual ~SGDB(){};

	virtual void guardar(std::list<Contacto> pacientes) = 0;

	virtual std::list<Contacto> cargar() = 0;
};

} /* namespace Dentista */

#endif /* SGDB_H_ */