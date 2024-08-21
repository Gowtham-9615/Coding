#include<stdio.h>
#include<stdlib.h>
typedef struct{
    int* a;
    int size;
    int capacity;
}dynamicarray;

dynamicarray* alloc(int capacity){
    dynamicarray* new=malloc(sizeof(dynamicarray));
    new->a=malloc(capacity*sizeof(int));
    new->size=0;
    new->capacity=capacity;
    return new;
}
void add(dynamicarray* da,int data){
    if(da->size==da->capacity){
    int nc=da->capacity*2;
    int* na=malloc(nc*sizeof(int));
    for(int i=0;i<da->size;i++)
        na[i]=da->a[i];
        free(da->a);
        da->a=na;
        da->capacity=nc;
    }
    da->a[da->size]=data;
    da->size++;
}

void print(dynamicarray* da){
    for(int i=0;i<da->size;i++){
        printf("%d ",da->a[i]);
    }
}
void remo(dynamicarray* da,int index){
    if(index<0 || index>=da->size){
        return ;
    }
    for(int i=index;i<da->size-1;i++){
        da->a[i]=da->a[i+1];
    }
    da->size--;
    if(da->size<da->capacity/4){
        int nc=da->capacity/2;
        int* na=malloc(nc*sizeof(int));
        for(int i=0;i<da->size;i++){
            na[i]=da->a[i];
        }
        free(da->a);
        da->a=na;
        da->capacity=nc;
    }
}
int main(){
    dynamicarray* da=alloc(1);
    add(da,1);
    add(da,2);
    add(da,3);
    remo(da,0);
    print(da);
}