/*
 * RedSocial.h
 *
 *  Created on: 3/12/2014
 *      Author: dark
 */

#ifndef REDSOCIAL_H_
#define REDSOCIAL_H_

#include <string>

namespace Dentista {

class RedSocial {
public:
	RedSocial();
	virtual ~RedSocial();

	const std::string& getNombreRed() const {
		return nombreRed;
	}

	void setNombreRed(const std::string& nombreRed) {
		this->nombreRed = nombreRed;
	}

	const std::string& getUsuario() const {
		return usuario;
	}

	void setUsuario(const std::string& usuario) {
		this->usuario = usuario;
	}

private:
	std::string nombreRed;
	std::string usuario;
};
} /* namespace Dentista */

#endif /* REDSOCIAL_H_ */
