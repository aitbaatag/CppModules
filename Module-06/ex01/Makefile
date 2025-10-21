
cc = g++
cflags = -Wall -Wextra -std=c++98
src = main.cpp Serializer.cpp
obj = $(src:.cpp=.o)
name = converter

all: $(name)

$(name): $(obj)
	$(cc) $(cflags) -o $(name) $(obj)

%.o: %.cpp
	$(cc) $(cflags) -c $< -o $@

clean:
	rm -f $(obj)

fclean: clean
	rm -f $(name)

re: fclean all

