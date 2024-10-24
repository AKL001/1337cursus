#include "libft.h"

char	*strnstr(const char *big, const char *little, size_t len)
{
	// if little == '\0' ; return big
	// if len ==0 ; return (NULL);
	// i < len
	// if little is not in big ; return (NULL);
	size_t i;
	size_t j;
	size_t big_len = ft_strlen(big);
	size_t little_len = ft_strlen(little);

	if (*little == '\0')
		return ((char *)big);
	if (len == 0)
		return (NULL);
	// if (little_len > big_len)
	// 	return (NULL);
	// [bob ish dogshit]
	// [shit]
	i = 0;
	while (big[i] && i < len)
	{
		// if (i + little_len > len)
		// 	return (break);
		if (big[i] == little[0])
		{
			j = 0;
			while (j < little_len && big[i + j] == little[j])
			{
				j++;
			}
			if (j == little_len)
				return (char *)(big + i);
		}
		i++;
	}
	return (NULL);
}