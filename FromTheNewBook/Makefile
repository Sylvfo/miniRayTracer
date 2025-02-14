NAME := minirt
CC := cc #-fsanitize=address
CFLAGS := #-Wall -Wextra -Werror
RM := rm -rf

OBJ_DIR = obj
SRC_DIR = ./src

MLX_DIR := minilibx_linux
MLX_INC := -I$(MLX_DIR)
MLX_LNK := -L$(MLX_DIR) -lmlx -lXext -lX11 -lm 

#make the all project cleaner. But at the end we have to change the.c by the files names. 
SRCS =	${shell find ${SRC_DIR} -type f -name '*.c'}\

OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
$(OBJ_DIR)/%.o: %.c #minirt.h
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -C $(MLX_INC) -c $< -o $@
#	$(CC) $(CFLAGS) -C -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_LNK)

clean:
	$(RM) $(OBJ_DIR)
	$(RM) $(OBJS)

fclean: clean
	$(RM) -r $(NAME)

re: fclean all

.PHONY:        all re clean fclean