#include "funA.h"
#include <stdio.h>
#include <string.h> 

#include "mylib_trie.h"

void write_content(struct TrieNode *root, char str[], int level, FILE *fp)
{ 
	if (root->isEndOfWord)
	{
		fputs(str, fp);
		fputs("\n", fp);

	}

	int i;
	for (i = 0; i < 95; i++)
	{

		if (root->children[i])
		{
			str[level] = (char)(i + (int)' ');
			write_content(root->children[i], str, level + 1, fp);
		}
	}
}

void change(char str[])
{

	for (int i = 0; i < strlen(str); i++)
	{
		if ((int)str[i] >= 65 && (int)str[i] <= 90)
		{
			str[i] = (char)((int)str[i] + 32);
		}
	}
}

void funA(char file_name_in[], struct TrieNode *root, char ten_file_out[])
{
	FILE *fp;
	fp = fopen(file_name_in, "r");
	char word[20];
	while (!feof(fp))
	{
		fscanf(fp, "%s", word);
		change(word);
		insert(root, word);
	}
	fclose(fp);
	FILE *fout;
	fout = fopen(ten_file_out, "w");
	char str[20];
	int level = 0;
	write_content(root, str, level, fout);
	fclose(fout);


}