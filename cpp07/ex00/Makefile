NAME := templateSample
FUNC	:= main.cpp Whatever.cpp
CC		:= c++ 
FLAGS	:= -Wall -Wextra -Werror -std=c++98 -pedantic-errors

all: $(NAME)

$(NAME): $(FUNC)
	$(CC) $(FLAGS) $(FUNC) -o $(NAME)

clean:
	rm -f $(NAME)

re: clean all

.PHONY:	all clean fclean re
