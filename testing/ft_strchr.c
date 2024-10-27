#include "stdlib.h"
char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}

int main()
{
    char c = '#';
    int len = strlen(c);
    char str[] = "###hello";
    printf("%s",ft_strchr(str,c));
}