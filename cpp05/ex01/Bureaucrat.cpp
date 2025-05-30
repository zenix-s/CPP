#include "Bureaucrat.hpp"
#include "Logger.hpp"

void Bureaucrat::copy(const Bureaucrat& other)
{
    _grade = other.getGrade();
}

Bureaucrat::Bureaucrat(void) : _name("steve"), _grade(150)
{
    Logger::printLog("Bureaucrat default constructor called");
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other.getName()), _grade(other.getGrade())
{
    if (other.getGrade() > 150)
        throw Bureaucrat::GradeTooLowException();
    if (other.getGrade() < 1)
        throw Bureaucrat::GradeTooHighException();

    Logger::printLog("Bureaucrat default constructor called");
}

Bureaucrat::Bureaucrat(const std::string& name) : _name(name), _grade(150)
{
    Logger::printLog("Bureaucrat constructor called");
}

Bureaucrat::Bureaucrat(const std::string& name, const int grade) : _name(name), _grade(grade)
{
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();

    Logger::printLog("Bureaucrat constructor called");
}

Bureaucrat::~Bureaucrat()
{
    Logger::printLog("Bureaucrat destructor called");
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    Logger::printLog("Bureaucrat equal operator called");

    if (this != &other)
        copy(other);

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
    Logger::printLog("Bureaucrat increment grade called");
    const int newGrade = _grade - 1;

    if (newGrade < 1)
        throw Bureaucrat::GradeTooHighException();

    _grade = newGrade;
}

void Bureaucrat::decrementGrade()
{
    Logger::printLog("Bureaucrat decrement grade called");
    const int newGrade = _grade + 1;

    if (newGrade > 150)
        throw Bureaucrat::GradeTooLowException();

    _grade = newGrade;
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
