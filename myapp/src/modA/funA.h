#ifndef FUNA_H_
#define FUNA_H_

#include <stdio.h>
#include "mylib_trie.h"


extern void write_content(struct TrieNode *root, char str[], int level, FILE *fp);
extern void change(char str[]);

extern void funA(char file_name_in[], struct TrieNode *root, char ten_file_out[]);

#endif  
