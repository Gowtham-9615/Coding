#include<stdio.h>
#include<stdbool.h>
bool isEmepty();
int n=5;
int a[5];
int front=-1;
int rear=-1;
bool isFull(){
    if(isEmepty()){
        return false;
    }
    if(rear==n-1){
        return true;
    }
    return false;
}
bool isEmepty(){
    return front==-1;
}
void enqueue(int data){
    if((rear+1)%n==front){
        printf("The Queue is FULL \n");
        return ;
    }
    else if(front==-1 && rear==-1){
        front=0;
        rear=0;
    }
    else
        rear=(rear+1)%n;
    a[rear]=data;
}
int peek(){

    if(front==-1){
        printf("The Queue is Emepty\n");
        return -1;
    }
    return a[front];
}
int dequeue(){
    if(isEmepty()){
        printf("Queue is Emepty is Delete\n");
        return -1;
    }
    else if(rear==front){
        int c=a[front];
        rear=-1;
        front=-1;
        return c;
    }
    int c=a[front];
    front=(front+1)%n;
    return c;
}
int main(){
    peek();
    dequeue();
    enqueue(1);
    // printf("%d\n",peek());
    enqueue(12);
    // printf("%d\n",peek());
    enqueue(14);
    // printf("%d\n",peek());
    enqueue(16);
    // printf("%d\n",peek());
    enqueue(18);
    // printf("%d\n",peek());
    enqueue(89);
    // printf("%d\n",peek());
    enqueue(167);
    printf("%d\n",peek());

    printf("The Deleted element is :: %d\n",dequeue());
    enqueue(89);
    
    printf("%d\n",front);
    printf("%d\n",rear);
    
}