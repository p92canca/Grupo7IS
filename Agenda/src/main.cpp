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
	system("clear");

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
				agenda.guardarLista();
				getchar();
				getchar();

				break;
			}

			case 1:
			{
				system("clear");
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
				system("clear");
				cout << "AGREGAR UN NUEVO CONTACTO" << endl;
				cout << "************************" << endl;

				Contacto nuevo;

				if(introducirDatosContacto(agenda, nuevo))
					agenda.insertar(nuevo);

				visualizarContacto(nuevo);
				getchar();
				getchar();
				break;
			}

			case 3:
			{
				system("clear");
				cout << "MOSTRANDO LOS 10 CONTACTOS MAS FRECUENTES" << endl;
				cout << "*****************************************" << endl;

				int contador = 0;
				list<Contacto> frecuentes;
				frecuentes = agenda.buscarFrecuentes();

				std::list<Contacto>::iterator it = frecuentes.begin();
				while(it != frecuentes.end() && contador < 10) {
					visualizarContacto((*it));
					it++;
					contador++;
				}

				getchar();
				getchar();
				break;
			}

			case 4:
			{
				system("clear");
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
				system("clear");
				cout << "AGREGAR CONTACTO A FAVORITOS" << endl;
				cout << "***************************" << endl;

				list<Contacto> encontrados;
				string apellidos;

				cout << "Introduzca apellidos del paciente: ";
				cin >>	apellidos;

				encontrados = agenda.buscarContacto(apellidos);

				//Listado de usuario, seleccionar por numero

				if(encontrados.size() != 0){
					list<Contacto>::iterator it = encontrados.begin();
					int orden = 1;
		
					while(it != encontrados.end()) {

						visualizarContacto((*it));
						it++;
					}
					/*
					 Seleccionar el contacto
					*/
					it = encontrados.begin();
					if(encontrados.size() > 1){
						do{
							cout << "\n\nVarias coincidencias, introduzca el orden: ";
							cin >>	orden;

						}while(orden < 1 || orden > encontrados.size());

						for(int i=0; i < orden-1; i++) it++;
					}
					agregarFavorito(agenda, *it);
				}
				else
					cout << "No se ha encontrado el contacto." << endl;

				getchar();
				getchar();
				break;
			}

			case 6:
			{
				system("clear");
				cout << "MODIFICANDO DATOS DE CONTACTO" << endl;
				cout << "*****************************" << endl;

				list<Contacto> encontrados;
				string apellidos;

				cout << "Introduzca apellidos del paciente: ";
				cin >>	apellidos;

				encontrados = agenda.buscarContacto(apellidos);

				if(encontrados.size() != 0){
					list<Contacto>::iterator it = encontrados.begin();
					int orden = 1;
		
					while(it != encontrados.end()) {

						visualizarContacto((*it));
						it++;
					}
					/*
					 Seleccionar el contacto
					*/
					it = encontrados.begin();
					if(encontrados.size() > 1){
						do{
							cout << "\n\nVarias coincidencias, introduzca el orden: ";
							cin >>	orden;

						}while(orden < 1 || orden > encontrados.size());

						for(int i=0; i < orden-1; i++) it++;
					}
					modificarContacto(agenda,(*it));
				}
				else
					cout << "No se ha encontrado el contacto." << endl;

				getchar();
				getchar();
				break;
			}

			case 7:
			{
				system("clear");
				cout << "ELIMINAR DATOS DE CONTACTO" << endl;
				cout << "**************************" << endl;

				list<Contacto> encontrados;
				string apellidos;

				cout << "Introduzca apellidos del paciente: ";
				cin >>	apellidos;

				encontrados = agenda.buscarContacto(apellidos);

				if(encontrados.size() != 0){
					list<Contacto>::iterator it = encontrados.begin();
					int orden = 1;
		
					while(it != encontrados.end()) {

						visualizarContacto((*it));
						it++;
					}
					/*
					 Seleccionar el contacto
					*/
					it = encontrados.begin();
					if(encontrados.size() > 1){
						do{
							cout << "\n\nVarias coincidencias, introduzca el orden: ";
							cin >>	orden;

						}while(orden < 1 || orden > encontrados.size());

						for(int i=0; i < orden-1; i++) it++;
					}
					eliminarContacto((*it).getDni(),agenda);
				}
				else
					cout << "No se ha encontrado el contacto." << endl;

				getchar();
				getchar();
				break;
			}

			case 8:
			{
				system("clear");
				cout << "GENERANDO INFORME DE AGENDA" << endl;
				cout << "***************************" << endl;

				if(crearInforme(*agenda.getPacientes()))
					cout << "Informe creado con éxito." << endl;
				else
					cout << "Error al crear el informe." << endl;

				getchar();
				getchar();
				break;
			}

			case 9:
			{
				system("clear");
				cout << "GENERANDO COPIA DE SEGURIDAD DEL ARCHIVO AGENDA" << endl;
				cout << "***********************************************" << endl;
				
				string backup;

				cout << "Introduzca nombre que recibirá el fichero de seguridad: ";
				cin >> backup;

				SGDBFichero copiaSeguridad(backup);
				copiaSeguridad.guardar(*agenda.getPacientes());

				cout << endl << "Se ha realizado la copia de seguridad en el fichero: " << backup << endl;
				getchar();
				getchar();
				break;
			}

			default:
			{
				cout << endl << "\t\tOpcion incorrecta. Intentelo de nuevo.";
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
		system("clear");

		cout << "MENU DEL SISTEMA AGENDA" << endl;
		cout << "***********************" << endl;
		cout << "(1) Buscar datos de paciente" << endl;
		cout << "(2) Insertar nuevo contacto" << endl;
		cout << "(3) Mostrar consultas frecuentes" << endl;
		cout << "(4) Mostrar favoritos" << endl;
		cout << "(5) Agregar contacto a favoritos" << endl;
		cout << "(6) Modificar datos de paciente" << endl;
		cout << "(7) Borrar datos de paciente" << endl;
		cout << "(8) Generar informe" << endl;
		cout << "(9) Generar copia de seguridad" << endl;
		cout << "(0) Salir" << endl << endl;

		cout << "Su opcion: ";
		cin >> opcion;

		if(opcion < 0 || opcion > 9)
			cout << endl << endl << "\tOpcion incorrecta. Intentelo de nuevo.";
	}while(opcion < 0 && opcion > 9);

	return opcion;
}
