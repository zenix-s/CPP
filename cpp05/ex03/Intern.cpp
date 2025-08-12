
#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <cstddef>
#include <string>

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
}

FormMaker::FormMaker(const FormMaker& other)
{
    (void)other; // Avoid unused parameter warning
}

FormMaker& FormMaker::operator=(const FormMaker& other)
{
    (void)other; // Avoid unused parameter warning
    return *this;
}

FormMaker::~FormMaker()
{
}

const char* FormMaker::NotRecognizedFormException::what() const throw()
{
    return "Form type not recognized";
}

// Intern
Intern::Intern()
{
}

Intern::Intern(const Intern& other)
{
    (void)other; // Avoid unused parameter warning
}

Intern& Intern::operator=(const Intern& other)
{
    (void)other; // Avoid unused parameter warning
    return *this;
}

Intern::~Intern()
{
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) const
{
    try
    {
        AForm* form = FormMaker::createForm(formName, target);
        std::cout << "Intern creates " << formName << std::endl;
        return form;
    }
    catch (const FormMaker::NotRecognizedFormException& e)
    {
        std::cout << "Intern could not create form: " << std::string(e.what()) << std::endl;
        return NULL;
    }
}
