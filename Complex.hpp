#pragma once
#include <iostream>
class Complex
{
  private:
    double Re;
    double Im;
  public:
    Complex(float Re, float Im) : Re(Re), Im(Im) {}
    Complex()                   : Re(0), Im(0) {}
  
  public:
    double GetRe() const { return this->Re; }
    double GetIm() const { return this->Im; }
    void Print() const   { std::cout << this->Re << " + " << "i * " << this->Im; }

    bool operator == (const Complex& another) { return (this->Re == another.GetRe() && this->Im == another.GetIm()); }
    bool operator != (const Complex& another) { return (this->Re != another.GetRe() || this->Im != another.GetIm()); }
    bool operator < (const Complex& another) { return ((this->GetRe())*(this->GetRe()) + (this->GetIm()) * (this->GetIm()) < another.GetRe() * another.GetRe() + another.GetIm()* another.GetIm()); }
    bool operator > (const Complex& another) { return ((this->GetRe())*(this->GetRe()) + (this->GetIm()) * (this->GetIm()) > another.GetRe() * another.GetRe() + another.GetIm()* another.GetIm()); }
    Complex& operator = (const Complex* another)
    {
      if(this == another) return *this;
      this->Re = another->GetRe();
      this->Im = another->GetIm();
      return *this;
    }
};