#include  <stdio.h>
#include <stdlib.h>
#include <time.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;     /*函数类型, 其值是函数结果状态码, 如 OK 等*/
typedef int ElemType;   /*ElemType 应根据实际情况来定, 这里假设为 int*/

/*线性表的静态链表存储结构*/
#define MAXSIZE 1000    /*假设链表最大长度是 1000*/
typedef struct
{
    ElemType    data;
    int cur;    /*游标(Cursor), 为 0 时表示无指向*/
}Conponent, StaticLinkList[MAXSIZE];

/*将一维数组 space 中各分量链成一备用链表*/
/*space[0].cur 为头指针, "0" 表示空指针*/
Status InitList(StaticLinkList space)
{
    int i;
    for ( i = 0; i < MAXSIZE - 1; i++)
    {
        space[i].cur = i + 1;   //给每个链表上游标
    }
    space[MAXSIZE - 1].cur  = 0;    /*目前静态链表为空, 最后一个元素的 cur 为 0*/
    return  OK;
}
