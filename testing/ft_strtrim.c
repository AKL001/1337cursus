#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Prototype for your ft_strtrim function
// char *ft_strtrim(char const *s1, char const *set);
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
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	len;
	size_t	s1_len;
	char	*ptr;

	if (!set || !s1)
		return (NULL);
	s1_len = strlen(s1);
	start = 0;
	while (s1[start] && strchr(set, s1[start]))
		start++;
	end = s1_len;
	while (end > start && strchr(set, s1[end - 1]))
		end--;
	len = end - start; // len
	ptr = ft_substr(s1, start, len);
	if (!ptr)
		return (NULL);
	ptr[len] = '\0';
	return (ptr);
}


// Main function to test ft_strtrim
int main() {
    char *result;

    // Test 1: Trim characters from both ends
    result = ft_strtrim("abchello worldabc", "abc");
    printf("Test 1 - Expected: 'hello world', Got: '%s'\n", result);
    free(result);

    // Test 2: Trim only from the beginning
    result = ft_strtrim("!!hello world", "!");
    printf("Test 2 - Expected: 'hello world', Got: '%s'\n", result);
    free(result);

    // Test 3: Trim only from the end
    result = ft_strtrim("hello world$$$", "$");
    printf("Test 3 - Expected: 'hello world', Got: '%s'\n", result);
    free(result);

    // Test 4: Trim multiple characters from both ends
    result = ft_strtrim("abcabcHelloabcabc", "abc");
    printf("Test 4 - Expected: 'Hello', Got: '%s'\n", result);
    free(result);

    // Test 5: Set has characters not in s1
    result = ft_strtrim("hello world", "#!");
    printf("Test 5 - Expected: 'hello world', Got: '%s'\n", result);
    free(result);

    // Test 6: s1 is fully made of set characters
    result = ft_strtrim("####", "#");
    printf("Test 6 - Expected: '', Got: '%s'\n", result);
    free(result);

    // Test 7: Empty s1
    result = ft_strtrim("", "#");
    printf("Test 7 - Expected: '', Got: '%s'\n", result);
    free(result);

    // Test 8: Empty set
    result = ft_strtrim("hello world", "");
    printf("Test 8 - Expected: 'hello world', Got: '%s'\n", result);
    free(result);

    // Test 9: Both s1 and set are empty
    result = ft_strtrim("", "");
    printf("Test 9 - Expected: '', Got: '%s'\n", result);
    free(result);

    return 0;
}
