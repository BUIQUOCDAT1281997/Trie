#include "funA.h"
#include <stdio.h>
#include <string.h> 

#include "mylib_trie.h"


void funA(char file_name_in[], struct TrieNode *root, char ten_file_out[])
{
	FILE *fp;
	fp = fopen(file_name_in, "r");
	char word[20];
	FILE *fout;
	fout = fopen(ten_file_out, "w");

	while (!feof(fp))
	{

		fscanf(fp, "%s", word);
		fputs(word, fout);
		fputs(" - ", fout);
		fputs(search(root, word), fout);
		fputs("\n", fout);

	}

	fclose(fp);
	fclose(fout);

}