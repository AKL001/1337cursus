#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t i = 0;

	while (*s)
	{
		f(i, s);
		s++;
		i++;
	}
}