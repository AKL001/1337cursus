#include "stdio.h"
char	*ft_strrchr(const char *s, int c)
{
	size_t	s_len;

	s_len = strlen(s);
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
int main() {
    // Test cases
    char *str1 = "hello!";
    char *str2 = "hello!";
    char *str3 = "hello";
    char *str4 = "a";
    char *str5 = "abcabcabc";
    char *str6 = "";
    
    // Case 1: Character is the last one in the string
    char *result1 = ft_strrchr(str1, 'h');
    printf("Test 1: %s\n", result1 ? result1 : "NULL"); // Expected: "!"

    // Case 2: Character is not present
    char *result2 = ft_strrchr(str1, 'x');
    printf("Test 2: %s\n", result2 ? result2 : "NULL"); // Expected: "NULL"

    // Case 3: Last character is 'o', should return pointer to 'o'
    char *result3 = ft_strrchr(str2, 'o');
    printf("Test 3: %s\n", result3 ? result3 : "NULL"); // Expected: "o!"

    // Case 4: Single character string, searching for that character
    char *result4 = ft_strrchr(str4, 'a');
    printf("Test 4: %s\n", result4 ? result4 : "NULL"); // Expected: "a"

    // Case 5: Character is the first one and also the last
    char *result5 = ft_strrchr(str5, 'a');
    printf("Test 5: %s\n", result5 ? result5 : "NULL"); // Expected: "abcabc"

    // Case 6: Searching for an empty string
    char *result6 = ft_strrchr(str6, '\0');
    printf("Test 6: %s\n", result6 ? result6 : "NULL"); // Expected: ""

    // Case 7: Searching for the last character which is the first in a single char string
    char *result7 = ft_strrchr(str4, 'a');
    printf("Test 7: %s\n", result7 ? result7 : "NULL"); // Expected: "a"

    return 0;
}