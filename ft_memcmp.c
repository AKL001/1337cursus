#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	// if n = 0 ; return (0);
	//
	size_t i = 0;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (*(unsigned char *)(s1 + i) != *(unsigned char *)(s2 + i))
		{
			return (*(unsigned char *)(s1 + i) - *(unsigned char *)(s2 + i));
		}
		i++;
	}
	return (0);
}