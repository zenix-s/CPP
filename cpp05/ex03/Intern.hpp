#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"

class FormMaker
{
  private:
    typedef struct s_formType
    {
        std::string name;
        AForm* (*factory)(const std::string& target);
    } t_formType;
    static const t_formType _formTypes[];

  public:
    FormMaker();
    FormMaker(const FormMaker& other);
    ~FormMaker();
    FormMaker& operator=(const FormMaker& other);

    static AForm* createForm(const std::string& form, const std::string& target);

    class NotRecognizedFormException : public std::exception
    {
      public:
        virtual const char* what() const throw();
    };
};

class Intern
{
  public:
    Intern();
    Intern(const Intern& other);
    ~Intern();
    Intern& operator=(const Intern& other);

    AForm* makeForm(const std::string& formName, const std::string& target) const;
};

#endif
