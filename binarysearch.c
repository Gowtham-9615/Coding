#include<stdio.h>
void bst(int* a,int n,int k){
    int s=0;
    int e=n-1;
    while(s<=e){
        int mid=(s+e)/2;
        if(a[mid]==k){
            printf("Element found\n");
            return ;
        }
        else if(a[mid]<k){
            s=mid+1;
        }
        else
            e=mid-1;
    }
    if(s>e){
        printf("Element not found\n");
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
    bst(a,n,k);
}