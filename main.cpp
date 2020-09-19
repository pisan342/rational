#include <cassert>
#include <iostream>
#include <sstream>

#include "rational.h"

using namespace std;

// testing comparison
void test1() {
  Rational r12(1, 2);
  Rational r23(2, 3);
  assert(r23 > r12);
  assert(r23 >= r12);
  assert(r12 < r23);
  assert(r12 <= r23);
  assert(r12 != r23);
  Rational r48(4, 8);
  assert(r12 == r48);
}

// testing arithmetic
void test2() {
  stringstream ss;
  Rational r12(1, 2);
  Rational r23(2, 3);
  ss << r12 + r23;
  assert(ss.str() == "7/6");

  ss.str("");
  ss << r12 - r23;
  assert(ss.str() == "-1/6");

  ss.str("");
  ss << r12 * r23;
  assert(ss.str() == "1/3");

  ss.str("");
  ss << r12 / r23;
  assert(ss.str() == "3/4");
}

// testing assignment operators
void test3() {
  stringstream ss;
  Rational r12(1, 2);
  Rational r23(2, 3);
  r12 += r23;
  ss << r12;
  assert(ss.str() == "7/6");

  ss.str("");
  r12 = Rational(1, 2);
  r12 -= r23;
  ss << r12;
  assert(ss.str() == "-1/6");

  ss.str("");
  r12 = Rational(1, 2);
  r12 *= r23;
  ss << r12;
  assert(ss.str() == "1/3");

  ss.str("");
  r12 = Rational(1, 2);
  r12 /= r23;
  ss << r12;
  assert(ss.str() == "3/4");
}

// test miscellaneous
void test4() {
  stringstream ss;
  Rational r(-1, -2);
  ss << r;
  assert(ss.str() == "1/2");

  ss.str("");
  istringstream toRead("-20 -70");
  toRead >> r;
  ss << r;
  assert(ss.str() == "2/7");

  ss.str("");
  Rational r10(10);
  r *= r10;
  ss << r;
  assert(ss.str() == "20/7");

  // same as old style casting using (int)
  int num = static_cast<int>(r);
  assert(num == 2);

  ss.str("");
  Rational whole(7, 1);
  ss << whole;
  assert(ss.str() == "7");

  ss.str("");
  Rational zero(0, 10);
  ss << zero;
  assert(ss.str() == "0");
}

int main() {
  test1();
  test2();
  test3();
  test4();
  // Rational r1(1, 16);
  // Rational r2(4);
  // Rational r3 = r1 + r2;
  // cout << "r3: " << r3 << endl;
  cout << "Done." << endl;
  return 0;
}