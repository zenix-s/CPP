#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>
#include <ostream>
#include <string>

class Form
{
  private:
    const std::string _name;
    const int         _signGrade;
    const int         _executionGrade;
    bool              _isSigned;

    void copy(const Form& other);

  public:
    Form();
    Form(const Form& other);
    Form(const std::string& name, const int signGrade, const int executionGrade);
    ~Form();
    Form& operator=(const Form& other);

    const std::string getName() const;
    const int         getSignGrade() const;
    const int         getExecutionGrade() const;
    const bool        getIsSigned() const;

    void beSigned(Bureaucrat& bureaucrat);

    class GradeToHighException : public std::exception
    {
      public:
        virtual const char* what() const throw();
    };

    class GradeToLowException : public std::exception
    {
      public:
        virtual const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif
