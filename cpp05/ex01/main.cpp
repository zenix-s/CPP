#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
    std::cout << std::endl;
    std::cout << "=== Form test ===" << std::endl;
    {
        Form form("Form1", 50, 50);
        std::cout << form << std::endl;

        std::cout << "Sign the contract" << std::endl;
        Bureaucrat bureaucrat("Santiago", 1);
        std::cout << bureaucrat << std::endl;

        form.beSigned(bureaucrat);

        std::cout << "Form new status" << std::endl;
        std::cout << form << std::endl;
    }

    std::cout << std::endl;
    std::cout << "=== Form test with exception ===" << std::endl;
    {
        try
        {
            Form form("Form2", 0, 50);
            std::cout << form << std::endl;
        }
        catch (const Form::GradeTooHighException& ex)
        {
            std::cout << "Exception Form::GradeTooHighException has ocurred" << std::endl;
            std::cout << ex.what() << std::endl;
        }
        catch (const std::exception& ex)
        {
            std::cout << "Unexpected exception:" << std::endl;
            std::cout << ex.what() << std::endl;
        }
    }

    std::cout << std::endl;
    std::cout << "=== Form test with exception ===" << std::endl;
    {
        try
        {
            Form form("Form3", 50, 151);
            std::cout << form << std::endl;
        }
        catch (const Form::GradeTooLowException& ex)
        {
            std::cout << "Exception Form::GradeTooLowException has ocurred" << std::endl;
            std::cout << ex.what() << std::endl;
        }
        catch (const std::exception& ex)
        {
            std::cout << "Unexpected exception:" << std::endl;
            std::cout << ex.what() << std::endl;
        }
    }

    std::cout << std::endl;
    std::cout << "=== Test copy constructor and equal operator ===" << std::endl;
    {
        Form  form("Complex form", 10, 5);
        Form  constructorCopy(form);
        Form* equalCopy = new Form();

        *equalCopy = form;

        std::cout << "Original form:" << std::endl;
        std::cout << form << std::endl;
        std::cout << "Copy constructor:" << std::endl;
        std::cout << constructorCopy << std::endl;
        std::cout << "Equal operator(Constant members should not change):" << std::endl;
        std::cout << *equalCopy << std::endl;
    }

    std::cout << std::endl;
    std::cout << "=== Let form be signed by a bureaucrat ===" << std::endl;
    {
        Bureaucrat bureaucrat("Santiago", 1);
        Form       form("Form4", 50, 50);

        std::cout << bureaucrat << std::endl;
        std::cout << form << std::endl;

        bureaucrat.signForm(form);

        std::cout << "After signing:" << std::endl;
        std::cout << form << std::endl;
    }

    std::cout << std::endl;
    std::cout << "=== Invalid form signing attempt ===" << std::endl;
    {
        Bureaucrat bureaucrat("Santiago");
        Form       form("Form5", 50, 50);

        std::cout << bureaucrat << std::endl;
        std::cout << form << std::endl;

        try
        {
            bureaucrat.incrementGrade(); // Raise the grade to 0
            bureaucrat.signForm(form);
        }
        catch (const Bureaucrat::GradeTooHighException& ex)
        {
            std::cout << "Exception Bureaucrat::GradeTooHighException has ocurred" << std::endl;
            std::cout << ex.what() << std::endl;
        }
        catch (const Bureaucrat::GradeTooLowException& ex)
        {
            std::cout << "Exception Bureaucrat::GradeTooLowException has ocurred" << std::endl;
            std::cout << ex.what() << std::endl;
        }
        catch (const Form::GradeTooHighException& ex)
        {
            std::cout << "Exception Form::GradeTooHighException has ocurred" << std::endl;
            std::cout << ex.what() << std::endl;
        }
        catch (const Form::GradeTooLowException& ex)
        {
            std::cout << "Exception Form::GradeTooLowException has ocurred" << std::endl;
            std::cout << ex.what() << std::endl;
        }
        catch (const std::exception& ex)
        {
            std::cout << "Unexpected exception:" << std::endl;
            std::cout << ex.what() << std::endl;
        }
    }

    std::cout << std::endl;
    std::cout << "=== Edge Case: Bureaucrat and Form at grade 150 (lowest valid) ===" << std::endl;
    {
        try
        {
            Bureaucrat low("Low", 150);
            Form       f("F", 150, 150);
            std::cout << low << std::endl;
            std::cout << f << std::endl;
            low.signForm(f); // Should succeed
            std::cout << "After signing: " << f << std::endl;
        }
        catch (const std::exception& e)
        {
            std::cout << "Unexpected exception:" << std::endl;
            std::cout << e.what() << std::endl;
        }
    }

    std::cout << std::endl;
    std::cout << "=== Edge Case: Already signed form ===" << std::endl;
    {
        Form       f2("F2", 100, 100);
        Bureaucrat b2("B2", 50);
        b2.signForm(f2); // Should sign
        b2.signForm(f2); // Should do nothing or log, but not throw
        std::cout << "Form signed status: " << (f2.getIsSigned() ? "signed" : "not signed") << std::endl;
    }

    std::cout << std::endl;
    std::cout << "=== Edge Case: Multiple bureaucrats signing the same form ===" << std::endl;
    {
        Form       f3("F3", 100, 100);
        Bureaucrat b3a("B3a", 100);
        Bureaucrat b3b("B3b", 99);
        b3a.signForm(f3); // Should sign
        b3b.signForm(f3); // Should do nothing or log, but not throw
        std::cout << "Form signed status: " << (f3.getIsSigned() ? "signed" : "not signed") << std::endl;
    }



    std::cout << std::endl;
    std::cout << "=== Edge Case: Increment at grade 1 and decrement at grade 150 ===" << std::endl;
    {
        try
        {
            Bureaucrat top("Top", 1);
            top.incrementGrade(); // Should throw
        }
        catch (const std::exception& e)
        {
            std::cout << "Caught expected exception (increment at grade 1):" << std::endl;
            std::cout << e.what() << std::endl;
        }
        try
        {
            Bureaucrat bottom("Bottom", 150);
            bottom.decrementGrade(); // Should throw
        }
        catch (const std::exception& e)
        {
            std::cout << "Caught expected exception (decrement at grade 150):" << std::endl;
            std::cout << e.what() << std::endl;
        }
    }
}
