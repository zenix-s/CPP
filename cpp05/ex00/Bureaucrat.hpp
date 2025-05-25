#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <exception>
#include <string>

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
    int          getGrade() const;

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

#endif
