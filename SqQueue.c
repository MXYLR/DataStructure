#include  <stdio.h>
#include <stdlib.h>
#include <time.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;     /*函数类型, 其值是函数结果状态码, 如 OK 等*/
typedef int QElemType;   /*SElemType 应根据实际情况来定, 这里假设为 int*/

#define MAXSIZE 1000    /*这里假定 MAXSIZE 为 1000*/

typedef struct
{
    QElemType data[MAXSIZE];
    int front;      /*头指针*/
    int rear;       /*尾指针, 若队列不空, 指向队列尾元素的下一个位置*/
}SqQueue;


/*初始化一个空循环队列 Q*/
Status InitQueue(SqQueue *Q)
{
    Q->front = 0;
    Q->rear = 0;
    return OK;
}

/*返回 Q 的元素个数, 也就是队列的当前长度*/
int QueueLength(SqQueue Q)
{
    return (Q.rear - Q.front + MAXSIZE) % MAXSIZE;
}

/*若队列未满, 则插入元素 e 为 Q 新的队尾元素*/
Status EnQueue(SqQueue *Q, QElemType e)
{
    if ((Q->rear + 1) % MAXSIZE == Q->front)        /*队列满的判断*/
    {
        return ERROR;
    }
    Q->data[Q->rear] = e;   /*将元素 e 赋值给队尾*/
    Q->rear = (Q->rear + 1) % MAXSIZE;      /*rear 指针向后移一个位置， 若到最后则转到数组头部*/
    return OK;
}

/*若队列不空, 则删除 Q 中队头元素, 用 e 返回其值*/
Status DeQueue(SqQueue *Q, QElemType *e)
{
    if (Q->front == Q->rear)    /*队列空的判断*/
    {
        return ERROR;
    }
    *e = Q->data[Q->front];     /*将队头元素赋值给 e*/
    Q->front = (Q->front + 1) % MAXSIZE;        /*将 front 指针向后移一个位置, 若到最后则转到数组头部*/
    return OK;
}
