#ifndef FIXED_HPP
#define FIXED_HPP

#include <ostream>

class Fixed
{
  private:
    int              _value;
    static const int _fractionalBits = 8;

  public:
    Fixed();
    Fixed(const Fixed& other);
    Fixed(const int value);
    Fixed(const float value);
    ~Fixed();

    int  getRawBits() const;
    void setRawBits(int const raw);
    
    Fixed& operator=(const Fixed& other);

    float toFloat() const;
    int   toInt() const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
