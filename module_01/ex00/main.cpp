
#include "Zombie.hpp"

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

int	main(void)
{
	Zombie	*foo;

	foo = newZombie("Foo");
	foo->announce();
	delete foo;
	randomChump("Zed");
	return (0);
}

Zombie	*newZombie(std::string name)
{
	return (new Zombie(name));
}

void	randomChump(std::string name)
{
	Zombie newZombie = Zombie(name);
	newZombie.announce();
}