INCLUDES+= -I ../include

main : test_trie.c ../src/trie.c
	gcc $(INCLUDES) -o  $@ test_trie.c ../src/trie.c

clean:
	$(RM) -f main main.exe