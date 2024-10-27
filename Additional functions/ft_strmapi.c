#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t i;
	size_t s_len;
	
	if (!s || !f)
        return NULL;
	i = 0;
	s_len = ft_strlen(s);
	char *ptr = (char *)malloc(sizeof(char) * (s_len + 1));
	if (!ptr)
		return (NULL);
	while (i < s_len)
	{
		ptr[i] = f(i, s[i]);
		i++;
	}
	ptr[s_len] = '\0';
	return (ptr);
}