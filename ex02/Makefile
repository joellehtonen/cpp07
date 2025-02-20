NAME	=	array
CC		=	c++
FLAGS	=	-Wall -Wextra -Werror -std=c++20 -ggdb3
SRCS	=	main_subject.cpp 
HEADER  =	Array.hpp \
			Array.tpp
OBJS	=	$(SRCS:.cpp=.o)

all: $(NAME)

%.o: %.cpp $(HEADER)
	@$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@$(CC) $(FLAGS) $(OBJS) -o $(NAME)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re