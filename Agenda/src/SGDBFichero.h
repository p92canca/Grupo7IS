/*
 * SGDBFichero.h
 *
 *  Created on: 10/12/2014
 *      Author: dark
 */

#ifndef SGDBFICHERO_H_
#define SGDBFICHERO_H_

#include <string>

namespace Dentista {

class SGDBFichero {
public:
	SGDBFichero();
	virtual ~SGDBFichero();

private:
	std::string fichero;
};

} /* namespace Dentista */

#endif /* SGDBFICHERO_H_ */
