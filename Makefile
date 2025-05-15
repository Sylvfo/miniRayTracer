# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/12 08:32:46 by cmegret           #+#    #+#              #
#    Updated: 2025/05/15 19:16:53 by cmegret          ###   ########.fr        #
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

# Flags de compilation -Wall -Wextra -Werror
CFLAGS = -Wall -Wextra -Werror #-Iincludes
LIBFLAGS = -Llib/libft -lft

# Fichiers sources
SRC_DIR = ./src
#SRCS = ${shell find ${SRC_DIR} -type f -name '*.c'}\

SRCS = ./src/main.c \
	./src/initialization/init_camera.c \
	./src/initialization/init_data.c \
	./src/initialization/init_hits_alloc.c \
	./src/initialization/init_hits_background.c \
	./src/initialization/init_hits.c \
	./src/initialization/init_hits_cylinders.c \
	./src/initialization/init_hits_init.c \
	./src/initialization/init_hits_plans.c \
	./src/initialization/init_hits_spheres.c \
	./src/initialization/init_light_alloc.c \
	./src/initialization/init_light.c \
	./src/initialization/init_light_init.c \
	./src/initialization/init_object_alloc.c \
	./src/initialization/init_object.c \
	./src/initialization/init_object_free.c \
	./src/initialization/init_object_free_utils.c \
	./src/initialization/init_object_init.c \
	./src/initialization/init_scene.c \
	./src/initialization/init_scene_camera.c \
	./src/initialization/init_scene_comps.c \
	./src/initialization/init_scene_hits.c \
	./src/initialization/init_scene_obj.c \
	./src/initialization/init_scene_viewport.c \
	./src/matrix/00_matrix_check.c \
	./src/matrix/00_matrix_creation.c \
	./src/matrix/00_matrix_multiplication.c \
	./src/matrix/00_matrix_operations.c \
	./src/matrix/00_matrix_rotation_rodrigues.c \
	./src/matrix/00_matrix_transl_scale.c \
	./src/matrix/00_matrix_transposing.c \
	./src/matrix/00_matrix_utils.c \
	./src/matrix/matrix_inverse.c \
	./src/matrix/matrix_minor_det.c \
	./src/matrix/matrix_submatrix.c \
	./src/parsing/parse_camera.c \
	./src/parsing/parse_checks.c \
	./src/parsing/parse_color.c \
	./src/parsing/parse_light.c \
	./src/parsing/parse_plane.c \
	./src/parsing/parse_sphere_cylinder.c \
	./src/parsing/parse_utils.c \
	./src/parsing/scene_parsing.c \
	./src/parsing_terminate/init_matrix_ima.c \
	./src/parsing_terminate/s_create_point_vector.c \
	./src/rays_calculs/00_raytracing_main.c \
	./src/rays_calculs/01_camera_construction.c \
	./src/rays_calculs/02_viewport_construction.c \
	./src/rays_calculs/03_m_transformations.c \
	./src/rays_calculs/04_intersect_main.c \
	./src/rays_calculs/05_intersect_sphere_plan.c \
	./src/rays_calculs/06_intersect_cylinder.c \
	./src/rays_calculs/07_closest_obj.c \
	./src/rays_calculs/08_prepare_comps.c \
	./src/rays_calculs/09_light_shadow_main.c \
	./src/rays_calculs/10_shadows.c \
	./src/rays_calculs/11_light.c \
	./src/rays_calculs/shadows_cylinder.c \
	./src/rays_calculs/shadows_plan.c \
	./src/rays_calculs/shadows_sphere.c \
	./src/saving_data/save_camera.c \
	./src/saving_data/save_cylinder.c \
	./src/saving_data/save_light.c \
	./src/saving_data/save_plane.c \
	./src/saving_data/save_scene_file.c \
	./src/saving_data/save_sphere.c \
	./src/vect_point_color/add_substr.c \
	./src/vect_point_color/check_type_coord.c \
	./src/vect_point_color/colors_operation.c \
	./src/vect_point_color/copy_coord.c \
	./src/vect_point_color/math.c \
	./src/vect_point_color/print_vector_point.c \
	./src/vect_point_color/set_colors.c \
	./src/vect_point_color/vector_operations.c \
	./src/vect_point_color/vector_operations_length.c \
	./src/window/event_hooks.c \
	./src/window/event_hooks_function.c \
	./src/window/image_to_window.c \
	./src/window/pixel_put.c \
	./src/free/free_all.c \
	./src/free/free_basics.c \
	./src/free/free_components.c \
	./src/free/free_comps.c \
	./src/free/free_hits.c \
	./src/free/free_lights.c \
	./src/free/free_pixels.c \
	./src/free/free_pixels2.c \

# Détection de l'OS pour choisir la bonne version de la MLX
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Darwin)
	MLX_DIR := lib/minilibx_opengl
	MLX_INC := -I$(MLX_DIR)
	MLX_LNK := -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
else
	MLX_DIR := lib/minilibx-linux
	MLX_INC := -I$(MLX_DIR)
	MLX_LNK := -L$(MLX_DIR) -lmlx -lXext -lX11 -lm
endif

# Bibliothèques
LIBFT = lib/libft/libft.a

# Fichiers objets
OBJ_DIR = objs
OBJ = $(SRCS:%.c=$(OBJ_DIR)/%.o)

# Fichiers de test
TEST_SRCS = tests/run_test.c tests/test_validate_ambient.c tests/test_validate_light.c tests/test_validate_camera.c $(filter-out srcs/main/main.c, $(SRCS))
TEST_OBJS = $(TEST_SRCS:.c=.o)
TEST_NAME = test_fonction

# all: start norm $(MLX_DIR)/libmlx.a $(NAME)
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