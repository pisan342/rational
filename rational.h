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
  // overloaded >>:
  // prints whole numbers without Denominator (as ints), otherwise uses '/'
  friend ostream &operator<<(ostream &output, const Rational &r);

  // overloaded >>: takes 2 ints as Numerator and Denominator
  friend istream &operator>>(istream &input, Rational &r);

public:
  // explicit conversion function
  explicit operator int() const;
  // default constructor using member values
  Rational();
  // constructor with just numerator
  explicit Rational(int numerator);
  // default constructor with numerator and denomintor
  Rational(int numerator, int denominator);

  // accessor for numerator
  int getNumerator() const;

  // accessor for denominator
  int getDenominator() const;

  // arithmetic operators
  Rational operator+(const Rational &other) const;
  Rational operator-(const Rational &other) const;
  Rational operator*(const Rational &other) const;
  Rational operator/(const Rational &other) const;

  // boolean comparison operators
  bool operator>(const Rational &other) const;
  bool operator<(const Rational &other) const;
  bool operator>=(const Rational &other) const;
  bool operator<=(const Rational &other) const;
  bool operator==(const Rational &other) const;
  bool operator!=(const Rational &other) const;

  // assignment operators
  Rational &operator+=(const Rational &other);
  Rational &operator-=(const Rational &other);
  Rational &operator*=(const Rational &other);
  Rational &operator/=(const Rational &other);

private:
  // Numerator of fraction
  int numerator = 0;
  // Denominator of fraction
  int denominator = 1;
  // reduce fraction to lowest terms
  void reduce();
};

#endif
