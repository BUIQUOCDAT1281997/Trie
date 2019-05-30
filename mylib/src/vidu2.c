
#include <stdio.h>
#include <string.h> 

#include "mylib_trie.h"

void write_content(struct TrieNode *root, char str[], int level)
{
	if (root->isEndOfWord)
	{
		

	}

	int i;
	for (i = 0; i < 95; i++)
	{

		if (root->children[i])
		{
			str[level] = (char)(i + (int)' ');
			write_content(root->children[i], str, level + 1);
		}
	}
}