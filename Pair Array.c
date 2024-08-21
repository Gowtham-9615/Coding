#include<stdio.h>

int findpairs(int n, int a[]){
    int i, j;
    int c=0;
    for(i=0; i<n-1; i++){
        for(j=i+1; j<n; j++){
            if((a[i]*a[j])%3==0){
                c++;
            }
        }
    }
    return c;
}
int main(){
    int n=1;
    int a[]={3};
    int k=findpairs(n,a);
    printf("%d\n",k);
}