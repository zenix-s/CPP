#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

AForm::AForm() : _name("Simple Form"), _signGrade(150), _executionGrade(150), _isSigned(false)
{
}

AForm::AForm(const std::string& name, const int signGrade, const int executionGrade)
    : _name(name), _signGrade(signGrade), _executionGrade(executionGrade), _isSigned(false)
{
    if (_signGrade > 150)
        throw AForm::GradeTooLowException();
    if (_signGrade < 1)
        throw AForm::GradeTooHighException();
    if (_executionGrade > 150)
        throw AForm::GradeTooLowException();
    if (_executionGrade < 1)
        throw AForm::GradeTooHighException();
}

AForm::AForm(const AForm& other)
    : _name(other.getName()), _signGrade(other.getSignGrade()), _executionGrade(other.getExecutionGrade()),
      _isSigned(other.getIsSigned())
{
}

AForm::~AForm()
{
}

AForm& AForm::operator=(const AForm& other)
{
    if (this != &other)
        copy(other);

    return *this;
}

void AForm::copy(const AForm& other)
{
    _isSigned = other.getIsSigned();
}

const std::string AForm::getName() const
{
    return _name;
}

int AForm::getSignGrade() const
{
    return _signGrade;
}

int AForm::getExecutionGrade() const
{
    return _executionGrade;
}

bool AForm::getIsSigned() const
{
    return _isSigned;
}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > getSignGrade())
        throw AForm::GradeTooLowException();

    _isSigned = true;
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return ("Grade is too low");
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return ("Grade is too high");
}

const char* AForm::NotSignedException::what() const throw()
{
    return ("Form is not signed");
}

std::ostream& operator<<(std::ostream& os, const AForm& form)
{
    os << form.getName() << " (sign grade: " << form.getSignGrade() << ", execution grade: " << form.getExecutionGrade()
       << ") is " << (form.getIsSigned() ? "" : "not ") << "signed";

    return os;
}
