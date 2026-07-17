#include<stdio.h>
#include<string.h>
void url_encoder(char *str , int length){
   int space_count = 0;
   for(int i=0;i<length;i++){
      if(str[i]==' ') space_count++;
   }
   int new_length = length + space_count*2;
   int i=length-1;
   int j = new_length - 1;
   while(i>=0){
    if(str[i]!=' '){
       str[j] = str[i];
       i--;
       j--;
    }
    else{
     str[j] = '0';
     str[j-1]= '2';
     str[j-2]= '%';
     i--;
     j=j-3;
    }
  }
}
int main(){
    char str[30] = "hello world ";
    url_encoder(str,12);
    printf("%s\n",str);
return 0;
}  
