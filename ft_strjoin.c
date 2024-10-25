#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	// memcpy or memmove
	if (!s1 || !s2)
		return (NULL);
	size_t s1_len = ft_strlen(s1);
	size_t s2_len = ft_strlen(s2);
	char *ptr;
	size_t max_len = s1_len + s2_len;
	ptr = (char *)malloc(sizeof(char) * (max_len + 1));
	if (ptr == NULL)
		return (NULL);
	ft_memmove(ptr, s1, s1_len);
	ft_memmove(ptr + s1_len, s2, s2_len);
	ptr[max_len] = '\0';
	return (ptr);
}