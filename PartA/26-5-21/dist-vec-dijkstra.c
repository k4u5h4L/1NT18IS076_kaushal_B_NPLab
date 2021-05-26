#include<stdio.h>

int main() {
  int count, src_router, i, j, k, l, w, v, min;
  int adj[100][100], dist[100]; 
  int flag[100];

  // scan number of routers
  printf("Enter no of routers:\n");
  scanf("%d", &count);

  // scan cost/adjacency matrix
  printf("Enter cost/adjacency matrix values:\n");
  for (i = 0; i < count; i++) {
    for (j = 0; j < count; j++) {
      printf("\n %d ---> %d : ", i, j);
      scanf("%d", &adj[i][j]);
      if (adj[i][j] < 0)
        adj[i][j] = 999;
    }
  }

  // scan source node
//   printf("Enter source node:\n");
//   scanf("%d", & src_router);

  for (l = 0; l < count; l++) {
      src_router = l;
    // initialise flag and distance array
    for (v = 0; v < count; v++) {
        flag[v] = 0;
        dist[v] = adj[src_router][v];
    }

    // compute shortest path
    flag[src_router] = 1;
    for (i = 0; i < count; i++) {
        min = 999;
        // compute minimum distance
        for (w = 0; w < count; w++) {
        if (!flag[w])
            if (dist[w] < min) {
            v = w;
            min = dist[w];
            }
        }

        flag[v] = 1;
        for (w = 0; w < count; w++) {
        if (!flag[w])
            if (min + adj[v][w] < dist[w]) {
              dist[w] = min + adj[v][w];
            }
        }
    }

    printf("\n\n--------------- Routing for Node %d ---------------\n", l);

    // print distance values
    for (i = 0; i < count; i++) {
        printf("\n%d -----> %d", src_router, i);
        w = i;
        printf("\n Shortest path cost = %d\n", dist[i]);
    }
  }
}
