NAME = ft_containers

SRCS = main.cpp

CFLAGS = -Wall -Werror -Wextra -std=c++98

BUILD_DIR = obj
OBJS = $(SRCS:.cpp=.o)
OBJ = $(addprefix $(BUILD_DIR)/,$(OBJS))

all: $(NAME)

$(NAME): $(OBJ)
	@clang++ $(OBJ) -lm -o $(NAME) #-g -fsanitize=address 1>/dev/null
	@echo "$(NAME) created"

$(BUILD_DIR)/%.o: %.cpp Makefile
	@mkdir -p $(BUILD_DIR) 1>/dev/null
	@clang++ $(CFLAGS) -o $@ -c $< 1>/dev/null

clean:
	@/bin/rm -rf $(BUILD_DIR) ft.txt std.txt 1>/dev/null

fclean: clean
	@/bin/rm -f $(NAME) 1>/dev/null

re: 
	@make fclean 1>/dev/null
	@make all 1>/dev/null

run:
	@make list
	@make vector
	@make fclean  1>/dev/null

list: 
	@clang++ $(CFLAGS) list.hpp containers.hpp list.cpp 
	./a.out 
	@rm a.out *.hpp.gch 1>/dev/null

list_compare:
	@clang++ $(CFLAGS) list.hpp containers.hpp list.cpp 
	@./a.out std 1>./std.txt
	@./a.out ft 1>./ft.txt
	@-diff std.txt ft.txt 
	@rm a.out ft.txt std.txt *.hpp.gch 1>/dev/null

vector: 
	@clang++ $(CFLAGS) vector.hpp containers.hpp vector.cpp 
	./a.out 
	@rm a.out *.hpp.gch 1>/dev/null

vector_compare:
	@clang++ $(CFLAGS) vector.hpp containers.hpp vector.cpp 
	@./a.out std 1>./std.txt
	@./a.out ft 1>./ft.txt
	@- diff std.txt ft.txt
	@rm a.out ft.txt std.txt *.hpp.gch 1>/dev/null


valgrind:
	@make re
	valgrind ./$(NAME)

.PHONY: all, clean, fclean, re, all

# '-' before command instructs to continue even if the command returns an error value
