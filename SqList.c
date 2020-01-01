#include  <stdio.h>
#include <stdlib.h>
#include <time.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;     /*函数类型, 其值是函数结果状态码, 如 OK 等*/
typedef int ElemType;   /*ElemType 应根据实际情况来定, 这里假设为 int*/

/*线性表的顺序存储结构*/
#define MAXSIZE 20
typedef struct 
{
        ElemType data[MAXSIZE]; /*数组存储数据元素， 最大值为 MAXSIZE*/
        int length;     /*线性表当前长度*/
}SqList;

/*顺序存储结构获得元素操作*/
/*初始条件 : 顺序线性表 L 已经存在, 1 小于等于 i 小于等于 ListLength(L)*/
/*操作结果 : 用 e 返回 L 中第 i 个数据元素的值*/
Status GetElem(SqList L, int i, ElemType *e)
{
        if (L.length == 0 || i < 1 || i > L.length)
        {
                return ERROR;
        }
        *e = L.data[i - 1];
        return OK;
}

/*顺序存储结构插入操作*/
/*初始条件 : 顺序线性表 L 已经存在, 1 小于等于 i 小于等于 ListLength(L)*/
/*操作结果 : 在 L 中第 i 个位置之前插入新的数据元素 e， L 的长度加 1*/
Status ListInsert(SqList *L, int i, ElemType e)
{
        int k;
        if (L -> length == MAXSIZE)     /*顺序线性表已经满了*/
        {
                return ERROR;
        }
        if (i < 1 || i > L -> length + 1)       /*当 i 不在范围内时*/
        {
                return ERROR;
        }
        if (i <= L->length )    /*若插入数据位置不在表尾*/
        {
                for ( k = L->length; k >= i - 1; k--)   /*将要插入位置后数据元素向后移动一位*/
                {
                        L->data[k + 1] = L->data[k];
                }
        }
        L->data[i - 1] = e;     /*将新元素插入*/
        L->length ++;
        return OK;
}

/*顺序存储结构删除操作*/
/*初始条件 : 顺序线性表 L 已经存在, 1 小于等于 i 小于等于 ListLength(L)*/
/*操作结果 : 删除 L 的第 i 个数据元素, 并用 e 返回其值, L 的长度减去 1*/
Status ListDelete(SqList *L, int i, ElemType *e)
{
    int k;
    if (L->length == 0) /*线性表为空*/
    {
        return ERROR;
    }
    if (i < 1 || i > L->length) /*删除位置不正确*/
    {
        return  ERROR;
    
    }
    *e = L->data[i - 1];    /*第 i 个数据元素的下标是 i - 1*/

    if (i < L->length)  /*如果删除位置不是最后的位置*/
    {
        for (k = i; k < L->length; k++)
        {
            L->data[k - 1] = L->data[k];    /*将删除位置后继元素前移*/
        }
        
        L->length --;
        
        return  OK;
    }
    
}
