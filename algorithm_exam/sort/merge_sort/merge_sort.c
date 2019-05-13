#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX       100
#define TRUE      1
#define FALSE     0

void MakeRandomNumber(void);
void MergeShort(int [], int, int);
void DisplayBuffer(void);
int IsNumberExit(int, int);

int Buf[MAX];
int temp[MAX];

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

void MergeShort(int data[], int left, int right)
{
    int i, j, k, middle;
    if(right > left)
    {
        middle = (left + right) / 2; 
    

        MergeShort(data, left, middle);
        MergeShort(data, middle+1, right);

        for(i = middle + 1; i > left; i--)
        {
            temp[i-1] = data[i-1];
        }
        for(j = middle; j < right; j++)
        {
            temp[right+middle-j] = data[j+1];
        }
        for(k = left; k <= right; k++)
        {
            data[k] = (temp[i]<temp[j])?temp[i++]:temp[j--];
        }
    }
}

void DisplayBuffer(void)
{
    int i;

    for(i = 0; i < MAX; i++)
    {
        if((i%10) == 0)
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
    printf("sort before data \r\n");

    MakeRandomNumber();
    DisplayBuffer();
    printf("sort result \r\n");
    MergeShort(Buf, 0, MAX-1);
    DisplayBuffer();
    printf("\r\n");

    return 0;
}