NAME = ft_retro
SOURCES = ./src/main.cpp ./src/hero.cpp ./src/Villain.cpp

$(NAME):
	@g++ -Wall -Werror -Wextra -lncurses -std=c++98 $(SOURCES) -o $(NAME)
	@echo "\033[1;32;4mCOMPILING SUCCESSFUL"

all: $(NAME)

clean:
	@rm -f $(NAME)
	@echo "\033[1;34;4mCLEAN SUCCESSFUL\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[1;34;4mFCLEAN SUCCESSFUL\033[0m"

re: fclean all