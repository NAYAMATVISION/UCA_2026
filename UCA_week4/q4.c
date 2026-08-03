#include<stdio.h>
int sign(int x) {
    return (x >> 31) | (!!x);
}
int main(){
   int x = 12;
   int ans = sign;
   printf("%d",ans);
}
