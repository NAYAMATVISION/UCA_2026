#include<stdio.h>
#include<stdbool.h>
void setMatrixZeroes(int m , int n , int arr[m][n]){
    bool isRowZero = false;
    bool isColZero = false;

    for(int i=0;i<n;i++){
        if(arr[0][i] == 0) {
            isRowZero = true;
            break;
         } 
      }

     for(int j=0;j<m;j++){
        if(arr[j][0]==0) {
           isColZero = true;
           break;
         }
      }

      for(int i = 1 ; i < m ; i++){
          for(int j = 1 ; j < n ; j++){
             if(arr[i][j] == 0){
                  arr[0][j] = 0;
                  arr[i][0] = 0;
             }
         }
      }

      for(int i = 1 ; i < m ; i++){
          for(int j = 1 ; j < n ; j++){
             if(arr[0][j] == 0 || arr[i][0] == 0){
                  arr[i][j] = 0;
              }
          }
       }

      if(isRowZero){
         for(int i = 0 ; i < n ; i++){
            arr[0][i] = 0;
          }
       }

      if(isColZero){
         for(int j = 0 ; j < m ; j++){
             arr[j][0] = 0;
         }
      }
}
int main(){
int m = 3;
int n = 3;
int arr[3][3] = {{1,1,1},{1,0,1},{1,1,1}};


setMatrixZeroes(m , n , arr);
for(int i = 0; i<m ; i++){
   for(int j=0;j<n;j++){
       printf("%d", arr[i][j]);
   }
   printf("\n");
}
return 0;
}
