#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>
#include <string>



Bureaucrat::Bureaucrat(void) : _name("steve"), _grade(150)
{
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other.getName()), _grade(other.getGrade())
{
    if (other.getGrade() > 150)
        throw Bureaucrat::GradeTooLowException();
    if (other.getGrade() < 1)
        throw Bureaucrat::GradeTooHighException();
}

Bureaucrat::Bureaucrat(const std::string& name) : _name(name), _grade(150)
{
}

Bureaucrat::Bureaucrat(const std::string& name, const int grade) : _name(name), _grade(grade)
{
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    if (this != &other)
        _grade = other.getGrade();

    return *this;
}

const std::string& Bureaucrat::getName() const
{
    return _name;
}

int Bureaucrat::getGrade() const
{
    return _grade;
}

void Bureaucrat::incrementGrade()
{
    const int newGrade = _grade - 1;

    if (newGrade < 1)
        throw Bureaucrat::GradeTooHighException();

    _grade = newGrade;
}

void Bureaucrat::decrementGrade()
{
    const int newGrade = _grade + 1;

    if (newGrade > 150)
        throw Bureaucrat::GradeTooLowException();

    _grade = newGrade;
}

void Bureaucrat::signForm(Form& form) const
{
    if (form.getIsSigned())
    {
        std::cout << _name << " couldn't sign " << form.getName() << " because it is already signed" << std::endl;
        return;
    }

    try
    {
        form.beSigned(*this);

        std::cout << _name << " signed " << form.getName() << std::endl;
    }
    catch (const Form::GradeTooHighException& ex)
    {
        std::cout << _name << " couldn't sign " << form.getName() << " because " << ex.what() << std::endl;
    }
    catch (const Form::GradeTooLowException& ex)
    {
        std::cout << _name << " couldn't sign " << form.getName() << " because " << ex.what() << std::endl;
    }
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade is too low");
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade is too high");
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return os;
}
