#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
struct Node* new(int data){
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=data;
    temp->next=NULL;
    return temp;
}
void display(struct Node* h){
    struct Node* temp=h;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
struct Node* reverse(struct Node* h){
    struct Node* curr=h;
    struct Node* prev=NULL;
    struct Node* next=NULL;
    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}
int main() {
    struct Node* head=NULL;
    head=new(1);
    head->next=new(2);
    head->next->next=new(3);
    head->next->next->next=new(4);
    printf("Original linked list: ");
    display(head);
    head=reverse(head);
    printf("Reversed linked list: ");
    display(head);
}