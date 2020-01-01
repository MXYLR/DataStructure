#include  <stdio.h>
#include <stdlib.h>
#include <time.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;     /*函数类型, 其值是函数结果状态码, 如 OK 等*/
typedef int ElemType;   /*ElemType 应根据实际情况来定, 这里假设为 int*/

/*线性表的单链表存储结构*/
typedef struct Node
{
        ElemType data;
        struct  Node *next;
} Node;
typedef struct Node *LinkList;  /*定义 LinkList*/

/*单链表的读取*/
/*初始条件 : 顺序线性表 L 已经存在， 1 小于等于 i 小于等于 ListLength(L)*/
/*操作结果 : 用 e 返回 L 中第 i 个数据元素的值*/
Status GetElem(LinkList L, int i, ElemType *e)
{
        int     j;
        LinkList p;     /*声明一个指针 p*/
        p = L -> next;    /*让p指向链表L的第一个节点*/
        j = 1;  /*j 为计数器*/
        while ( p && j <  i)
        {
                p = p -> next;  /*让p指向下一个节点*/
                j++;
        }
        if(!p  || j > i)
                return ERROR;   /*第 i 个节点不存在*/
        *e = p -> data; /*取第 i 个节点的数据*/

        return OK;
}

/*单链表的插入*/
/*初始条件  : 顺序线性表 L 已经存在， 1 小于等于 i 小于等于 ListLength(L)*/
/*操作结果 : 在 L 中第 i 个结点位置之前插入新的数据元素 e, L 的长度增加 1*/
Status ListInsert (LinkList *L, int i, ElemType e)
{
        int     j;
        LinkList        p, s;
        p = *L;
        j = 1;
        while (p && j < i)      /*寻找第 i - 1 个结点*/
        {
                p = p -> next;
                j++;
        }
        if (!p || j > i)
        {
                return  ERROR;  /*第 i 个结点不存在*/
        }
        s = (LinkList)malloc(sizeof(Node));     /*生成新结点 (C 标准函数)*/
        s -> data = e;
        s -> next = p -> next;  /*将 p 的后继结点赋值给 s 的后继*/
        p -> next = s;  /*将 s 赋值给 p 的后继*/
        return  OK;
}

/*单链表的删除*/
/*初始条件 : 顺序线性表 L 已经存在， 1 小于等于 i 小于等于 ListLength(L)*/
/*操作结果 : 删除 L 的第 i 个节点, 并用 e 返回其值， L 的长度减去 1*/
Status  ListDelete(LinkList *L, int i, ElemType *e)
{
        int     j;
        LinkList        p, q;
        p = *L;
        j = 1;
        while (p -> next && j < i) /* 遍历寻找第 i - 1 个结点*/
        {
                p = p -> next;
                j++;
        }
        if (!(p -> next) || j > i)
        {
                return ERROR;   /*第 i 个结点不存在*/
        }
        q = p -> next;
        p -> next = q -> next;  /*将 q 的后继结点赋值给 p 的后继*/
        *e = q -> data; /*将 q 结点中的数据给 *e*/
        free(q);        /*让系统回收此结点， 释放内存*/
}

/*单链表的整表创建*/
/*随机产生 n 个元素的值, 建立带表头结点的单链线性表 L (头插法)*/
void CreateListHead (LinkList *L, int n)
{
        LinkList p;
        int i;
        srand(time(0)); /*初始化随机数种子*/
        *L = (LinkList)malloc(sizeof(Node));
        (*L) -> next = NULL;    /*先建立一个带头结点的单链表*/
        for ( i = 0; i < n; i++)
        {
                p = (LinkList)malloc(sizeof(Node));     /*生成新结点*/
                p -> data = rand() % 100 + 1;   /*随机生成 100 以内的数字*/
                p -> next = (*L) -> next;
                (*L) -> next = p;       /*插入到表头*/
        }
        
}

/*随机产生 n 个元素的值, 建立带表头结点的单链线性表 L (尾插法)*/
void CreateListTail(LinkList *L, int n)
{
        LinkList p, r;
        int i;
        srand(time(0)); /*初始化随机数种子*/
        *L = (LinkList)malloc(sizeof(Node));    /*为整个线性表*/
        r = *L; /*r 为指向尾部的结点*/
        for ( i = 0; i < n; i++)
        {
                p = (Node *)malloc(sizeof(Node));       /*生成新结点*/
                p -> data = rand() % 100 + 1;   /*随机生成 100 以内数字*/
                r -> next = p;  /*将表尾终端结点的指针指向新结点*/
                r = p;  /*将当前的新结点定义为表尾终端结点*/
        }
        r -> next = NULL;       /*表示当前链表结束*/
}

/*单链表的整表删除*/
/*初始条件 : 顺序线性表 L 已经存在, 操作结果 : 将 L 重置为空表*/
Status ClearLisk(LinkList *L)
{
        LinkList        p, q;
        p = (*L) ->next;        /*p 指向第一个结点*/
        while (p)       /*没到表尾, 到了表尾 p 就是 NULL, 条件为假跳出循环*/
        {
                q = p -> next;
                free(p);
                p = q;
        }
        (*L) -> next = NULL;    /*头结点指针域为空*/
        return OK;
}
