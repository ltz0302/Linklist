#include "list.h"



/**********创建新结点*******************/
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


/************创建链表*******************/
Node* creatMyList(Node* pHeadNode)
{
    Node* pNode1 = NULL;
    Node* pNode2 = pHeadNode;
    int  Data;

    // 输入数据
    fflush(stdin);      // 清空输入缓冲区
    printf("Please input the data\n");
    scanf("%d",&(Data));
    while(Data != 0)
    {
        // 分配结点的内存
        pNode1 = creat_Node(Data);
        if(pNode1 == NULL)
        {
            printf("The allocating memory defeat.\n");
            return NULL;
        }


        // 执行链接操作
        if(pHeadNode == NULL)
        {
            // 直接作为头结点
            pHeadNode = pNode1;
            pNode2 = pHeadNode;
        }
        else
        {
            pNode2->next = pNode1; // 将新结点挂在链表表尾后面
            pNode2 = pNode2->next; // 指向下一个结点
        }

        // 输入下一个结点的数据
        fflush(stdin);      // 清空输入缓冲区
        printf("Please input the data\n");
        scanf("%d",&(Data));
    }
    return pHeadNode;
}

/**********删除链表*******************/
void clearMyList(Node** pHeadNode)
{
    Node* pListNodeTmp = NULL;
    if((*pHeadNode) == NULL)
    {
        printf("The list is empty, no need to clear.\n");
        return;
    }

    // 循环释放链表中的结点所占内存，清空结束后
    while((*pHeadNode)->next != NULL)
    {
        pListNodeTmp = (*pHeadNode)->next;
        free(*pHeadNode);
        (*pHeadNode) = pListNodeTmp;

    }

    // 清除最后一个结点
    if((*pHeadNode) != NULL)
    {
        free((*pHeadNode));
        (*pHeadNode) = NULL;
        printf("The list is cleared.\n");
    }

}

/************打印链表*******************/
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


/*************头节点前插入结点*****************/
Node* InsertFirstNode(Node* pHeadNode, int value)
{
    Node* pListNodeTmp = NULL;

    // 错误函数输入的处理
    if(pHeadNode == NULL)
    {
        printf("There is no list.\n");
        return NULL;
    }

    // 为新增结点分配内存
    pListNodeTmp = creat_Node(value);
    if(pListNodeTmp == NULL)
    {
        printf("The new node's memory allocating defeat.\n");
        return NULL;
    }

    // 将原始头结点链接到此结点后面
    pListNodeTmp->next = pHeadNode;
    pHeadNode = pListNodeTmp;

    return pHeadNode;
}


/***********尾节点后插入结点******************/
Node* InsertTailNode(Node* pHeadNode, int value)
{
    Node* pListNodeTmp  = pHeadNode;
    Node* pListNodeTmp1 = NULL;

    // 判断是否有链表输入
    if(pHeadNode == NULL)
    {
        printf("There is no list.\n");
        return NULL;
    }

    // 为新增结点分配内存
    pListNodeTmp1 = creat_Node(value);
    if(pListNodeTmp1 == NULL)
    {
        printf("The new node's memory allocating defeat.\n");
        return NULL;
    }

    // 将指针移至尾结点
    while(pListNodeTmp->next!= NULL)
    {
        pListNodeTmp = pListNodeTmp->next;
    }
    pListNodeTmp->next = pListNodeTmp1;

    return pHeadNode;
}



/************删除头结点********************/
void DeletFirstNode(Node** ppHeadNode)
{
    Node* pListNodeTmp = NULL;

    // 判断是否有链表输入
    if((*ppHeadNode) == NULL)
    {
        printf("There is no list.\n");
        return;
    }

    if((*ppHeadNode)->next != NULL)
    {
        // 更新头结点
        pListNodeTmp = (*ppHeadNode)->next;
        free((*ppHeadNode));
        (*ppHeadNode) = pListNodeTmp;
    }
    else
    {
        // 原来的链表中只有头结点，释放后剩下空表
        free((*ppHeadNode));
        (*ppHeadNode) = NULL;
    }
}


/************删除尾结点********************/
void DeletTailNode(Node** ppHeadNode)
{
    Node* pListNodeTmp  = *ppHeadNode;
    Node* pListNodeTmp1 = NULL;

    // 判断是否有链表输入
    if((*ppHeadNode) == NULL)
    {
        printf("There is no list.\n");
        return;
    }

    // 将指针移至尾结点，pListNodeTmp1保存的是尾结点的前一个结点
    while(pListNodeTmp->next != NULL)
    {
        pListNodeTmp1 = pListNodeTmp;
        pListNodeTmp  = pListNodeTmp->next;
    }

    // 释放结点
    free(pListNodeTmp);
    pListNodeTmp = NULL;
    pListNodeTmp1->next = NULL;

}



/************任意位置插入结点********************/
Node* InsertOtherNode(Node* pHeadNode, int value, int Position, int iAfterBefore)
{
    /**iAfterBefore=1 前 /iAfterBefore=0 后**/
    Node* pListNodeTmp1 = pHeadNode;
    Node* pListNodeTmp2 = pHeadNode;
    Node* pListNodeTmp3 = NULL;
    Node* pListNode     = NULL;
    int iCount = 1;

    // 判断是否有链表输入
    if(pHeadNode == NULL)
    {
        printf("There is no list.\n");
        return NULL;
    }

    // 找到要插入结点的位置
    while((pListNodeTmp1 != NULL)&&(iCount<Position))
    {
        iCount++;
        pListNodeTmp2 = pListNodeTmp1;  // 保存pListNodeTmp1的前一结点
        pListNodeTmp1 = pListNodeTmp1->next;
    }

    // 没有在链表中找到关键字标志的结点
    if(pListNodeTmp1 == NULL)
    {
        printf("Sorry, can't find the node.\n");
        return NULL;
    }
    else if(iCount == 1 && iAfterBefore == 1)
    {
        // 插入的是头结点
        pHeadNode = InsertFirstNode(pHeadNode, value);
        return pHeadNode;
    }
    else if(pListNodeTmp1->next == NULL && iAfterBefore == 0)
    {
        // 插入的是尾结点
        pHeadNode = InsertTailNode(pHeadNode, value);
        return pHeadNode;
    }

    // 需要插入的既不是头结点也不是尾结点，为新增结点分配内存
    pListNode = creat_Node(value);
    if(pListNode == NULL)
    {
        printf("The new node's memory allocating defeat.\n");
        return NULL;
    }

    if(iAfterBefore == 0)
    {
        // 插入其后
        pListNodeTmp3 = pListNodeTmp1->next;
        pListNodeTmp1->next = pListNode;
        pListNode->next= pListNodeTmp3;
    }
    else
    {
        // 插入其前
        pListNodeTmp3 = pListNodeTmp2->next;
        pListNodeTmp2->next = pListNode;
        pListNode->next    = pListNodeTmp3;
    }

    return pHeadNode;
}


/************删除任意结点********************/
void DeletOtherNode(Node** ppHeadNode, int Position)
{
    Node* pListNodeTmp1 = (*ppHeadNode);
    Node* pListNodeTmp2 = NULL;
    int iCount = 1;

    // 判断是否有链表输入
    if((*ppHeadNode) == NULL)
    {
        printf("There is no list.\n");
        return;
    }

    // 找到要删除结点的位置
    while((pListNodeTmp1 != NULL)&&(iCount<Position))
    {
        iCount++;
        pListNodeTmp2 = pListNodeTmp1;      // 保存pListNodeTmp1的前一结点
        pListNodeTmp1 = pListNodeTmp1->next;
    }

    // 没有在链表中找到关键字标志的结点
    if(pListNodeTmp1 == NULL)
    {
        printf("Sorry, can't find the node.\n");
        return;
    }
    else if(iCount == 1)
    {
        // 删除的是头结点
        DeletFirstNode(ppHeadNode);
        return;
    }
    else if(pListNodeTmp1->next == NULL)
    {
        // 删除的是尾结点
        DeletTailNode(ppHeadNode);
        return;
    }

    // 执行删除和重新链接的操作
    pListNodeTmp2->next = pListNodeTmp1->next;
    free(pListNodeTmp1);
    pListNodeTmp1 = NULL;

}



/************获取链表长度********************/
int GetMyListLen(Node* pHeadNode)
{
    Node* pListNodeTmp = pHeadNode;
    int Len = 0;

    // 判断是否有链表输入
    if(pHeadNode == NULL)
    {
        printf("There is no list.\n");
        return -1;
    }

    // 获得长度
    while(pListNodeTmp != NULL)
    {
        Len++;
        pListNodeTmp = pListNodeTmp->next;
    }
    return Len;
}

/************判断链表是否为空********************/
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


/************设置结点数据********************/
void SetCurrentNodeData(Node* pHeadNode, int Position, int value)
{
    Node* pListNodeTmp = pHeadNode;
    int icount =1;

    // 判断是否有链表输入
    if(pHeadNode == NULL)
    {
        printf("There is no list.\n");
        return;
    }

    // 找到要更新数据的结点
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




/************获取结点数据********************/
int GetCurrentNodeData(Node* pHeadNode, int Position)
{
    Node* pListNodeTmp = pHeadNode;
    int icount = 1,a = 0;

    // 判断是否有链表输入
    if(pHeadNode == NULL)
    {
        printf("There is no list.\n");
        return -1;
    }

    // 找到要获得数据的结点
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


/************排序********************/
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



/************查找********************/
void SearchData(Node* pHeadNode, int value)
{
   Node* pListNodeTmp = pHeadNode;
   int icount=1,flag=0;
    // 判断是否有链表输入
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
