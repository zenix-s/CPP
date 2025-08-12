#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>
#include <iostream>

const std::string ShrubberyCreationForm::NAME = "ShrubberyCreationForm";
const int         ShrubberyCreationForm::SIGN_GRADE = 145;
const int         ShrubberyCreationForm::EXEC_GRADE = 137;

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm(NAME, SIGN_GRADE, EXEC_GRADE), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), _target(other._target)
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

const std::string ShrubberyCreationForm::getStaticName() const
{
    return NAME;
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
        std::cout << "Failed to open file for shrubbery creation" << std::endl;
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
    std::cout << "ShrubberyCreationForm executed: " << _target << "_shrubbery created" << std::endl;
}

AForm* ShrubberyCreationForm::factory(const std::string& target)
{
    return new ShrubberyCreationForm(target);
}
