# MAKEFILE

CC = gcc
OPT = -std=c99 -Wall -Werror -g
EXEC = exec

BINDIR = bin
OBJDIR = obj
SRCDIR = src

SOMMET = Sommet
GRAPHE = Graphe

all:$(EXEC)

$(GRAPHE).o: $(SRCDIR)/$(GRAPHE).c
	$(CC) -c $(SRCDIR)/$(GRAPHE).c $(SRCDIR)/$(SOMMET) -o $(GRAPHE).o $(OPT)
	mv $(GRAPHE).o $(OBJDIR)

$(EXEC): $(OBJDIR)/$(GRAPHE).o
	$(CC) $(OBJDIR)/$(GRAPHE).o -o $(BINDIR)/$(EXEC) $(OPT)

clean:
	rm -rf $(SRCDIR)/Jeu.h $(SRCDIR)/Jeu.class $(SRCDIR)/libfct_jeu.so
