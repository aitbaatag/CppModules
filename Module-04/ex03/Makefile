NAME = program
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp AMateria.cpp Cure.cpp Ice.cpp MateriaSource.cpp Character.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all