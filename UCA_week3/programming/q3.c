#include<stdio.h>
void smallerNumAfterSelf(int nums[] , int n){
     int answer[n] = {};
     int k = n-2;
     answer[n-1] = 0;
     int count = 0;
     for(int i=n-2 ; i>=0 ;i--){
         if(nums[i+1] < nums[i]){
           count++;
           answer[k--] = count;
         }
     }
     for(int j=0;j<n;j++){
       printf("%d\t" , answer[j]);
     }
}

int main(){
int nums[] = {5,2,6,1};
int n = 4;
smallerNumAfterSelf(nums , n);
return 0;
}
