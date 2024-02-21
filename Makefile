NAME = pipex

SRCS = 	pipex.c \
		src/init_vars.c \
		src/init_paths_list.c \
		src/open_pipes.c \
		src/child_process.c \
		src/check_cmd.c \
		src/free_vars.c 
		

OBJ_DIR = obj
OBJS = $(SRCS:%.c = $(OBJ_DIR)/%.o)

CC = cc

CFLAGS = -Wall -Werror -Wextra -g3

LIBFT_PATH		=	./libft
LIBFT			=	$(LIBFT_PATH)/libft.a

all: 		$(NAME)

$(NAME):	$(OBJ_DIR) $(OBJS)
			make -C $(LIBFT_PATH) all
			cp $(LIBFT) $(NAME)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) 

$(OBJ_DIR)/%.o:	%.c
		$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
		make -C $(LIBFT_PATH) all

$(OBJ_DIR):
		mkdir -p $(OBJ_DIR)

clean:	
		make -C $(LIBFT_PATH) clean
		rm -rf $(OBJ_DIR)

fclean:	clean;
		make -C $(LIBFT_PATH) fclean
		rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re libft test
