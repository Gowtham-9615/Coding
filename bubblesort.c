#include<stdio.h>
void bubblesort(int *a,int n){
    for(int i=0;i<n;i++){
        int c=0;
        for(int j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1]){
                a[j]=a[j]+a[j+1]-(a[j+1]=a[j]);
                c=1;
            }
        }
        if(c==0)
            break;
    }
}
int main(){
    printf("Enter the size of an array\n");
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    bubblesort(a,n);
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
}