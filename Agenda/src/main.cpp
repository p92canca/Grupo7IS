//============================================================================
// Name        : Agenda.cpp
// Author      : Grupo7
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdlib>
#include <list>
#include "Agenda.h"
#include "MenuTerminal.h"

using namespace std;
using namespace Dentista;

int menu();

int main() {
	system("cls");

	string fichero = "agenda";
	SGDBFichero almacenamiento(fichero);
	Agenda agenda = almacenamiento.cargar();

	int opcion;

	do{
		opcion = menu();

		switch(opcion)
		{
			case 0:
			{
				cout << endl << "\t\tHa seleccionado salir.";
				getchar();
				getchar();

				break;
			}

			case 1:
			{
				system("cls");
				cout << "BUSCAR DATOS DE PACIENTES" << endl;
				cout << "*************************" << endl;

				list<Contacto> encontrados;
				string apellidos;

				cout << "Introduzca apellidos del paciente: ";
				cin >>	apellidos;

				encontrados = agenda.buscarContacto(apellidos);

				if(encontrados.size() == 0)
					cout << endl << "No hay coincidencias.";
				else
				{
					std::list<Contacto>::iterator it = encontrados.begin();
					while(it != encontrados.end()) {
						visualizarContacto((*it));
						it++;
					}
				}

				getchar();
				getchar();
				break;
				break;
			}

			case 2:
			{
				system("cls");

				char seguir = 'S';
				int contadorDireccion = 1;
				int contadorRed = 1;

				string nombre;
				string apellidos;
				string dni;
				int telefono1;
				int telefono2;
				string correo1;
				string correo2;
				list<Direccion> direccion;
				string anotaciones;
				list<RedSocial> redes;

				Direccion direccionAuxiliar;
				RedSocial redSocialAuxiliar;

				cout << "AÑADIR UN NUEVO CONTACTO" << endl;
				cout << "************************" << endl;

				Contacto nuevo;

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
					break;
				}

				cout << endl << "Teléfono: ";
				cin >> telefono1;
				nuevo.setTelefono1(telefono1);

				cout << endl << "Segundo teléfono (opcional): ";
				cin >> telefono2;
				nuevo.setTelefono2(telefono2);

				cout << endl << "Correo electrónico:  ";
				cin >> correo1;
				nuevo.setCorreo1(correo1);

				cout << endl << "Segundo correo electrónico (opcional): ";
				cin >> correo2;
				nuevo.setCorreo2(correo2);

				do{
					cout << endl << "Dirección " << contadorDireccion << ": ";
					direccionAuxiliar = introducirDireccion();
					direccion.push_back(direccionAuxiliar);

					cout << endl << "¿Desea introducir otra dirección? (S/N) ";
					cin >> seguir;

					contadorDireccion++;
				}while(seguir == 's' || seguir == 'S');

				do{
					cout << endl << "Red Social " << contadorRed << ": ";
					redSocialAuxiliar = introducirRedSocial();
					redes.push_back(redSocialAuxiliar);

					cout << endl << "¿Desea introducir otra Red Social? (S/N) ";
					cin >> seguir;

					contadorRed++;
				}while(seguir == 's' || seguir == 'S');

				cout << endl << "Anotaciones: ";
				cin >> anotaciones;
				nuevo.setAnotaciones(anotaciones);

				agenda.insertar(nuevo);

				getchar();
				getchar();
				break;
				break;
			}

			case 3:
			{

				break;
			}

			case 4:
			{
				system("cls");
				cout << "MOSTRANDO FAVORITOS" << endl;
				cout << "*******************" << endl;

				list<Contacto> favoritos;
				favoritos = agenda.buscarFavoritos();

				std::list<Contacto>::iterator it = favoritos.begin();
				while(it != favoritos.end()) {
					visualizarContacto((*it));
					it++;
				}

				getchar();
				getchar();
				break;
			}

			case 5:
			{
				system("cls");
				cout << "AÑADIR CONTACTO A FAVORITOS" << endl;
				cout << "***************************" << endl;

				list<Contacto> encontrados;
				string apellidos;

				cout << "Introduzca apellidos del paciente: ";
				cin >>	apellidos;

				encontrados = agenda.buscarContacto(apellidos);

				std::list<Contacto>::iterator it = encontrados.begin();
				while(it != encontrados.end()) {
					visualizarContacto((*it));
					it++;
				}

				getchar();
				getchar();
				break;
			}

			case 6:
			{

				break;
			}

			case 7:
			{

				break;
			}

			case 8:
			{

				break;
			}

			default:
			{
				cout << endl << "\t\tOpción incorrecta. Inténtelo de nuevo.";
				getchar();
				getchar();
			}
		}
	}while(opcion != 0);

	return 0;
}

int menu() {
	int opcion;

	do{
		system("cls");

		cout << "MENU DEL SISTEMA AGENDA" << endl;
		cout << "***********************" << endl;
		cout << "(1) Buscar datos de paciente" << endl;
		cout << "(2) Insertar nuevo contacto" << endl;
		cout << "(3) Mostrar consultas frecuentes" << endl;
		cout << "(4) Mostrar favoritos" << endl;
		cout << "(5) Añadir contacto a favoritos" << endl;
		cout << "(6) Modificar datos de paciente" << endl;
		cout << "(7) Borrar datos de paciente" << endl;
		cout << "(8) Generar informe" << endl;
		cout << "(0) Salir" << endl << endl;

		cout << "Su opcion: ";
		cin >> opcion;

		if(opcion < 0 || opcion > 8)
			cout << endl << endl << "\tOpción incorrecta. Inténtelo de nuevo.";
	}while(opcion < 0 && opcion > 8);

	return opcion;
}
