#include "node.h"

#define MAX    100

NODE *Queue[MAX];

/**
 * Front Get 사용 시 증가
 * Rear Put 사용 시 증가
*/
int Front, Rear;


void InitializeQueue(void);
void Put(NODE *);
NODE *Get(void);
int IsQueueEmpty(void);

void InitializeQueue(void)
{
    Front = Rear = 0;
}

void Put(NODE *ptrNode)
{
    Queue[Rear] = ptrNode;
    (Rear++)%MAX;
}

NODE *Get(void)
{
    NODE *ptrNode;

    if(!IsQueueEmpty())
    {
        ptrNode = Queue[Front];
        (Front++)%MAX;

        return ptrNode;
    }else{
        printf("Queue is Empty \r\n");
        return NULL;
    }
}

int IsQueueEmpty(void)
{
    if(Rear == Front)
    {
        return TRUE;
    }
    else{
        return FALSE;
    }
}