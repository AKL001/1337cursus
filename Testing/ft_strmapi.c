#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char to_upper_if_even(unsigned int index, char c) {
    if (index % 2 == 0 && c >= 'a' && c <= 'z') {
        return c - 32; // Convert lowercase to uppercase
    }
    return c;
}
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	s_len;
	char	*ptr;

	if (!s || !f)
		return (NULL);
	i = 0;
	s_len = strlen(s);
	ptr = (char *)malloc(sizeof(char) * (s_len + 1));
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
int	main()
{
	char *str = "hello world";
	char *result = ft_strmapi(str, to_upper_if_even);

	if (result)
	{
		printf("Original string: %s\n", str);
		printf("Modified string: %s\n", result);
		free(result); // Free the allocated memory
	}
	else
	{
		printf("Memory allocation failed.\n");
	}

	return (0);
}