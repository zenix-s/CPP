#ifndef FIXED_HPP
#define FIXED_HPP

#include <ostream>

class Fixed
{
  private:
    static const int _fractionalBits = 8;
    int              _value;

  public:
    // Constructors/Destructors
    Fixed();
    Fixed(const Fixed& other);
    Fixed(const int value);
    Fixed(const float value);
    ~Fixed();

    // Getters / Setters
    int  getRawBits() const;
    void setRawBits(int const raw);

    // Assignment operator
    Fixed& operator=(const Fixed& other);

    // Comparaison operators
    bool operator>(const Fixed& other) const;
    bool operator<(const Fixed& other) const;
    bool operator>=(const Fixed& other) const;
    bool operator<=(const Fixed& other) const;
    bool operator==(const Fixed& other) const;
    bool operator!=(const Fixed& other) const;

    // Arithmetic operators
    Fixed operator+(const Fixed& other) const;
    Fixed operator-(const Fixed& other) const;
    Fixed operator*(const Fixed& other) const;
    Fixed operator/(const Fixed& other) const;

    // Increment/Decrement operators
    Fixed& operator++();    // Pre-increment
    Fixed  operator++(int); // Post-increment
    Fixed& operator--();    // Pre-decrement
    Fixed  operator--(int); // Post-decrement

    // Conversion methods
    float toFloat() const;
    int   toInt() const;

    // Static methods
    static Fixed&       min(Fixed& a, Fixed& b);
    static const Fixed& min(const Fixed& a, const Fixed& b);
    static Fixed&       max(Fixed& a, Fixed& b);
    static const Fixed& max(const Fixed& a, const Fixed& b);
    static Fixed&       min(Fixed* a, Fixed* b);
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
