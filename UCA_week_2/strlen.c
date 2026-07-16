#include<stdio.h>
#include<string.h>
int myStrLen(const char * str){
   int length = 0;
   while(str[length] != '\0'){
       length++;
   }
  return length;
}

int main(){
char  mystr[] =  "Nayamat e meet Mittal";
int totalLength = myStrLen(mystr);
printf("%d\n", totalLength);
return 0;
}
