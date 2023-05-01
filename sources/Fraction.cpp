#include "Fraction.hpp"
#include <iostream>
#include <string>
#include <math.h>
#include <sstream>
#include <fstream>
#include <functional>
using namespace ariel;
using namespace std;
namespace ariel
{
    int max_int = std::numeric_limits<int>::max();
    int min_int = std::numeric_limits<int>::min();
    Fraction::Fraction()
    {
        this->numerator = 1;
        this->denominator = 1;
    }
    Fraction::Fraction(int mone, int mechane)
    {

        if(mechane==0)
        {
            throw std::invalid_argument("Cant make an fraction with zero as the denominator.");
        }
        int gcdres = gcd(mone,mechane);
        this->numerator = mone/gcdres;
        this->denominator = mechane/gcdres;
    }
    Fraction::Fraction(float n)
    {   
        if (n!=0)
        {
            float round=n*1000;
            int gcdres = gcd(round,1000);
            this->numerator = round/gcdres;
            this->denominator = 1000/gcdres;
        }

        else
        {
            this->numerator = 0;
            this->denominator = 1;
        }
    }
    int check_for_overflow(int thisMone, int thisMechane, int otherMone, int otherMechane)
    {
        if((float)thisMone * (float)otherMone > max_int || (float)thisMone * (float)otherMone < min_int||
        (float)thisMechane * (float)otherMechane > max_int || (float)thisMechane * (float)otherMechane < min_int){
            return 1;
        }
        return 0;
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
    float Fraction::fractToFloat(Fraction frac) const
    {
        return (float)frac.getNumerator()/(float)frac.getDenominator();
    }
    Fraction Fraction::operator+(const Fraction &f)
    {
        Fraction result;
        result.numerator = numerator * f.denominator + f.numerator * denominator;
        result.denominator = denominator * f.denominator;
        if (check_for_overflow(this->numerator,this->denominator,f.numerator,f.denominator))
        {
            throw std::overflow_error("The result is not in range.");
        }
        return reduceFraction (result);
    }
    Fraction Fraction::operator-(const Fraction &f)
    {
        Fraction result;
        result.setNumerator( this->getNumerator() * f.denominator - f.numerator * this->getDenominator());
        result.setDenominator (this->denominator * f.denominator);
        if (check_for_overflow(this->numerator,this->denominator,f.numerator,f.denominator))
        {
            throw std::overflow_error("The result is not in range.");
        }
        return reduceFraction (result);
    }
    Fraction Fraction::operator*(const Fraction& f) {
        Fraction result;
        result.setNumerator(this->numerator* f.numerator);
        result.setDenominator(this->denominator * f.denominator);
        if ((check_for_overflow(this->numerator,this->denominator,f.numerator,f.denominator)))
        {
            throw std::overflow_error("The result is not in range.");
        }
        return reduceFraction(result);
    }
    Fraction Fraction::operator/(const Fraction &f)
    {
        Fraction result;
        if (f.numerator==0)
        {
            throw::runtime_error("Can't divide by zero");
        }
        result.setNumerator(this->getNumerator() * f.denominator);
        result.setDenominator (this->getDenominator() * f.numerator);
        if (check_for_overflow(this->numerator,this->denominator,f.numerator,f.denominator))
        {
            throw std::overflow_error("The result is not in range.");
        }
        return reduceFraction (result);
    }
    Fraction Fraction::operator+(float num)
    {
        num = round(num*1000)/1000;
        Fraction resfrac;
        resfrac.setNumerator(this->numerator);
        resfrac.setDenominator(this->denominator);
        float resfloat = fractToFloat(resfrac);
        resfloat += num;
        resfrac = Fraction(resfloat);
        return reduceFraction(resfrac);
    }
    Fraction Fraction::operator-(float num)
    {
        num = round(num*1000)/1000;
        Fraction resfrac;
        resfrac.setNumerator(this->numerator);
        resfrac.setDenominator(this->denominator);
        float resfloat = fractToFloat(resfrac);
        resfloat -= num;
        resfrac = Fraction(resfloat);
        return reduceFraction(resfrac);
    }
    Fraction Fraction::operator*(float num)
    {
        num = round(num*1000)/1000;
        Fraction resfrac = Fraction(*this*Fraction(num));
        return reduceFraction(resfrac);
    }
    Fraction Fraction::operator/(float num)
    {
        if(num == 0)
        {
            throw std::runtime_error("Cant make an fraction with zero as the denominator.");
        }
        num = round(num*1000)/1000;
        Fraction resfrac = Fraction(*this/Fraction(num));
        return reduceFraction(resfrac);
    }
    Fraction Fraction::operator++(int num)
    {
        Fraction temp(*this);
        numerator = numerator + denominator;
        return temp;
    }
    Fraction Fraction::operator--(int num)
    {
        Fraction temp(*this);
        numerator = numerator - denominator;
        return temp;
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
        return fractToFloat(*this)>=fractToFloat(f);
    }
    bool Fraction::operator<=(const Fraction &f)const
    {
        return fractToFloat(*this)<=fractToFloat(f);
    }
    bool Fraction::operator==(const Fraction &f)const
    {
        int num1 = (int)(((float)(this->numerator)/(float)this->denominator)*1000);
        int num2 = (int)(((float)(f.numerator)/(float)f.denominator)*1000);
        return num1==num2;
    }
    bool Fraction::operator>(const Fraction &f)const
    {
        return fractToFloat(*this)>fractToFloat(f);
    }
    bool Fraction::operator<(const Fraction &f)const
    {
        return fractToFloat(*this)<fractToFloat(f);
    }
    std::string Fraction::toString()
    {
        return "";
    }
    Fraction operator+(float d, const Fraction &f)
    {
        d = round(d*1000)/1000;
        Fraction resfrac;
        resfrac.setNumerator(f.numerator);
        resfrac.setDenominator(f.denominator);
        float resfloat = f.fractToFloat(resfrac);
        resfloat += d;
        resfrac = Fraction(resfloat);
        return resfrac;
    }
    Fraction operator-(float d, const Fraction &f)
    {
        d = round(d*1000)/1000;
        Fraction resfrac;
        resfrac.setNumerator(f.numerator);
        resfrac.setDenominator(f.denominator);
        float resfloat = f.fractToFloat(resfrac);
        resfloat = d-resfloat;
        resfrac = Fraction(resfloat);
        return resfrac;
    }
    Fraction operator*(float d, const Fraction &f)
    {
        return Fraction(d) * f;
    }
    Fraction operator/(float d, const Fraction &f)
    {
        return Fraction(d) / f;
    }
    ostream &operator<<(ostream &os, const Fraction &f)
    {
        if(f.denominator>=0)
            os << f.numerator << "/" << f.denominator;
        else 
            os<<-1*f.numerator << "/" <<-1*f.denominator;
        return os;
    }
    istream& operator>>(istream& input, Fraction& f)
    {
        int slash_char = '/',numerator,denominator;  
        input >> numerator;
        if (input.fail())
        {
            throw runtime_error("The numerator is not a number");
        }
        input >> slash_char;
        if (input.fail())
        {
            throw runtime_error("Please put in a slash");
        }
        if (slash_char == '/')
        {
            input >> denominator;
            if (input.fail() || denominator == 0)
            {
                throw runtime_error("The denominator is bad.");
            }
            Fraction frac(numerator, denominator);
            f.numerator = frac.getNumerator();
            f.denominator = frac.getDenominator();
        }
        else
        {
            if (slash_char == 0)
            {
                throw runtime_error("The denominator is bad.");
            }
            Fraction frac(numerator, slash_char);
            f.numerator = frac.getNumerator();
            f.denominator = frac.getDenominator();
        }
        return input;
    }
    bool operator>=(float n, const Fraction &f)
    {
        return n>=f.fractToFloat(f);
    }
    bool operator<=(float n, const Fraction &f)
    {
        return n<=f.fractToFloat(f);
    }
    bool operator==(float n, const Fraction &f)
    {
        return n==f.fractToFloat(f);
    }
    bool operator>(float n, const Fraction &f)
    {
        return n>f.fractToFloat(f);
    }
    bool operator<(float n, const Fraction &f)
    {
        return n<f.fractToFloat(f);
    }
    bool operator>=(const Fraction &f, float n)
    {
        return f.fractToFloat(f)>=n;
    }
    bool operator<=(const Fraction &f, float n)
    {
        return f.fractToFloat(f)<=n;
    }
    bool operator==(const Fraction &f, float n)
    {
        return f.fractToFloat(f)==n;
    }
    bool operator>(const Fraction &f, float n)
    {
        return f.fractToFloat(f)>n;
    }
    bool operator<(const Fraction &f, float n)
    {
        return f.fractToFloat(f)<=n;
    }
}