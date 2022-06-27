#include <stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define M 6
#define N 6

bool bipartiteGraph[M][N]; 
bool bipartiteMax(int u, bool visited[], int a[]) {
   for (int v = 0; v < N; v++) {
      if (bipartiteGraph[u][v] && !visited[v]) {
         visited[v] = true;

         if (a[v] < 0 || bipartiteMax(a[v], visited, a)) {
            a[v] = u;
            return true;
         }
      }
   }
   return false;
}

int maxMatch() {
   int a[N];
   for(int i = 0; i<N; i++)
      a[i] = -1;
   int Count = 0;

   for (int u = 0; u < M; u++) {
      bool visited[N];
      for(int i = 0; i<N; i++)
         visited[i] = false;
      if (bipartiteMax(u, visited, a))
         Count++;
   }
   return Count;
}

int main() {
    printf("Enter the matrix: ");
    int i,j;
    int graph[M][N];
    for(i=0;i<M;i++)
    {
        for(j=0;j<N;j++)
        {
        scanf("%d",&graph[i][j]);
        bipartiteGraph[i][j]=graph[i][j];
        }
    }
    printf("Maximum number of applicants matching for a particular job: %d ",maxMatch());
}