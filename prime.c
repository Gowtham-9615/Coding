#include<stdio.h>
#include<math.h>
// #include "header.h"
int main(){
    int a;
    scanf("%d",&a);
    if(a==2 || a==3 || a==5 || a==7){
        printf("Prime Number");
        return 0;
    }
    else if (a==4 || a==6 || a==9){
        printf("Not Prime Number");
        return 0;
    }
    for(int i=2;i<sqrt(a);i++){
        if(a%i==0){
            printf("Not a prime Number");
            return -1;
        }
    }
    printf("Prime Number");
}