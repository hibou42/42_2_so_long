#***** Name *****#

NAME			=		so_long

#***** Makeflags *****#

MAKEFLAGS += --no-print-directory

#***** Sources / Objs *****#

SRC				=		z_test.c \

OBJS			=		$(SRC:.c=.o)

#***** Libft / MiniLbx *****#

LIBFT			=		./libft/libft.a
MLXLIB			=		./mlx/libmlx.a
MINILBX			=		-Lmlx -lmlx -framework OpenGL -framework AppKit
MLIBFT			=		$(MAKE) -C libft
MMLX			=		$(MAKE) -C mlx

ifeq ($(shell uname), Linux)
MLXLIB			=		./mlx-linux/libmlx.a
MINILBX			=		-L ./mlx-linux/ -lmlx -Ilmlx -lXext -lX11
MMLX			=		$(MAKE) -C mlx-linux
endif

#***** Couleurs *****#

GREEN			=		\033[1;32m
BG_GREEN		=		\033[42m
BLUE			=		\033[0;94m
RED				=		\033[1;31m
GREY			=		\033[0;37m
ENDCOLOR		=		\033[0m

#***** Textes *****#

START			=		echo "$(GREEN)Compilation of $(NAME) started\n$(ENDCOLOR)"
TEST			=		echo "$(GREY)Running some test\n$(ENDCOLOR)"
END_COMP		=		echo "$(GREEN)Compilation is done$(ENDCOLOR)"
CLEAN_TXT		=		echo "$(RED)Deleting objects$(ENDCOLOR)"
FCLEAN_TXT		=		echo "$(RED)Deleting program$(ENDCOLOR)"
CHARG_LINE		=		echo "$(BG_GREEN)    $(ENDCOLOR)\c"
BS_N			=		echo "\n"

#***** Flags *****#

CC				=		gcc
CFLAGS			=		-Wall -Wextra -Werror -g
L				=		$(CFLAGS) -fsanitize=address
RM				=		rm -f

#***** Compilation *****#

all : logo lib start $(NAME)

lib:
			@$(MLIBFT) all
			@$(MMLX) all
			@$(END_COMP_LIB)

start:
			@tput setaf 2; cat ascii_art/so_long; tput setaf default
			@$(START)

logo :
			@tput setaf 2; cat ascii_art/hibou; tput setaf default

%.o:		%.c ./libft/libft.h Makefile
			@$(CC) $(CFLAGS) -c $< -o $@
			@$(CHARG_LINE)

$(NAME) :	${OBJS}
			@$(BS_N)
			@${CC} ${MINILBX} ${CFLAGS} -o ${NAME} ${OBJS} ${LIBFT}
			@$(END_COMP)
			@tput setaf 2; cat ascii_art/small_hibou1; tput setaf default

l :			${OBJS}
			${MLIBFT} all
			${CC} ${MINILBX} ${L} -o ${NAME} ${OBJS} ${LIBFT}
			@$(END_COMP)

test: 		all
			@${CC} ${MINILBX} ${CFLAGS} ${OBJS} libft/libft.a
			@$(TEST)
			@./a.out
			@rm -f ./a.out			

#***** Clean *****#

clean:
			@$(CLEAN_TXT)
			@${RM} ${OBJS}
			@cd libft && make clean
			@cd mlx && make clean
			@tput setaf 1; cat ascii_art/trash; tput setaf default

fclean:		clean
			@$(FCLEAN_TXT)	
			@${RM} ${NAME}
			@cd libft && make fclean
			@cd mlx && make clean
			@echo "$(GREEN)Cleaning succes$(ENDCOLOR)"

re:			fclean all

.PHONY:		all clean fclean 
