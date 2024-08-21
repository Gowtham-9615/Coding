#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* new(int data){
    struct Node* nn=(struct Node*)malloc(sizeof(struct Node));
    nn->data=data;
    nn->left=NULL;
    nn->right=NULL;
    return nn;
}
struct Node* insert(struct Node* root,int data){
    if(root==NULL){
        root=new(data);
        return root;
    }
    if(data<=root->data){
        root->left=insert(root->left,data);
        
    }
    else{
        root->right=insert(root->right,data);
    }
    return root;
}
void inorder(struct Node* root){
    if(root==NULL){
        return ;
    }
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}
bool search(struct Node* root,int data){
    if(root==NULL)
        return false;
    if(root->data==data)
        return true;
    if(data<=root->data)
        return search(root->left,data);
    if(data>=root->data)
        return search(root->right,data);
    return false;
}
int max(int a,int b){
    if(a>=b){
        return b;
    }
    return a;
}
int height(struct Node* root){
    if(root==NULL){
        return -1;
    }
    int lh=height(root->left);
    int rh=height(root->right);
    int k=max(lh,rh)+1;
    return k;
}

int main(){
    struct Node* root=NULL;
    root=insert(root,12);
    root=insert(root,23);
    root=insert(root,42);
    
    if(search(root,49)){
        printf("Found\n");
    }
    else
        printf("Not Found\n");
    inorder(root);

    printf("Height of a Tree : %d",height(root));
    
}