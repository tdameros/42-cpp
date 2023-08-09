#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name);

int	main(void)
{
	Zombie	*horde;
	int 	numberOfZombies;

	numberOfZombies = 5;
	horde = zombieHorde(numberOfZombies, "Foo");
	for (int i = 0; i < numberOfZombies; i++)
		horde[i].announce();
	delete[] horde;
	return (0);
}

Zombie	*zombieHorde(int N, std::string name)
{
	Zombie	*horde = new Zombie[N];
	for (int i = 0; i < N; i++)
		horde[i].setName(name);
	return (horde);
}
