#pragma once

#include "AForm.hpp"
#include <string>

class RobotomyRequestForm : public AForm
{
  private:
    static const std::string FORM_NAME;
    static const int         SIGN_GRADE;
    static const int         EXEC_GRADE;
    std::string              _target;

  public:
    RobotomyRequestForm(const std::string& target);
    RobotomyRequestForm(const RobotomyRequestForm& other);
    RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
    ~RobotomyRequestForm();

    const std::string getStaticName() const;

    void execute(const Bureaucrat& executor) const;

    static AForm* factory(const std::string& target);
};
