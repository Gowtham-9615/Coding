#include<stdio.h>
#include<stdlib.h>
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};
struct Node* head;
void insert(int data){
    struct Node* nn=(struct Node*)malloc(sizeof(struct Node));
    nn->data=data;
    nn->next=NULL;
    nn->prev=NULL;
    
    if(head==NULL){
        head=nn;
        return ;
    }
    struct Node* h=head;
    while(h->next!=NULL){
        h=h->next;
    }
    h->next=nn;
    nn->prev=h;
}
void print(){
    
    if(head==NULL){
        printf("The list is Emepty\n");
        return ;
    }
    struct Node* h=head;
    while(h!=NULL){
        printf("%d ",h->data);
        h=h->next;
    }
    printf("\n");
}
int size(){
    struct Node *h=head;
    int c=0;
    while(h!=NULL){
        c++;
        h=h->next;
    }
    return c;
}
void insertAt(int index,int data){
    struct Node* nn=(struct Node*)malloc(sizeof(struct Node*));
    nn->data=data;
    if(!(size()>index)){
        printf("Enter Correct Index \n");
        return ;
    }
    struct Node* h=head;
    for(int i=0;i<index-1;i++){
        h=h->next;
    }
    nn->next=h->next->next;
    h->next=nn;
    nn->prev=h;
    
}
void insertFirst(int data){
    struct Node* nn=(struct Node*)malloc(sizeof(struct Node));
    nn->data=data;
    nn->next=NULL;
    nn->prev=NULL;
    if(head==NULL){
        head=nn;
        return ;
    }
    struct Node* h1=head;
    nn->next=h1;
    head=nn;
    
}
int search(int data){
    int c=0,c1=-1;
    struct Node* h=head;
    while(h!=NULL){
        
        if(h->data==data){
            c1=1;
            return c;
        }
        c++;
        h=h->next;
    }
    if(c1==1){
        return c;
    }
    return -1;
}
void delete(int data){
    struct Node* h=head;
    int found=search(data);
    if(found==-1){
        printf("Element Not Found\n");
        return;
    }
    for(int i=0;i<found-1;i++){
        h=h->next;
    }
    struct Node* del=h->next->next;
    h->next=del;
    printf("Element Deleted succesfully\n");
}
void deleteend(){
    struct Node* h=head;
    if(h==NULL){
        printf("NO Element found to delete\n");
        return ;
    }
    while(h->next->next!=NULL){
        h=h->next;
    }
    h->next=NULL;
}
void deleteFirst(){
    if(head==NULL){
        printf("No element to delete\n");
        return ;
    }
    struct Node* h=head;
    head=h->next;
}
int main(){
    printf("Enter Number of Elements \n");
    int a;
    scanf("%d",&a);
    for(int i=0;i<a;i++){
        int a1;
        scanf("%d",&a1);
        insert(a1);
    }
    insertFirst(56);
    deleteend();
    deleteFirst();
    printf("List of Elements are :: \n");
    print();
    printf("-------------------------------------------\n");
    printf("The size of Doublely list is :: %d \n",size());
    printf("-------------------------------------------\n");
    printf("Replacing the element with Index \n");
    insertAt(2,34);
    printf("-------------------------------------------\n");
    printf("List after replacing the Element\n");
    print();
    printf("-------------------------------------------\n");
    printf("Element Found At index :: %d\n",search(34));
    printf("-------------------------------------------\n");
    printf("-------------------------------------------\n");
    delete(34);
    printf("List After Deleting the Element\n");
    print();
    printf("-------------------------------------------\n");
    return 0;
}

