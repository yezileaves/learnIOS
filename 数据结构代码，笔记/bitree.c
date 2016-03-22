#include <stdio.h>
#include <stdlib.h>

struct bitnode {
	int data;
	struct bitnode *lchild;
	struct bitnode *rchild;
};
typedef struct bitnode btnode_t;

btnode_t *bitree_init(int start, int end);
btnode_t *bitree_create_node(int value);
int bitree_preoder(btnode_t *root);
int bitree_inoder(btnode_t *root);
int bitree_postorder(btnode_t *root);
int bitree_destroy(btnode_t *root);

int main()
{
	btnode_t *root;

	root = bitree_init(1, 10);
	puts("PreOrder:");
	bitree_preoder(root);
	putchar('\n');

	puts("InOrder:");
	bitree_inoder(root);
	putchar('\n');

	puts("PostOrder:");
	bitree_postorder(root);
	putchar('\n');
	
	bitree_destroy(root);

	return 0;
}

btnode_t *bitree_create_node(int value)
{
	btnode_t *node;

	node = malloc(sizeof(btnode_t));
	node->data = value;
	node->lchild = NULL;
	node->rchild = NULL;

	return node;
}

btnode_t *bitree_init(int start, int end)
{
	btnode_t *root;

	root = bitree_create_node(start);
	if (start * 2 <= end)
		root->lchild = bitree_init(start * 2, end);
	if (start * 2 + 1 <= end)
		root->rchild = bitree_init(start * 2 + 1, end);

	return root;
}

int bitree_preoder(btnode_t *root)
{
	printf("%5d", root->data);
	if (root->lchild != NULL)
		bitree_preoder(root->lchild);
	if (root->rchild != NULL)
		bitree_preoder(root->rchild);

	return 0;
}

int bitree_inoder(btnode_t *root)
{
	if (root->lchild != NULL)
		bitree_inoder(root->lchild);

	printf("%5d", root->data);

	if (root->rchild != NULL)
		bitree_inoder(root->rchild);

	return 0;
}

int bitree_postorder(btnode_t *root)
{
	if (root->lchild != NULL)
		bitree_postorder(root->lchild);
	if (root->rchild != NULL)
		bitree_postorder(root->rchild);

	printf("%5d", root->data);

	return 0;
}

int bitree_destroy(btnode_t *root)
{
	if (root->lchild != NULL)	
		bitree_destroy(root->lchild);
	if (root->rchild != NULL)
		bitree_destroy(root->rchild);
	free(root);

	return 0;
}
