#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	s_len;

	s_len = ft_strlen(s);
	if (c == '\0')
		return ((char *)(s + s_len));
	while (s_len > 0)
	{
		if (*(s + s_len - 1) == (char)c)
			return ((char *)(s + s_len - 1));
		s_len--;
	}
	return (NULL);
}
