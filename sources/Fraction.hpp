#ifndef FRACTION_H
#define FRACTION_H
#include <stdio.h>
#include <iostream>
using namespace std;
namespace ariel{
    class Fraction
    {
    private:
        int numerator;
        int denominator;
    public:
        Fraction();
        Fraction(int a,int b);
        int getMone();
        int getMechane();
        int gcd(int a, int b);
        Fraction reduceFraction(Fraction& f);
        Fraction operator+(const Fraction& f);
        Fraction operator-(const Fraction& f);
        Fraction operator*(const Fraction& f);
        Fraction operator/(const Fraction& f);
        Fraction operator+(int num);
        Fraction operator-(int num);
        Fraction operator*(int num);
        Fraction operator/(int num);
        Fraction operator++(int num);
        Fraction operator--(int num);
        Fraction operator++();
        Fraction operator--();
        Fraction operator+(double num);
        Fraction operator-(double num);
        Fraction operator*(double num);
        Fraction operator/(double num);
        friend Fraction operator+(double d, const Fraction& f);
        friend Fraction operator-(double d, const Fraction& f);
        friend Fraction operator*(double d, const Fraction& f);
        friend Fraction operator/(double d, const Fraction& f);
        friend Fraction operator+(int d, const Fraction& f);
        friend Fraction operator-(int d, const Fraction& f);
        friend Fraction operator*(int d, const Fraction& f);
        friend Fraction operator/(int d, const Fraction& f);
        friend ostream& operator<<(ostream& os, const Fraction& f);
        friend ostream& operator<<(const Fraction f, ostream& os);
        friend istream& operator>>(istream& inputStream, Fraction& f);
        bool operator>=(const Fraction& f);
        bool operator<=(const Fraction& f);
        bool operator==(const Fraction& f);
        bool operator>(const Fraction& f);
        bool operator<(const Fraction& f);
        bool operator>=(int n);
        bool operator<=(int n);
        bool operator==(int n);
        bool operator>(int n);
        bool operator<(int n);
        bool operator>=(double n);
        bool operator<=(double n);
        bool operator==(double n);
        bool operator>(double n);
        bool operator<(double n);
        std::string toString();
    };
}
#endif