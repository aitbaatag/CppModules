
cc = g++
cflags = -Wall -Wextra -std=c++98
src = main.cpp A.cpp B.cpp C.cpp Base.cpp functions.cpp
obj = $(src:.cpp=.o)
name = identify 

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

