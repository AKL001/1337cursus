#include <ctype.h>
#include <stdio.h>

void	to_uppercase(unsigned int i, char *c)
{
	// This function will convert each character to uppercase
	if (c && *c)
		*c = (char)toupper(*c);
}

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return ;
	while (*s)
	{
		f(i, s);
		s++;
		i++;
	}
}

int	main(void)
{
	char	str[] = "hello, world!";

	printf("Original string: %s\n", str);
	// Apply ft_striteri with to_uppercase function
	ft_striteri(str, to_uppercase);
	printf("Modified string: %s\n", str); // Expected: "HELLO, WORLD!"
	return (0);
}
