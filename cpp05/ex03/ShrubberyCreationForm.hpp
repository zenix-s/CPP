#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <string>

class ShrubberyCreationForm : public AForm
{
  private:
    static const std::string NAME;
    static const int         SIGN_GRADE;
    static const int         EXEC_GRADE;
    std::string              _target;

  public:
    ShrubberyCreationForm(const std::string& target);
    ShrubberyCreationForm(const ShrubberyCreationForm& other);
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
    ~ShrubberyCreationForm();

    const std::string getStaticName() const;

    void execute(Bureaucrat const& executor) const;
    
    static AForm* factory(const std::string& target); 
};

#endif
