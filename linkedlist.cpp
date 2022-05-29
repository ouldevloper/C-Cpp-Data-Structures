#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
typedef struct array List;
typedef void *var;
struct array
{
    void *item;
    struct array *next;
};
List *global = NULL;
List *__new()
{
    return (List *)malloc(sizeof(List));
}
void add(List *array, var item)
{
    if (array == NULL)
    {
        array = __new();
        array->item = item;
        array->next = NULL;
    }
    else
    {
        List *tmp = array;
        List *newItem = __new();
        newItem->item = item;
        newItem->next = NULL;
        while (tmp->next != NULL)
        {
            tmp = tmp->next;
            tmp++;
        }
        tmp->next = newItem;
    }
}
void remove(List*array,var item){
    List  * tmp = __new();
    while(array->next!=NULL){
        if(array->item!= item){
            tmp = array;
            tmp->next = array->next;
        }
    }
}
void print(List *list)
{
    List *tmp = list;
    while (tmp->next != NULL)
    {
        printf("%d\n", tmp->item);
        tmp = tmp->next;
    }
}
int main(void)
{
    add(global, (var)10);
    add(global, (var)10);
    add(global, (var)10);
    print(global);
    return 0;
}