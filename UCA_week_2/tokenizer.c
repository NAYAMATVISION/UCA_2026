#include<stdio.h>
#include<string.h>

int main(){
      char str[] = "C,C++,Java,Python,Rust";
      const char *delimiter = ",";
      

      char* token = strtok(str,delimiter);

      while(token!=NULL){
            printf("%s\n" , token);
            token = strtok(NULL,delimiter);


    

}
return 0;
}
