#ifndef UTILS_HPP

#define UTILS_HPP

#include <string>

class Utils
{
  public:
    Utils();
    ~Utils();
    Utils(const Utils& other);
    Utils& operator=(const Utils& other);

    static std::string to_string(int nbr);
};

#endif
