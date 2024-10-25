#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <limits.h>
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	// len of the substr
	// s[start]
	// [ a , b , c , d , f , g ,h ,r ,t]
	//   1   2   3   4   5   6  7  8  9
	// s_len = 9;  start  = 3; len = 9;
	// s_len < start + len
	// len > max_string_len
	char *ptr;
    if(!s)
        return NULL;
    size_t s_len = strlen(s);
	if (start >= s_len)
		len = 0;
	else if (len > s_len - start || len > s_len)
		len = s_len - start;
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (ptr == NULL)
		return (NULL);
	memcpy(ptr, s + start, len);
	ptr[len] = '\0';
	return (ptr);
}

int main()
{
    char *result;

    // Test Case 8: NULL String Input
    result = ft_substr(NULL, 0, 5);
    printf("Test 8: %s\n", result ? result : "(null)"); // Expected output: "(null)" or no crash
    free(result);

    // Test Case 9: Start Value Larger than String Length
    result = ft_substr("Test", 1000, 5);
    printf("Test 9: %s\n", result); // Expected output: "" (empty string) with no crash
    free(result);

    // Test Case 10: Extremely Large Length Value
    result = ft_substr("Edge", 1, SIZE_MAX);
    printf("Test 10: %s\n", result ? "Allocated" : "(null)"); // Expected output: "(null)" if malloc fails
    free(result);

    // Test Case 11: Start Value is Max Unsigned Integer
    result = ft_substr("Hello World", UINT_MAX, 5);
    printf("Test 11: %s\n", result ? result : "(null)"); // Expected output: "" (empty string) with no crash
    free(result);

    // Test Case 12: Very Large Start Value with Small String
    result = ft_substr("Small", 5000, 2);
    printf("Test 12: %s\n", result); // Expected output: "" (empty string) with no crash
    free(result);

    return 0;
}