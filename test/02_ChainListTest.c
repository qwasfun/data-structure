#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "../include/ChainList.h"

/*
 * 通过 &传入地址是C++语法，C语言必须使用二级指针传入，
 * 否则因参数拷贝，无法通过指针取得返回值
 */
// 带头节点初始化
bool InitChainList(ChainListType **head) {
    *head = (ChainListType *) malloc(sizeof(ChainListType));
    if (*head == NULL) {
        return false;
    }
    (*head)->next = NULL;
    return true;
};

// bool InitChainListWithoutHead(ChainListType *head) {
//     head = NULL;
// }


// // 带头节点链表销毁
// void destoryChainList(ChainListType *head) {
//     free(head);
// };


void ChainListAll(ChainListType *ChainList) {
    ChainListType *p = ChainList;

    printf("输出链表中所有元素：\n");
    while (p != NULL) {
        printf("key=%s, name=%s, age=%d\n", p->data.key, p->data.name, p->data.age);
        p = p->next;
    }
}

int main() {
    // int i;
    ChainListType *ChainList = NULL;
    // ChainListType head = NULL;
    InitChainList(&ChainList);

    DATA data1 = {"11", "2", 23};
    DATA data2 = {"22", "33", 24};

    DATA data3 = {"33", "444", 25};
    DATA data4 = {"44", "5555", 26};
    DATA data5 = {"55", "5555", 27};

    ChainListAddEnd(ChainList, data1);
    ChainListAddEnd(ChainList, data2);
    ChainListAddEnd(ChainList, data3);
    // ChainListAddEnd(&ChainList, data4);
    ChainListAddFirst(ChainList, data4);

    ChainListType *c1 = ChainListFind(ChainList, "4444");
    ChainListType *c2 = ChainListFind(ChainList, "44440");

    if (c1 != NULL) {
        DATA d1 = c1->data;
        printf("找到d1：name=%s, age=%d\n", d1.name, d1.age);
    }
    if (c2 != NULL) {
    } else {
        printf("未找到 key为 44440的d2值\n");
    }

    // for (int i = 0; i < 2; ++i) {
    //     ChainListAddEnd(&ChainList, array[i]);
    // }
    // // ChainListAddEnd(&ChainList, data);
    // // ChainListAddEnd(&ChainList, DATA );
    // // ChainListAddEnd(&ChainList, DATA {333, 444, 555});
    // // ChainListAddEnd(&ChainList, DATA {4444, 5555, 6666});

    ChainListAll(ChainList);


    ChainListInsert(ChainList, 2, data5);

    ChainListAll(ChainList);

    ChainListDelete(ChainList, "11");
    ChainListAll(ChainList);

    int len = ChainListLength(ChainList);

    printf("链表长度为 %d\n", len);
    // destoryChainList(&ChainList);
    return 0;
}
