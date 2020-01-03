#include  <stdio.h>
#include <stdlib.h>
#include <time.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;     /*函数类型, 其值是函数结果状态码, 如 OK 等*/
typedef int SElemType;   /*SElemType 应根据实际情况来定, 这里假设为 int*/

#define MAXSIZE 1000    /*这里假定 MAXSIZE 为 1000*/

typedef struct StackNode
{
    SElemType data;
    struct StackNode    *next;
}StackNode, *LinkStackPtr;

typedef struct LinkStack
{
    LinkStackPtr    top;
    int count;
}LinkStack;

/*插入元素 e 为新的栈顶元素*/
Status  Push(LinkStack *S, SElemType e)
{
    LinkStackPtr    s = (LinkStackPtr)malloc(sizeof(StackNode));
    s->data = e;
    s->next = S->top;   /*把当前的栈顶元素赋值给新结点的直接后继*/
    S->top = s; /*将新的结点 s 赋值给栈顶指针*/
    S->count++;
    return  OK;
}

/*若栈不空, 则删除 S 的栈顶元素, 用 e 返回其值, 并返回 OK; 否则返回 ERROR*/
Status Pop(LinkStack *S, SElemType *e)
{
    LinkStackPtr    p;
    if (StackEmpty(*S))
    {
        return  ERROR;
    }
    *e = S->top->data;
    p = S->top; /*将栈顶结点赋值给 p*/ 
    S->top = S->top->next;  /*使得栈顶指针下移一位, 指向后一结点*/
    free(p);
    S->count--;
    return  OK;
}

/*斐波那契递归函数*/
int Fbi(int i)
{
    if (i < 2)
    {
        return i == 0 ? 0 : 1;
    }
    return Fbi(i - 1) + Fbi(i - 2); /*这里 Fbi 就是函数自己, 它在调用自己*/
}
