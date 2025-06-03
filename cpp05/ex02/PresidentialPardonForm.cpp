#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include "Logger.hpp"

#include <iostream>

const int         PresidentialPardonForm::SIGN_GRADE = 25;
const int         PresidentialPardonForm::EXEC_GRADE = 5;
const std::string PresidentialPardonForm::NAME = "PresidentialPardonForm";

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
    : AForm(NAME, SIGN_GRADE, EXEC_GRADE), _target(target)
{
    Logger::printLog("PresidentialPardonForm constructor called");
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
    : AForm(other), _target(other._target)
{
    Logger::printLog("PresidentialPardonForm copy constructor called");
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
    Logger::printLog("PresidentialPardonForm assignment operator called");
    if (this != &other)
    {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    Logger::printLog("PresidentialPardonForm destructor called");
}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
    if (!getIsSigned())
        throw AForm::NotSignedException();
    if (executor.getGrade() > getExecutionGrade())
        throw AForm::GradeTooLowException();

    std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
