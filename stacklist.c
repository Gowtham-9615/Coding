#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct Node{
    int data;
    struct Node* next;
};
struct Node* top=NULL;
void push(int data){
    struct Node* nn=(struct Node*)malloc(sizeof(struct Node*));
    nn->data=data;
    nn->next=top;
    top=nn;
}
int pop(){
    if(top==NULL){
        printf("NO element to pop\n");
        return -1;
    }
    int del=top->data;
    top=top->next;
    return del;
}
bool isEmepty(){
    if(top==NULL)
        return true;
    return false;
}
int peek(){
    return top->data;
}
int main(){
    pop();
    push(23);
    push(12);
    push(99);
    printf("The Deleted Element is :: %d \n",pop());
    printf("%d",peek());
}