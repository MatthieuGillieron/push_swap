NAME = push_swap

LIBDIR = libft

CC = gcc

CFLAGS = -Wall -Werror -Wextra -I./include -I$(LIBDIR) -I./header

RM = rm -f

SRCDIR = src
OBJDIR = obj

SRC = main.c \
      operations/operations.c \
      operations/op2.c \
      operations/helper_op.c \
	  operations/init_stack.c \
      parsing/parse_args.c \
      sorting/sort.c \
      utils/1.c \
      utils/2.c \
      utils/free_struct.c

# Chemin vers la bibliothèque libft
LIBFT = libft.a

# Génération des noms de fichiers objets
OBJ = $(addprefix $(OBJDIR)/, $(notdir $(SRC:.c=.o)))

SUCCESS = "\033[1;35m✅ Compilation réussie de PUSH_SWAP!\033[0m"

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

# Nettoyage des fichiers objets
clean:
	@$(RM) $(OBJ)
	@rmdir $(OBJDIR) 2>/dev/null || true
	@make -C $(LIBDIR) clean

# Nettoyage complet (objets et exécutable)
fclean: clean
	@$(RM) $(NAME) $(LIBFT)
	@$(RM) libft.a
	@make -C $(LIBDIR) fclean
	@rmdir $(OBJDIR) 2>/dev/null || true

# Recompilation complète
re: fclean all

.PHONY: all clean fclean re
