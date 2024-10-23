#include "libft.h"
#include <string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t src_len = ft_strlen(src);
	size_t dst_len = ft_strlen(dst);
	size_t total_len;
	size_t i;

	total_len = src_len + dst_len;
	if(size == 0)
		return src_len;

	if (size <= dst_len)
	{
		return (size + src_len);
	}

	i = 0;
	while ((dst_len + i + 1) < size && src[i])
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';

	return (total_len);
}

void run_test(char *dst, const char *src, size_t size) {
    char original_dst[50]; // To preserve original dst for output
    strcpy(original_dst, dst); // Copy for output
    size_t result = ft_strlcat(dst, src, size);
    printf("dst = '%s', src = '%s', size = %zu\n", original_dst, src, size);
    printf("Resulting dst: '%s'\n", dst);
    printf("Return value: %zu\n\n", result);
}

int main() {
    // Test cases
    char dst1[8] = "hello";
    run_test(dst1, " ,world", 8); // Expect: "hello ,", return 12

    char dst2[10] = "hi";
    run_test(dst2, " there", 10); // Expect: "hi there", return 10

    char dst3[6] = "hello";
    run_test(dst3, " ,world", 5); // Expect: "hello", return 12

    char dst4[10] = "test";
    run_test(dst4, "", 10); // Expect: "test", return 10

    char dst5[10] = "";
    run_test(dst5, "world", 10); // Expect: "world", return 5

    char dst6[6] = "abc";
    run_test(dst6, "def", 6); // Expect: "abcdef", return 6

    char dst7[10] = "short";
    run_test(dst7, "longer string", 10); // Expect: "short lon", return 15

    char dst8[6] = "hello";
    run_test(dst8, "world", 0); // Expect: "hello", return 5

    return 0;
}