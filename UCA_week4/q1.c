#include<stdio.h>
// AND using OR and ~
int bitAnd(int A, int B){
   return ~((~A) | (~B));
}
int main(){
   int A = 5;
   int B = 6;
   int C = bitAnd(A,B);
   printf("%d" , C);
return 0 ;
}
