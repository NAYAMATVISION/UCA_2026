#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void bubbleSort(int arr[], int n)
{
   for(int i=0;i<n-1;i++){
      for(int j=0;j<n-i-1;j++){
         if(arr[j]>arr[j+1])
           {
            int t = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = t;
           }
        }
     }
}

void insertionSort(int arr[], int n)
{
    for(int i=1;i<n;i++){
        int key = arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key){ // Fixed logic to sort in ascending order
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

void selectionSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int min = i;
        for(int j=i+1;j<n;j++){
            if(arr[j] < arr[min]) min=j;
        }
        int t = arr[min];
        arr[min] = arr[i];
        arr[i]=t;
    }
}

int partition(int arr[] , int low , int high)
{
  int pivot = arr[high];
  int i = low-1;

   for(int j=low;j<high;j++)
   {
    if(arr[j]<pivot)
    {
     i++;
     int t = arr[i];
     arr[i] = arr[j];
     arr[j] = t;
     }
    }
   int t = arr[i+1];
   arr[i+1] = arr[high];
   arr[high] = t;
   return i + 1; // Fixed: Added missing return statement
}

void quickSort(int arr[], int low , int high)
{ 
   if(low<high)
   {
    int pi = partition(arr,low,high);

    quickSort(arr,low,pi-1);
    quickSort(arr,pi+1,high); // Fixed: Typo 'quicksort' and semicolon separator
   }
}

void merge(int arr[], int l , int m, int r)
{
  int n1=m-l+1;
  int n2 = r-m;
  
  int *L=malloc(n1*sizeof(int));
  int *R = malloc(n2*sizeof(int));
  
  for(int i=0;i<n1;i++)
    L[i] = arr[l+i];

  for(int j=0;j<n2;j++)
    R[j] = arr[m+1+j];

  int i=0,j=0,k=l;

  while(i<n1 && j<n2)
  {
    if(L[i] <= R[j])
      arr[k++] = L[i++];
    else 
      arr[k++] = R[j++];
  }
  while(i<n1)
     arr[k++] = L[i++]; // Fixed: Was copying from R using j++ incorrectly

  while(j<n2)
     arr[k++] = R[j++];

  free(L);
  free(R);
}

void mergeSort(int arr[], int l , int r)
{
  if(l<r)
  {
    int m = (l+r)/2;
    
    mergeSort(arr,l,m);
    mergeSort(arr,m+1,r);
    merge(arr,l,m,r); // Fixed: Changed from recursive mergeSort to merge function call
   }
}

void heapify(int arr[] , int n, int i)
{
   int largest = i;
   int l=2*i+1;
   int r=2*i+2;

   if(l<n && arr[l]>arr[largest])
      largest = l;

   if(r<n && arr[r] > arr[largest])
      largest = r;
   if(largest!=i)
   {
     int t=arr[i];
     arr[i] = arr[largest];
     arr[largest] = t;

     heapify(arr,n,largest);
   }
}

void heapSort(int arr[] , int n)
{
  for(int i=n/2-1;i>=0;i--)
     heapify(arr,n,i); // Fixed: Changed hardcoded 1 to variable loop index i

  for(int i=n-1;i>0;i--)
   {
     int t=arr[0];
     arr[0] = arr[i];
     arr[i] = t;
    
     heapify(arr,i,0);
   }
}

void randomArray(int arr[] , int n)
{
  for(int i=0;i<n;i++)
   arr[i] = rand();
}

void ascendingArray(int arr[] , int n)
{
  for(int i=0;i<n;i++)
      arr[i] = i;
}

void descendingArray(int arr[] , int n)
{
   for(int i=0;i<n;i++){
    arr[i] = n-i;
   }
}

double elapsed_ms(clock_t start , clock_t end)
{
   return ((double)(end-start))*1000/CLOCKS_PER_SEC; // Fixed: Typo in CLOCKS_PER_SEC
}

int main()
{
srand(time(NULL));
// Fixed: Expanded array to include 8 iterations as required by assignment steps
int sizes[] = {8000, 12000, 16000, 20000, 24000, 28000, 32000, 36000}; 
int num_sizes = sizeof(sizes) / sizeof(sizes[0]);

for(int s=0;s<num_sizes;s++){ // Fixed: Dynamically bounding loop instead of hardcoded error-prone limits
 int n=sizes[s];
 printf("\n=============================\nSize = %d\n=============================\n",n);
 for(int type=0;type<3;type++)
 {
   int *arr = malloc(n*sizeof(int));
   int *copy = malloc(n*sizeof(int));
   
   if(type==0){
    printf("\n--- Random Input ---\n");
    randomArray(arr,n);
   }
   else if(type==1){
    printf("\n--- Ascending Input ---\n");
    ascendingArray(arr,n);
   }
   else{
    printf("\n--- Descending Input ---\n");
    descendingArray(arr,n); // Fixed: Variable case casing typo ('Arr' to 'arr')
   }

   clock_t st, en; // Fixed: Variables declared once at block level to prevent redefinition errors

   memcpy(copy,arr,n*sizeof(int));
   st = clock();
   bubbleSort(copy,n);
   en = clock();
   printf("Bubble: %.2f ms\n",elapsed_ms(st,en)); // Fixed: Changed format from %.2s to %.2f

   memcpy(copy,arr,n*sizeof(int));
   st = clock();
   insertionSort(copy,n);
   en = clock();
   printf("InsertionSort: %.2f ms\n",elapsed_ms(st,en));
 
   memcpy(copy,arr,n*sizeof(int));
   st = clock();
   selectionSort(copy,n);
   en = clock();
   printf("Selection: %.2f ms\n",elapsed_ms(st,en));
  
   memcpy(copy,arr,n*sizeof(int));
   st = clock();
   quickSort(copy,0,n-1); // Fixed: Passed missing lower/upper index arguments
   en = clock();
   printf("Quick: %.2f ms\n",elapsed_ms(st,en));

   memcpy(copy,arr,n*sizeof(int));
   st = clock();
   mergeSort(copy,0,n-1); // Fixed: Passed missing lower/upper index arguments
   en = clock();
   printf("Merge: %.2f ms\n",elapsed_ms(st,en));

   memcpy(copy,arr,n*sizeof(int));
   st = clock();
   heapSort(copy,n);
   en = clock();
   printf("Heap: %.2f ms\n",elapsed_ms(st,en));

   free(arr);
   free(copy);
}
}
return 0;
}
