#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<time.h>
int main(int argc , char* argv[]){
    struct stat info;
    
    if(argc!=2){
      printf("Usage: %s <file_path>\n" , argv[0]);
      return 1;
    }

    if(stat(argv[1] , &info) == -1){
      perror("stat");
      return 1;
    }

    printf("=== File Attributes for: %s ===\n", argv[1]);


    printf("file type:          ");
    if(S_ISREG(info.st_mode)){
      printf("Regular File\n");
    }
    else if (S_ISDIR(info.st_mode))
        printf("Directory\n");
    else if (S_ISLNK(info.st_mode))
        printf("Symbolic Link\n");
    else if (S_ISCHR(info.st_mode))
        printf("Character Device\n");
    else if (S_ISBLK(info.st_mode))
        printf("Block Device\n");
    else if (S_ISFIFO(info.st_mode))
        printf("FIFO (Named Pipe)\n");
    else if (S_ISSOCK(info.st_mode))
        printf("Socket\n");
    else
        printf("Unknown\n");



    printf("Permissions:           %04o\n" ,info.st_mode & 0777);
    printf("File Size:            %ld bytes\n", info.st_size);
    printf("Hard Links Count:     %ld\n", info.st_nlink);
    printf("Owner (UID):          %d\n", info.st_uid);
    printf("Group (GID):          %d\n", info.st_gid);


    printf("Last Access Time:     %s", ctime(&info.st_atime));
    printf("Last Modification:    %s", ctime(&info.st_mtime));
    printf("Status Change Time:   %s", ctime(&info.st_ctime));

return 0;
}
