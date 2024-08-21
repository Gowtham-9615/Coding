#include<stdio.h>
#include<stdlib.h>

int index(int data);

struct Node {
    int data;
    struct Node *next;
};
struct Node *head;
void insert(int data){
    struct Node *h=head;
    struct Node *nn=(struct Node*)malloc(sizeof(struct Node));
    nn->data=data;
    nn->next=NULL;
    if(head==NULL){
        head=nn;
        return ;
    }
    while(h->next!=NULL){
        h=h->next;
    }
    h->next=nn;
}
int size(){
    int count=0;
    struct Node *h=head;
    while(h!=NULL){
        count++;
        h=h->next;
    }
    return count;
}
void insertAtIndex(int data,int index){
    struct Node *nn=(struct Node *)malloc(sizeof(struct Node));
    struct Node *h=head;
    nn->data=data;
    if(index==0){
        insert(data);
        return ;
    }
    for(int i=0;i<index-1;i++){
        h=h->next;
    }
    struct Node *add=h->next->next;
    h->next=nn;
    nn->next=add;
}
void display(){
    struct Node *h=head;
    while(h!=NULL){
        printf("%d ",h->data);
        h=h->next;
    }
    printf("\n");
}
void search(int data){
    struct Node *h=head;
    while(h!=NULL){
        if(data==h->data){
            printf("Element Found \n");
            return ;
        }
        h=h->next;
    }
    printf("Element Not Found\n");
}
int index(int data){
    int c=0;
    struct Node *h=head;
    while(h!=NULL){
        if(h->data==data)
            return c;
        c++;
        h=h->next;
    }
    return -1;
}
void delete(int data){
    int k=index(data);
    // printf("The index of deleted element is:: %d",k);
    struct Node *h=head;
    if(k==-1)
    {
        printf("Element is not Not Found\n");
        return ;
    }
    if(k==0){
        h=h->next;
        return ;
    }
    for(int i=0;i<k-1;i++){
        h=h->next;
    }
    struct Node *del=h->next->next;
    h->next=del;
}
void insertstart(int data){

    struct Node *nn=(struct Node*)malloc(sizeof(struct Node*));
    struct Node *h=head;
    nn->data=data;
    nn->next=h;
    head=nn;
}
void deleteAtfirst(){
    if(head==NULL){
        printf("----------------------------------\n");
        printf("The List is Emepty...!\n");
        return ;
    }
    struct Node *temp=head;
    head=temp->next;
    printf("----------------------------------\n");
    printf(("First Element deleted succesfully\n"));
}
void deletelast(){
    struct Node* h=head;
    if(h!=NULL){
        while(h->next->next!=NULL){
            h=h->next;
        }
    }
    h->next=NULL;
    
}
int main(){
    insert(12);
    insert(89);
    insert(44);
    insert(98);
    insert(65);
    insert(54);
    insert(343);
    insertAtIndex(240,2);
    printf("----------------------------------\n");
    search(343);
    printf("----------------------------------\n");

    // printf("The element in index %d ",index(54));
    delete(54);
    
    insertstart(54);
    printf("\n");
    printf("Size of Linked list is :: %d \n",size());
    display();
    deleteAtfirst();
    deletelast();
    display();
    printf("----------------------------------\n");

}