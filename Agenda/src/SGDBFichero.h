/*
 * SGDBFichero.h
 *
 *  Created on: 10/12/2014
 *      Author: dark
 */

#ifndef SGDBFICHERO_H_
#define SGDBFICHERO_H_

#include <string>
#include <list>
#include <fstream>
#include <cstring>
#include <iostream>
#include "SGDB.h"

using namespace std;

namespace Dentista {

class SGDBFichero:public SGDB {
private:
	std::string _fichero;
public:
	SGDBFichero() throw (){ }
	SGDBFichero(std::string fichero)  throw () { _fichero = fichero; }
	virtual ~SGDBFichero(){};

	void guardar(std::list<Contacto> pacientes){
		std::string auxiliar="auxiliar.tmp";
		std::ofstream flujoSalida;
		Contacto personaAux;

		flujoSalida.open(auxiliar.c_str(), std::ios::app);// | std::ios::binary);

		std::list<Contacto>::iterator it = pacientes.begin();

		while(it != pacientes.end()) {
			personaAux = (*it);
			flujoSalida.write((char *) (&personaAux), sizeof(Contacto));
			it++;
		}

		flujoSalida.close();

		remove(_fichero.c_str());
		rename(auxiliar.c_str(), _fichero.c_str());

	}

	std::list<Contacto> cargar(){
		std::list<Contacto> pacientes;
		std::ifstream flujoEntrada;
		Contacto c;

		flujoEntrada.open(_fichero.c_str(), std::ios::in);

		//flujoEntrada.read(reinterpret_cast<char *>(&c), flujoEntrada.tellg());
		flujoEntrada.read((char *) (&c), sizeof(Contacto));

		while(flujoEntrada)
		{
			pacientes.push_back(c);
			//c.getNombre();
			// cout << "Paciente: " << c.getNombre() << " favorito: " << c.isFavorito() << endl;
			// getchar();
			// getchar();
			flujoEntrada.read((char *) (&c), sizeof(Contacto));
		}
		flujoEntrada.close();

		return pacientes;
	}

	void setFichero(std::string f) { _fichero = f; }
};

} /* namespace Dentista */

#endif /* SGDBFICHERO_H_ */
