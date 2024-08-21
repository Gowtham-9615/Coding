#include<stdio.h>
int primesum(int input1){
    int sum = 0;
    for(int i = 2; i <= input1; i++) {
        int c = 1;
        for(int j = 2; j < i; j++) {
            if(i % j == 0) {
                c = 0;
                break;
            }
        }
        if(c) {
            sum = sum+i;
        }
    }
    return sum;
}
int main() {
    int k=primesum(20);
    printf("%d ",k);
}