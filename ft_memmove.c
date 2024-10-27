#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	// overlaping case  -> max(left bound) <= min(right bound)
	if (n == 0 || dest == src)
		return (dest);
	if (dest < src)
	{
		ft_memcpy(dest, src, n);
	}
	else
	{
		while (n--)
		{
			*((unsigned char *)(dest + n)) = *((unsigned char *)(src + n));
		}
	}
	return (dest);
}
