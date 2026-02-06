# ========================
#        Variables
# ========================

CC = cc
CFLAGS = -Wall -Wextra -Werror

MLX_DIR = mlx_linux
MLX_INC = -I$(MLX_DIR)
MLX_LIB = -L$(MLX_DIR) -lmlx -lX11 -lXext -lm

NAME = fractol
SRCS = main.c close_win.c uni_libft.c fractol.c
OBJS = $(SRCS:.c=.o)

# ========================
#        Colors
# ========================

GREEN  = \033[0;32m
YELLOW = \033[1;33m
RED    = \033[0;31m
NC     = \033[0m

# ========================
#        Rules
# ========================

all: mlx $(NAME)

# Build MiniLibX silently
mlx:
	@echo -e "$(YELLOW)Building MiniLibX...$(NC)"
	@$(MAKE) -C $(MLX_DIR) --silent > /dev/null 2>&1
	@echo -e "$(GREEN)MiniLibX built successfully!$(NC)"

# Link executable
$(NAME): $(OBJS)
	@echo -e "$(YELLOW)Linking $(NAME)...$(NC)"
	@$(CC) $(OBJS) -o $(NAME) $(MLX_LIB)
	@echo -e "$(GREEN)$(NAME) is ready!$(NC)"

# Compile .c to .o
%.o: %.c
	@echo -e "$(YELLOW)Compiling $<...$(NC)"
	@$(CC) $(CFLAGS) $(MLX_INC) -c $< -o $@

# Remove object files only
clean:
	@echo -e "$(RED)Cleaning object files...$(NC)"
	@rm -f $(OBJS)
	@$(MAKE) -C $(MLX_DIR) clean --silent > /dev/null 2>&1

# Remove object files + executable
fclean: clean
	@echo -e "$(RED)Removing executable...$(NC)"
	@rm -f $(NAME)

# Full rebuild
re: fclean all

# ========================
#        Phony
# ========================

.PHONY: all clean fclean re mlx

