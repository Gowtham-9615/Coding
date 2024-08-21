#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct Node{
    int data;
    struct Node* next;
};
struct Node* front=NULL;
struct Node* rear=NULL;
void enqueue(int data){
    struct Node* nn=(struct Node*)malloc(sizeof(struct Node*));
    nn->data=data;
    nn->next=NULL;
    if(front==NULL && rear==NULL){
        front=rear=nn;
        return ;
    }
    rear->next=nn;
    rear=nn;
}
bool isEmepty(){
    if(front==NULL){
        return true;
    }
    return false;
}
int peek(){
    if(isEmepty()){
        printf("The Queue is Emepty\n");
        return -1;
    }
    return front->data;
}
void dequeue(){
    if(isEmepty()){
        printf("No Element is in Queue to delete\n");
        return ;
    }
    if(front==rear){
        front=NULL;
        rear=NULL;
    }
    front=front->next;
}
int main(){
    enqueue(12);
    enqueue(33);
    enqueue(88);
    dequeue();
    printf("%d",peek());
}