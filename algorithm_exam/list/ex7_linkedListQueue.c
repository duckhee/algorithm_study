#include <stdio.h>
#include <stdlib.h>

typedef struct  _NODE
{
    /* data */
    int Data;
    struct _NODE *Next;
}NODE;

NODE *Front, *Rear;
NODE *ptrNode;

void Initialize(void);
void Put(int);
int Get(void);
void DisplayQueue(void);

void Initialize(void)
{
    Front = (NODE *)malloc(sizeof(NODE));
    Rear = (NODE *)malloc(sizeof(NODE));
    Front->Next = Rear;
    Rear->Next = Rear;
}

void Put(int num)
{
    ptrNode = (NODE *)malloc(sizeof(NODE));
    ptrNode->Data = num;
    if(Front->Next == Rear)
    {
        Front->Next = ptrNode;
        ptrNode->Next = Rear;
        Rear->Next = ptrNode;
    }else{
        Rear->Next->Next = ptrNode;
        ptrNode->Next = Rear;
        Rear->Next = ptrNode;
    }
    
}

int Get(void)
{
    int ret;
    NODE *deleteNode;
    printf("\n");

    if(Front->Next == Rear)
    {
        printf("Queue Empty\r\n");
    }else{
        deleteNode = Front->Next;
        Front->Next = deleteNode->Next;
        ret = deleteNode->Data;
        printf("get() : %d", ret);

        free(deleteNode);
    }
    return 0;
}

void DisplayQueue(void)
{
    NODE *ptrTemp;
    if(Front->Next != Rear)
    {
        for(ptrTemp = Front->Next; ptrTemp->Next != Rear; ptrTemp = ptrTemp->Next)
        {
            printf("%d -> ", ptrTemp->Data);
        }
        printf("%d\r\n", ptrTemp->Data);
    }else if(Front->Next == Rear)
    {
        printf("Queue Empty\r\n");
    }
}

void main()
{
    int ret;
    Initialize();
    printf("Put() call \r\n");

    Put(1);
    Put(3);
    Put(10);
    Put(20);
    Put(12);

    printf("five Put() function call later result\r\n");
    DisplayQueue();

    ret = Get();
    ret = Get();
    ret = Get();

    printf("three Get() function call later result \r\n");
    DisplayQueue();

    ret = Get();
    ret = Get();

    printf("two Get() function later result\r\n");
    DisplayQueue();
}