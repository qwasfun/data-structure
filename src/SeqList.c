#include <stdio.h>
#include <string.h>
# include "../include/SeqList.h"

// 遍历顺序表中所有节点
void SeqListAll(SeqListType *SL) {
    for (int i = 0; i < SL->length; i++) {
        printf("顺序表中数据为 (%s,%s,%d)\n", SL->ListData[i].key, SL->ListData[i].name, SL->ListData[i].age);
    }
}

// 初始化顺序表
void SeqListInit(SeqListType *SL) {
    SL->length = 0;
}

int SeqListLength(SeqListType *SL) {
    return SL->length;
}

int SeqListAdd(SeqListType *SL, DATA data) {
    if (SL->length >= MAXSIZE) {
        printf("顺序表已满，不能再添加节点\n");
        return 1;
    }
    //
    // printf("顺序表 添加 %d\n",SL->length);
    SL->ListData[(SL->length)++] = data; // 保存数据到顺序表尾部
    return 0;
}

// 插入节点
int SeqListInsert(SeqListType *SL, int n, DATA data) {
    if (SL->length >= MAXSIZE) {
        printf("顺序表已满，不能插入节点");
        return 1;
    }

    if (n < 0 || n > SL->length - 1) {
        //插入序号有误
        printf("插入序号有误，不能插入元素");
        return 2;
    }
    for (int i = SL->length; i >= n; i--) {
        SL->ListData[i + 1] = SL->ListData[i];
    }
    SL->ListData[n] = data;
    SL->length++;
    return 0;
}

// 删除元素
int SeqListDelete(SeqListType *SL, int n) {
    if (n < 0 || n > SL->length + 1) {
        printf("删除节点序号错误，不能删除节点");
        return 1;
    }
    for (int i = n; i < SL->length; i++) {
        SL->ListData[i] = SL->ListData[i + 1];
    }
    SL->length--;
    return 0;
}


DATA *SeqListFindByIndex(SeqListType *SL, int index) {
    if (index < 0 || index > (SL->length)) {
        return NULL;
    }
    return &(SL->ListData[index]);
}

void SeqListFindByIndexP(SeqListType *SL, int index, DATA **p) {
    if (index < 0 || index > (SL->length)) {
        // return NULL;
        *p = NULL;
    }
    *p = &(SL->ListData[index]);
}

// 通过关键字查找节点
int SeqListFindByKey(SeqListType *SL, char *key) {
    for (int i = 0; i < SL->length; ++i) {
        if (strcmp(SL->ListData[i].key, key) == 0) {
            return i;
        }
    }
    return 0;
}
