#include<stdio.h>
#include<stdlib.h>

#define MIN(x, y)(x > y) ? y : x

int main() {
  int orate, drop = 0, cap, x, count = 0, inp[10] = {0}, i = 0, nsec, ch;

  printf("\n Enter bucket size: ");
  scanf("%d", &cap);

  printf("\n Enter output rate: ");
  scanf("%d", &orate);

  do {
    printf("\n Enter number of packets coming at a given second %d: ", i + 1);
    scanf("%d", & inp[i]);

    if (inp[i] > cap) {
      printf("Bucket overflow\n");
      printf("Packet Discarded from the Bucket\n");
      exit(0);
    }

    i++;

    printf("\n Enter 1 to contiue or 0 to quit: ");
    scanf("%d", &ch);

  } while (ch);

  nsec = i;
  printf("\n Second \tRecieved \tSent  \tDropped Data\tRemaining Data \n");

  for (i = 0; count || i < nsec; i++) {
    printf(" %d", i + 1);
    printf(" \t\t%d\t ", inp[i]);
    printf(" \t%d\t ", MIN((inp[i] + count), orate));

    if ((x = inp[i] + count - orate) > 0) {
      if (x > cap) {
        count = cap;
        drop = x - cap;
      } else {
        count = x;
        drop = 0;
      }
    } else {
      drop = 0;
      count = 0;
    }

    printf(" \t %d \t %d \n", drop, count);
  }

  return 0;
}
