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



/*两栈共享空间结构*/
typedef struct
{
    SElemType data[MAXSIZE];
    int top1;   /*栈 1 栈顶指针*/
    int top2;   /*栈 2 栈顶指针*/
}SqDoubleStack;


/*插入元素 e 为新的栈顶元素*/
Status Push(SqDoubleStack *S, SElemType e, int stackNumber)
{
    if (S->top1+1 == S->top2)   /*栈满了, 不能再 push 新元素了*/
    {
        return ERROR;
    }
    if (stackNumber == 1)   /*栈 1 有元素进栈*/
    {
        S->data[++S->top1] = e; /*若栈 1 则先 top1 + 1 后给数组元素赋值*/
    }
    else if (stackNumber == 2)  /*栈 2 有元素进栈*/
    {
        S->data[--S->top2] = e; /*若栈 2 则先 top2 - 1 后给数组元素赋值*/
    }
    return  OK;
}

/*若栈不空, 则删除 S 的栈顶元素 用 e 返回其值, 并返回 OK; 否则返回 ERROR*/
Status Pop(SqDoubleStack *S, SElemType *e, int stackNumber)
{
    if(stackNumber == 1)
    {
        if (S->top1 == -1)
        {
            return ERROR;   /*说明栈 1 已经是空栈, 溢出*/
        }
        *e = S->data[S->top1--];    /*将栈 1 的栈顶元素出栈*/
    }
    else if (stackNumber == 2)
    {
        if(S->top2 == MAXSIZE)
        {
            return ERROR;   /*说明栈 2 已经是空栈, 溢出*/
        }
        *e = S->data[S->top2++];    /*将栈 2 的栈顶元素出栈*/
    }
    return OK;
}
