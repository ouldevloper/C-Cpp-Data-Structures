#include <iostream>
#include <stdio.h>
#include <stdlib.h>


typedef struct arr Item;
struct arr
{
    void * item;
};



void add(Item arr[],Item it){
    //if(arr==NULL) arr = (Item*)malloc(sizeof(Item));
    //else arr = (Item*)realloc(arr,sizeof(Item));
    //arr[sizeof(arr)] = it;
    printf("arr: %d\nItem: %d\n",sizeof(arr),sizeof(Item));
}
int main(void){

    Item *array = (Item*)malloc(sizeof(Item)*10);
    Item i1 = {item:(int)100};
    //add(i1);
    //array[0] = i1;
    add(array,i1);

    return 0;
}