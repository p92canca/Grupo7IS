/*
 * RedSocial_unittest.cpp

#include <string>
#include "RedSocial.h"
#include "gtest/gtest.h"

using namespace std;
using namespace dentista;

TEST(Nombre,RedSocial) {

 RedSocial d;

  d.setNombreRed("Twitter");
  EXPECT_EQ("Twitter", getNombreRed());
 }

TEST(Usuario,RedSocial) {

RedSocial d;

 d.setUsuario("@JTR");
 EXPECT_EQ("@JTR",getUsuario());
}
