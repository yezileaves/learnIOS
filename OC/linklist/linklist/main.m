//
//  main.m
//  linklist
//
//  Created by 谢荣盛 on 16/3/23.
//  Copyright © 2016年 yezi. All rights reserved.
//

#import <Foundation/Foundation.h>

//定义节点结构体，每个节点包涵一个值，和一个指向下一节的指针；
typedef struct Node_ {
    int value;
    struct Node_ *next;
} Node;


//节点创建函数，使用malloc申请空间，
Node *createNode(int value,Node *next) {
    Node* node = malloc(sizeof(Node));
    node->value = value;
    node->next = next;
    return node;
}

//链表遍历，我们的链表其实是少遍历一个的，有一个作为链表的头，方便反转。所以是从第二个开始
//当node为空时说明遍历到最后一个了
void printList(Node *fistNode) {
    for (Node *node = fistNode->next; node != NULL; node = node->next) {
        printf("Current node value %d\n",node->value);
    }
}

//销毁链表，必须要先备份下当前的节点，再把节点往后移，再销毁备份的。不能直接销毁当前的
//因为需要用到，往后移；
void destroyList(Node *first) {
    Node *node = first;
    Node *tmp;
    
    while (node != NULL) {
        tmp = node;
        node = node->next;
        free(tmp);
    }
}


//反转，需要额外两个节点来辅助反转，一个用来记下当前节点，一个用来记下下一个节点。
//呃，说不清，需要画图才能弄清。
void reverseList(Node *first) {
    Node *node = first->next;
    Node *tmp;
    
    first->next = NULL;
    while (node != NULL) {
        tmp = node;
        node = node->next;
        
        tmp->next = first->next;
        first->next = tmp;
    }
    
    
}

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        //创建链节点头，这个头一直不变，用来反转比较方便
        Node *current = createNode(0,NULL);
        Node *first = current;
        
        for (int i = 0;i < 10;i++) {
            current->next = createNode(i, NULL);
            current = current->next;
        }
        
        printList(first);
        
        printf("reverse:\n");
        
        reverseList(first);
        
        printList(first);
        
        destroyList(first);
    }
    return 0;
}
