#include <stdio.h>
#include <stdlib.h>
typedef struct item{
    int item;
}Item;
typedef struct arr
{
    int lenght;
    Item *item;
}List;

void add(List *arr,Item it){
    if(arr==NULL){ 
        arr = (List*)malloc(sizeof(List));
        //arr->item+arr->lenght = &it;
        arr->item = &it;
        arr->lenght=1;
    //    return arr->lenght;
    }
    // /else{ 
    // /    arr = (List*)realloc(arr,sizeof(List));
    // /    (arr+(arr->lenght*sizeof(List))+sizeof(List))->item = it;
    // /    arr->lenght++;
    //// /    return arr->lenght;
    // /}
    //return 0;
}
List * new (){
    List * arr = (List*)malloc(sizeof(List));
    arr->lenght = 0;
    arr->item = malloc(sizeof(Item));
    (*arr->item).item = 0;
    return arr;
}
int main(void){

    List * array=new();
   
    return 0;
}