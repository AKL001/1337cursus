#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t i;
	if (!dest || !src) // or (! dest && !src)
		return (NULL);

	i = 0;
	while (i < n)
	{
		*((unsigned char *)(dest + i)) = *((unsigned char *)(src + i));
		i++;
	}
	return (dest);
}