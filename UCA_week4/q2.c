#include<stdio.h>
int bitXor(int a , int b){
    int x = ~a & b;
    int y = a & (~b);
    return ~(~x & (~y));
}
int main(){
   int a = 5;
   int b = 4;
   int c = bitXor(a,b);
   printf("%d" , c);
}
