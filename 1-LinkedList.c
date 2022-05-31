#include <stdio.h>
#include <stdlib.h>
typedef struct array *linkedList;
struct array
{
    void *item;
    struct array *nextItem;
};
linkedList globalList = NULL;
linkedList __new__(void)
{
    linkedList list = (linkedList)malloc(sizeof(struct array));
    list->item = (void *)0;
    list->nextItem = (void *)0;
    return list;
}
void add(linkedList list, void *item)
{
    if (list == NULL)
        return -1;
    if(list->item==NULL){
        list->item = item;
        list->nextItem = NULL;
        return;
    }

    linkedList tmpItem = list;
    linkedList tmp     = __new__();

    if (tmp == NULL)
        perror("No enough memory space!");
    tmp->item = item;
    tmp->nextItem = NULL;
    while (tmpItem->nextItem != NULL)
    {
        tmpItem = tmpItem->nextItem;
    }
    tmpItem->nextItem = tmp;
}
int count(linkedList list){
    linkedList tmp = list;
    int count;
    while(tmp!=NULL) {
        count++;
        tmp = tmp->nextItem;
    }
    return count;
}
void removeItem(linkedList list, void *item)
{
    linkedList tmpItem =list;
    linkedList tmp = __new__();
    linkedList val = __new__();
    while(tmpItem != NULL){
        if(tmpItem->item!=item){
            printf("OK found: %d == %d\n",tmpItem->item,item);
            tmp = __new__();
            tmp->item = tmpItem->item;
            tmp->nextItem = NULL;
        }else{
            tmpItem = tmpItem->nextItem;
        }
    }
}
void updateItem(linkedList list, void *item,void * newItem)
{
    linkedList tmp = list;
    while(tmp!=NULL){
        if(tmp->item==item){
            printf("item found %d == %d\n",tmp->item,item);
            tmp->item=newItem;
        }
        tmp = tmp->nextItem;
    }
}
void clear(linkedList list)
{
    free(list);
    list = __new__();
}
void print(linkedList list)
{
    linkedList tmp = list;
    while (tmp != NULL)
    {
        printf("%d\n", tmp->item);
        tmp = tmp->nextItem;
    }
}
int main(void)
{
    globalList = __new__();
    add(globalList, (int)100);
    add(globalList, (int)101);
    //removeItem(globalList, (int)100);
    //removeItem(globalList, (int)101);
    add(globalList, (int)104);
    add(globalList, (int)105);
    updateItem(globalList, (int)105,(int)150);
    print(globalList);
    printf("clearing");
    clear(globalList);
    print(globalList);
    return 0;
}