#include<stdio.h>
#include<string.h>
void reverse_string(char str[]){
   int start=0;
   int end = strlen(str) - 1;
   while(start < end){
     char temp =  str[start];
     str[start] = str[end];
     str[end] = temp;
    start++;
    end--;
   }
    printf("%s",str);
   
}
int main(){
   char input[] = "Data Structures";
   reverse_string(input);
    
    return 0;
}
