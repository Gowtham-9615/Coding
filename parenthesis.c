#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
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
bool valid(char *a){
    for(int i=0;i<4;i++){
        if(a[i]=='(' || a[i]=='{' || a[i]=='['){
            push(a[i]);
        }
        else{
            if(isEmepty()){
                return false;
            }
            else{
                int h=peek(); 
                if((a[i]==')' && h=='(') || (a[i]==']' && h=='[') || (a[i]=='}' && h=='{') )
                    pop();
                else
                    return false;
            }
        }
    }
    return isEmepty();
}
int main(){
    char a[4];
    for(int i=0;i<4;i++){
        scanf("%c",&a[i]);
    }
    if(valid(a))
        printf("Entered Expression is a Valid\n");
    else
        printf("Entered expression is not a valid\n");
}