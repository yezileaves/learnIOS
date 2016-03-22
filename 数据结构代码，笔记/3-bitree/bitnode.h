#ifndef __BITNODE_H__
#define __BITNODE_H__

struct bitnode {
	int data;
	struct bitnode *lchild;
	struct bitnode *rchild;
};
typedef struct bitnode btnode_t;

#endif	/* __BITNODE_H__*/
