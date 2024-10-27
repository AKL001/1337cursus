#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	// s_len < start + len
	// len > max_string_len
	char *ptr;
	size_t s_len = ft_strlen(s);
	if (start >= s_len)
		len = 0;
	else if (len > s_len - start || len > s_len)
		len = s_len - start;
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (ptr == NULL)
		return (NULL);
	ft_memcpy(ptr, s + start, len);
	ptr[len] = '\0';
	return (ptr);
}