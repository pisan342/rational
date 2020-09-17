// a Rational object holds one Rational number, one fraction
// Example from Deitel and Deitel: C++ How To Program

#include "rational.h"

// default constructor using member values
Rational::Rational() = default;

// constructor with numberator only, denominator defaults to 1
Rational::Rational(int numerator) : numerator{numerator} {}

// constructor with numberator and denominator
Rational::Rational(int aNumerator, int aDenominator)
    : numerator{aNumerator}, denominator{aDenominator} {
  // If denominator is negative, flip both
  if (aDenominator < 0) {
    numerator = -aNumerator;
    denominator = -aDenominator;
  }
  // to lowest terms
  reduce();
}

Rational::operator int() const { return numerator / denominator; }
//----------------------------------------------------------------------------
// operator+
// overloaded +: addition of 2 Rationals, current object and parameter
// Result is reduced to lowest terms.

Rational Rational::operator+(const Rational &other) const {
  int n = other.numerator * denominator + other.denominator * numerator;
  int d = other.denominator * denominator;
  Rational result(n, d);
  return result;
}

//----------------------------------------------------------------------------
// operator-
// overloaded -: subtraction of 2 Rationals, current object and parameter
// Result is reduced to lowest terms.

Rational Rational::operator-(const Rational &other) const {
  int n = other.denominator * numerator - denominator * other.numerator;
  int d = other.denominator * denominator;
  Rational result(n, d);
  return result;
}

// overloaded *: multiplication of 2 Rationals, current object and parameter
Rational Rational::operator*(const Rational &other) const {
  int n = other.numerator * numerator;
  int d = other.denominator * denominator;
  Rational result(n, d);
  return result;
}

// overloaded /: division of 2 Rationals
Rational Rational::operator/(const Rational &other) const {
  Rational div;
  // make sure new denominator is not zero
  if (other.numerator != 0) {
    div.numerator = other.denominator * numerator;
    div.denominator = denominator * other.numerator;
    div.reduce();
  }
  return div;
}

// overloaded >: true if current object is > parameter, otherwise false
bool Rational::operator>(const Rational &other) const {
  return numerator * other.denominator > other.numerator * denominator;
}

// overloaded <: true if current object is < parameter, otherwise false
bool Rational::operator<(const Rational &other) const {
  return numerator * other.denominator < other.numerator * denominator;
}

// overloaded >=: true if current object is >= parameter, otherwise false
bool Rational::operator>=(const Rational &other) const {
  return *this == other || *this > other;
}

// overloaded <=: true if current object is <= parameter, otherwise false
bool Rational::operator<=(const Rational &other) const {
  return *this == other || *this < other;
}

// overloaded ==: true if current object is == parameter, otherwise false
bool Rational::operator==(const Rational &other) const {
  return numerator == other.numerator && denominator == other.denominator;
}

// overloaded !=: true if current object is != parameter, otherwise false
bool Rational::operator!=(const Rational &other) const {
  return !(*this == other);
}

// overloaded +=: current object = current object + parameter
Rational &Rational::operator+=(const Rational &other) {
  numerator = other.numerator * denominator + other.denominator * numerator;
  denominator *= other.denominator;
  reduce();
  return *this;
}

// overloaded -=: current object = current object - parameter
Rational &Rational::operator-=(const Rational &other) {
  numerator = numerator * other.denominator - other.numerator * denominator;
  denominator *= other.denominator;
  reduce();
  return *this;
}

// overloaded *=: current object = current object * parameter
Rational &Rational::operator*=(const Rational &other) {
  numerator *= other.numerator;
  denominator *= other.denominator;
  reduce();
  return *this;
}

// overloaded /=: current object = current object / parameter
Rational &Rational::operator/=(const Rational &other) {
  numerator *= other.denominator;
  denominator *= other.numerator;
  reduce();
  return *this;
}

//----------------------------------------------------------------------------
// operator<<
// overloaded <<: prints "DIVIDE BY ZERO ERROR!!!" if Denominator is zero,
//    prints whole numbers without Denominator (as ints), otherwise uses '/'
ostream &operator<<(ostream &output, const Rational &r) {
  if (r.denominator == 0) {
    return output << "DIVIDE BY ZERO ERROR!!!";
  }
  if (r.numerator == 0) {
    return output << 0;
  }
  if (r.denominator == 1) {
    // whole number
    return output << r.numerator;
  }
  return output << r.numerator << "/" << r.denominator;
}

//----------------------------------------------------------------------------
// operator>>
// overloaded >>: takes 2 ints as Numerator and Denominator, does no
//    error checking, standard C casting between floats, char, etc occurs

istream &operator>>(istream &input, Rational &r) {
  input >> r.numerator >> r.denominator;
  if (r.denominator < 0) {
    r.numerator = -r.numerator;
    r.denominator = -r.denominator;
  }
  r.reduce();
  return input;
}

// reduce fraction to lowest terms
void Rational::reduce() {
  // make Numerator positive
  int n = numerator < 0 ? -numerator : numerator;

  int greatestCommonCivisor = 0;

  // find Largest value that divides both Numerator and Denominator evenly
  for (int loop = max(n, denominator); loop > 1; loop--) {
    if (numerator % loop == 0 && denominator % loop == 0) {
      greatestCommonCivisor = loop;
      break;
    }
  }

  // alter Numerator, Denominator if originally not reduced to lowest terms
  if (greatestCommonCivisor != 0) {
    numerator /= greatestCommonCivisor;
    denominator /= greatestCommonCivisor;
  }
}
