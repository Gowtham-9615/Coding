#include<stdio.h>
#include<stdbool.h>
int n=5;
int a[5];
int top=-1;
void push(int data){
    if(top==n-1){
        printf("Stack overflow...\n");
        return ;
    }
    a[++top]=data;
}
bool isEmepty(){
    if(top==-1){
        return true;
    }
    return false;
}
void pop(){
    if(isEmepty()){
        printf("No Element to pop\n");
        return ;
    }
    top--;
}
int peek(){
    return a[top];
}
int main(){
    push(23);
    push(44);
    push(876);
    pop();
    printf("%d",peek());
}