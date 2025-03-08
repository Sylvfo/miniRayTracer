# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/12 08:32:46 by cmegret           #+#    #+#              #
#    Updated: 2025/03/08 11:15:51 by cmegret          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# https://patorjk.com/software/taag/
HEADER1 =                                               
HEADER2 =                                               
HEADER3 = "███╗   ███╗██╗███╗   ██╗██╗██████╗ ████████╗"
HEADER4 = "████╗ ████║██║████╗  ██║██║██╔══██╗╚══██╔══╝"
HEADER5 = "██╔████╔██║██║██╔██╗ ██║██║██████╔╝   ██║   "
HEADER6 = "██║╚██╔╝██║██║██║╚██╗██║██║██╔══██╗   ██║   "
HEADER7 = "██║ ╚═╝ ██║██║██║ ╚████║██║██║  ██║   ██║   "
HEADER8 = "╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝╚═╝  ╚═╝   ╚═╝   "
HEADER9 =                                               
HEADER10 =                                              

# Délai d'affichage du logo
DELAY = 0.1

# Redirection des erreurs
REDIRECT = > /dev/null 2>&1

# Codes de couleur
RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
MAGENTA = \033[0;35m
CYAN = \033[0;36m
RESET = \033[0m

# Nom de l'exécutable
NAME = minirt

# Compilateur
CC = cc

# Flags de compilation
CFLAGS = -Wall -Wextra -Werror #-Iincludes
LIBFLAGS = -Llib/libft -lft

# Fichiers sources
SRC_DIR = ./src
SRCS = ${shell find ${SRC_DIR} -path ${SRC_DIR}/parsing_terminate -prune -o -type f -name '*.c' -print}\

# Bibliothèques
LIBFT = lib/libft/libft.a
MLX_DIR := lib/minilibx-linux
MLX_INC := -I$(MLX_DIR)
MLX_LNK := -L$(MLX_DIR) -lmlx -lXext -lX11 -lm 

# Fichiers objets
OBJ_DIR = objs
OBJ = $(SRCS:%.c=$(OBJ_DIR)/%.o)

# Fichiers de test
TEST_SRCS = tests/run_test.c tests/test_validate_ambient.c tests/test_validate_light.c tests/test_validate_camera.c $(filter-out srcs/main/main.c, $(SRCS))
TEST_OBJS = $(TEST_SRCS:.c=.o)
TEST_NAME = test_fonction

all: start norm $(MLX_DIR)/libmlx.a $(NAME)

# Règle pour afficher le logo au démarrage
start:
	clear
	@echo $(HEADER1)
	@sleep $(DELAY)
	@echo $(HEADER2)
	@sleep $(DELAY)
	@echo $(HEADER3)
	@sleep $(DELAY)
	@echo $(HEADER4)
	@sleep $(DELAY)
	@echo $(HEADER5)
	@sleep $(DELAY)
	@echo $(HEADER6)
	@sleep $(DELAY)
	@echo $(HEADER7)
	@sleep $(DELAY)
	@echo $(HEADER8)
	@sleep $(DELAY)
	@echo $(HEADER9)
	@sleep $(DELAY)
	@echo $(HEADER10)
	@sleep $(DELAY)

# Règle pour compiler MinilibX
$(MLX_DIR)/libmlx.a:
	@echo "$(BLUE)Compiling MinilibX...$(RESET)"
	@$(MAKE) -s -C $(MLX_DIR) $(REDIRECT)

# Règle pour compiler la libft
$(LIBFT):
	@echo "$(BLUE)Compiling: lib/libft$(RESET)"
	@$(MAKE) -C ./lib/libft -f Makefile $(REDIRECT)

# Règle pour l'exécutable final
$(NAME): $(LIBFT) $(OBJ)
	@echo "$(BLUE)Linking: $@$(RESET)"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFLAGS) $(MLX_LNK)
	@echo "$(GREEN)\nCompilation successful!\n$(RESET)"

# Règle pour les fichiers objets
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@echo "$(BLUE)Compiling: $<$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

# Règle pour compiler les tests
$(TEST_NAME): $(TEST_OBJS) $(LIBFT) $(MLX_DIR)/libmlx.a
	@echo "$(BLUE)Linking: $@$(RESET)"
	@$(CC) $(CFLAGS) -o $(TEST_NAME) $(TEST_OBJS) $(LIBFLAGS) $(MLX_LNK)
	@echo "$(GREEN)\nCompilation des tests réussie!\n$(RESET)"

# Règle pour la norminette
norm:
	@echo "$(YELLOW)Exécution de norminette sur les fichiers spécifiés dans SRC...$(RESET)"
	@norminette $(SRCS) > norminette_output.txt || (echo "")
	@error=0; \
	while IFS= read -r line; do \
		if ! echo "$$line" | grep -q 'OK!$$'; then \
			echo "$(RED)Erreur dans le fichier : $$line$(RESET)"; \
			error=1; \
		fi; \
	done < norminette_output.txt || (echo "$(MAGENTA)Erreur lors de la vérification du résultat de norminette$(RESET)"); \
	if [ $$error -eq 0 ]; then \
		echo "$(GREEN)Tous les fichiers spécifiés dans SRC sont conformes à la norme.$(RESET)"; \
	fi
	@rm norminette_output.txt
	@echo " "

debug: CFLAGS += -g
debug: re

# Règle pour exécuter les tests
test: $(TEST_NAME)
	@echo "$(BLUE)Running tests...$(RESET)"
	@./$(TEST_NAME)

# Règle pour nettoyer les fichiers objets
clean:
	@echo "$(RED)Cleaning object files...$(RESET)"
	@rm -rf $(OBJ_DIR)
	@rm -f $(TEST_OBJS)
	@echo "$(RED)Cleaning MinilibX...$(RESET)"
	@$(MAKE) -s -C $(MLX_DIR) clean $(REDIRECT)
	@echo "$(RED)Cleaning libft...$(RESET)"
	@$(MAKE) -C lib/libft/ clean $(REDIRECT)

# Règle pour nettoyer tout
fclean: clean
	@echo "$(RED)Cleaning executable(s)...$(RESET)"
	@rm -f $(NAME)
	@rm -f $(TEST_NAME)
	@$(MAKE) -C lib/libft/ fclean $(REDIRECT)
	@sleep 1
	clear

# Règle pour refaire tout
re: fclean all

# Règle pour rendre le makefile "phony"
.PHONY: all clean fclean re norm start debug test