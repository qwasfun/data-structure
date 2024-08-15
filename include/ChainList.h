typedef struct {
    char key[15]; // 学号
    char name[20]; // 姓名
    int age; // 年龄
} DATA;

typedef struct Node {
    DATA data;
    struct Node *next;
} ChainListType;

bool ChainListAddEnd(ChainListType *head, DATA data); // 添加节点到链表末尾
void ChainListAddFirst(ChainListType *head, DATA data); // 添加节点到链表首部
ChainListType *ChainListFind(ChainListType *head, char *key); // 按关键字查找内容
ChainListType *ChainListInsert(ChainListType *head, int n, DATA data); // 插入节点到链表的指定位置
bool ChainListDelete(ChainListType *head, char *key); // 删除指定关键字的节点
int ChainListLength(ChainListType *head); //返回链表节点数量
