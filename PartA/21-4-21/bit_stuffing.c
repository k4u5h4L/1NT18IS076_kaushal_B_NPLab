#include <stdio.h>
#include <string.h>

#define SIZE 50

void main() {
    int count = 0, nl, i, j;
    char frame[SIZE];
    
    
    printf("Enter the string: \n");
    scanf("%s", &frame);
    
    for (i = 0; i < strlen(frame); i++) {
        count = 0;
        for (j = i; j <= (i + 5); j++){
            if (frame[j] == '1'){
                count++;
            }
        }
        
        if( count == 6){
            nl = strlen(frame) + 2;
          
			for (;nl >= (i + 5); nl--) {
				frame[nl] = frame[nl - 1];
			}
			frame[i + 5] = '0';
			i = i + 7;
        }
    }
    
    printf("\nStuffed string is: \n");
    for (i = 0;i < strlen(frame); i++)
        printf("%c", frame[i]);

}
