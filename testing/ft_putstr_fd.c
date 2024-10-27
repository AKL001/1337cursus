#include <stdio.h>
#include <fcntl.h>  // For open
#include <unistd.h> // For close
#include <string.h>
void	ft_putstr_fd(char *s, int fd)
{
	size_t s_len;

	if (!s || fd < 0)
		return ;
	s_len = strlen(s);
	write(fd, s, s_len);
}
int main(void)
{
    printf("\n----- Testing ft_putstr_fd -----\n\n");

    // Test 1: Normal string to stdout
    printf("Test 1 - Normal string to stdout:\n");
    ft_putstr_fd("Hello World!", 1);
    printf("\n\n");

    // Test 2: Empty string to stdout
    printf("Test 2 - Empty string to stdout:\n");
    ft_putstr_fd("", 1);
    printf("(empty string was printed)\n\n");

    // Test 3: String with special characters to stdout
    printf("Test 3 - Special characters:\n");
    ft_putstr_fd("Tab:\t Newline:\n Backslash:\\ Quote:\"", 1);
    printf("\n\n");

    // Test 4: Writing to stderr
    printf("Test 4 - Writing to stderr:\n");
    ft_putstr_fd("This is an error message", 2);
    printf("\n\n");

    // Test 5: Writing to a file
    printf("Test 5 - Writing to file:\n");
    int fd = open("test.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1)
    {
        printf("Error opening file\n");
        return (1);
    }
    ft_putstr_fd("Writing this to a file!", fd);
    close(fd);
    printf("Check test.txt file for content\n\n");

    // Test 6: NULL pointer (should not crash)
    printf("Test 6 - NULL pointer:\n");
    ft_putstr_fd(NULL, 1);
    printf("(program didn't crash with NULL)\n\n");

    // Test 7: Invalid fd (should not crash)
    printf("Test 7 - Invalid fd:\n");
    ft_putstr_fd("This shouldn't be written", -1);
    printf("(program didn't crash with invalid fd)\n\n");

    // Test 8: Long string
    printf("Test 8 - Long string:\n");
    char long_str[1000];
    memset(long_str, 'A', 998);
    long_str[998] = '\n';
    long_str[999] = '\0';
    ft_putstr_fd(long_str, 1);
    printf("\n");

    // Test 9: Multiple writes to same fd
    printf("Test 9 - Multiple writes:\n");
    ft_putstr_fd("First ", 1);
    ft_putstr_fd("Second ", 1);
    ft_putstr_fd("Third\n", 1);
    printf("\n");

    // Test 10: Writing to multiple files
    printf("Test 10 - Multiple files:\n");
    int fd1 = open("test1.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    int fd2 = open("test2.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd1 != -1 && fd2 != -1)
    {
        ft_putstr_fd("Content for file 1", fd1);
        ft_putstr_fd("Content for file 2", fd2);
        close(fd1);
        close(fd2);
        printf("Check test1.txt and test2.txt for content\n");
    }

    printf("\n----- Tests Complete -----\n");
    return (0);
}