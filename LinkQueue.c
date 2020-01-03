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

typedef struct QNode        /*结点结构*/
{
    QElemType data;
    struct QNode *next;
}QNode, *QueuePtr;

typedef struct
{
    QueuePtr front, rear;   /*队头、队尾指针*/
}LinkQueue;

/*插入元素 e 为 Q 的新的队尾元素*/
Status EnQueue(LinkQueue *Q, QElemType e)
{
    QueuePtr s = (QueuePtr)malloc(sizeof(QNode));
    
    if (!s)     /*存储分配失败*/
    {
        exit(0);
    }

    s->data = e;
    s->next = NULL;
    Q->rear->next = s;      /*把拥有元素 e 新结点 s 赋值给原队尾结点的后继*/
    Q->rear = s;        /*把当前的 s 设置为队尾结点, rear 指向 s*/

    return  OK;
    
}


/*若队列不空, 删除 Q 的队头元素, 用 e 返回其值, 并返回 OK, 否则返回 ERROR*/
Status DeQueue(LinkQueue *Q, QElemType *e)
{
    QueuePtr    p;
    if (Q->front == Q->rear)        /*队列为空*/
    {
        return  ERROR;
    }
    p = Q->front->next;     /*将想要删除的队头结点暂时存放到 p*/
    *e = p->data;       /*把想要删除的这个结点, 把结点里面的数据传给 e*/
    Q->front->next = p->next;       /*将原队头结点的后继 p->next 赋值给头结点后继*/
    if (Q->rear == p)       /*如果队头是队尾, 则删除后把 rear 指向头结点*/
    {
        Q->rear = Q->front;
    }
    free(p);
    return  OK;
}
