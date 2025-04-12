#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
  private:
    int              _value;
    static const int _fractionalBits = 8;

  public:
    Fixed();
    Fixed(const Fixed& other);
    ~Fixed();
    Fixed& operator=(const Fixed& other);

    int  getRawBits() const;
    void setRawBits(int const raw);
};

#endif
