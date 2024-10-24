#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t len;
	len = ft_strlen(s1);
	char *dst;

	if (!(dst = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	ft_memcpy(dst, s1, len);
	dst[len] = '\0';
    free(dst);
	return (dest);
}