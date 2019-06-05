
#include "mylib_trie.h"
#include "modA/funA.h"

void load_data(struct TrieNode *root) {
	insert(root, "again", "�����");
	insert(root, "almost", "���� ��");
	insert(root, "already", "���");
	insert(root, "alright", "������");
	insert(root, "also", "�����");
	insert(root, "always", "������");
	insert(root, "and", "�");
	insert(root, "angry", "����");
	insert(root, "animal", "��������");
	insert(root, "another", "������");
	insert(root, "anything", "���-����");
	insert(root, "bad", "������");
}

int main()
{

	struct TrieNode *root = getNode();
	load_data(root);
	funA("data_in.txt", root, "data_out.txt");

	
}