#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>

std::string	replaceInStr(std::string line, std::string s1, std::string s2);
void 		replaceInNewFile(std::ifstream &src, std::ofstream &dst,
							  std::string s1, std::string s2);

int	main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cerr << "Error: invalid arguments" << std::endl;
		return (EXIT_FAILURE);
	}
	std::ifstream	srcFile(argv[1]);
	std::string		dstFilename(std::string(argv[1]).append(".replace"));
	std::ofstream	dstFile(dstFilename.c_str());
	if (dstFile.is_open() && srcFile.is_open())
		replaceInNewFile(srcFile, dstFile, std::string(argv[2]), std::string(argv[3]));
	else
	{
		std::cerr << "Error: " << strerror(errno) << std::endl;
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

void	replaceInNewFile(std::ifstream &src, std::ofstream &dst,
								  std::string s1, std::string s2)
{
	std::string	line;

	std::getline(src, line, '\0');
	line = replaceInStr(line, s1, s2);
	dst << line;
}

std::string	replaceInStr(std::string line, std::string s1, std::string s2)
{
	std::size_t	index;
	std::size_t	s1_length;

	index = line.find(s1);
	s1_length = s1.length();
	if (s1_length == 0 || s1.compare(s2) == 0)
		return (line);
	while (index != std::string::npos)
	{
		line.erase(index, s1_length);
		line.insert(index, s2);
		index = line.find(s1);
	}
	return (line);
}