#include <stdio.h>
// #include "libft.h"
// int	ft_strncmp(const char *s1, const char *s2, size_t n);
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	i = 0;
	if (n > 0)
	{
		while (i < n && (s1[i] != '\0' || s2[i] != '\0'))
		{
			if (s1[i] != s2[i])
				return (s1[i] - s2[i]);
			i++;
		}
	}
	return (0);
}

int	main(void)
{
	// Test case 1: Equal strings, n > length
	printf("Test 1: %d\n", ft_strncmp("hello", "hello", 5));  // Output: 0

	// Test case 2: Equal strings, n < length
	printf("Test 2: %d\n", ft_strncmp("hello", "hello", 3));  // Output: 0

	// Test case 3: Different strings, n < first difference
	printf("Test 3: %d\n", ft_strncmp("hello", "hellp", 4));  // Output: 0

	// Test case 4: Different strings, n = first difference
	printf("Test 4: %d\n", ft_strncmp("hello", "hellp", 5));  // Output: negative (since 'o' < 'p')

	// Test case 5: Different strings, n > first difference
	printf("Test 5: %d\n", ft_strncmp("hello", "hellz", 10));  // Output: negative (since 'o' < 'z')

	// Test case 6: First string is shorter
	printf("Test 6: %d\n", ft_strncmp("hell", "hello", 5));  // Output: negative (since 'o' > '\0')

	// Test case 7: Second string is shorter
	printf("Test 7: %d\n", ft_strncmp("hello", "hell", 5));  // Output: positive (since '\0' < 'o')

	// Test case 8: Empty strings
	printf("Test 8: %d\n", ft_strncmp("", "", 1));  // Output: 0

	// Test case 9: First string is empty
	printf("Test 9: %d\n", ft_strncmp("", "hello", 5));  // Output: negative (since '\0' < 'h')

	// Test case 10: Second string is empty
	printf("Test 10: %d\n", ft_strncmp("hello", "", 5));  // Output: positive (since 'h' > '\0')

	// Test case 11: Case sensitivity check
	printf("Test 11: %d\n", ft_strncmp("Hello", "hello", 5));  // Output: negative (since 'H' < 'h')

	// Test case 12: n = 0 (should always return 0)
	printf("Test 12: %d\n", ft_strncmp("hello", "world", 0));  // Output: 0

	// Test case 13: n = 1 (compare only first character)
	printf("Test 13: %d\n", ft_strncmp("hello", "world", 1));  // Output: negative (since 'h' < 'w')

	// Test case 14: Comparing longer n than both strings
	printf("Test 14: %d\n", ft_strncmp("hello", "hello", 100));  // Output: 0

	// Test case 15: One string longer but n < length
	printf("Test 15: %d\n", ft_strncmp("hello world", "hello", 5));  // Output: 0
}
