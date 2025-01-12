LINK_TARGET = game

OBJS = \
       helloworld.o \
       cards.o

REBUILDABLES = $(OBJS) $(LINK_TARGET)

all: $(LINK_TARGET)
	@echo done

$(LINK_TARGET): $(OBJS)
	gcc -o $@ $^ -lsodium

%.o : %.c
	gcc -o $@ -c $<

libs:
	sudo dnf install libsodium-devel

helloworld.o : helloworld.h cards.h
cards.o : cards.h

clean:
	rm -f $(REBUILDABLES)
