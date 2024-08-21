#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};
struct Node* new(int data){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    if(!newNode){
        printf("Memory Allocation failed\n");
        exit(0);
    }
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}
void display(struct Node* head){
    struct Node* h=head;
    while(h!=NULL){
        printf("%d ",h->data);
        h=h->next;
    }
    printf("\n");
}

int find(int k,struct Node* head){
    if(head==NULL)
        return -1;
    
    struct Node** array=(struct Node**)malloc(sizeof(struct Node));
    int c=0;
    struct Node* h=head;
    while(h){
        array[c]=h;
        h=h->next;
        c++;
    }
    int n=c-k;
    if(n<0)
        return -1;
    return array[n]->data;
}
int main(){
    struct Node* head=NULL;
    head=new(1);
    head->next=new(2);
    head->next->next=new(3);
    head->next->next->next=new(4);
    printf("Linked List is: ");
    display(head);

    int k;
    printf("Enter the value of k: ");
    scanf("%d",&k);
    if(k==0){
        printf("Invalid Input\n");
        return 0;
    }

    int m=find(k,head);
    printf("%d ",m);
    // display(h);
}