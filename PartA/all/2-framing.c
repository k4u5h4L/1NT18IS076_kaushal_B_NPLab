// Design and Implement C program in which sender module should count the number of bytes in the frame and
// receiver module should display each frame received.

#include <stdio.h> 
#include <string.h> 

void sender(char message[], int counts[]) { 
    int n, i; 
    char frame[100],l[100]; 
    printf("Enter the number of frames\n"); 
    scanf("%d", &n); 
    for (i = 0; i < n; i++) { 
        printf("Enter the frame %d\n", i + 1); 
        scanf("%s", &frame); 
        strcat(message, frame);
        printf("Size of the frame entered: %d\n", strlen(frame));
        counts[i] = strlen(frame); // should be 8
    } 
    // printf("Number of bytes in the frame: %d\n", strlen(message) / 8);
    printf("\n\nThe final message transmitted is %s\n", message);
}

void reciever(char message[], int counts[]) { 
    int i, j, count = 1; 
    int flag = 1;
    printf("\nReceived frames are: \n"); 
    for (i = 0; i < strlen(message); i++) { 
        if (i % 8 == 0) {
            // assuming the frame length is 1
            printf("\n\n");
            printf("Frame %d:\n", count++);
        }
        
        printf("%c", message[i]);
    } 
}

void main() { 
    char message[100];
    int counts[100];

    sender(message, counts);
    reciever(message, counts);
}
