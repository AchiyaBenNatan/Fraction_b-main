#include "Fraction.hpp"
#include <iostream>
#include <string>
using namespace ariel;
namespace ariel
{
    Fraction::Fraction()
    {
        this->numerator = 1;
        this->denominator = 1;
    }
    Fraction::Fraction(int mone, int mechane)
    {
        this->numerator = mone;
        this->denominator = mechane;
    }
    int Fraction::getMone()
    {
        return this->numerator;
    }
    int Fraction::getMechane()
    {
        return this->denominator;
    }
    int Fraction::gcd(int a, int b) 
    {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }
    Fraction Fraction::reduceFraction(Fraction &f)
    {
        int greatestCommonDivisor = Fraction::gcd(f.numerator, f.denominator);
        f.numerator /= greatestCommonDivisor;
        f.denominator /= greatestCommonDivisor;
        return Fraction(f.numerator,f.denominator);
    }
    Fraction Fraction::operator+(const Fraction &f)
    {
        Fraction result;
        result.numerator = numerator * f.denominator + f.numerator * denominator;
        result.denominator = denominator * f.denominator;
        return reduceFraction (result);
    }
    Fraction Fraction::operator-(const Fraction& f) {
        Fraction result;
        result.numerator = numerator * f.denominator - f.numerator * denominator;
        result.denominator = denominator * f.denominator;
        return reduceFraction (result);
    }
    Fraction Fraction::operator*(const Fraction& f) {
        Fraction result;
        // result.mone = mone * f.mechane + f.mone * mechane;
        // result.mechane = mechane * f.mechane;
        return reduceFraction (result);
    }
    Fraction Fraction::operator/(const Fraction &f)
    {
        Fraction result;
        // result.mone = mone * f.mechane + f.mone * mechane;
        // result.mechane = mechane * f.mechane;
        return reduceFraction (result);
    }
    Fraction Fraction::operator+(int num)
    {
        Fraction result;
        // result.mone = mone * f.mechane + f.mone * mechane;
        // result.mechane = mechane * f.mechane;
        return reduceFraction (result);
    }
    Fraction Fraction::operator-(int num)
    {
        Fraction result;
        // result.mone = mone * f.mechane + f.mone * mechane;
        // result.mechane = mechane * f.mechane;
        return reduceFraction (result);
    }
    Fraction Fraction::operator*(int num)
    {
        Fraction result;
        // result.mone = mone * f.mechane + f.mone * mechane;
        // result.mechane = mechane * f.mechane;
        return reduceFraction (result);
    }
    Fraction Fraction::operator/(int num)
    {
        Fraction result;
        // result.mone = mone * f.mechane + f.mone * mechane;
        // result.mechane = mechane * f.mechane;
        return reduceFraction (result);
    }
    Fraction Fraction::operator++(int num)
    {
        return Fraction();
    }
    Fraction Fraction::operator--(int num)
    {
        return Fraction();
    }
    Fraction Fraction::operator++()
    {
        this->numerator += this->denominator;
        return *this;
    }
    Fraction Fraction::operator--()
    {
        this->numerator -= this->denominator;
        return *this;
    }
    Fraction Fraction::operator+(double num)
    {
        Fraction result;
        // result.mone = mone * f.mechane + f.mone * mechane;
        // result.mechane = mechane * f.mechane;
        return reduceFraction (result);
    }
    Fraction Fraction::operator-(double num)
    {
        Fraction result;
        // result.mone = mone * f.mechane + f.mone * mechane;
        // result.mechane = mechane * f.mechane;
        return reduceFraction (result);
    }
    Fraction Fraction::operator*(double num)
    {
        Fraction result;
        // result.mone = mone * f.mechane + f.mone * mechane;
        // result.mechane = mechane * f.mechane;
        return reduceFraction (result);
    }
    Fraction Fraction::operator/(double num)
    {
        Fraction result;
        // result.mone = mone * f.mechane + f.mone * mechane;
        // result.mechane = mechane * f.mechane;
        return reduceFraction (result);
    }
    Fraction operator+(double d, const Fraction& f) {
        Fraction result;
        // result.mone = f.mechane * d;
        // result.mechane = f.mechane;
        // return reduceFraction(result);
        return result;
    }
    Fraction operator-(double d, const Fraction& f) {
        Fraction result;
        // result.mone = f.mechane * d;
        // result.mechane = f.mechane;
        //return reduceFraction (result);
        return result;
    }
    Fraction operator*(double d, const Fraction& f) {
        Fraction result;
        // result.mone = f.mechane * d;
        // result.mechane = f.mechane;
        //return reduceFraction (result);
        return result;
    }
    Fraction operator/(double d, const Fraction& f) {
        Fraction result;
        // result.mone = f.mechane * d;
        // result.mechane = f.mechane;
        return result;
    }
    Fraction operator+(int d, const Fraction& f) {
        Fraction result;
        // result.mone = f.mechane * d;
        // result.mechane = f.mechane;
        return result;
    }
    Fraction operator-(int d, const Fraction& f) {
        Fraction result;
        // result.mone = f.mechane * d;
        // result.mechane = f.mechane;
        return result;
    }
    Fraction operator*(int d, const Fraction& f) {
        Fraction result;
        // result.mone = f.mechane * d;
        // result.mechane = f.mechane;
        return result;
    }
    Fraction operator/(int d, const Fraction& f) {
        Fraction result;
        // result.mone = f.mechane * d;
        // result.mechane = f.mechane;
        return result;
    }

    std::string Fraction::toString()
    {
        return "";
    }
    ostream &operator<<(ostream &os, const Fraction &f)
    {
        os << "numerator: " << f.numerator << ", denominator: " << f.denominator<<endl;
        return os;
    }
    ostream &operator<<(const Fraction f, ostream &os)
    {
        os << "numerator: " << f.numerator << ", denominator: " << f.denominator<<endl;
        return os;
    }
    istream& operator>>(istream& inputStream, Fraction& f) {
        inputStream >> f.numerator >> f.denominator;
        return inputStream;
    }
    bool Fraction::operator>=(const Fraction &f)
    {
        return false;
    }
    bool Fraction::operator<=(const Fraction &f)
    {
        return false;
    }
    bool Fraction::operator==(const Fraction &f)
    {
        if (this->numerator==f.numerator&&this->denominator==f.denominator)
        {
            return true;
        }
        return false;
    }
    bool Fraction::operator>(const Fraction &f)
    {
        return false;
    }
    bool Fraction::operator<(const Fraction &f)
    {
        return false;
    }
    bool Fraction::operator>=(int n)
    {
        return false;
    }
    bool Fraction::operator<=(int n)
    {
        return false;
    }
    bool Fraction::operator==(int n)
    {
        return false;
    }
    bool Fraction::operator>(int n)
    {
        return false;
    }
    bool Fraction::operator<(int n)
    {
        return false;
    }
    bool Fraction::operator>=(double n)
    {
        return false;
    }
    bool Fraction::operator<=(double n)
    {
        return false;
    }
    bool Fraction::operator==(double n)
    {
        return false;
    }
    bool Fraction::operator>(double n)
    {
        return false;
    }
    bool Fraction::operator<(double n)
    {
        return false;
    }
}