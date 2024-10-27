#include <stdio.h>
#include <stdlib.h>

char *ft_strjoin(char const *s1, char const *s2)
{
    // memcpy or memmove 
    if(!s1 || !s2)
        return NULL;
    size_t s1_len = strlen(s1);
    size_t s2_len = strlen(s2);
    char *ptr;
    size_t max_len = s1_len + s2_len;
    ptr = (char *)malloc(sizeof(char) * (max_len + 1));
    if(ptr == NULL)
        return NULL;
    memmove(ptr,s1,s1_len);
    memmove(ptr + s1_len,s2,s2_len);
    ptr[max_len] = '\0';
    return ptr;
}
int main() {
    char *s1 = "Hello, ";
    char *s2 = "World!";
    char *result = ft_strjoin(s1, s2);

    if (result) {
        printf("Result: %s\n", result);  // Expected output: "Hello, World!"
        free(result);
    } else {
        printf("Failed to allocate memory.\n");
    }

    return 0;
}
