#include<stdio.h>
void lst(int* a,int n,int k){
    int c=0;
    for(int i=0;i<n;i++){
        if(a[i]==k){
            printf("Element Found\n");
            c=1;
            return ;
        }
    }
    if(c==0){
        printf("element not found\n");
    }
}
int main()
{
    printf("Enter the Size of an array\n");
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("Enter the key element to be searched\n");
    int k;
    scanf("%d",&k);
    lst(a,n,k);
}