NAME = RPN

LCYAN = \033[1;36m
GREEN = \033[0;32m
LGREEN = \033[1;32m
LRED = \033[1;31m
RESET = \033[0m
GRAY = \033[90m
PURPLE = \033[0;35m

INFO = $(LCYAN)/INFO/$(RESET)
CLEANING = $(LRED)[DELETING]$(RESET)
SUCCESS = $(LGREEN)[SUCCESS]$(RESET)

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

OBJ_DIR = obj

FILE = main RPN \

SRC = $(addsuffix .cpp, $(FILE))

OBJS = $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(FILE)))

all: $(NAME)

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@echo "$(INFO) $(GREEN)Creating $(NAME)$(RESET)"
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	@echo "$(SUCCESS)"

clean:
	@echo "$(CLEANING) $(GRAY)$(OBJ_DIR) in local dir$(RESET)"
	rm -rf $(OBJ_DIR)

fclean: clean
	@echo "$(CLEANING) $(GRAY)$(NAME)$(RESET)"
	rm -f $(NAME)


re: fclean all

.PHONY: all clean fclean re bonus
