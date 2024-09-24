CC		= cc
CFLAGS	= -Wall -Wextra -Werror
TARGET	= rush-02
SRCS	= ft_strcmp.c ft_strlen.c main.c ft_sort_string_tab.c ft_file_io.c ft_strcmp_len.c ft_strcpy.c ft_split.c ft_arg_split.c ft_search.c ft_putstr.c ft_free.c ft_dict.c ft_substr.c ft_valid_type.c ft_strwith.c ft_search2.c ft_search3.c ft_search4.c
OBJS	= $(SRCS:.c=.o)

all:$(TARGET)

$(TARGET):$(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

.o.c:
	$(CC)  -c $< -o $@ 

clean:
	rm -f $(OBJS)

fclean:clean
	rm -f $(TARGET)

re:fclean all
