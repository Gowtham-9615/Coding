#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* root=NULL;
struct Node* new(int data){
    struct Node* nn=(struct Node*)malloc(sizeof(struct Node));
    nn->data=data;
    nn->left=NULL;
    nn->right=NULL;
    return nn;
}
void insert(int data){
    struct Node* r=root;
    if(root==NULL){
        root=new(data);
        return ;
    }
    // printf("hi");
    if(data<=r->data){
        r->left=new(data);
    }
    else
        r->right=new(data);
} 
int findmin(){
    struct Node* r=root;
    if(root==NULL){
        printf("The tree is emepty\n");
        return -1;
    }
    while(r->left!=NULL){
        r=r->left;
    }
    return r->data;
}
int main(){
    insert(23);
    insert(2);
    insert(34);
    insert(1);
    printf("%d ",findmin());
}