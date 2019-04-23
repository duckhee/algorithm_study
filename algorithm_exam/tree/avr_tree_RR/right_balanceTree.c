#include <stdio.h>
#include <stdlib.h>
#include "node.h"

extern NODE *HeadNode, *EndNode;
NODE *ParentNode;
NODE *GrandNode;
NODE *ChildNode;
NODE *BigNode;

void InitializeTree(void);
void InsertNode(int );
int IsBalance(void);
void RR_Rotate(void);
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

    if(HeadNode->Right == HeadNode)
    {
        HeadNode->Right = ptrNode;
        HeadNode->Left = ptrNode;
    }
    else{
        GrandNode = HeadNode;
        ParentNode = HeadNode;
        ChildNode = HeadNode->Right;
        tmpNode = HeadNode->Right;

        while(tmpNode != HeadNode)
        {
            ChildNode = tmpNode;
            if(ChildNode->Data > ptrNode->Data)
            {
                BigNode = GrandNode;
                GrandNode = ParentNode;
                ParentNode = ChildNode;
                tmpNode = tmpNode->Left;
            }else{
                BigNode = GrandNode;
                GrandNode = ParentNode;
                ParentNode = ChildNode;
                tmpNode = tmpNode->Right;
            }
        }
        ChildNode = ptrNode;

        if(ParentNode->Data > ChildNode->Data)
        {
            ParentNode->Left = ChildNode;
            ParentNode->Balance++;

            if(GrandNode != HeadNode)
            {
                GrandNode->Balance++;
            }
        }
        else{
            ParentNode->Right = ChildNode;
            ParentNode->Balance--;

            if(GrandNode != HeadNode)
            {
                GrandNode->Balance--;
            }
        }
        if(IsBalance()  == FALSE)
        {
            RR_Rotate();
        }
    }
}

int IsBalance()
{
    int ret = TRUE;
    NODE *ptrNode;
    ptrNode = HeadNode->Right;

    InitializeQueue();
    Put(ptrNode);

    while(!IsQueueEmpty())
    {
        ptrNode = Get();

        if(ptrNode->Balance > 1 || ptrNode->Balance < -1)
        {
            ret = FALSE;
            break;
        }
        if(ptrNode->Left != HeadNode)
        {
            Put(ptrNode->Left);
        }
        if(ptrNode->Right != HeadNode)
        {
            Put(ptrNode->Right);
        }
    }
    return ret;
}

void RR_Rotate()
{
    ParentNode = GrandNode->Right;
    ChildNode = ParentNode->Right;

    if(GrandNode-> Balance == -2)
    {
        BigNode->Right = ParentNode;
        ParentNode->Left = GrandNode;
        GrandNode->Left = HeadNode;
        GrandNode->Right = HeadNode;
    }
    BigNode->Balance++;
    ParentNode->Balance = 0;
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
    printf("node 10, 20 insert \r\n");

    InsertNode(10);
    InsertNode(20);
    Level_Traverse(HeadNode->Right);

    printf("\r\n=================================================\r\n");
    printf("node 30 insert\r\n");
    InsertNode(30);
    Level_Traverse(HeadNode->Right);

    return 0;
}