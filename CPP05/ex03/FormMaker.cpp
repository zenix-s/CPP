#include "FormMaker.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <string>

const FormMaker::t_formType FormMaker::_formTypes[] = {{"presidential pardon", &PresidentialPardonForm::factory},
                                                       {"robotomy request", &RobotomyRequestForm::factory},
                                                       {"shrubbery creation", &ShrubberyCreationForm::factory},
                                                       {"", NULL}};

FormMaker::FormMaker()
{
}

FormMaker::FormMaker(const FormMaker& other)
{
    (void)other;
}

FormMaker& FormMaker::operator=(const FormMaker& other)
{
    (void)other;
    return *this;
}

FormMaker::~FormMaker()
{
}

AForm* FormMaker::createForm(const std::string& form, const std::string& target)
{
    for (const t_formType* it = _formTypes; it->name != ""; ++it)
    {
        if (it->name == form)
            return it->factory(target);
    }

    throw FormMaker::NotRecognizedFormException();
}

const char* FormMaker::NotRecognizedFormException::what() const throw()
{
    return "Form type not recognized";
}
