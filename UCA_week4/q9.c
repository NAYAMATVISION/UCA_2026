#include<stdio.h>
int isPower2(int x) {
    int sign = (x >> 31) & 1;
    int nonZero = !!x;
    int singleBit = !(x & (x + ~0));   // x & (x - 1)
    return (!sign) & nonZero & singleBit;
}
int main(){
  int x = 8;
  int y = 5;
  int ans1 = isPower2(x);
  int ans2 = isPower2(y);
  printf("%d\n" , ans1);
  printf("%d\n" , ans2);
return 0;
}
