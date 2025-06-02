#ifndef FORM_HPP
#define FORM_HPP

#include <exception>
#include <iostream>
#include <ostream>
#include <string>

class Bureaucrat;

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
    int               getSignGrade() const;
    int               getExecutionGrade() const;
    bool              getIsSigned() const;

    void beSigned(const Bureaucrat& bureaucrat);

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

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif
