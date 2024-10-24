#include "stdio.h"
void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char *ptr = (unsigned char *)s;
	size_t i = 0;
	while (i < n)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
int main() {
    int s[10] = {1};

    // Set the first 3 bytes (not recommended for integers)
    ft_memset(s, 5, 3); // This can lead to undefined behavior for int arrays.

    // Print the entire first integer
    printf("First integer after memset: %d\n", s[0]);

    // Print the first byte of the first integer
    unsigned char *bytePtr = (unsigned char *)&s[0]; // Cast to unsigned char pointer
    printf("First byte after memset: %02x\n", bytePtr[0]); // Print the first byte in hex

    return 0;
}