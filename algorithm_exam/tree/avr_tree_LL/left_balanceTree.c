#include <stdio.h>
#include <stdlib.h>
#include "node.h"

#define RR       1
#define LL       2

extern NODE *HeadNode, *EndNode;
NODE *ParenetNode, *GrandNode, *ChildNode, *BigNode;

void InitializeTree(void);
void InsertNode(int );
int IsBalance(void);
void RR_Rotate(void);
void LL_Rotate(void);
void Level_Traverse(NODE *);
void Visit(NODE *);

extern void InitializeQueue(void);
extern void Put(NODE *);
extern NODE *Get(void);
extern int IsQueueEmpty(void);

void InitializeTree()
{
    HeadNode = (NODE *)malloc(sizeof(NODE));
    HeadNode->Left = HeadNode;
    HeadNode->Right = HeadNode;
    BigNode = HeadNode;
}

void InsertNode(int Data)
{
    NODE *tmpNode;
    NODE *ptrNode = (NODE *)malloc(sizeof(NODE));

    ptrNode->Data = Data;
    ptrNode->Balance = 0;
    ptrNode->Left = HeadNode;
    ptrNode->Right = HeadNode;
    BigNode = HeadNode;

    if(HeadNode->Right == HeadNode)
    {
        HeadNode->Right = ptrNode;
        HeadNode->Left = ptrNode;
    }else{
        GrandNode = HeadNode;
        ParenetNode = HeadNode;
        ChildNode = HeadNode->Right;
        tmpNode = HeadNode->Right;

        while(tmpNode != HeadNode)
        {
            ChildNode = tmpNode;

            if(ChildNode->Data > ptrNode->Data)
            {
                BigNode = GrandNode;

                GrandNode = ParenetNode;
                ParenetNode = ChildNode;
                tmpNode = tmpNode->Left;
            }else{
                BigNode = GrandNode;
                GrandNode = ParenetNode;
                ParenetNode = ChildNode;
                tmpNode = tmpNode->Right;
            }
        }
        ChildNode = ptrNode;

        if(ParenetNode->Data > ChildNode->Data)
        {
            ParenetNode->Left = ChildNode;
            ParenetNode->Balance++;

            if(GrandNode != HeadNode)
            {
                GrandNode->Balance++;
            }
            if(BigNode != HeadNode)
            {
                BigNode->Balance++;
            }
        }else{
            ParenetNode->Right = ChildNode;
            ParenetNode->Balance--;

            if(GrandNode != HeadNode)
            {
                GrandNode->Balance--;
            }
            if(BigNode != HeadNode)
            {
                BigNode->Balance--;
            }
        }
        switch(IsBalance())
        {
            case RR:
                RR_Rotate();
                break;
            case LL:
                LL_Rotate();
                break;
            default:
                break;
        }
    }
}

int IsBalance(void)
{
    int ret = 0;
    int LeftCnt  = 0;
    int RightCnt = 0;

    NODE *ptrNode;
    ptrNode = HeadNode->Right;

    InitializeQueue();
    Put(ptrNode);

    while(!IsQueueEmpty())
    {
        ptrNode = Get();

        if(ptrNode->Balance > 1)
        {
            ret = LL;
            break;
        }else if(ptrNode->Balance < -1)
        {
            ret = RR;
            break;
        }
        if(ptrNode->Left != HeadNode)
        {
            Put(ptrNode->Left);
            LeftCnt++;
            RightCnt = 0;
        }
        if(ptrNode->Right != HeadNode)
        {
            Put(ptrNode->Right);
            RightCnt++;
            LeftCnt = 0;
        }
    }
    return ret;
}

void RR_Rotate()
{
    ParenetNode = GrandNode->Right;
    ChildNode = ParenetNode->Right;

    if(GrandNode->Balance == -2)
    {
        BigNode->Right = ParenetNode;
        ParenetNode->Left = GrandNode;
        GrandNode->Left = HeadNode;
        GrandNode->Right = HeadNode;
    }

    BigNode->Balance++;

    ParenetNode->Balance = 0;
    GrandNode->Balance = 0;
    ChildNode->Balance = 0;
}

void LL_Rotate()
{
    ParenetNode = GrandNode->Left;
    ChildNode = ParenetNode->Left;

    if(GrandNode->Balance == 2)
    {
        BigNode->Left = ParenetNode;
        ParenetNode->Right = GrandNode;
        GrandNode->Left = HeadNode;
        GrandNode->Right = HeadNode;
    }

    BigNode->Balance--;

    ParenetNode->Balance = 0;
    GrandNode->Balance = 0;
    ChildNode->Balance = 0;
}

void Level_Traverse(NODE *ptrNode)
{
    InitializeQueue();
    Put(ptrNode);

    while(!IsQueueEmpty())
    {
        ptrNode = Get();
        printf(" -> ");
        Visit(ptrNode);

        if(ptrNode->Left != HeadNode)
        {
            Put(ptrNode->Left);
        }
        if(ptrNode->Right != HeadNode)
        {
            Put(ptrNode->Right);
        }
    }
}

void Visit(NODE *ptrNode)
{
    printf("%2d", ptrNode->Data);
}

int main()
{
    InitializeTree();
    printf("node insert 30, 20, 40, 10 \r\n");
    InsertNode(30);
    InsertNode(20);
    InsertNode(40);
    InsertNode(10);
    Level_Traverse(HeadNode->Right);
    printf("\r\n=========================================\r\n");
    printf("node insert 5\r\n");
    InsertNode(5);
    Level_Traverse(HeadNode->Right);

    return 0;
}