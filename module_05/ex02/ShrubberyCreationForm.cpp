#include <iostream>
#include <fstream>
#include <cstring>
#include <cerrno>

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void): Form("ShrubberyCreationForm",
														 "Undefined",
														 145, 137)
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target):
											 Form("ShrubberyCreationForm",
												  target, 145, 137)
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other): Form(other)
{

}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{

}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
	{
		*this = other;
	}
	return (*this);
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	this->beExecute(executor);
	std::ofstream	asciiFile((this->getTarget() + "_shrubbery").c_str());
	if (asciiFile.is_open())
	{
		asciiFile << "   x       o       @\n"
				  << "  xxx     ooo     @@@\n"
				  << " xxxxx   ooooo   @@@@@\n"
				  << "xxxxxxx ooooooo @@@@@@@\n"
				  << "   |       |       |"
				  << std::endl;
		asciiFile.close();
	}
	else
		std::cerr << "ShruberryCreateForm execute error: " << strerror(errno) << std::endl;
}