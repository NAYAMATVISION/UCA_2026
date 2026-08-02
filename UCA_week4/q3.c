#include<stdio.h>
int fitsBits(int x, int n) {
    int shift = 32 + (~n + 1);   // 32 - n
    return !((((x << shift) >> shift) ^ x));
}
int main(){
   int x = 5;
   int n = 4;
   int ans = fitsBits(x,n);
   printf("%d" , ans);
}
