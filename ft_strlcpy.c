#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t len)
{
	size_t	i;
	size_t	src_len;

	// return size_t => leghth of the string it tried to create
	// the len of src  ?
	// null terminator at the end
	// size > 0
	// if size = 0 ; dst in not modified & return src_len
	i = 0;
	src_len = ft_strlen(src);
	if (len == 0)
		return (src_len);
	if (len)
	{
		while (i < len - 1 && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (src_len);
}
