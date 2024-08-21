#include<stdio.h>
#include<stdlib.h>
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* nn(int data){
    struct Node* nn=(struct Node*)malloc(sizeof(struct Node*));
    nn->data=data;
    nn->left=NULL;
    nn->right=NULL;
    return nn;
}
void inorder(struct Node* a){
    if(a==NULL)
        return ;

        inorder(a->left);
        printf("%d ",a->data);
        inorder(a->right);
    
}
void preorder(struct Node* a){
    if(a!=NULL){
        printf("%d ",a->data);
        preorder(a->left);
        preorder(a->right);
    }
}
void postorder(struct Node* a){
    if(a!=NULL){
        postorder(a->left);
        postorder(a->right);
        printf("%d ",a->data);
    }
}
int main(){
    struct Node* root=nn(1);
    root->left=nn(2);
    root->right=nn(3);
    root->left->left=nn(44);
    // root->left->right=nn(45);


    printf("Inoder Traversal is :: \n");
    inorder(root);
    // printf("Preoder Traversal is :: \n",preorder(root));
    // printf("Postoder Traversal is ::\n",postorder(root));

}