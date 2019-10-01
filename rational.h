// a Rational object holds one Rational number, one fraction  // Carol Zander
// Example from Deitel and Deitel: C++ How To Program

#ifndef RAT2_H
#define RAT2_H
#include <iostream>
using namespace std;

//---------------------------------------------------------------------------
// Rational numbers:  defined as ratios of whole number, otherwise known as
//    fractions (can be proper or improper), all follow the laws of arithmetic
//    such as commutative law, associative law, distributive law, etc.
//    Examples include  2/3 , -7/8 , 20/9
//
// Implementation and assumptions:
//   -- Rationals are stored as integer numerators and denominators
//   -- if the rational number is negative, the Numerator is the negative
//   -- all stored rationals are reduced to lowest terms
//   -- all arithmetic operators return Rationals reduced to lowest terms
//   -- Dividing by zero returns zero

class Rational {

// overloaded <<: prints "DIVIDE BY ZERO ERROR!!!" if Denominator is zero,
//    prints whole numbers without Denominator (as ints), otherwise uses '/'
  friend ostream &operator<<(ostream &Output, const Rational &R);

// overloaded >>: takes 2 ints as Numerator and Denominator, does no
//    error checking, standard C casting between floats, char, etc occurs
  friend istream &operator>>(istream &input, Rational &R);

 public:
  // conversion function
  explicit operator int() const;
  // default constructor:  parameters are Numerator and Denominator resp.
  explicit Rational(int N = 0, int D = 1);

  // arithmetic operators
  Rational operator+(const Rational &A) const;   // add 2 Rationals
  Rational operator-(const Rational &S) const;   // subtract 2 Rationals
  Rational operator*(const Rational &M) const;   // multiply 2 Rationals
  Rational operator/(const Rational &V) const;   // divide 2 Rationals
  // division by zero terminates

  // boolean comparison operators
  bool operator>(const Rational &R) const;       // is object > parameter?
  bool operator<(const Rational &R) const;       // is object < parameter?
  bool operator>=(const Rational &R) const;      // is object >= parameter?
  bool operator<=(const Rational &R) const;      // is object >= parameter?
  bool operator==(const Rational &R) const;      // is object == parameter?
  bool operator!=(const Rational &R) const;      // is object != parameter?

  // assignment operators
  Rational &operator+=(const Rational &A);       // current object += parameter
// Rational& operator-=(const Rational &);       // current object -= parameter
// Rational& operator*=(const Rational &);       // current object *= parameter
// Rational& operator/=(const Rational &);       // current object /= parameter
  // division by zero terminates

 private:
  int Numerator;                       // Numerator of fraction
  int Denominator;                     // Denominator of fraction
  void reduce();                       // reduce fraction to lowest terms
};

#endif
