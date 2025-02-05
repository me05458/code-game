LINK_TARGET = game
TUTORIAL_TARGET = tutorial

OBJS = \
       game.o \
       pieces.o \

COLOR = \
	bar.o \
	cards.o

COLORLESS = \
	colorless.o

TUTORIAL_OBJS = \
	tutorial.o

REBUILDABLES = $(OBJS) $(LINK_TARGET) $(TUTORIAL_OBJS) $(TUTORIAL_TARGET) $(COLOR) $(COLORLESS)

all: $(LINK_TARGET)
	@echo done
	@echo type './tutorial' for a tutorial or './game' to play

$(LINK_TARGET): $(OBJS) tutorial.o $(COLOR)
	gcc -o $@ $(OBJS) $(COLOR) -lsodium
	gcc -o $(TUTORIAL_TARGET) pieces.o $(COLOR) tutorial.o


%.o : %.c
	gcc -o $@ -c $<


game.o : cards.h bar.h
cards.o : cards.h
bar.o : bar.h
pieces.o : pieces.h
tutorial.o : cards.h
colorless.o : colorless.h

clean:
	rm -f $(REBUILDABLES)

colorless: $(OBJS) $(COLORLESS) tutorial.o
	gcc -o game $(OBJS) $(COLORLESS) -lsodium
	gcc -o $(TUTORIAL_TARGET) pieces.o tutorial.o $(COLORLESS)
	@echo done
	@echo type './tutorial' for a tutorial or './game' to play
