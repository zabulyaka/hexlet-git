#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
	char * word;
	unsigned int n;
} Data;

typedef struct Node {
	Data data;
	struct Node * left;
	struct Node * right;
} Node;

void tree_print(Node * tree) {
	if (NULL == tree)
		return;
	tree_print(tree->left);
	printf("%s %u\n", tree->data.word, tree->data.n);
	tree_print(tree->right);
}

void tree_clear(Node * tree) {
	if (NULL == tree)
		return;
	tree_clear(tree->left);
	tree_clear(tree->right);
	free(tree);
}

Node * tree_add(Node * tree, char * word) {
	if (NULL == tree) {
		Node * node = malloc(sizeof(Node));
		node->data.word = word;
		node->data.n = 1;
		node->left = node->right = NULL;
		return node;
	}
	if (strcmp(tree->data.word, word) == 0)
		tree->data.n += 1;
	if (strcmp(tree->data.word, word) > 0)
		tree->left = tree_add(tree->left, word);
	if (strcmp(tree->data.word, word) < 0)
		tree->right = tree_add(tree->right, word);
		
	return tree;
}

int main(void) {
	Node * tree = NULL;
	char * line = malloc(sizeof(char) * MAX);
	size_t storage = MAX;
	const char * delim = ",;?!. \t";
	int read = getline(&line, &storage, stdin);
	
	while(read != -1)	{
		for (char * p = strtok(line, delim); p != NULL; p = strtok(NULL, delim))
			tree = tree_add(tree, p);
		read = getline(&line, &storage, stdin);
	}
	free(line);
	
	tree_print(tree);
	tree_clear(tree);
	
	return EXIT_SUCCESS;
}
