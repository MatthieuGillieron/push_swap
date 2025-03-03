NAME = push_swap

LIBDIR = libft

CC = gcc

CFLAGS = -Wall -Werror -Wextra -I./include -I$(LIBDIR) -I./header

RM = rm -f

SRCDIR = src
OBJDIR = obj

SRC = main.c \
      operations/utils_op.c \
      operations/stack_op.c \
      operations/stack_moves.c \
	  operations/stack_init.c \
      parsing/args_parser.c \
      sorting/sort.c \
      utils/utils_rotate.c \
      utils/utils_strings.c \
      utils/free_struct.c

# Chemin vers la bibliothèque libft
LIBFT = libft.a

# Génération des noms de fichiers objets
OBJ = $(addprefix $(OBJDIR)/, $(notdir $(SRC:.c=.o)))

SUCCESS = "\033[1;92m✅ Compilation réussie ! ✅\033[0m"

all: $(NAME)

# Compilation de l'exécutable final
$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)
	@echo $(SUCCESS)

# Compilation des fichiers objets
$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/%.o: $(SRCDIR)/*/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Création du dossier obj
$(OBJDIR):
	@mkdir -p $@

# Compilation de la libft
$(LIBFT):
	@make -C $(LIBDIR)
	@cp $(LIBDIR)/$(LIBFT) .


clean:
	@$(RM) $(OBJ)
	@rmdir $(OBJDIR) 2>/dev/null || true
	@make -C $(LIBDIR) clean

fclean: clean
	@$(RM) $(NAME) $(LIBFT)
	@$(RM) libft.a
	@make -C $(LIBDIR) fclean
	@rmdir $(OBJDIR) 2>/dev/null || true

re: fclean all

.PHONY: all clean fclean re
