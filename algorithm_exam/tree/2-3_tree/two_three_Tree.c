#include <stdio.h>
#include <stdlib.h>
#include "node.h"

#define RR       1
#define LL       2

extern NODE *HeadNode;

NODE *ParentNode;

void InitializeTree(void);
void InsertNode(int );
NODE *SplitNode(NODE *, NODE *);
void Level_Traverse(NODE *);
void Visit(NODE *);

extern void InitializeQueue(void);
extern void Put(NODE *);
extern NODE *Get(void);
extern int IsQueueEmpty(void);

void InitializeTree(void)
{
	HeadNode = (NODE *)malloc(sizeof(NODE));
	HeadNode->Left = HeadNode;
	HeadNode->Mid = HeadNode;
	HeadNode->Right = HeadNode;
}


void InsertNode(int Data)
{
	int FlagSplit = 0;
	NODE *tmpNode;

	if (HeadNode->Right == HeadNode) { 
		NODE *ptrNode = (NODE *)malloc(sizeof(NODE));

		ptrNode->LeftData = Data;
		ptrNode->RightData = -1;
		ptrNode->Left = HeadNode;
		ptrNode->Mid = HeadNode;
		ptrNode->Right = HeadNode;

		HeadNode->Right = ptrNode;
		HeadNode->Mid = ptrNode;
		HeadNode->Left = ptrNode;
	}

	else {
		tmpNode = HeadNode->Left;
		ParentNode = HeadNode;

		while (1) {
			if (tmpNode->LeftData < Data) {
				if (tmpNode->RightData == -1)
                {
					break;

                }

				else {
					if (tmpNode->Left == HeadNode) {
						FlagSplit = 1;
						break;
					}

					else {
						if (tmpNode->RightData < Data) {
							if (tmpNode->Mid == HeadNode)
                            {
								break;

                            }

							else {
								ParentNode = tmpNode;
								tmpNode = tmpNode->Mid;
							}
						}

						else {
							if (tmpNode->Mid == HeadNode)
                            {
								break;

                            }

							else {
								ParentNode = tmpNode;
								tmpNode = tmpNode->Mid;
							}
						}
					}
				}
			}

			else {
				if (tmpNode->Left == HeadNode) {
					if (tmpNode->RightData == -1)
                    {
						FlagSplit = 0;
                    }

					else
                    {
						FlagSplit = 1;
                    }

					break;
				}
				else {
					ParentNode = tmpNode;
					tmpNode = tmpNode->Left;
				}
			}
		}

		if (tmpNode->RightData == -1 && FlagSplit == 0) {
			if (tmpNode->LeftData < Data)
            {
				tmpNode->RightData = Data;
            }
			else {
				tmpNode->RightData = tmpNode->LeftData;
				tmpNode->LeftData = Data;
			}
		}

		else if (FlagSplit > 0) {
			NODE *ptrNode = (NODE *)malloc(sizeof(NODE));

			ptrNode->LeftData = Data;
			ptrNode->RightData = -1;
			ptrNode->Left = HeadNode;
			ptrNode->Mid = HeadNode;
			ptrNode->Right = HeadNode;

			if (FlagSplit == 1) {
				ParentNode->Left = SplitNode(tmpNode, ptrNode);
				tmpNode = ParentNode->Left;

				if (ParentNode->RightData == -1) {
					ParentNode->RightData = ParentNode->LeftData;
					ParentNode->LeftData = tmpNode->LeftData;
					ParentNode->Right = ParentNode->Mid;
					ParentNode->Mid = tmpNode->Mid;
					ParentNode->Left = tmpNode->Left;
				}
			}
		}
	}
}

void Level_Traverse(NODE *ptrNode)
{
	InitializeQueue();
	Put(ptrNode);

	while (!IsQueueEmpty()) {
		ptrNode = Get();
		printf(" -> ");
		Visit(ptrNode);

		if (ptrNode->Left != HeadNode)
			Put(ptrNode->Left);

		if (ptrNode->Mid != HeadNode)
			Put(ptrNode->Mid);

		if (ptrNode->Right != HeadNode)
			Put(ptrNode->Right);
	}
}

void Visit(NODE *ptrNode)
{
	printf("%2d ", ptrNode->LeftData);

	if (ptrNode->RightData != -1)
		printf("%2d ", ptrNode->RightData);
}


NODE *SplitNode(NODE *tmpNode, NODE *ptrNode)
{
	NODE *NewNode = (NODE *)malloc(sizeof(NODE));
	NewNode->RightData = -1;
	NewNode->Left = HeadNode;
	NewNode->Mid = HeadNode;
	NewNode->Right = HeadNode;

	if (tmpNode->LeftData < ptrNode->LeftData) {
		if (ptrNode->LeftData < tmpNode->RightData) {
			NewNode->LeftData = tmpNode->RightData;
			tmpNode->RightData = -1;
		}

		else {
			NewNode->LeftData = ptrNode->LeftData;
			ptrNode->LeftData = tmpNode->RightData;
			tmpNode->RightData = -1;
		}
	}

	else {
		NewNode->LeftData = tmpNode->RightData;
		tmpNode->RightData = ptrNode->LeftData;
		ptrNode->LeftData = tmpNode->LeftData;
		tmpNode->LeftData = tmpNode->RightData;
		tmpNode->RightData = -1;
	}

	ptrNode->Left = tmpNode;
	ptrNode->Mid = NewNode;

	return ptrNode;
}

int main()
{
    InitializeTree();
    printf("node insert 10, 20, 15, 13, 5, 12 \r\n");
    InsertNode(10);
    InsertNode(20);
    Level_Traverse(HeadNode->Left);
    printf("\r\n=======================================================\r\n");
    InsertNode(15);
    Level_Traverse(HeadNode->Left);
    printf("\r\n=======================================================\r\n");
    InsertNode(13);
    Level_Traverse(HeadNode->Left);
    printf("\r\n=======================================================\r\n");
    InsertNode(5);
    Level_Traverse(HeadNode->Left);
    printf("\r\n=======================================================\r\n");
    InsertNode(12);
    Level_Traverse(HeadNode->Left);
    printf("\r\n=======================================================\r\n");

    return 0;
}