#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	len;
	size_t	s1_len;
	char	*ptr;

	if (!set || !s1)
		return (NULL);
	s1_len = ft_strlen(s1);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = s1_len;
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	len = end - start; // len
	ptr = ft_substr(s1, start, len);
	if (!ptr)
		return (NULL);
	ptr[len] = '\0';
	return (ptr);
}