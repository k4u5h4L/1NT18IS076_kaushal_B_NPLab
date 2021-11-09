#include<stdio.h>

struct node {
  unsigned dist[20];
  unsigned from[20];
}table[10];

int main() {
  int dmat[20][20];
  int n, i, j, k, count = 0;

  printf("\nEnter the number of nodes: ");
  scanf("%d", & n);
  
  printf("\nEnter the cost matrix:\n");
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++) {
      scanf("%d", & dmat[i][j]);
      dmat[i][i] = 0;
      table[i].dist[j] = dmat[i][j];
      table[i].from[j] = j;
    }

  do {
    count = 0;
    for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
        for (k = 0; k < n; k++) {
          if (table[i].dist[j] > dmat[i][k] + table[k].dist[j]) {
            table[i].dist[j] = table[i].dist[k] + table[k].dist[j];
            table[i].from[j] = k;
            count++;
          }
        }
      }
    }
  } while (count != 0);

  for (i = 0; i < n; i++) {
    printf("\n\nState value for router %d is \n", i + 1);
    printf("\nNode \t Via \t Distance ");
    for (j = 0; j < n; j++) {
      printf("\n%d \t %d \t %d ", j + 1, table[i].from[j] + 1, table[i].dist[j]);
    }
  }
  printf("\n\n");
}
