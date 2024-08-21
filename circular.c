#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
struct Node* head=NULL;

void display(){
    struct Node* h=head;
    h=head->next;
    do{
        printf("%d ", h->data);
        h=h->next;
    }
    while(h!=head->next);
}
void insert(int data){
    struct Node* nn=(struct Node*)malloc(sizeof(struct Node));
    if(head==NULL){
        nn->data=data;
        nn->next=nn;
        head=nn;
    }
    else{
        nn->data=data;
        nn->next=head->next;
        head->next=nn;
        head=nn;
    }
}
int main(){
    insert(22);
    insert(44);
    insert(66);
    insert(88);
    display();
}