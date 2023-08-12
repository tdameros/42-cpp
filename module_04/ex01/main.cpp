#include <iostream>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	std::cout << "Subject Tests" << std::endl;
	{
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		delete j;//should not create a leak
		delete i;
	}
	std::cout << std::endl;
	std::cout << "Custom tests" << std::endl;
	{
		Animal*	animalsArray[6];

		for (int i = 0; i < 3; i++)
			animalsArray[i] = new Dog();
		for (int i = 3; i < 6; i++)
			animalsArray[i] = new Cat();

		for (int i = 0; i < 6; i++)
			delete animalsArray[i];
	}
	return (0);
}