#include<stdio.h>
#include<stdbool.h>
void lru_implementation(int requests[] , int num_requests , int num_frames){
     
     int frames[num_frames];
     int last_used[num_frames];
     int pageFaults = 0;

     for(int i=0 ; i<num_frames ; i++){
         
        frames[i] = -1;
        last_used[i] = -1;
     } 

      for(int i=0; i<num_requests;i++){
         int page = requests[i];
         bool hit = false;

         for(int j=0 ; j<num_frames ;j++){
            
            if(frames[j] == page){
               hit = true;
               last_used[j] = i;
               break;
             }
         }

         if(!hit)
         {
            pageFaults++;

            int frame_index = -1;

            for(int i=0; i<num_frames;i++){
               
               if(frames[i] == -1){
                  frame_index = i;
                  break;
                }
            }

            if(frame_index == -1){
               frame_index = 0;
              
               for(int i=1 ; i<num_frames;i++){
                  
                  if(last_used[i] < last_used[frame_index]){
                        
                      frame_index = i;
                   }
               }
             }

             frames[frame_index] = page;
             last_used[frame_index] = i;
          }

       printf("Request %d: %s | RAM: [",
               page, hit ? "HIT" : "FAULT");

        for (int i = 0; i < num_frames; i++)
        {
            if (frames[i] == -1)
                printf("-");
            else
                printf("%d", frames[i]);

            if (i < num_frames - 1)
                printf(", ");
        }

        printf("]\n");
    }

    printf("\nTotal Page Faults: %d\n", pageFaults);
}
int main()
{
    int requests[] = {1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5};

    int num_requests = sizeof(requests) / sizeof(requests[0]);

    int num_frames = 3;

    lru_implementation(requests, num_requests, num_frames);

    return 0;
}
