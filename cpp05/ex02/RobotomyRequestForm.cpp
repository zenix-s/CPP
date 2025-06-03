#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include "Logger.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

const std::string RobotomyRequestForm::NAME = "RobotomyRequestForm";
const int         RobotomyRequestForm::SIGN_GRADE = 72;
const int         RobotomyRequestForm::EXEC_GRADE = 45;

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : AForm(NAME, SIGN_GRADE, EXEC_GRADE), _target(target)
{
    Logger::printLog("RobotomyRequestForm constructor called");
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other), _target(other._target)
{
    Logger::printLog("RobotomyRequestForm copy constructor called");
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    Logger::printLog("RobotomyRequestForm assignment operator called");
    if (this != &other)
    {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    Logger::printLog("RobotomyRequestForm destructor called");
}

void RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
    if (!getIsSigned())
        throw AForm::NotSignedException();
    if (executor.getGrade() > getExecutionGrade())
        throw AForm::GradeTooLowException();

    std::cout << "* Drilling noises *" << std::endl;

    // Seed randomness only once per program run
    static bool seeded = false;
    if (!seeded)
    {
        std::srand(static_cast<unsigned int>(std::time(0)));
        seeded = true;
    }

    if (std::rand() % 2)
        std::cout << _target << " has been robotomized successfully!" << std::endl;
    else
        std::cout << "Robotomy failed on " << _target << "!" << std::endl;
}
