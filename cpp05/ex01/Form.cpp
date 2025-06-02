#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "Logger.hpp"
#include <iostream>

Form::Form() : _name("Simple Form"), _signGrade(150), _executionGrade(150), _isSigned(false)
{
    Logger::printLog("Form Default constructor called");
}

Form::Form(const std::string& name, const int signGrade, const int executionGrade)
    : _name(name), _signGrade(signGrade), _executionGrade(executionGrade), _isSigned(false)
{
    Logger::printLog("Form Constructor called");

    if (_signGrade > 150)
        throw Form::GradeTooLowException();
    if (_signGrade < 1)
        throw Form::GradeTooHighException();
    if (_executionGrade > 150)
        throw Form::GradeTooLowException();
    if (_executionGrade < 1)
        throw Form::GradeTooHighException();
}

Form::Form(const Form& other)
    : _name(other.getName()), _signGrade(other.getSignGrade()), _executionGrade(other.getExecutionGrade()),
      _isSigned(other.getIsSigned())
{
    Logger::printLog("Form Copy Constructor called");
}

Form::~Form()
{
    Logger::printLog("Form Destructor called");
}

Form& Form::operator=(const Form& other)
{
    Logger::printLog("Form equal operator called");

    if (this != &other)
        copy(other);

    return *this;
}

void Form::copy(const Form& other)
{
    _isSigned = other.getIsSigned();
}

const std::string Form::getName() const
{
    return _name;
}

int Form::getSignGrade() const
{
    return _signGrade;
}

int Form::getExecutionGrade() const
{
    return _executionGrade;
}

bool Form::getIsSigned() const
{
    return _isSigned;
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > _signGrade)
        throw Form::GradeTooLowException();

    _isSigned = true;
}

const char* Form::GradeTooLowException::what() const throw()
{
    return ("Grade is too low");
}

const char* Form::GradeTooHighException::what() const throw()
{
    return ("Grade is too high");
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
    os << form.getName() << " (sign grade: " << form.getSignGrade() << ", execution grade: " << form.getExecutionGrade()
       << ") is " << (form.getIsSigned() ? "" : "not ") << "signed";

    return os;
}
