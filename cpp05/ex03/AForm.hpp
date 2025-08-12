#pragma once

#include <exception>
#include <iostream>
#include <ostream>
#include <string>

class Bureaucrat;

class AForm
{
  private:
    const std::string _name;
    const int         _signGrade;
    const int         _executionGrade;
    bool              _isSigned;



  public:
    AForm();
    AForm(const AForm& other);
    AForm(const std::string& name, const int signGrade, const int executionGrade);
    virtual ~AForm();
    AForm& operator=(const AForm& other);

    const std::string getName() const;
    int               getSignGrade() const;
    int               getExecutionGrade() const;
    bool              getIsSigned() const;

    void beSigned(const Bureaucrat& bureaucrat);

    virtual void execute(Bureaucrat const& executor) const = 0;

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

    class NotSignedException : public std::exception
    {
      public:
        virtual const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& os, const AForm& form);
