#ifndef HARL_HPP
# define HARL_HPP

# include <string>
# include <cstddef>
# include <sys/types.h>

class Harl
{
	public:
		Harl();

		void	complain(std::string level);
		int 	getLevel(std::string level);

	private:
		std::string	_strLevel[4];

		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);


};


#endif