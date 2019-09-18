
#include <stdlib.h>
#include "list.h"

int main()
{
    int len;
    Node* list;
    list=creatMyList(NULL);
    list=InsertOtherNode(list,11,3,1);
    len=GetMyListLen(list);
    printf("The Len is %d\n",len);
    PrintfListDataNode(list);
    SearchData(list,3);
    return 0;
}
