#include<stdio.h>
int logicalShift(int x, int n) {
    int mask = ~(((1 << 31) >> n) << 1);
    return (x >> n) & mask;
}
int main(){
   int x = 87654321;
   int n = 4;
   int ans = logicalShift(x,n);
   printf("%d" , ans);
}


