// Contacto_unittest.cpp: Grupo7
// A sample program demonstrating using Google C++ testing framework.
//
// This sample shows how to write a more complex unit test for a class
// that has multiple member functions.
//
// Usually, it's a good idea to have one test for each method in your
// class.  You don't have to do that exactly, but it helps to keep
// your tests organized.  You may also throw in additional tests as
// needed.

//#include <fstream>
#include <list>
#include <string>
#include "Contacto.h"
#include "gtest/gtest.h"

using namespace std;
using namespace Dentista;

TEST(Contacto, setAnotacionesygetAnotaciones) {
  Contacto c;  
  c.setAnotaciones("Paciente con dentadura");
  EXPECT_EQ("Paciente con dentadura", c.getAnotaciones());
  c.setAnotaciones("Paciente con carnet de jubilado");
  EXPECT_EQ("Paciente con carnet de jubilado", c.getAnotaciones());
}

TEST(Contacto, setApellidosygetApellidos) {
  Contacto c;
  c.setApellidos("Garcia Perez");
  EXPECT_EQ("Garcia Perez", c.getApellidos());
}

TEST(Contacto, setCorreosygetCorreos) {
  Contacto c;
  c.setCorreo1("antoniogarper@gmail.com");
  c.setCorreo2("antoniogarper@hotmail.com");
  EXPECT_EQ("antoniogarper@gmail.com", c.getCorreo1());
  EXPECT_EQ("antoniogarper@hotmail.com", c.getCorreo2());
}

TEST(Contacto, setDniygetDni) {
  Contacto c;
  c.setDni("30204456A");
  EXPECT_EQ("30204456A", c.getDni());
}

TEST(Contacto, setNombreygetNombre) {
  Contacto c;
  c.setNombre("Juan");
  EXPECT_EQ("Juan", c.getNombre());
}

TEST(Contacto, setTelefonosygetTelefonos) {
  Contacto c;
  c.setTelefono1(678234948);
  c.setTelefono2(654893123);
  EXPECT_EQ(678234948, c.getTelefono1());
  EXPECT_EQ(654893123, c.getTelefono2());
}
