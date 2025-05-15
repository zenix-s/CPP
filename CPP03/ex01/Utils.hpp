#ifndef UTILS_HPP
#define UTILS_HPP
#include <string>

class Utils
{
private:
    static const std::string BOLD;
    static const std::string BOLD_OFF;
    static const std::string RED;
    static const std::string GREEN;
    static const std::string YELLOW;
    static const std::string BLUE;
    static const std::string CYAN;
    static const std::string WHITE;
    static const std::string RESET;

public:
    Utils();
    Utils(const Utils& other);
    ~Utils();

    static std::string getBold();
    static std::string getBoldOff();
    static std::string getRed();
    static std::string getGreen();
    static std::string getYellow();
    static std::string getBlue();
    static std::string getCyan();
    static std::string getWhite();
    static std::string getReset();

    Utils& operator=(const Utils& other);
};


#endif
