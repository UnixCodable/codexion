NAME=codexion
CC=cc
CFLAGS=-Wall -Wextra -Werror -pthread
WORKDIR=quantum/
OBJDIR=$(WORKDIR)objects/
CFILES=codexion.c\
	   args_validation.c\
	   struct_organizer.c\
	   duplication.c\
	   validation.c
OFILES=$(CFILES:%.c=$(OBJDIR)%.o)

all: $(NAME)

$(NAME): $(OBJDIR) $(OFILES)
	$(CC) $(CFLAGS) $(OFILES) -o $(NAME)

$(OBJDIR)%.o: $(WORKDIR)utils/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)%.o: $(WORKDIR)parsing/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)%.o: $(WORKDIR)%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir $(OBJDIR)

clean:
	rm -rf $(OBJDIR)

fclean:
	rm -rf $(OBJDIR)
	rm $(NAME)

re: fclean all

.PHONY: all clean fclean re
