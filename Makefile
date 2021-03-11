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
	@/bin/rm -rf $(BUILD_DIR) 1>/dev/null

fclean: clean
	@/bin/rm -f $(NAME) 1>/dev/null

re: 
	@make fclean 1>/dev/null
	@make all 1>/dev/null

run:
	@make re  1>/dev/null
	./$(NAME)
	@make fclean  1>/dev/null

valgrind:
	@make re
	valgrind ./$(NAME)

.PHONY: all, clean, fclean, re, all
