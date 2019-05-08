#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX      100
#define TRUE     1
#define FALSE    0

void MakeRandomNumber(void);
void SelectionSort(void);
void DisplayBuffer(void);
int IsNumberExit(int , int);
int Buf[MAX];

void MakeRandomNumber(void)
{
    int i, Num;
    i = 1;
    srand((unsigned)time(NULL));
    Buf[0] = 100;

    while(i < MAX)
    {
        Num = rand() % MAX;
        if(!IsNumberExit(Num, i))
        {
            Buf[i] = Num;
            i++;
        }
    }
}

void SelectionSort(void)
{
    int i, j, min1, dummy;

    for(i = 0; i < MAX; i++)
    {
        min1 = i;

        for(j = i + 1; j < MAX; j++)
        {
            if(Buf[j] < Buf[min1])
            {
                min1 = j;
            }

        }
        dummy = Buf[min1];
        Buf[min1] = Buf[i];
        Buf[i] = dummy;
    }
}

void DisplayBuffer(void)
{
    int i;

    for(i = 0; i < MAX; i++)
    {
        if((i % 10) == 0)
        {
            printf("\r\n");
        }
        printf("%4d ", Buf[i]);
    }
    printf("\r\n");
}

int IsNumberExit(int number, int index)
{
    int i;

    for(i = 0; i < index; i++)
    {
        if(Buf[i] == number || number == 0)
        {
            return TRUE;
        }
    }
        return FALSE;
}

int main()
{
    printf("set data \r\n");
    MakeRandomNumber();
    DisplayBuffer();
    printf("sort result \r\n");
    SelectionSort();
    DisplayBuffer();

    printf("\r\n");
    return 0;
}