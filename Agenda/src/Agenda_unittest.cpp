// Agenda_unittest.cpp: Grupo7

#include "Agenda.h"
#include "gtest/gtest.h"

using namespace std;
using namespace Dentista;


TEST(Agenda, insertarContactoyEliminarContacto) {
  Agenda a;
  Contacto c;
  
  c.setDni("12093487B");
  EXPECT_EQ(0, (*a.getPacientes()).size());
  a.insertar(c);
  EXPECT_EQ(1, (*a.getPacientes()).size());
  a.eliminar(c);
  EXPECT_EQ(0, (*a.getPacientes()).size());
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
