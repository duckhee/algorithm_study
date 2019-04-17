#include <stdio.h>
#include <stdlib.h>

#define MAX    100

int Queue[MAX];
int Front, Rear;

void InitializeQueue(void);
void Put(int);
int Get(void);
void DisplayQueue(void);

void InitializeQueue()
{
    Front = Rear = 0;
}

void Put(int num)
{
    Queue[Rear++] = num;

    if(Rear >= MAX)
    {
        Rear = 0;
    }
}

int Get()
{
    int ret;
    ret = Queue[Front++];

    if(Front >= MAX)
    {
        Front = 0;
    }

    return ret;
}

void DisplayQueue(void)
{
    int i ;
    printf("Front-> ");
    for(i= Front; i < Rear; i++)
    {
        printf("%2d->", Queue[i]);
    }
    printf("Rear\r\n");
}

void main()
{
    int ret;
    InitializeQueue();

    Put(1);
    Put(3);
    Put(10);
    Put(20);
    Put(12);

    printf("\r\n five time put() after \r\n");
    DisplayQueue();
    
    ret = Get();
    ret = Get();
    ret = Get();

    printf("\r\n three time Get() after \r\n");
    DisplayQueue();

    printf("\r\n two time Get() after \r\n");
    ret = Get();
    ret = Get();

    DisplayQueue();
}