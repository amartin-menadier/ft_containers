NAME = a.out

SRCS = main.cpp

CFLAGS = -Wall -Werror -Wextra -std=c++98

BUILD_DIR = obj
OBJS = $(SRCS:.cpp=.o)
OBJ = $(addprefix $(BUILD_DIR)/,$(OBJS))

all: 
	@clang++ $(CFLAGS) main.cpp containers.hpp list.cpp list.hpp map.cpp map.hpp queue.cpp queue.hpp stack.cpp stack.hpp vector.cpp vector.hpp
	@rm *.hpp.gch 1>/dev/null

clean:
	@/bin/rm -rf $(BUILD_DIR) ft.txt std.txt 1>/dev/null

fclean: clean
	@/bin/rm -f $(NAME) 1>/dev/null

re: 
	@make fclean 1>/dev/null
	@make all 1>/dev/null

print: list vector map queue stack

all_compare: list_compare vector_compare map_compare queue_compare stack_compare

list: 
	@./a.out list

list_compare:
	@./a.out list std 1>./std.txt
	@./a.out list ft 1>./ft.txt
	@-diff std.txt ft.txt 

vector: 
	@./a.out vector

vector_compare:
	@./a.out vector std 1>./std.txt
	@./a.out vector ft 1>./ft.txt
	@- diff std.txt ft.txt

map: 
	@./a.out map

map_compare:
	@./a.out map std 1>./std.txt
	@./a.out map ft 1>./ft.txt
	@- diff std.txt ft.txt

stack: 
	@./a.out stack

stack_compare:
	@./a.out stack std 1>./std.txt
	@./a.out stack ft 1>./ft.txt
	@- diff std.txt ft.txt

queue:
	@./a.out queue

queue_compare:
	@./a.out queue std 1>./std.txt
	@./a.out queue ft 1>./ft.txt
	@- diff std.txt ft.txt

valgrind:
	@make re
	valgrind ./$(NAME)

.PHONY: all, clean, fclean, re, all

# '-' before command instructs to continue even if the command returns an error value
# '@' before command instructs not to echo it 
