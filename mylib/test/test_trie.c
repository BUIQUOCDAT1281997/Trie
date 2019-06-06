#include <stdio.h>
#include "..//include/mylib_trie.h"

#define ALPHABET_SIZE (95)   
#define CHAR_TO_INDEX(c) ((int)c - (int)' ') 


void test_isEmpty(void)
{
	struct TrieNode *root = getNode();

	bool couter1 = isEmpty(root) == 1;

	insert(root, "aa", "1");
	insert(root, "bb", "2");
	insert(root, "cc", "3");

	bool couter2 = isEmpty(root) == 0;

	if (couter1 && couter2)
	{
		printf("test_isEmpty :		 Success! assertions passed\n");
	}
	else
	{
		printf("test_isEmpty : Test assertion failed!\n");
	}
	
}



void test_insert(void)
{
	struct TrieNode *root = getNode();

	insert(root, "ab", "1");

	int count = 0;

	if (root->children[CHAR_TO_INDEX('a')]) {
		count++;
		if (root->children[CHAR_TO_INDEX('a')]->children[CHAR_TO_INDEX('b')])
		{
			count++;
			if (root->children[CHAR_TO_INDEX('a')]->children[CHAR_TO_INDEX('b')]->value == "1")
			{
				count++;
			}

		}
	}


	if (count == 3)
	{
		printf("test_insert:	         Success! assertions passed\n");
	}
	else
	{
		printf("test_insert: Test assertion failed!\n");
	}
}


void test_deleteChildrenNode(void)
{
	struct TrieNode *root = getNode();

	insert(root, "aa", "1");
	insert(root, "bb", "2");
	insert(root, "cc", "3");

	deleteChildrenNode(root);

	if (isEmpty(root)) {
		printf("test_deleteChildrenNode: Success! assertions passed\n");
	}
	else
	{
		printf("test_deleteChildrenNode: Test assertion failed!\n");
	}
}


void test_search(void)
{
	struct TrieNode *root = getNode();

	insert(root, "aa", "1");
	insert(root, "bb", "2");
	insert(root, "cc", "3");

	int count = 0;

	if (search(root, "aa") == "1")
	{
		count++;
	}
	if (!search(root, "ddddd"))
	{
		count++;
	}

	if (count == 2)
	{
		printf("test_search:	         Success! assertions passed\n");
	}
	else
	{
		printf("test_search: Test assertion failed!\n");
	}
}

void test_removeKey(void)
{
	struct TrieNode *root1 = getNode();

	insert(root1, "aa", "1");
	insert(root1, "bb", "2");
	insert(root1, "cc", "3");

	int a = 0;

	int count = 0;

	//попробую удалить один элемент
	removeKey(root1, "bb", a);
	// проверить
	if (!search(root1, "bb"))
	{
		count++;
	}
	if (search(root1, "aa"))
	{
		count++;
	}
	if (search(root1, "cc"))
	{
		count++;
	}

	// попробую удалить все эелементы
	a = 0;
	removeKey(root1, "aa", a);
	a = 0;
	removeKey(root1, "cc", a);
	if (isEmpty(root1))
	{
		count++;
	}

	if (count == 4)
	{
		printf("test_removeKey:		 Success! assertions passed\n");
	}
	else
	{
		printf("test_removeKey: Test assertion failed!\n");
	}

}

int main(void) {

	
	test_isEmpty();
	test_deleteChildrenNode();
	test_insert();
	test_search();
	test_removeKey();

	return 0;
}