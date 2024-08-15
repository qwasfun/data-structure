#include <stdio.h>
#include "../include/SeqList.h"

int main() {
    SeqListType SL; // 定义顺序表变量
    DATA data; //节点保存数据类型变量 指针变量
    char key[15];

    SeqListInit(&SL);

    DATA d1 = {"11", "123", 21};
    DATA d2 = {"22", "234", 22};
    DATA d3 = {"33", "345", 23};
    DATA d4 = {"44", "456", 24};
    SeqListAdd(&SL, d1);
    SeqListAdd(&SL, d2);
    SeqListAdd(&SL, d3);
    SeqListAdd(&SL, d4);

    /*
     do {
        printf("输入添加的节点:");

        scanf("%s %s %d", &data.key, &data.name, &data.age);

        if (data.age) {
            // age为0, 退出循环
            if (SeqListAdd(&SL, data) != 0) {
                printf("添加失败\n");
                break;
            };
            printf("添加成功 %s %s %d\n", data.key, data.name, data.age);
        } else {
            break; // 输入数据有误
        }
    } while (1);
    */
    SeqListAll(&SL); // 显示所有节点数据

    printf("\n输入需要取出的节点序号\n");
    /*
    int i;
    scanf("%d", &i);

    */

    DATA *data_p = NULL;

    data_p = SeqListFindByIndex(&SL, 1);

    if (data_p) {
        printf("找到的值 %s, %s ,%d\n", data_p->name, data_p->key, data_p->age);
    }

    DATA data2 = {};
    DATA *data2_p = &data2;
    // 通过参数获取返回值
    SeqListFindByIndexP(&SL, 2, &data2_p);

    if (data2_p) {
        printf("找到的值 %s, %s ,%d ", data2_p->key, data2_p->name, data2_p->age);
    }

    SeqListInsert(&SL, 1, d1);

    SeqListDelete(&SL, 1);
}
