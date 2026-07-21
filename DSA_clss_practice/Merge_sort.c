#include<stdio.h>
void merge(int arr[] , int low ,  int mid ,int high){
    int temp[high - low + 1] = {};
    int left = low;
    int right = mid+1;
    int k=0;
    while(left <= mid && right <= high) {
       if(arr[left] <= arr[right]) {
            temp[k++] = arr[left];
            left++;
         }
       else {
           temp[k++] = arr[right];
           right++;
         }
    }
   while(left <= mid){
      temp[k++] = arr[left];
      left++;
    }
   while(right <= high){
      temp[k++] = arr[right];
      right++;
   }
   for(int i=low ; i<=high ; i++){
      arr[i] = temp[i-low];
   }

}
void mergeSort(int arr[] , int low , int high){
    int mid = (low+high)/2;
    if(low==high) return;
    mergeSort(arr , low , mid);
    mergeSort(arr , mid+1 , high);
    merge(arr , low , mid , high);
}

int main(){
   int arr[] = {3,1,2,4,1,5,2,6,4};
   int size = sizeof(arr)/sizeof(arr[0]);
   mergeSort(arr , 0 , size-1);
   for(int i=0;i<size;i++){
     printf("%d\t" , arr[i] );
   }
return 0;
}
