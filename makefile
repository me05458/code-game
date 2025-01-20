LINK_TARGET = game
TUTORIAL_TARGET = tutorial

OBJS = \
       game.o \
       cards.o \
       bar.o \
       pieces.o \

TUTORIAL_OBJS = \
	tutorial.o

REBUILDABLES = $(OBJS) $(LINK_TARGET) $(TUTORIAL_OBJS) $(TUTORIAL_TARGET)

all: $(LINK_TARGET)
	@echo done
	@echo type './tutorial' for a tutorial or './game' to play

$(LINK_TARGET): $(OBJS) tutorial.o
	gcc -o $@ $(OBJS) -lsodium
	gcc -o $(TUTORIAL_TARGET) tutorial.o cards.o


%.o : %.c
	gcc -o $@ -c $<


game.o : game.h cards.h bar.h
cards.o : cards.h
bar.o : bar.h
pieces.o : pieces.h
tutorial.o : tutorial.h cards.h

clean:
	rm -f $(REBUILDABLES)
