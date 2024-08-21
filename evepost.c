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
int perform(int op1,int op2,char a){
    switch(a){
        case '*':
            return op1*op2;
            break;
        case '+':
            return op1+op2;
            break;
        case '-':
            return op1-op2;
            break;
        case '/':
            return op1/op2;
            break;
        case '%':
            return op1%op2;
            break;
    }
    return -1;
}
int evepost(char* a){
    if(a=="")
        return 0;
    int res=0;
    for(int i=0;i<10;i++){
        if(a[i]>='1' && a[i]<='9'){
            int k=atoi(&a[i]);
            push(k);
        }
        else if(a[i]!=' '){
            int op2=pop();
            int op1=pop();
            res=perform(op1,op2,a[i]);
            push(res);
        }
    }
    return res;
}
int main(){
    char a[10];
    for(int i=0;i<10;i++){
        scanf("%c",&a[i]);
    }
    printf("The output of Postfix expression %d \n",evepost(a));
}