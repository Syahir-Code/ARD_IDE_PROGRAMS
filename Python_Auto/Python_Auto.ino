
#include "DigiKeyboard.h" 
#include "DigiKeyboardFr.h"

void del() {
  delay (100);
}

//Small alphabet
void a() {
  DigiKeyboard.print("a");
  del();
}

void b() {
  DigiKeyboard.print("b");
  del();
}

void c() {
  DigiKeyboard.print("c");
  del();
}

void d() {
  DigiKeyboard.print("d");
  del();
}

void e() {
  DigiKeyboard.print("e");
  del();
}

void f() {
  DigiKeyboard.print("f");
  del();
}

void g() {
  DigiKeyboard.print("g");
  del();
}

void h() {
  DigiKeyboard.print("h");
  del();
}

void i() {
  DigiKeyboard.print("i");
  del();
}

void j() {
  DigiKeyboard.print("j");
  del();
}

void k() {
  DigiKeyboard.print("k");
  del();
}

void l() {
  DigiKeyboard.print("l");
  del();
}

void m() {
  DigiKeyboard.print("m");
  del();
}

void n() {
  DigiKeyboard.print("n");
  del();
}

void o() {
  DigiKeyboard.print("o");
  del();
}

void p() {
  DigiKeyboard.print("p");
  del();
}

void q() {
  DigiKeyboard.print("q");
  del();
}

void r() {
  DigiKeyboard.print("r");
  del();
}

void s() {
  DigiKeyboard.print("s");
  del();
}

void t() {
  DigiKeyboard.print("t");
  del();
}

void u() {
  DigiKeyboard.print("u");
  del();
}

void v() {
  DigiKeyboard.print("v");
  del();
}

void w() {
  DigiKeyboard.print("w");
}

void x() {
  DigiKeyboard.print("x");
}

void y() {
  DigiKeyboard.print("y");
}

void z() {
  DigiKeyboard.print("z");
}



//Capital alphabet
void A() {
  DigiKeyboard.print("A");
  del();
}

void B() {
  DigiKeyboard.print("B");
  del();
}

void C() {
  DigiKeyboard.print("C");
  del();
}

void D() {
  DigiKeyboard.print("D");
  del();
}

void E() {
  DigiKeyboard.print("E");
  del();
}

void F_() {
  DigiKeyboard.print("F");
  del();
}

void G() {
  DigiKeyboard.print("G");
  del();
}

void H() {
  DigiKeyboard.print("H");
  del();
}

void I() {
  DigiKeyboard.print("I");
  del();
}

void J() {
  DigiKeyboard.print("J");
  del();
}

void K() {
  DigiKeyboard.print("K");
  del();
}

void L() {
  DigiKeyboard.print("L");
  del();
}

void M() {
  DigiKeyboard.print("M");
  del();
}

void N() {
  DigiKeyboard.print("N");
  del();
}

void O() {
  DigiKeyboard.print("O");
  del();
}

void P() {
  DigiKeyboard.print("P");
  del();
}

void Q() {
  DigiKeyboard.print("Q");
  del();
}

void R() {
  DigiKeyboard.print("R");
  del();
}

void S() {
  DigiKeyboard.print("S");
  del();
}

void T() {
  DigiKeyboard.print("T");
  del();
}

void U() {
  DigiKeyboard.print("U");
  del();
}

void V() {
  DigiKeyboard.print("V");
  del();
}

void W() {
  DigiKeyboard.print("W");
}

void X() {
  DigiKeyboard.print("X");
}

void Y() {
  DigiKeyboard.print("Y");
}

void Z() {
  DigiKeyboard.print("Z");
}


//Numbers
void n0() {
  DigiKeyboard.print("0");
  del();
}

void n1() {
  DigiKeyboard.print("1");
  del();
}

void n2() {
  DigiKeyboard.print("2");
  del();
}

void n3() {
  DigiKeyboard.print("3");
  del();
}

void n4() {
  DigiKeyboard.print("4");
  del();
}

void n5() {
  DigiKeyboard.print("5");
  del();
}

void n6() {
  DigiKeyboard.print("6");
  del();
}

void n7() {
  DigiKeyboard.print("7");
  del();
}

void n8() {
  DigiKeyboard.print("8");
  del();
}

void n9() {
  DigiKeyboard.print("9");
  del();
}


void Import() {
  i(); 
  m();
  p();
  o();
  r();
  t();
}

void Print() {
  p();
  r();
  i();
  n();
  t();
}

void space() {
  DigiKeyboard.print(" ");
  del();
}

void setup() {
  Import();
  space();
  m();
  a();
  t();
  h();
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  del();
  Import();
  space();
  t();
  i();
  m();
  e();
  

}

void loop() {
  // put your main code here, to run repeatedly:

}
