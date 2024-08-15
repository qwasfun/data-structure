#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../include/ChainList.h"

// 添加节点到链表末尾
bool ChainListAddEnd(ChainListType *head, DATA data) {
    ChainListType *p = head;
    while (p->next != NULL) {
        p = p->next;
    }

    p->next = (ChainListType *) malloc(sizeof(ChainListType));
    if (p->next == NULL) {
        return false; // 内存分配失败
    }
    p->next->data = data;
    p->next->next = NULL;

    return true;
}

// 添加节点到链表首部
// (实现是添加到第二个元素的位置)(是这个意思？)
void ChainListAddFirst(ChainListType *head, DATA data) {
    ChainListType *p = head;
    ChainListType *d = NULL;
    ChainListType *a = NULL;
    if (head->next != NULL) {
        d = head->next;
    }

    a = (ChainListType *) malloc(sizeof(ChainListType));
    a->data = data;
    p->next = a;
    a->next = d;
}

// 按关键字查找内容
ChainListType *ChainListFind(ChainListType *head, char *key) {
    ChainListType *p = head;
    while (p->next != NULL) {
        if (strcmp(p->data.key, key) == 0) {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

// 插入节点到链表的指定位置, n 为索引值 (不含头节点)
ChainListType *ChainListInsert(ChainListType *head, int n, DATA data) {
    ChainListType *p = head;
    ChainListType *t = NULL;
    int i = 0;
    while (p->next != NULL && i < n - 1) {
        p = p->next;
        i++;
    }
    // t = p->next;
    // p->next = (ChainListType *)malloc(sizeof(ChainListType));
    // p->data = data;
    // p->next->next = t;

    t = p->next;
    p->next = (ChainListType *) malloc(sizeof(ChainListType));
    p->next->data = data;
    p->next->next = t;


    return 0;
}

// // 删除指定关键字的节点 (错误示例)
// bool ChainListDelete(ChainListType *head, char *key) {
//     ChainListType *p = head;
//
//     while (p->next != NULL) {
//         if (strcmp(p->data.key, key) == 0) {
//             // p->next = p->next->next;
//             return true;
//         }
//         p = p->next;
//     }
//
//     return false;
// }

// 删除指定关键字的节点
bool ChainListDelete(ChainListType *head, char *key) {
    ChainListType *p = head;
    ChainListType *node = p; // node 保存删除节点前一个节点

    while (p) {
        if (strcmp(p->data.key, key) == 0) {
            node->next = p->next;
            free(p); // 释放内存
            return true;
        }
        node = p;
        p = p->next;
    }

    return false;
}

//返回链表节点数量
int ChainListLength(ChainListType *head) {
    ChainListType *p = head;
    int i = 0;
    while (p) {
        p = p->next;
        i++;
    }
    return i;
}
