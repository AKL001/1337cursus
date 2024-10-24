#include "libft.c"

void	*ft_calloc(size_t sizeOf, size_t len)
{
	void *ptr;
	if (!ptr = malloc(sizeOf * len))
		return NULL;
	ft_bzero(ptr, sizeOf * len);
	return (ptr);
}