// a Rational object holds one Rational number, one fraction
// Example from Deitel and Deitel: C++ How To Program

#include "rational.h"

//----------------------------------------------------------------------------
// Rational
// Parameters are Numerator and Denominator respectively.
// Takes zero, one, two parameters. Parameters have default values of 0, 1.

Rational::Rational(int N, int D) {
  cout << "Creating rational with " << N << " and " << D << endl;
  Numerator = D < 0 ? -N : N;            // Numerator is always the negative
  Denominator = D < 0 ? -D : D;          // Denominator is always positive
  reduce();                              // to lowest terms
}

Rational::operator int() const {
  cout << "Inside int() with Numerator = " << Numerator << " and denom = " << Denominator << endl;
  return Numerator / Denominator;
}
//----------------------------------------------------------------------------
// operator+
// overloaded +: addition of 2 Rationals, current object and parameter
// Result is reduced to lowest terms.

Rational Rational::operator+(const Rational &A) const {
  Rational Sum;

  Sum.Numerator = A.Numerator * Denominator + A.Denominator * Numerator;
  // same as:
  // Sum.Numerator = A.Numerator * this->Denominator
  //                 + A.Denominator * this->Numerator;

  Sum.Denominator = A.Denominator * Denominator;
  Sum.reduce();

  return Sum;
}

//----------------------------------------------------------------------------
// operator-
// overloaded -: subtraction of 2 Rationals, current object and parameter
// Result is reduced to lowest terms.

Rational Rational::operator-(const Rational &S) const {
  Rational Sub;

  Sub.Numerator = S.Denominator * Numerator - Denominator * S.Numerator;
  Sub.Denominator = S.Denominator * Denominator;
  Sub.reduce();

  return Sub;
}

//----------------------------------------------------------------------------
// operator*
// overloaded *: multiplication of 2 Rationals, current object and parameter
// Result is reduced to lowest terms.

Rational Rational::operator*(const Rational &M) const {
  Rational Mult;

  Mult.Numerator = M.Numerator * Numerator;
  Mult.Denominator = M.Denominator * Denominator;
  Mult.reduce();

  return Mult;
}

//----------------------------------------------------------------------------
// operator/
// overloaded /: division of 2 Rationals, current object and parameter,
//               division by zero terminates prog
// Result is reduced to lowest terms.

Rational Rational::operator/(const Rational &V) const {
  Rational Div;

  if (V.Numerator != 0) {              // make sure new Denominator != zero
    Div.Numerator = V.Denominator * Numerator;
    Div.Denominator = Denominator * V.Numerator;
    Div.reduce();
  }
  return Div;
}

//----------------------------------------------------------------------------
// operator>
// overloaded >: true if current object is > parameter, otherwise false

bool Rational::operator>(const Rational &R) const {
  // Old C-style cast
  // return (float) Numerator / Denominator > (float) R.Numerator / R.Denominator;
  // do not give warning for the narrowing conversion
  return (static_cast<float>(Numerator) / Denominator) >       // NOLINT
      (static_cast<float>(R.Numerator) / R.Denominator);       // NOLINT
}

//----------------------------------------------------------------------------
// operator<
// overloaded <: true if current object is < parameter, otherwise false

bool Rational::operator<(const Rational &R) const {
  // do not give warning for the narrowing conversion
  return (static_cast<float>(Numerator) / Denominator) <         // NOLINT
      (static_cast<float>(R.Numerator) / R.Denominator);         // NOLINT
}

//----------------------------------------------------------------------------
// operator>=
// overloaded >=: true if current object is >= parameter, otherwise false

bool Rational::operator>=(const Rational &R) const {
  return *this == R || *this > R;
}

//----------------------------------------------------------------------------
// operator<=
// overloaded <=: true if current object is <= parameter, otherwise false

bool Rational::operator<=(const Rational &r) const {
  return *this == r || *this < r;
}

//----------------------------------------------------------------------------
// operator==
// overloaded ==: true if current object is == parameter, otherwise false

bool Rational::operator==(const Rational &R) const {
  return (Numerator == R.Numerator && Denominator == R.Denominator);
}

//----------------------------------------------------------------------------
// operator!=
// overloaded !=: true if current object is != parameter, otherwise false

bool Rational::operator!=(const Rational &r) const {
  return !(*this == r);
}

//----------------------------------------------------------------------------
// operator+=
// overloaded +=: current object = current object + parameter
// Result is reduced to lowest terms.

Rational &Rational::operator+=(const Rational &A) {

  Numerator = A.Numerator * Denominator + A.Denominator * Numerator;
  Denominator = A.Denominator * Denominator;

  // Or the following although less efficient because of extra new/deletes
  // *this = *this + A;

  reduce();

  return *this;
}

//----------------------------------------------------------------------------
// operator<<
// overloaded <<: prints "DIVIDE BY ZERO ERROR!!!" if Denominator is zero,
//    prints whole numbers without Denominator (as ints), otherwise uses '/'

ostream &operator<<(ostream &Output, const Rational &R) {
  if (R.Denominator == 0)
    Output << endl << "DIVIDE BY ZERO ERROR!!!" << endl;
  else if (R.Numerator == 0)                              // zero rational
    Output << 0;
  else if (R.Denominator == 1)                            // whole number
    Output << R.Numerator;
  else
    Output << R.Numerator << "/" << R.Denominator;

  return Output;
}

//----------------------------------------------------------------------------
// operator>>
// overloaded >>: takes 2 ints as Numerator and Denominator, does no
//    error checking, standard C casting between floats, char, etc occurs

istream &operator>>(istream &input, Rational &R) {
  input >> R.Numerator >> R.Denominator;
  R.reduce();

  return input;
}

//----------------------------------------------------------------------------
// reduce
// reduce fraction to lowest terms

void Rational::reduce() {
  int N = Numerator < 0 ? -Numerator : Numerator;  // make Numerator positive
  int D = Denominator;
  int Largest = N > D ? N : D;           // larger of Numerator and denom

  int Gcd = 0;                           // greatest common divisor

  // find Largest value that divides both Numerator and Denominator evenly
  for (int Loop = Largest; Loop >= 2; Loop--)
    if (Numerator % Loop == 0 && Denominator % Loop == 0) {
      Gcd = Loop;
      break;
    }

  // alter Numerator, Denominator if originally not reduced to lowest terms
  if (Gcd != 0) {
    Numerator /= Gcd;
    Denominator /= Gcd;
  }
}
