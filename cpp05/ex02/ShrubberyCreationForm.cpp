#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include "Logger.hpp"
#include <fstream>
#include <iostream>

const std::string ShrubberyCreationForm::NAME = "ShrubberyCreationForm";
const int         ShrubberyCreationForm::SIGN_GRADE = 145;
const int         ShrubberyCreationForm::EXEC_GRADE = 137;

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm(NAME, SIGN_GRADE, EXEC_GRADE), _target(target)
{
    Logger::printLog("ShrubberyCreationForm constructor called");
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), _target(other._target)
{
    Logger::printLog("ShrubberyCreationForm copy constructor called");
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    Logger::printLog("ShrubberyCreationForm assignment operator called");
    if (this != &other)
    {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    Logger::printLog("ShrubberyCreationForm destructor called");
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
    if (!getIsSigned())
        throw AForm::NotSignedException();
    if (executor.getGrade() > getExecutionGrade())
        throw AForm::GradeTooLowException();

    std::ofstream ofs((_target + "_shrubbery").c_str());
    if (!ofs)
    {
        Logger::printError("Failed to open file for shrubbery creation");
        return;
    }

    ofs << "       _-_\n"
           "    /~~   ~~\\\n"
           " /~~         ~~\\\n"
           "{               }\n"
           " \\  _-     -_  /\n"
           "   ~  \\\\ //  ~\n"
           "_- -   | | _- _\n"
           "  _ -  | |   -_\n"
           "      // \\\\\n";
    ofs.close();
    Logger::printLog("ShrubberyCreationForm executed: " + _target + "_shrubbery created");
}
