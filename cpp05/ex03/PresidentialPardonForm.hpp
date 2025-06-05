#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <string>

class PresidentialPardonForm : public AForm
{
  private:
    static const std::string NAME;
    static const int         SIGN_GRADE;
    static const int         EXEC_GRADE;
    std::string              _target;

  public:
    PresidentialPardonForm(const std::string& target);
    PresidentialPardonForm(const PresidentialPardonForm& other);
    PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
    ~PresidentialPardonForm();

    const std::string getStaticName() const;

    void execute(const Bureaucrat& executor) const;

    static AForm* factory(const std::string& target);
};

#endif
