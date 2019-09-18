#include "list.h"



/**********�����½��*******************/
Node* creat_Node(int value)
{
    Node* pt;
    pt=(Node*)malloc(sizeof(Node));
    if(pt!=NULL)
    {
        pt->data=value;
        pt->next=NULL;
    }

    return pt;
}


/************��������*******************/
Node* creatMyList(Node* pHeadNode)
{
    Node* pNode1 = NULL;
    Node* pNode2 = pHeadNode;
    int  Data;

    // ��������
    fflush(stdin);      // ������뻺����
    printf("Please input the data\n");
    scanf("%d",&(Data));
    while(Data != 0)
    {
        // ��������ڴ�
        pNode1 = creat_Node(Data);
        if(pNode1 == NULL)
        {
            printf("The allocating memory defeat.\n");
            return NULL;
        }


        // ִ�����Ӳ���
        if(pHeadNode == NULL)
        {
            // ֱ����Ϊͷ���
            pHeadNode = pNode1;
            pNode2 = pHeadNode;
        }
        else
        {
            pNode2->next = pNode1; // ���½����������β����
            pNode2 = pNode2->next; // ָ����һ�����
        }

        // ������һ����������
        fflush(stdin);      // ������뻺����
        printf("Please input the data\n");
        scanf("%d",&(Data));
    }
    return pHeadNode;
}

/**********ɾ������*******************/
void clearMyList(Node** pHeadNode)
{
    Node* pListNodeTmp = NULL;
    if((*pHeadNode) == NULL)
    {
        printf("The list is empty, no need to clear.\n");
        return;
    }

    // ѭ���ͷ������еĽ����ռ�ڴ棬��ս�����
    while((*pHeadNode)->next != NULL)
    {
        pListNodeTmp = (*pHeadNode)->next;
        free(*pHeadNode);
        (*pHeadNode) = pListNodeTmp;

    }

    // ������һ�����
    if((*pHeadNode) != NULL)
    {
        free((*pHeadNode));
        (*pHeadNode) = NULL;
        printf("The list is cleared.\n");
    }

}

/************��ӡ����*******************/
void PrintfListDataNode(Node* pHeadNode)
{
    int icount = 0;

    while(pHeadNode != NULL)
    {
        icount++;
        printf("The node %d's name is %d.\n", icount,
               pHeadNode->data);
        pHeadNode = pHeadNode->next;
    }
    printf("\n");
}


/*************ͷ�ڵ�ǰ������*****************/
Node* InsertFirstNode(Node* pHeadNode, int value)
{
    Node* pListNodeTmp = NULL;

    // ����������Ĵ���
    if(pHeadNode == NULL)
    {
        printf("There is no list.\n");
        return NULL;
    }

    // Ϊ�����������ڴ�
    pListNodeTmp = creat_Node(value);
    if(pListNodeTmp == NULL)
    {
        printf("The new node's memory allocating defeat.\n");
        return NULL;
    }

    // ��ԭʼͷ������ӵ��˽�����
    pListNodeTmp->next = pHeadNode;
    pHeadNode = pListNodeTmp;

    return pHeadNode;
}


/***********β�ڵ�������******************/
Node* InsertTailNode(Node* pHeadNode, int value)
{
    Node* pListNodeTmp  = pHeadNode;
    Node* pListNodeTmp1 = NULL;

    // �ж��Ƿ�����������
    if(pHeadNode == NULL)
    {
        printf("There is no list.\n");
        return NULL;
    }

    // Ϊ�����������ڴ�
    pListNodeTmp1 = creat_Node(value);
    if(pListNodeTmp1 == NULL)
    {
        printf("The new node's memory allocating defeat.\n");
        return NULL;
    }

    // ��ָ������β���
    while(pListNodeTmp->next!= NULL)
    {
        pListNodeTmp = pListNodeTmp->next;
    }
    pListNodeTmp->next = pListNodeTmp1;

    return pHeadNode;
}



/************ɾ��ͷ���********************/
void DeletFirstNode(Node** ppHeadNode)
{
    Node* pListNodeTmp = NULL;

    // �ж��Ƿ�����������
    if((*ppHeadNode) == NULL)
    {
        printf("There is no list.\n");
        return;
    }

    if((*ppHeadNode)->next != NULL)
    {
        // ����ͷ���
        pListNodeTmp = (*ppHeadNode)->next;
        free((*ppHeadNode));
        (*ppHeadNode) = pListNodeTmp;
    }
    else
    {
        // ԭ����������ֻ��ͷ��㣬�ͷź�ʣ�¿ձ�
        free((*ppHeadNode));
        (*ppHeadNode) = NULL;
    }
}


/************ɾ��β���********************/
void DeletTailNode(Node** ppHeadNode)
{
    Node* pListNodeTmp  = *ppHeadNode;
    Node* pListNodeTmp1 = NULL;

    // �ж��Ƿ�����������
    if((*ppHeadNode) == NULL)
    {
        printf("There is no list.\n");
        return;
    }

    // ��ָ������β��㣬pListNodeTmp1�������β����ǰһ�����
    while(pListNodeTmp->next != NULL)
    {
        pListNodeTmp1 = pListNodeTmp;
        pListNodeTmp  = pListNodeTmp->next;
    }

    // �ͷŽ��
    free(pListNodeTmp);
    pListNodeTmp = NULL;
    pListNodeTmp1->next = NULL;

}



/************����λ�ò�����********************/
Node* InsertOtherNode(Node* pHeadNode, int value, int Position, int iAfterBefore)
{
    /**iAfterBefore=1 ǰ /iAfterBefore=0 ��**/
    Node* pListNodeTmp1 = pHeadNode;
    Node* pListNodeTmp2 = pHeadNode;
    Node* pListNodeTmp3 = NULL;
    Node* pListNode     = NULL;
    int iCount = 1;

    // �ж��Ƿ�����������
    if(pHeadNode == NULL)
    {
        printf("There is no list.\n");
        return NULL;
    }

    // �ҵ�Ҫ�������λ��
    while((pListNodeTmp1 != NULL)&&(iCount<Position))
    {
        iCount++;
        pListNodeTmp2 = pListNodeTmp1;  // ����pListNodeTmp1��ǰһ���
        pListNodeTmp1 = pListNodeTmp1->next;
    }

    // û�����������ҵ��ؼ��ֱ�־�Ľ��
    if(pListNodeTmp1 == NULL)
    {
        printf("Sorry, can't find the node.\n");
        return NULL;
    }
    else if(iCount == 1 && iAfterBefore == 1)
    {
        // �������ͷ���
        pHeadNode = InsertFirstNode(pHeadNode, value);
        return pHeadNode;
    }
    else if(pListNodeTmp1->next == NULL && iAfterBefore == 0)
    {
        // �������β���
        pHeadNode = InsertTailNode(pHeadNode, value);
        return pHeadNode;
    }

    // ��Ҫ����ļȲ���ͷ���Ҳ����β��㣬Ϊ�����������ڴ�
    pListNode = creat_Node(value);
    if(pListNode == NULL)
    {
        printf("The new node's memory allocating defeat.\n");
        return NULL;
    }

    if(iAfterBefore == 0)
    {
        // �������
        pListNodeTmp3 = pListNodeTmp1->next;
        pListNodeTmp1->next = pListNode;
        pListNode->next= pListNodeTmp3;
    }
    else
    {
        // ������ǰ
        pListNodeTmp3 = pListNodeTmp2->next;
        pListNodeTmp2->next = pListNode;
        pListNode->next    = pListNodeTmp3;
    }

    return pHeadNode;
}


/************ɾ��������********************/
void DeletOtherNode(Node** ppHeadNode, int Position)
{
    Node* pListNodeTmp1 = (*ppHeadNode);
    Node* pListNodeTmp2 = NULL;
    int iCount = 1;

    // �ж��Ƿ�����������
    if((*ppHeadNode) == NULL)
    {
        printf("There is no list.\n");
        return;
    }

    // �ҵ�Ҫɾ������λ��
    while((pListNodeTmp1 != NULL)&&(iCount<Position))
    {
        iCount++;
        pListNodeTmp2 = pListNodeTmp1;      // ����pListNodeTmp1��ǰһ���
        pListNodeTmp1 = pListNodeTmp1->next;
    }

    // û�����������ҵ��ؼ��ֱ�־�Ľ��
    if(pListNodeTmp1 == NULL)
    {
        printf("Sorry, can't find the node.\n");
        return;
    }
    else if(iCount == 1)
    {
        // ɾ������ͷ���
        DeletFirstNode(ppHeadNode);
        return;
    }
    else if(pListNodeTmp1->next == NULL)
    {
        // ɾ������β���
        DeletTailNode(ppHeadNode);
        return;
    }

    // ִ��ɾ�����������ӵĲ���
    pListNodeTmp2->next = pListNodeTmp1->next;
    free(pListNodeTmp1);
    pListNodeTmp1 = NULL;

}



/************��ȡ������********************/
int GetMyListLen(Node* pHeadNode)
{
    Node* pListNodeTmp = pHeadNode;
    int Len = 0;

    // �ж��Ƿ�����������
    if(pHeadNode == NULL)
    {
        printf("There is no list.\n");
        return -1;
    }

    // ��ó���
    while(pListNodeTmp != NULL)
    {
        Len++;
        pListNodeTmp = pListNodeTmp->next;
    }
    return Len;
}

/************�ж������Ƿ�Ϊ��********************/
void CheckMyListEmpty(Node* pHeadNode)
{
    if(pHeadNode == NULL)
    {
        printf("The list is empty.\n");
        return;
    }
    else
    {
        printf("The list is no empty.\n");
        return;
    }
}


/************���ý������********************/
void SetCurrentNodeData(Node* pHeadNode, int Position, int value)
{
    Node* pListNodeTmp = pHeadNode;
    int icount =1;

    // �ж��Ƿ�����������
    if(pHeadNode == NULL)
    {
        printf("There is no list.\n");
        return;
    }

    // �ҵ�Ҫ�������ݵĽ��
    for(icount = 1; icount < Position; icount++)
    {
        if(pListNodeTmp == NULL)
        {
            printf("The input Position is error.\n");
            return;
        }
        else
        {
            pListNodeTmp = pListNodeTmp->next;
        }
    }
    pListNodeTmp->data=value;

}




/************��ȡ�������********************/
int GetCurrentNodeData(Node* pHeadNode, int Position)
{
    Node* pListNodeTmp = pHeadNode;
    int icount = 1,a = 0;

    // �ж��Ƿ�����������
    if(pHeadNode == NULL)
    {
        printf("There is no list.\n");
        return -1;
    }

    // �ҵ�Ҫ������ݵĽ��
    for(icount = 1; icount < Position; icount++)
    {
        if(pListNodeTmp == NULL)
        {
            printf("The input i is error.\n");
            return -1;
        }
        else
        {
            pListNodeTmp = pListNodeTmp->next;
        }
    }
    a=pListNodeTmp->data;
    return a;
}


/************����********************/
Node* SortList(Node* pHeadNode)
{
    Node* ptemp1 = NULL;
    Node* ptemp2 = NULL;
    Node* ptemp3 = NULL;

    for (ptemp1 = pHeadNode; ptemp1->next!= NULL; ptemp1 = ptemp1->next)
    {
        Node* pEnd = ptemp3;
        ptemp2 = pHeadNode;
        ptemp3 = ptemp2->next;
        for ( ;ptemp3 != pEnd; ptemp2 = ptemp2->next, ptemp3 = ptemp3->next)
        {
            if (ptemp2->data > ptemp3->data)
            {
                int temp = ptemp2->data;
                ptemp2->data = ptemp3->data;
                ptemp3->data = temp;
            }
        }
    }

    return pHeadNode;
}



/************����********************/
void SearchData(Node* pHeadNode, int value)
{
   Node* pListNodeTmp = pHeadNode;
   int icount=1,flag=0;
    // �ж��Ƿ�����������
    if(pHeadNode == NULL)
    {
        printf("There is no list.\n");
        return;
    }

    while(pListNodeTmp != NULL)
    {
        if(pListNodeTmp->data==value)
        {
          printf("The node is found at Position %d.\n",icount);
          flag++;
        }
        icount++;
        pListNodeTmp = pListNodeTmp->next;
    }
    if(flag==0)
    {
         printf("The node isn't found.\n");
    }

    return;

}
