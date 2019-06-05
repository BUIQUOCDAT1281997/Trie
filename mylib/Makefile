CFLAGS= -std=c11 -pedantic -Wall
CFLAGS+= -O1
OBJS= trie.o 
MYLIBNAME= libmylib.a
INCLUDES+= -I ./include

vpath %.h include
vpath %.c src

$(MYLIBNAME): $(OBJS)
	$(AR) -rsc $@ $^

$(OBJS) : ./src/trie.c
	gcc -MD $(CFLAGS) $(INCLUDES) -c -o $(OBJS) ./src/trie.c

-include $(OBJS:.o=.d)

clean:
	$(RM) -f $(OBJS)
	$(RM) -f $(OBJS:.o=.d)
	$(RM) -f $(MYLIBNAME)