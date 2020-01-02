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

typedef struct
{
    SElemType data[MAXSIZE];
    int top;    /*用于栈顶指针*/
}SqStack;

/*插入元素 e 为新的栈顶元素*/
Status Push(SqStack *S, SElemType e)
{
    if (S->top == MAXSIZE - 1)  /* 栈满了*/
    {
        return ERROR;
    }
    S->top++;   /*栈顶指针加 1*/
    S->data[S->top] = e;    /*插入新元素赋值给栈顶空间*/
    return OK;
}

/*若栈不空, 则删除 S 的栈顶元素, 用 e 返回其值, 并返回 OK; 否则返回 ERROR*/
Status Pop(SqStack *S, SElemType *e)
{
    if (S->top == -1)
    {
        return ERROR;
    }
    *e = S->data[S->top];   /*将要删除的栈顶元素赋值给 e*/
    S->top--;   /*栈顶指针减 1*/
    return OK;
}
