/*
 * SGDBFichero.h
 *
 *  Created on: 10/12/2014
 *      Author: dark
 */

#ifndef SGDBFICHERO_H_
#define SGDBFICHERO_H_

#include <string>
#include "SGDB.h"

namespace Dentista {

class SGDBFichero: public SGDB {
private:
	std::string fichero;
public:
	SGDBFichero();
	virtual ~SGDBFichero();

	void guardar(std::list<Contacto> pacientes){

	}

	std::list<Contacto> cargar(){
		std::list<Contacto> pacientes;

		return pacientes;
	}
};

} /* namespace Dentista */

#endif /* SGDBFICHERO_H_ */
