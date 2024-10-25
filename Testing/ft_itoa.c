#include <stdio.h>
#include <stdlib.h>  // Required for malloc

static int ft_sign(int nbr)
{
    if (nbr < 0)
        return (-1);
    return (1);
}

static int ft_len(int nbr) {
    int len = 0;
    if (nbr <= 0)
        len = 1;
    while (nbr != 0) {
        nbr /= 10;
        len++;
    }
    return len;
}

char *ft_itoa(int nbr)
{
    int sign = ft_sign(nbr);
    int len = ft_len(nbr);
    char *dest;

    dest = (char *)malloc(sizeof(char) * (len + 1));
    if (!dest)
        return (NULL);
    
    dest[len] = '\0';
    
    if (nbr == 0)
    {
        dest[0] = '0';
        return (dest);
    }
    
    if (nbr < 0)
    {
        dest[0] = '-';
    }
    
    while (nbr)
    {
        len--; 
        dest[len] = '0' + (sign * (nbr % 10));
        nbr /= 10;
    }
    
    return (dest);
}

int main() {
    int test_cases[] = {0, 123, -123, 2147483647, -2147483648};
    for (int i = 0; i < 5; i++) {
        char *result = ft_itoa(test_cases[i]);
        printf("ft_itoa(%d) = %s\n", test_cases[i], result);
        free(result);
    }
    return 0;
}