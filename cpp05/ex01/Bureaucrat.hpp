#pragma once

#include <exception>
#include <iostream>
#include <string>

class Form;

class Bureaucrat
{
  private:
    const std::string _name;
    int               _grade;

    void copy(const Bureaucrat& other);

  public:
    Bureaucrat();
    Bureaucrat(const std::string& name);
    Bureaucrat(const std::string& name, const int grade);
    Bureaucrat(const Bureaucrat& other);
    ~Bureaucrat();
    Bureaucrat& operator=(const Bureaucrat& other);

    const std::string& getName() const;
    int                getGrade() const;

    void incrementGrade();
    void decrementGrade();
    void signForm(Form& form) const;

    class GradeTooHighException : public std::exception
    {
      public:
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
      public:
        virtual const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);
