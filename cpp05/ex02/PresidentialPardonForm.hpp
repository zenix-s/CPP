#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <string>

class PresidentialPardonForm : public AForm
{
  private:
    std::string _target;

  public:
    static const int SIGN_GRADE = 25;
    static const int EXEC_GRADE = 5;

    PresidentialPardonForm(const std::string& target);
    PresidentialPardonForm(const PresidentialPardonForm& other);
    PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
    virtual ~PresidentialPardonForm();

    const std::string& getTarget() const;
    virtual void       execute(const Bureaucrat& executor) const;
};

#endif
