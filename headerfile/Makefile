# Makefile for libft

# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -Werror

# Source files
SRCS = ft_bzero.c ft_isalpha.c ft_isdigit.c ft_memcpy.c ft_memset.c \
       ft_isalnum.c ft_isascii.c ft_isprint.c ft_memmove.c ft_strlen.c \

# Object files
OBJS = $(SRCS:.c=.o)

# Library name
NAME = libft.a

# Rule to create the library
all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $@ $^

# Rule to compile source files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up object files and the library
clean:
	rm -f $(OBJS)

# Clean up all files (including the library)
fclean: clean
	rm -f $(NAME)

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re
