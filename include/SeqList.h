#ifndef SEQLIST_H
#define SEQLIST_H
#define MAXSIZE 100 // 定义顺序表的最大长度

typedef struct {
    char key[15]; // 学号
    char name[20]; // 姓名
    int age; // 年龄
} DATA;

typedef struct {
    DATA ListData[MAXSIZE + 1];
    int length;
} SeqListType, *SeqListTypeNode;

void SeqListAll(SeqListType *SL);

void SeqListInit(SeqListType *SL); // 初始化顺序表
int SeqListLength(SeqListType *SL); // 返回顺序表的元素数量
int SeqListAdd(SeqListType *SL, DATA data); // 向顺序表末尾添加元素

int SeqListInsert(SeqListType *SL, int n, DATA data); // 插入节点
int SeqListDelete(SeqListType *SL, int n); // 删除元素

DATA *SeqListFindByIndex(SeqListType *SL, int); // 根据索引返回元素
void SeqListFindByIndexP(SeqListType *SL, int, DATA **); // 根据索引返回元素（通过参数返回）二级指针

int SeqListFindByKey(SeqListType *SL, char *key);

#endif //SEQLIST_H
