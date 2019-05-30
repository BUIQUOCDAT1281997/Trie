#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <stdbool.h> 

#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0]) 

// Alphabet size (# of symbols) 
#define ALPHABET_SIZE (95) 

// Converts key current character into index 
// use only 'a' through 'z' and lower case 
#define CHAR_TO_INDEX(c) ((int)c - (int)' ') 

// trie node 
struct TrieNode
{
	struct TrieNode *children[ALPHABET_SIZE];

	// isEndOfWord is true if the node represents 
	// end of a word 
	bool isEndOfWord;
};

// Returns new trie node (initialized to NULLs) 
struct TrieNode *getNode(void)
{
	struct TrieNode *pNode = NULL;

	pNode = (struct TrieNode *)malloc(sizeof(struct TrieNode));

	if (pNode)
	{
		int i;

		pNode->isEndOfWord = false;

		for (i = 0; i < ALPHABET_SIZE; i++)
			pNode->children[i] = NULL;
	}

	return pNode;
}

// Delete node
void deleteChildrenNode(struct TrieNode *node)
{
	for (int i = 0; i < ALPHABET_SIZE; i++)
		node->children[i] = NULL;
}

// If not present, inserts key into trie 
// If the key is prefix of trie node, just marks leaf node 
void insert(struct TrieNode *root, const char *key)
{
	int level;
	int length = strlen(key);
	int index;

	struct TrieNode *pCrawl = root;

	for (level = 0; level < length; level++)
	{
		index = CHAR_TO_INDEX(key[level]);
		if (!pCrawl->children[index])
			pCrawl->children[index] = getNode();

		pCrawl = pCrawl->children[index];
	}

	// mark last node as leaf 
	pCrawl->isEndOfWord = true;
}

// Returns true if key presents in trie, else false 
bool search(struct TrieNode *root, const char *key)
{
	int level;
	int length = strlen(key);
	int index;
	struct TrieNode *pCrawl = root;

	for (level = 0; level < length; level++)
	{
		index = CHAR_TO_INDEX(key[level]);

		if (!pCrawl->children[index])
			return false;

		pCrawl = pCrawl->children[index];
	}

	return (pCrawl != NULL && pCrawl->isEndOfWord);
}

// Returns true if root has no children, else false 
bool isEmpty(struct TrieNode* root)
{
	for (int i = 0; i < ALPHABET_SIZE; i++)
		if (root->children[i])
			return false;
	return true;
}

// Recursive function to delete a key from given Trie 
struct TrieNode *removeKey(struct TrieNode* root, const char *key, int depth)
{
	// If tree is empty 
	if (!root)
		return NULL;

	// If last character of key is being processed 
	if (depth == strlen(key)) {

		// This node is no more end of word after 
		// removal of given key 
		if (root->isEndOfWord)
			root->isEndOfWord = false;

		// If given is not prefix of any other word 
		if (isEmpty(root)) {
			deleteChildrenNode(root);
			root = NULL;
		}

		return root;
	}

	// If not last character, recur for the child 
	// obtained using ASCII value 
	int index = CHAR_TO_INDEX(key[depth]);
	root->children[index] =
		removeKey(root->children[index], key, depth + 1);

	// If root does not have any child (its only child got  
	// deleted), and it is not end of another word. 
	if (isEmpty(root) && root->isEndOfWord == false) {
		deleteChildrenNode(root);
		root = NULL;
	}

	return root;
}

// function to display the content of Trie 
void display(struct TrieNode* root, char str[], int level)
{
	// If node is leaf node, it indiicates end 
	// of string, so a null charcter is added 
	// and string is displayed 
	if (root->isEndOfWord)
	{
		//str[level] = '\n';
		printf("\n");
		for (int k = 0; k < level; k++)
		{
			printf("%c", str[k]);
		}
	}

	int i;
	for (i = 0; i < ALPHABET_SIZE; i++)
	{
		// if NON NULL child is found 
		// add parent key to str and 
		// call the display function recursively 
		// for child node 
		if (root->children[i])
		{
			str[level] = (char)(i + (int)' ');
			display(root->children[i], str, level + 1);
		}
	}
}



void ghi_vao_file(struct TrieNode *root, char str[], int level, FILE *fp)
{
	// If node is leaf node, it indiicates end 
	// of string, so a null charcter is added 
	// and string is displayed 
	if (root->isEndOfWord)
	{
		//str[level] = '\0';
		fputs(str, fp);
		fputs("\n", fp);

	}

	int i;
	for (i = 0; i < ALPHABET_SIZE; i++)
	{
		// if NON NULL child is found 
		// add parent key to str and 
		// call the display function recursively 
		// for child node 
		if (root->children[i])
		{
			str[level] = (char)(i + (int)' ');
			ghi_vao_file(root->children[i], str, level + 1,fp);
		}
	}
}

void doi_thanh_in_hoa(char str[])
{

	for (int i = 0; i < strlen(str); i++)
	{
		if ((int)str[i] >= 65 && (int)str[i] <= 90)
		{
			str[i] = (char)((int)str[i] + 32);
		}
	}
}

void dictionary(char file_name_in[], struct TrieNode *root, char ten_file_out[])
{
	FILE *fp;
	fp = fopen(file_name_in, "r");
	char word[20];
	while (!feof(fp))
	{
		fscanf(fp, "%s", word);
		doi_thanh_in_hoa(word);
		insert(root, word);
	}
	fclose(fp);
	FILE *fout;
	fout = fopen(ten_file_out, "w");
	char str[20];
	int level = 0;
	ghi_vao_file(root, str, level, fout);
	fclose(fout);


}

// Driver 

int main()
{
	// Input keys (use only 'a' through 'z' and lower case)
	char keys[][8] = { "t_e", "a", "there", "answer", "any",
					"by", "BYE", "their" };

	char output[][32] = { "Not present in trie", "Present in trie" };


	struct TrieNode *root = getNode();
	dictionary("text.txt", root, "out.txt");

	// Construct trie
	/*
	int i;
	for (i = 0; i < ARRAY_SIZE(keys); i++)
		insert(root, keys[i]);
	*/

	// Search for different keys
	/*
	printf("%s --- %s\n", "the", output[search(root, "the")]);
	printf("%s --- %s\n", "these", output[search(root, "these")]);
	printf("%s --- %s\n", "their", output[search(root, "their")]);
	printf("%s --- %s\n", "thaw", output[search(root, "thaw")]);

	int a = 0;
	removeKey(root, "their", a);

	printf("%s --- %s\n", "the", output[search(root, "the")]);
	printf("%s --- %s\n", "these", output[search(root, "these")]);
	printf("%s --- %s\n", "their", output[search(root, "their")]);
	printf("%s --- %s\n", "thaw", output[search(root, "thaw")]);
	*/

	int level = 0;
	char str[20];

	display(root, str, level);

	return 0;

}

