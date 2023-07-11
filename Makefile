NAME = libftprintf.a

CC = cc
FLAGS = -Wall -Wextra -Werror -g3
SRC_DIR = srcs
RM = rm -f
AR = ar rcs

SRC = ft_printf ft_putnbr_base ft_splitflags ft_utoa handler1 handler2
SRCS 			=	$(addprefix $(SRC_DIR)/, $(addsuffix .c, $(SRC)))

OBJ_DIR = obj
OBJS			=	$(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(SRC)))

LIBFT_PATH		=	./libft
LIBFT			=	$(LIBFT_PATH)/libft.a

$(OBJ_DIR)/%.o:		$(SRC_DIR)/%.c
	$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME):			$(LIBFT) $(OBJ_DIR) $(OBJS)
	cp	$(LIBFT) $(NAME)
	$(AR) $(NAME) $(OBJS)
	ranlib $(NAME)

$(LIBFT):
	make -C $(LIBFT_PATH) all
	make -C $(LIBFT_PATH) bonus	
	make clean -C $(LIBFT_PATH)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
