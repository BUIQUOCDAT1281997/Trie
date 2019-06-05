#ifndef MYLIB_TRIE_H_
#define MYLIB_TRIE_H_

#include <stddef.h>
#include <stdbool.h>

struct TrieNode;

// Функции для работы с типом TrieNode
extern struct TrieNode *getNode(void);
extern void deleteChildrenNode(struct TrieNode *node);
extern void insert(struct TrieNode *root, const char *key,char *value);
extern char *search(struct TrieNode *root, const char *key);
extern bool isEmpty(struct TrieNode *root);
extern struct TrieNode *removeKey(struct TrieNode *root, const char *key, int depth);
extern void display(struct TrieNode* root, char str[], int level);

#endif
