#pragma once

#include "AForm.hpp"
#include <string>
#include <exception>

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