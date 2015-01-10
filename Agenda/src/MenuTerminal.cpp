/*
 * MenuTerminal.cpp
 *
 *  Created on: 7/1/2015
 *      Author: Federico
 */

#include "MenuTerminal.h"

using namespace std;

namespace Dentista {

MenuTerminal::MenuTerminal() {
	// TODO Auto-generated constructor stub

}

void visualizarContacto(Contacto &c) {
	//list<Direccion> auxDir;
	//list<RedSocial> auxRed;

	cout << endl << endl << "Datos de " << c.getNombre() << " " << c.getApellidos() << ":" << endl;
	cout << "---------------------------------------------------------------------" << endl;

	cout << "DNI:\t" << c.getDni() << endl;
	cout << "Telefono 1:\t" << c.getTelefono1() << "\t| Telefono 2:\t" << c.getTelefono2() << endl;
	cout << "Correo 1:\t" << c.getCorreo1() << "\t| Correo 2:\t" << c.getCorreo2() << endl;
	//cout << "Direcciones:" << endl;
	//auxDir = c.getDireccion();
	// list<Direccion>::iterator it = auxDir.begin();
	// while(it != auxDir.end()) {
	// 	mostrarDireccion(*it);
	// 	it++;
	// }
	cout << "Redes Sociales:" << endl;
	//auxRed = c.getRedes();
	// list<RedSocial>::iterator itr = auxRed.begin();
	// while(itr != auxRed.end()) {
	// 	mostrarRedSocial(*itr);
	// 	itr++;
	// }
	cout << "Anotaciones:" << endl;
	cout << "\t" << c.getAnotaciones() << endl;

}

void visualizarAgenda(Agenda &a) {

}

bool eliminarContacto(std::string dni, Agenda &agenda) {

	std::list<Contacto> * pacientes = agenda.getPacientes();
	
	std::list<Contacto> :: iterator it;

	for (it = pacientes->begin(); it != pacientes->end(); it++){
	
		if ( (*it).getDni() == dni){

			agenda.eliminar(*it);
			return true;
		}
	}
	return false;
}

bool agregarFavorito(Agenda &agenda, Contacto &c) {

	std::list<Contacto> * pacientes = agenda.getPacientes();
	
	std::list<Contacto> :: iterator it;

	for (it = pacientes->begin(); it != pacientes->end(); it++){
	
		if ( (*it).getDni() == c.getDni()){

			(*it).setFavorito(true);
			return true;
		}
	}
	return false;
}

bool introducirDatosContacto(Agenda &agenda, Contacto &nuevo) {
	//char seguir = 'S';
	//int contadorDireccion = 1;
	//int contadorRed = 1;

	string nombre;
	string apellidos;
	string dni;
	int telefono1;
	int telefono2;
	string correo1;
	string correo2;
	//list<Direccion> direccion;
	string anotaciones;
	//list<RedSocial> redes;

	//Direccion direccionAuxiliar;
	RedSocial redSocialAuxiliar;

	cout << endl << "Nombre: ";
	cin >> nombre;
	nuevo.setNombre(nombre);

	cout << endl << "Apellidos: ";
	cin >> apellidos;
	nuevo.setApellidos(apellidos);

	cout << endl << "DNI: ";
	cin >> dni;
	nuevo.setDni(dni);
	if(agenda.existeDNI(dni))
	{
		cout << endl << "Error, el DNI introducido ya existe.";
		return false;
	}

	cout << endl << "Telefono: ";
	cin >> telefono1;
	nuevo.setTelefono1(telefono1);
	fflush(stdin);

	cout << endl << "Segundo telefono (opcional): ";
	cin >> telefono2;
	nuevo.setTelefono2(telefono2);
	fflush(stdin);

	cout << endl << "Correo electronico:  ";
	cin >> correo1;
	nuevo.setCorreo1(correo1);
	fflush(stdin);

	cout << endl << "Segundo correo electronico (opcional): ";
	cin >> correo2;
	nuevo.setCorreo2(correo2);
	fflush(stdin);

	// do{
	// 	cout << endl << "Direccion " << contadorDireccion << ": ";
	// 	direccionAuxiliar = introducirDireccion();
	// 	direccion.push_back(direccionAuxiliar);

	// 	cout << endl << "Desea introducir otra direccion? (S/N) ";
	// 	cin >> seguir;

	// 	contadorDireccion++;
	// }while(seguir == 's' || seguir == 'S');

	// do{
	// 	cout << endl << "Red Social " << contadorRed << ": ";
	// 	redSocialAuxiliar = introducirRedSocial();
	// 	redes.push_back(redSocialAuxiliar);

	// 	cout << endl << "Desea introducir otra Red Social? (S/N) ";
	// 	cin >> seguir;

	// 	contadorRed++;
	// }while(seguir == 's' || seguir == 'S');

	cout << endl << "Anotaciones: ";
	cin >> anotaciones;
	nuevo.setAnotaciones(anotaciones);

	nuevo.setFavorito(false);
	nuevo.setContadorAcceso(0);

	return true;
}

bool modificarContacto(Agenda &agenda, Contacto &c){

	Contacto nuevo(c);
	char seguir;

	string nombre;
	string apellidos;
	string dni;
	int telefono1;
	int telefono2;
	string correo1;
	string correo2;
	//list<Direccion> direccion;
	string anotaciones;
	//list<RedSocial> redes;

	//Direccion direccionAuxiliar;
	RedSocial redSocialAuxiliar;


	cout << endl << "Nombre: " << c.getNombre();
	cout << endl << "Modificar[S/N]?: ";
	fflush(stdin);
	cin >> seguir;

	if(seguir == 'S' || seguir == 's'){

		cin >> nombre;
		nuevo.setNombre(nombre);

	}

	cout << endl << "Apellidos: " << c.getApellidos();
	cout << endl << "Modificar[S/N]?: ";
	fflush(stdin);
	cin >> seguir;

	if(seguir == 'S' || seguir == 's'){
	
		cin >> apellidos;
		nuevo.setApellidos(apellidos);
	}

	cout << endl << "DNI: " << c.getDni();
	cout << endl << "Modificar[S/N]?: ";
	fflush(stdin);
	cin >> seguir;

	if(seguir == 'S' || seguir == 's'){

		cin >> dni;
		nuevo.setDni(dni);

		if(agenda.existeDNI(dni))
		{
			cout << endl << "Error, el DNI introducido ya existe.";
			return false;
		}
	}

	cout << endl << "Telefono: " << c.getTelefono1();
	cout << endl << "Modificar[S/N]?: ";
	fflush(stdin);
	cin >> seguir;

	if(seguir == 'S' || seguir == 's'){

		cin >> telefono1;
		nuevo.setTelefono1(telefono1);
		fflush(stdin);
	}

	cout << endl << "Segundo telefono (opcional): " << c.getTelefono2();
	cout << endl << "Modificar[S/N]?: ";
	fflush(stdin);
	cin >> seguir;

	if(seguir == 'S' || seguir == 's'){

		cin >> telefono2;
		nuevo.setTelefono2(telefono2);
		fflush(stdin);
	}

	cout << endl << "Correo electronico:  " << c.getCorreo1();
	cout << endl << "Modificar[S/N]?: ";
	fflush(stdin);
	cin >> seguir;

	if(seguir == 'S' || seguir == 's'){

		cin >> correo1;
		nuevo.setCorreo1(correo1);
		fflush(stdin);
	}

	cout << endl << "Segundo correo electronico (opcional): " << c.getCorreo2();
	cout << endl << "Modificar[S/N]?: ";
	fflush(stdin);
	cin >> seguir;

	if(seguir == 'S' || seguir == 's'){

		cin >> correo2;
		nuevo.setCorreo2(correo2);
		fflush(stdin);
	}

	agenda.eliminar(c);
	agenda.insertar(nuevo);

	return true;
}

bool crearInforme(list<Contacto> contacto_) {
	fstream informe;

	informe.open("Informe.txt", ios::out);
	      
	if (informe.is_open() == true)
	{
      	list <Contacto>::iterator i;

      	informe << "******************* AGENDA *******************" << endl;
      	for (i=contacto_.begin(); i!=contacto_.end(); i++)
		{
	        informe << "Nombre: \t"<<(*i).getNombre()<<"\n";
		   	informe << "Apellidos: \t"<< (*i).getApellidos()<<"\n";
		   	informe << "DNI: \t\t"<< (*i).getDni()<<"\n";
		   	informe << "Telefono 1: \t"<< (*i).getTelefono1()<<"\n";
		   	informe << "Telefono 2: \t" <<(*i).getTelefono2()<<"\n";
		   	informe << "Correo 1: \t"<< (*i).getCorreo1()<<"\n";
		   	informe << "Correo 2: \t"<< (*i).getCorreo2()<<"\n";
		   	informe << "Anotaciones: \t" <<(*i).getAnotaciones()<<"\n";
		   	informe << "-------------------()-------------------" << endl;
        }
	    informe.close();

	    return true;
	}
	else
		return false;
}

} /* namespace Dentista */
