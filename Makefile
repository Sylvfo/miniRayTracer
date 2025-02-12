# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/12 08:32:46 by cmegret           #+#    #+#              #
#    Updated: 2025/02/12 08:32:46 by cmegret          ###   ########.fr        #
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

CFLAGS = -Wall -Wextra -Werror -Iincludes

SRCS = \
		srcs/main/main.c \
		srcs/parsing/parse.c

MLX_DIR := lib/minilibx-linux
MLX_INC := -I$(MLX_DIR)
MLX_LNK := -L$(MLX_DIR) -lmlx -lXext -lX11 -lm 

OBJ = $(SRCS:.c=.o)

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

# Règle pour l'exécutable final
$(NAME): $(OBJ)
	@echo "$(BLUE)Linking: $@$(RESET)"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(MLX_LNK)
	@echo "$(GREEN)\nCompilation successful!\n$(RESET)"

# Règle pour les fichiers objets
%.o: %.c
	@echo "$(BLUE)Compiling: $<$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

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

# Règle pour nettoyer les fichiers objets
clean:
	@echo "$(RED)Cleaning object files...$(RESET)"
	@rm -rf $(OBJ_DIR)
	@echo "$(RED)Cleaning MinilibX...$(RESET)"
	@$(MAKE) -s -C $(MLX_DIR) clean $(REDIRECT)

# Règle pour nettoyer tout
fclean: clean
	@echo "$(RED)Cleaning executable(s)...$(RESET)"
	@rm -f $(NAME)
	@sleep 1
	clear

# Règle pour refaire tout
re: fclean all

# Règle pour rendre le makefile "phony"
.PHONY: all clean fclean re norm start debug