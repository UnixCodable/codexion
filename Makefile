NAME=codexion
CC=cc
CFLAGS=-Wall -Wextra -Werror -pthread
WORKDIR=quantum/
OBJDIR=$(WORKDIR)objects/
CFILES=
OFILES=$(FILES:%.c=$(OBJDIR)%.o)

all: $(NAME)

$(NAME): $(OFILES)
	$(CC) $(CFLAGS) $(CFILES) -o $(NAME)

$(OBJDIR)%.o: %.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $(CFILES) -o $(OFILES)

$(OBJDIR):
	mkdir $(OBJDIR)

clean:

fclean:

re:

.PHONY:
