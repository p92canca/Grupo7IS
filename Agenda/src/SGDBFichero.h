/*
 * SGDBFichero.h
 *
 *  Created on: 10/12/2014
 *      Author: dark
 */

#ifndef SGDBFICHERO_H_
#define SGDBFICHERO_H_

#include <string>
#include <fstream>
#include "SGDB.h"

namespace Dentista {

class SGDBFichero: public SGDB {
private:
	std::string _fichero;
public:
	SGDBFichero(std::string f);
	virtual ~SGDBFichero();

	void guardar(std::list<Contacto> pacientes){

	}

	std::list<Contacto> cargar(){
		std::list<Contacto> pacientes;
		std::ifstream flujoEntrada;
		Contacto c;

		flujoEntrada.open(_fichero.c_str(), std::ios::in);

		flujoEntrada.read((char *) (&c), sizeof(Contacto));
		while(flujoEntrada)
		{
			pacientes.push_back(c);
			flujoEntrada.read((char *) (&c), sizeof(Contacto));
		}
		flujoEntrada.close();

		return pacientes;
	}

	void setFichero(std::string f) { _fichero = f; }
};

} /* namespace Dentista */

#endif /* SGDBFICHERO_H_ */
