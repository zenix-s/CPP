#include "RobotomyRequestForm.hpp"
#include "Logger.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
    Logger::printLog("RobotomyRequestForm constructor called");
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
    : AForm(other), _target(other._target)
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
