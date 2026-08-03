#include<stdio.h>

int getByte(int x, int n) {
    return (x >> (n << 3)) & 0xFF;
}

int main(){
 int x = 0x12345678;
 int n=2;
 int ans = getByte(x,n);
 printf("%d" , ans);
 return 0;
}
