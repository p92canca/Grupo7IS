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
	SGDBFichero() throw () { }
	SGDBFichero(std::string fichero)  throw () { _fichero = fichero; }
	virtual ~SGDBFichero();

	void guardar(std::list<Contacto> pacientes){
		std::string auxiliar="auxiliar.tmp";
		std::ofstream flujoSalida;
		Contacto personaAux;

		flujoSalida.open(auxiliar.c_str(), ios::out);

		std::list<Contacto>::iterator it = pacientes.begin();

		while(it != pacientes.end()) {
			flujoSalida.write((char *) (&it), sizeof(Contacto));
			it++;
		}

		flujoSalida.close();

		remove(_fichero.c_str());
		rename(auxiliar.c_str(), _fichero.c_str());*/

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
