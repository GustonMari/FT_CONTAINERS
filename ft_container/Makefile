CXX = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror -g -MMD -fsanitize=address
SRCS = main.cpp

OBJS_STD =	$(addprefix $(OBJS_PATH), $(SRCS:.cpp=_std.o))
OBJS_FT =	$(addprefix $(OBJS_PATH), $(SRCS:.cpp=_ft.o))

DEPS = $(OBJS_STD:.o=.d) $(OBJS_FT:.o=.d)
NAME_FT= ft_containers
NAME_STD= std_containers

ft: $(NAME_FT)

std: $(NAME_STD)

all: $(NAME_FT) $(NAME_STD)
	@echo "\\n\033[32;1mMAKE ALL OK \033[0m \\n"
	# @echo "\033[32;1m      ___           ___           ___           ___                  \033[0m"
	# @echo "\033[32;1m     /\__\         /\  \         /\  \         /\  \                 \033[0m"
	# @echo "\033[32;1m    /:/ _/_       |::\  \       /::\  \       /::\  \         ___    \033[0m"
	# @echo "\033[32;1m   /:/ /\  \      |:|:\  \     /:/\:\  \     /:/\:\__\       /|  |   \033[0m"
	# @echo "\033[32;1m  /:/ /::\  \   __|:|\:\  \   /:/ /::\  \   /:/ /:/  /      |:|  |   \033[0m"
	# @echo "\033[32;1m /:/__\/\:\__\ /::::|_\:\__\ /:/_/:/\:\__\ /:/_/:/__/___    |:|  |   \033[0m"
	# @echo "\033[32;1m \:\  \ /:/  / \:\~~\  \/__/ \:\/:/  \/__/ \:\/:::::/  /  __|:|__|   \033[0m"
	# @echo "\033[32;1m  \:\  /:/  /   \:\  \        \::/__/       \::/~~/~~~~  /::::\  \   \033[0m"
	# @echo "\033[32;1m   \:\/:/  /     \:\  \        \:\  \        \:\~~\      ~~~~\:\  \  \033[0m"
	# @echo "\033[32;1m    \::/  /       \:\__\        \:\__\        \:\__\          \:\__\ \033[0m"
	# @echo "\033[32;1m     \/__/         \/__/         \/__/         \/__/           \/__/ \033[0m"
	# @echo "\\n"

$(NAME_FT): $(OBJS_FT)
	$(CXX) $(CXXFLAGS) -o $(NAME_FT) $(OBJS_FT) 
	@echo "\\n\033[32;1mFT COMPILATION OK \033[0m \\n"

$(NAME_STD): $(OBJS_STD)
	$(CXX) $(CXXFLAGS) -o $(NAME_STD) $(OBJS_STD) 
	@echo "\\n\033[32;1mSTD COMPILATION OK \033[0m \\n"

$(OBJS_PATH)%_std.o: $(SRCS_PATH)%.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -D TESTED_NAMESPACE=std -MMD -c $< -o $@ $(INCS)

$(OBJS_PATH)%_ft.o: $(SRCS_PATH)%.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -D TESTED_NAMESPACE=ft -MMD -c $< -o $@ $(INCS)

clean:
	@echo "\\n\033[38;5;202;1mDeleting Objects... \033[0m \\n"
	rm -rf $(OBJS_FT) $(OBJS_STD) $(DEPS) ft.txt std.txt
	@echo "\\n\033[32;1mDeleting OK \033[0m \\n"

fclean: clean
	@echo "\\n\033[38;5;202;1mCLEANING ALL... \033[0m \\n"
	rm -rf $(NAME_FT) $(NAME_STD)
	@echo "\\n\033[32;1mOK \033[0m \\n"

re: fclean all

compare: all
	@echo "\\n\033[38;5;202;1mCOMPARING... \033[0m \\n"
	./$(NAME_FT) > ft.txt
	./$(NAME_STD) > std.txt
	diff ft.txt std.txt
	@echo "\\n\033[32;1mOK \033[0m \\n"

-include $(DEPS)

.PHONY: all clean fclean re libft server client

.SILENT: