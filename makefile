LINK_TARGET = game

OBJS = \
       game.o \
       cards.o

REBUILDABLES = $(OBJS) $(LINK_TARGET)

all: $(LINK_TARGET)
	@echo done

$(LINK_TARGET): $(OBJS)
	gcc -o $@ $^ -lsodium

%.o : %.c
	gcc -o $@ -c $<

game.o : game.h cards.h
cards.o : cards.h

clean:
	rm -f $(REBUILDABLES)
