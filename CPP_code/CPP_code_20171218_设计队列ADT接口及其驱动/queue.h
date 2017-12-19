#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED
#include <stdbool.h>

//这里插入Item的定义，例如
typedef int Item;    //用于main.c
//或者typedef struct item {int gumption; int charisma;} Item;

#define MAXQUEUE 10
typedef struct node {
    Item item;
    struct node * next;
} Node;
typedef struct queue {
    Node * front;    //指向队列首项的指针
    Node * rear;    //指向队列尾项的指针
    int items;    //队列中的项数
} Queue;

//操作：初始化队列
//前提：pq指向一个队列
//后置：队列被初始化为空
void InitializeQueue(Queue * pq);

//操作：检查队列是否已满
//前提：pq指向之前被初始化的队列
//后置：如队列已满则返回true，否则false
bool QueueIsFull(const Queue * pq);

//检查队列是否为空
//pq指向之前被初始化的队列
//如队列为空则返回true，否则false
bool QueueIsEmpty(const Queue * pq);

//确定队列中的项数
//pq指向之前被初始化的队列
//返回队列的项数
int QueueItemCount(const Queue * pq);

//在队列末尾添加项
//pq指向之前被初始化的队列，item只要被添加在队列末尾的项
//如队列不为空，item将被添加在队列末尾，该函数返回true；否则，队列不改变，返回false
bool EnQueue(Item item, Queue * pq);

//从队列的开头删除项
//pq指向之前被初始化的队列
//如队列不为空，队列首项的item将被拷贝到*pitem中；并被删除，同时返回true；如为空，则重置队列为空；如队列在操作前为空，该函数返回false
bool DeQueue(Item * pitem, Queue * pq);

//清空队列
//pq指向之前被初始化的队列
//队列被清空
void EmptyTheQueue(Queue * pq);

#endif // QUEUE_H_INCLUDED
