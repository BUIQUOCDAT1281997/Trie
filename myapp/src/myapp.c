
#include "mylib_trie.h"
#include "modA/funA.h"

void load_data(struct TrieNode *root) {
	insert(root, "again", "снова");
	insert(root, "almost", "едва не");
	insert(root, "already", "уже");
	insert(root, "alright", "хорошо");
	insert(root, "also", "также");
	insert(root, "always", "всегда");
	insert(root, "and", "и");
	insert(root, "angry", "злой");
	insert(root, "animal", "животное");
	insert(root, "another", "другой");
	insert(root, "anything", "что-либо");
	insert(root, "bad", "плохой");
}

int main()
{

	struct TrieNode *root = getNode();
	load_data(root);
	funA("data_in.txt", root, "data_out.txt");

	
}