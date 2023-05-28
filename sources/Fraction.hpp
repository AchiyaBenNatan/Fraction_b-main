#ifndef FRACTION_H
#define FRACTION_H
#include <stdio.h>
#include <iostream>
using namespace std;
namespace ariel
{
    class Fraction
    {
    private:
        int numerator;
        int denominator;
    public:
        Fraction();
        Fraction(int mone, int mechane);
        Fraction(float n);
        int getNumerator();
        int getDenominator();
        void setNumerator(int num);
        void setDenominator(int num);
        int gcd(int mone, int mechane);
        float fractToFloat(Fraction frac) const;
        Fraction reduceFraction(Fraction &frac);
        Fraction operator+(const Fraction &frac);
        Fraction operator-(const Fraction &frac);
        Fraction operator*(const Fraction &frac);
        Fraction operator/(const Fraction &frac);
        Fraction operator+(float num);
        Fraction operator-(float num);
        Fraction operator*(float num);
        Fraction operator/(float num);
        Fraction operator++(int num);
        Fraction operator--(int num);
        Fraction operator++();
        Fraction operator--();
        friend Fraction operator+(float num, const Fraction &frac);
        friend Fraction operator-(float num, const Fraction &frac);
        friend Fraction operator*(float num, const Fraction &frac);
        friend Fraction operator/(float num, const Fraction &frac);
        friend ostream &operator<<(ostream &ostream, const Fraction &frac);
        friend istream &operator>>(istream &inputStream, Fraction &frac);
        bool operator>=(const Fraction &frac)const;
        bool operator<=(const Fraction &frac)const;
        bool operator==(const Fraction &frac)const;
        bool operator>(const Fraction &frac)const;
        bool operator<(const Fraction &frac)const;
        friend bool operator<=(float num, const Fraction &frac);
        friend bool operator>=(float num, const Fraction &frac);
        friend bool operator==(float num, const Fraction &frac);
        friend bool operator>(float num, const Fraction &frac);
        friend bool operator<(float num, const Fraction &frac);
        friend bool operator==(const Fraction &frac, float num);
        friend bool operator>(const Fraction &frac, float num);
        friend bool operator<(const Fraction &frac, float num);
        friend bool operator<=(const Fraction &frac,float num);
        friend bool operator>=(const Fraction &frac,float num);
    };
}
#endif