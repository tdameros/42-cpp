#include <iostream>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "wrong/WrongAnimal.hpp"
#include "wrong/WrongCat.hpp"

int main()
{
	{
		std::cout << "Basic Test" << std::endl;
		const Animal* animal = new Animal();
		const Animal* dog = new Dog();
		const Animal* cat = new Cat();
		std::cout << animal->getType() << " " << std::endl;
		std::cout << dog->getType() << " " << std::endl;
		std::cout << cat->getType() << " " << std::endl;
		animal->makeSound();
		dog->makeSound();
		cat->makeSound();

		delete animal;
		delete dog;
		delete cat;
	}
	std::cout << std::endl;
	{
		std::cout << "Wrong Test" << std::endl;
		const WrongAnimal* animal = new WrongAnimal();
		const WrongAnimal* cat = new WrongCat();
		std::cout << animal->getType() << " " << std::endl;
		std::cout << cat->getType() << " " << std::endl;
		animal->makeSound();
		cat->makeSound();

		delete animal;
		delete cat;
	}
	return (0);
}