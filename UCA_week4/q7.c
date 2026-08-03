#include<stdio.h>

int bang(int x) {
    return ((x | (~x + 1)) >> 31) + 1;
}
int main(){
  int x = 3;
  int ans = bang(x);
  printf("%d", ans);
return 0;
}
