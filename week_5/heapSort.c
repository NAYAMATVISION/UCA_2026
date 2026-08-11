#include<stdio.h>
void heapify(int arr[] , int n , int i){
    int largest = i;
    int left = i*2+1;
    int right = i*2+2;

    if(left < n && arr[left] > arr[largest]){
        largest = left;
     }
     if(right < n && arr[right] > arr[largest]){
        largest = right;
      }
     if(largest != i){
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
       
        heapify(arr , n , largest);
      }
}
void heapSort(int arr[] , int n){
     
      int size = n-1;

 
     while(size > 0){ 
      int temp = arr[0];
      arr[0] = arr[size];
      arr[size] = temp;

      size--;

       heapify(arr,size+1,0);
}
}

int main(){
    int arr[] = {50,55,53,52,54};
    int n = 5;

     for(int i = n/2-1 ; i>=0 ; i--){
        heapify(arr , n , i);
     }

     heapSort(arr,n);
     for(int i=0;i<n;i++){
       printf("%d\t",arr[i]);
    }
return 0;
}
