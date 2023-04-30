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
    Fraction::Fraction(float n)
    {
        Fraction(n*1000,1000);
    }
    int Fraction::getNumerator()
    {
        return this->numerator;
    }
    int Fraction::getDenominator()
    {
        return this->denominator;
    }
    void Fraction::setNumerator(int num)
    {
        this->numerator = num;
    }
    void Fraction::setDenominator(int num)
    {
        this->denominator = num;
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
        result.setNumerator( this->getNumerator() * f.denominator - f.numerator * this->getDenominator());
        result.setDenominator (this->getDenominator() * f.denominator);
        return reduceFraction (result);
    }
    Fraction Fraction::operator*(const Fraction& f) {
        Fraction result;
        result.setNumerator(this->getNumerator() * f.numerator);
        result.setDenominator(this->getDenominator() * f.denominator);
        return reduceFraction(result);
    }
    Fraction Fraction::operator/(const Fraction &f)
    {
        Fraction result;
        result.setNumerator( this->getNumerator() * f.denominator+ f.numerator * this->getDenominator());
        result.setDenominator (this->getDenominator() * f.denominator);
        return reduceFraction (result);
    }
    Fraction Fraction::operator+(float num)
    {
        Fraction result;
        
        return reduceFraction (result);
    }
    Fraction Fraction::operator-(float num)
    {
        Fraction result;
        // result.mone = mone * f.mechane + f.mone * mechane;
        // result.mechane = mechane * f.mechane;
        return reduceFraction (result);
    }
    Fraction Fraction::operator*(float num)
    {
        Fraction result;
        // result.mone = mone * f.mechane + f.mone * mechane;
        // result.mechane = mechane * f.mechane;
        return reduceFraction (result);
    }
    Fraction Fraction::operator/(float num)
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
    bool Fraction::operator>=(const Fraction &f)const
    {
        return false;
    }
    bool Fraction::operator<=(const Fraction &f)const
    {
        return false;
    }
    bool Fraction::operator==(const Fraction &f)const
    {
        return false;
    }
    bool  Fraction::operator>(const Fraction &f)const
    {
        return false;
    }
    bool Fraction::operator<(const Fraction &f)const
    {
        return false;
    }
    Fraction operator+(double d, const Fraction &f)
    {
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
    Fraction operator+(float d, const Fraction &f)
    {
        return Fraction();
    }
    Fraction operator-(float d, const Fraction &f)
    {
        return Fraction();
    }
    Fraction operator*(float d, const Fraction &f)
    {
        return Fraction();
    }
    Fraction operator/(float d, const Fraction &f)
    {
        return Fraction();
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
    bool operator>=(float n, const Fraction &f)
    {
        return false;
    }
    bool operator<=(float n, const Fraction &f)
    {
        return false;
    }
    bool operator==(float n, const Fraction &f)
    {
        return false;
    }
    bool operator>(float n, const Fraction &f)
    {
        return false;
    }
    bool operator<(float n, const Fraction &f)
    {
        return false;
    }
    bool operator>=(const Fraction &f, float n)
    {
        return false;
    }
    bool operator<=(const Fraction &f, float n)
    {
        return false;
    }
    bool operator==(const Fraction &f, float n)
    {
        return false;
    }
    bool operator>(const Fraction &f, float n)
    {
        return false;
    }
    bool operator<(const Fraction &f, float n)
    {
        return false;
    }
}