NAME = push_swap

LIBDIR = libraties
CC = gcc
CFLAGS = -Wall -Werror -Wextra -I./header -I$(LIBDIR)/libft -I$(LIBDIR)
RM = rm -f

SRCDIR = src
OBJDIR = obj

FILES = main.c \
		main.c \

LIBFT = $(LIBDIR)/libft/libft.a

SRC = $(addprefix $(SRCDIR)/, $(FILES))
OBJ = $(addprefix $(OBJDIR)/, $(FILES:.c=o))

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(FT_PRINTF)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

clean:
	@$(RM) $(OBJ)
	@make -C $(LIBDIR)/libft clean

fclean: clean
	@$(RM) $(NAME)
	@make -C $(LIBDIR)/libft fclean

re: fclean all

 .PHONY: all clean fclean