#include <stdio.h>
#include <string.h>
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	// overlaping case  -> max(left bound) <= min(right bound)
	if (n == 0 || dest == src)
		return (dest);
	if (dest < src)
	{
		memcpy(dest, src, n);
	}
	else
	{
		while (n--)
		{
			*((unsigned char *)(dest + n)) = *((unsigned char *)(src + n));
		}
	}
	return (dest);
}
int main() {
    char src[] = "Hello, World!";
    char dest[20];

    ft_memmove(dest, src, 5); // Copy entire string
    printf("Test Case 1: %s\n", dest); // Expected: "Hello, World!"
    return 0;
}