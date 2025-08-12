#include "Intern.hpp"
#include "FormMaker.hpp"
#include <iostream>

Intern::Intern()
{
}

Intern::Intern(const Intern& other)
{
    (void)other;
}

Intern& Intern::operator=(const Intern& other)
{
    (void)other;
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
