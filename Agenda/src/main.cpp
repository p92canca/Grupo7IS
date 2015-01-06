//============================================================================
// Name        : Agenda.cpp
// Author      : Grupo7
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdlib>
#include <vector>
#include "Agenda.h"

using namespace std;
using namespace Dentista;

int menu();

int main() {
	system("cls");

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

				break;
			}

			case 2:
			{

				break;
			}

			case 3:
			{
				system("cls");
				cout << "MOSTRANDO FAVORITOS" << endl;
				cout << "*******************" << endl;

				list<Contacto> favoritos;
				favoritos = buscarFavoritos();		// ¿Por qué no reconoce la función que está en Agenda.h?

				getchar();
				getchar();
				break;
			}

			case 4:
			{

				break;
			}

			case 5:
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
		cout << "(2) Mostrar consultas frecuentes" << endl;
		cout << "(3) Mostrar favoritos" << endl;
		cout << "(4) Modificar datos de paciente" << endl;
		cout << "(5) Borrar datos de paciente" << endl;
		cout << "(6) Generar informe" << endl;
		cout << "(0) Salir" << endl << endl;

		cout << "Su opcion: ";
		cin >> opcion;
	}while(opcion > 0 && opcion < 8);

	return opcion;
}
