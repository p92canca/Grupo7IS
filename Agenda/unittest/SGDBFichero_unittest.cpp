// SGDBFichero_unittest.cpp: Grupo7

/*TEST(Jugador, setApuestasygetApuestas) {
  Jugador j("33XX", "1");
  string nomfich=j.getDNI()+".txt";
  ofstream salida(nomfich.c_str());
  salida << 1 << "," << "10" << "," << 15<< "\n";
  salida << 2 << "," << "rojo" << "," << 25<< "\n";
  salida << 3 << "," << "par" << "," << 35<< "\n";
  salida << 4 << "," << "bajo" << "," << 45<< "\n";
  salida.close();
  list<Apuesta> l;
  j.setApuestas();
  l= j.getApuestas();
  EXPECT_EQ(4, l.size());
  list<Apuesta>::iterator i;
  i=l.begin();
  EXPECT_EQ(1, (*i).tipo);
  EXPECT_EQ("10", (*i).valor);
  EXPECT_EQ(15, (*i).cantidad);
  i++;
  EXPECT_EQ(2, (*i).tipo);
  EXPECT_EQ("rojo", (*i).valor);
  EXPECT_EQ(25, (*i).cantidad);
  i++;
  EXPECT_EQ(3, (*i).tipo);
  EXPECT_EQ("par", (*i).valor);
  EXPECT_EQ(35, (*i).cantidad);
  i++;
  EXPECT_EQ(4, (*i).tipo);
  EXPECT_EQ("bajo", (*i).valor);
  EXPECT_EQ(45, (*i).cantidad);
}*/

