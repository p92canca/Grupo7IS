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
bool introducirDatosContacto(Agenda &agenda, Contacto &nuevo);

int main() {
	system("cls");

	string fichero = "agenda";
	SGDBFichero almacenamiento(fichero);
	Agenda agenda;

	agenda.setGestor(almacenamiento);
	agenda.cargarLista();

	int opcion;

	do{
		opcion = menu();

		switch(opcion)
		{
			case 0:
			{
				cout << endl << "\t\tHa seleccionado salir.";
				agenda.guardarLista()
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
			}

			case 2:
			{
				system("cls");
				cout << "AÑADIR UN NUEVO CONTACTO" << endl;
				cout << "************************" << endl;

				Contacto nuevo;

				if(introducirDatosContacto(agenda, nuevo))
					agenda.insertar(nuevo);

				getchar();
				getchar();
				break;
			}

			case 3:
			{
				system("cls");
				cout << "MOSTRANDO LOS 10 CONTACTOS MÁS FRECUENTES" << endl;
				cout << "*****************************************" << endl;

				list<Contacto> frecuentes;
				frecuentes = agenda.buscarFavoritos();

				std::list<Contacto>::iterator it = frecuentes.begin();
				while(it != frecuentes.end()) {
					visualizarContacto((*it));
					it++;
				}

				getchar();
				getchar();
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

			case 5:		// Falta que permita seleccionar a uno de los contactos
			{
				system("cls");
				cout << "AÑADIR CONTACTO A FAVORITOS" << endl;
				cout << "***************************" << endl;

				list<Contacto> encontrados;
				string apellidos;

				cout << "Introduzca apellidos del paciente: ";
				cin >>	apellidos;

				encontrados = agenda.buscarContacto(apellidos);

				if(encontrados.size() != 0){
					list<Contacto>::iterator it = encontrados.begin();
					while(it != encontrados.end()) {
						visualizarContacto((*it));
						it++;
					}
					/*
					 Seleccionar el contacto
					*/
					(*it).setFavorito(true);
				}
				else
					cout << "No se ha encontrado el contacto." << endl;

				getchar();
				getchar();
				break;
			}

			case 6:
			{
				system("cls");
				cout << "MODIFICANDO DATOS DE CONTACTO" << endl;
				cout << "*****************************" << endl;

				list<Contacto> encontrados;
				string apellidos;

				cout << "Introduzca apellidos del paciente: ";
				cin >>	apellidos;

				encontrados = agenda.buscarContacto(apellidos);

				if(encontrados.size() != 0){
					list<Contacto>::iterator it = encontrados.begin();
					while(it != encontrados.end()) {
						visualizarContacto((*it));
						it++;
					}
					/*
					 Seleccionar el contacto
					*/
					if(introducirDatosContacto(agenda, (*it)))
						cout << endl << "Usuario modificado con éxito.";
				}
				else
					cout << "No se ha encontrado el contacto." << endl;

				getchar();
				getchar();
				break;
			}

			case 7:
			{
				system("cls");
				cout << "ELIMINAR DATOS DE CONTACTO" << endl;
				cout << "**************************" << endl;

				list<Contacto> encontrados;
				string apellidos;

				cout << "Introduzca apellidos del paciente: ";
				cin >>	apellidos;

				encontrados = agenda.buscarContacto(apellidos);

				if(encontrados.size() != 0){
					list<Contacto>::iterator it = encontrados.begin();
					while(it != encontrados.end()) {
						visualizarContacto((*it));
						it++;
					}
					/*
					 Seleccionar el contacto
					*/
					agenda.borrarContacto((*it));
				}
				else
					cout << "No se ha encontrado el contacto." << endl;

				getchar();
				getchar();
				break;
			}

			case 8:
			{
				system("cls");
				cout << "GENERANDO INFORME DE AGENDA" << endl;
				cout << "***************************" << endl;


				getchar();
				getchar();
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
