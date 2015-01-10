// Agenda_unittest.cpp: Grupo7

#include <string>
#include <fstream>
#include <list>
#include <iostream>
#include <algorithm>
#include "Contacto.h"
#include "Agenda.h"
#include "SGDBFichero.h"
#include <list>
#include "gtest/gtest.h"

using namespace std;
using namespace Dentista;

TEST(Agenda, insertarContacto) {
  Agenda a;
  Contacto c, d;
  c.setDni("12093487B");
  d.setDni("46573919D");
  list<Contacto> pacientes;
  a.insertar(c);
  a.insertar(d);
  EXPECT_EQ(2, pacientes.size());
  list<Contacto>::iterator i;
  i=pacientes.begin();
  EXPECT_EQ("12093487B", (*i).getDni());
  i++;
  EXPECT_EQ("46573919D", (*i).getDni());
}

TEST(Agenda, eliminarContacto) {
  Agenda a;
  Contacto c, d;
  c.setDni("12093487B");
  d.setDni("46573919D");
  list<Contacto> pacientes;
  EXPECT_EQ(2, pacientes.size());
  a.eliminar("12093487B");
  EXPECT_EQ(1, pacientes.size());
  EXPECT_EQ("46573919D", pacientes.begin()->getDni());
  a.eliminar("46573919D");
  EXPECT_EQ(0, pacientes.size());
}

TEST(Agenda, modificarContacto) {
  Agenda a;
  Contacto c;
  list<Contacto> pacientes;
  c.setDni("12093487B");
  EXPECT_EQ("12093487B", pacientes.begin()->getDni());
  a.modificar("20223704B",c);
  EXPECT_EQ("20223704B", pacientes.begin()->getDni());
}

TEST(Agenda, buscarFavoritos) {
  Agenda a;
  Contacto c, d;
  list<Contacto> pacientes;
  list<Contacto>::iterator i; 
  c.setFavorito(true);
  d.setFavorito(true);
  a.insertar(c);
  a.insertar(d);
  pacientes = a.buscarFavoritos();
  i=pacientes.begin();
  EXPECT_TRUE((*i).isFavorito());
  i++;
  EXPECT_TRUE((*i).isFavorito());  
}

TEST(Agenda, buscarContacto) {
  Agenda a;
  Contacto c;
  list<Contacto> pacientes;
  list<Contacto> buscados;
  list<Contacto>::iterator i;
  //i = pacientes.begin();
  c.setApellidos("Perez Lima");
  pacientes.push_back(c);
  buscados = a.buscarContacto("Perez Lima");
  EXPECT_EQ("Perez Lima", buscados.begin()->getApellidos());
}
