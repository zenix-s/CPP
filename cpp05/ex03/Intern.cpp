
#include "Intern.hpp"
#include "AForm.hpp"
#include "Logger.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <cstddef>
#include <string>

// FormMaker

// typedef struct s_formType
// {
//     std::string name;
//     AForm* (*create)(const std::string& target);
// } t_formType;

// static const t_formType _formTypes[];

const FormMaker::t_formType FormMaker::_formTypes[] = {{"presidential pardon", &PresidentialPardonForm::factory},
                                                       {"robotomy request", &RobotomyRequestForm::factory},
                                                       {"shrubbery creation", &ShrubberyCreationForm::factory},
                                                       {"", NULL}

};

AForm* FormMaker::createForm(const std::string& form, const std::string& target)
{
    for (const t_formType* it = _formTypes; it->name != ""; ++it)
    {
        if (it->name == form)
            return it->factory(target);
    }

    throw FormMaker::NotRecognizedFormException();
}

// FormMaker constructors and destructors
FormMaker::FormMaker()
{
    Logger::printLog("FormMaker default constructor called");
}

FormMaker::FormMaker(const FormMaker& other)
{
    Logger::printLog("FormMaker copy constructor called");
    (void)other; // Avoid unused parameter warning
}

FormMaker& FormMaker::operator=(const FormMaker& other)
{
    Logger::printLog("FormMaker assignment operator called");
    (void)other; // Avoid unused parameter warning
    return *this;
}

FormMaker::~FormMaker()
{
    Logger::printLog("FormMaker destructor called");
}

const char* FormMaker::NotRecognizedFormException::what() const throw()
{
    return "Form type not recognized";
}

// Intern
Intern::Intern()
{
    Logger::printLog("Intern default constructor called");
}

Intern::Intern(const Intern& other)
{
    Logger::printLog("Intern copy constructor called");
    (void)other; // Avoid unused parameter warning
}

Intern& Intern::operator=(const Intern& other)
{
    Logger::printLog("Intern assignment operator called");
    (void)other; // Avoid unused parameter warning
    return *this;
}

Intern::~Intern()
{
    Logger::printLog("Intern destructor called");
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) const
{
    Logger::printLog("Intern makeForm called with formName: " + formName + " and target: " + target);

    try
    {
        return FormMaker::createForm(formName, target);
    }
    catch (const FormMaker::NotRecognizedFormException& e)
    {
        Logger::printError("Intern could not create form: " + std::string(e.what()));
        return NULL;
    }
}
