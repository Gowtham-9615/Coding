#include<stdio.h>
#include<stdlib.h>

#define TableSize 10

struct Node{
    int key;
    int data;
    struct Node *next;
};
struct Node* array[TableSize];

int hashcode(int key){
    return key%TableSize;
}

void insert(int key, int data){
    struct Node* nn=(struct Node*) malloc(sizeof(struct Node));
    nn->data=data;
    nn->key=key;
    nn->next=NULL;

    int index=hashcode(key);
    if(array[index]==NULL){
        array[index]=nn;
        return ;
    }
    struct Node* c=array[index];
    while(c->next!=NULL){
        c=c->next;
    }
    c->next=nn;
}

void display(){
    
    for(int i=0;i<TableSize;i++){
       struct Node* h=array[i];
       if(h!=NULL){
            while(h!=NULL){
                printf("(key %d : Data %d)\n",h->key,h->data);
                h=h->next;
            }
       } 
    }
}

struct Node* search(int key){
    int index=hashcode(key);
    struct Node* h=array[index];
    while(h!=NULL){
        if(h->key==key){
            return h;
        }
        h=h->next;
    }
    return NULL;
}

int main(){
    insert(1,23);
    insert(2,45);
    insert(8,67);
    insert(4,89);
    insert(8,12);
    display();

    struct Node* s=search(8);
    if(s==NULL){
        printf("Key not found\n");
    }
    else{
        printf("Key found : Data %d\n",s->data);
    }
}