#include <iostream>

#include "rational.h"

int main() {
  Rational R1(1, 16);
  //Rational R2(1, 8);
  //Rational r4;
  Rational R2;
  Rational R5 = Rational(5) + R1;
  //r4 = R1 + (R1 += R2);
  cout << "R5: " << R5 << endl;
  //cout << r4 << endl;
  std::cout << "Hello, World!" << std::endl;
  return 0;
}