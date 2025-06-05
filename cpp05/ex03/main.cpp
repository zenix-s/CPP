#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "Logger.hpp"
#include <iostream>

int main()
{
    Logger::printTitle("Intern creates a form");
    {
        Intern intern;

        AForm* form1 = intern.makeForm("robotomy request", "Bender");
        std::cout << "Created form: " << form1->getName() << std::endl;
        delete form1;

        AForm* form2 = intern.makeForm("presidential pardon", "Zaphod");
        std::cout << "Created form: " << form2->getName() << std::endl;
        delete form2;

        AForm* form3 = intern.makeForm("shrubbery creation", "Earth");
        std::cout << "Created form: " << form3->getName() << std::endl;
        delete form3;

        // This will throw an exception
        AForm* form4 = intern.makeForm("unknown form", "Unknown");
        delete form4;
    }
}
