#ifndef UTILS_HPP
#define UTILS_HPP
#include <string>

class Logger
{
  public:
    Logger();
    Logger(const Logger& other);
    ~Logger();

    static std::string getBold();
    static std::string getBoldOff();
    static std::string getRed();
    static std::string getGreen();
    static std::string getYellow();
    static std::string getBlue();
    static std::string getCyan();
    static std::string getWhite();
    static std::string getReset();

    static void printLog(const std::string& message);

    Logger& operator=(const Logger& other);

  private:
    static const bool _log;

    static const std::string _bold;
    static const std::string _boldOff;
    static const std::string _red;
    static const std::string _green;
    static const std::string _yellow;
    static const std::string _blue;
    static const std::string _cyan;
    static const std::string _white;
    static const std::string _reset;
};

#endif
