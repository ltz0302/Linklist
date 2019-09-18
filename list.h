#ifndef list_h_
#define list_h_

#include <stdio.h>
#include <stdlib.h>





typedef struct Node
{
    int data;
    struct Node *next;
} Node;



Node* creat_Node(int value);
Node* creatMyList(Node* pHeadNode);
void clearMyList(Node** pt);
void PrintfListDataNode(Node* pHeadNode);
Node* InsertFirstNode(Node* pHeadNode, int value);
Node* InsertTailNode(Node* pHeadNode, int value);
int GetMyListLen(Node* pHeadNode);
void DeletFirstNode(Node** ppHeadNode);
void DeletTailNode(Node** ppHeadNode);
Node* InsertOtherNode(Node* pHeadNode, int value, int Position, int iAfterBefore);
void DeletOtherNode(Node** ppHeadNode, int Position);
void CheckMyListEmpty(Node* pHeadNode);
void SetCurrentNodeData(Node* pHeadNode, int Position, int value);
int GetCurrentNodeData(Node* pHeadNode, int Position);
Node* SortList(Node* pHeadNode);
void SearchData(Node* pHeadNode, int value);

#endif // list_h_
