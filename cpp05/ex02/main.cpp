#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Logger.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

void testShrubberyCreationForm()
{
    Logger::printTitle("Test: ShrubberyCreationForm Execution");
    Bureaucrat            bob("Bob", 130);
    ShrubberyCreationForm shrub("garden");

    std::cout << shrub << std::endl;
    bob.signForm(shrub);
    std::cout << shrub << std::endl;
    bob.executeForm(shrub);

    Logger::printComment("Test: Execution without signing");
    ShrubberyCreationForm shrub2("backyard");
    bob.executeForm(shrub2);

    Logger::printComment("Test: Execution with insufficient grade");
    Bureaucrat            low("Low", 150);
    ShrubberyCreationForm shrub3("frontyard");
    low.signForm(shrub3);
    low.executeForm(shrub3);
}

void testRobotomyRequestForm()
{
    Logger::printTitle("Test: RobotomyRequestForm Execution");
    Bureaucrat          alice("Alice", 40);
    RobotomyRequestForm robo("TargetX");

    std::cout << robo << std::endl;
    alice.signForm(robo);
    std::cout << robo << std::endl;
    for (int i = 0; i < 4; ++i)
        alice.executeForm(robo);

    Logger::printComment("Test: Execution without signing");
    RobotomyRequestForm robo2("TargetY");
    alice.executeForm(robo2);

    Logger::printComment("Test: Execution with insufficient grade");
    Bureaucrat          low("Low", 100);
    RobotomyRequestForm robo3("TargetZ");
    low.signForm(robo3);
    low.executeForm(robo3);
}

void testPresidentialPardonForm()
{
    Logger::printTitle("Test: PresidentialPardonForm Execution");
    Bureaucrat             pres("President", 1);
    PresidentialPardonForm pardon("Ford Prefect");

    std::cout << pardon << std::endl;
    pres.signForm(pardon);
    std::cout << pardon << std::endl;
    pres.executeForm(pardon);

    Logger::printComment("Test: Execution without signing");
    PresidentialPardonForm pardon2("Arthur Dent");
    pres.executeForm(pardon2);

    Logger::printComment("Test: Execution with insufficient grade");
    Bureaucrat             low("Low", 30);
    PresidentialPardonForm pardon3("Trillian");
    low.signForm(pardon3);
    low.executeForm(pardon3);
}

int main()
{
    Logger::printLineJunp();
    testShrubberyCreationForm();

    Logger::printLineJunp();
    testRobotomyRequestForm();

    Logger::printLineJunp();
    testPresidentialPardonForm();

    Logger::printLineJunp();
    Logger::printTitle("All new form tests completed.");
    return 0;
}
