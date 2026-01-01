#include "stdio.h"

// Adjacency Matrix representation of our graph.
  int graph[7][7] = {
  // 0 1 2 3 4 5 6
    {0,1,1,1,0,0,0}, // 0
    {1,0,1,0,0,0,0}, // 1
    {1,1,0,1,1,0,0}, // 2
    {1,0,1,0,1,0,0}, // 3
    {0,0,1,1,0,1,1}, // 4
    {0,0,0,0,1,0,0}, // 5
    {0,0,0,0,1,0,0}  // 6
};

int visited[7] = {0, 0, 0, 0, 0, 0, 0};//Array for storing visited nodes and initialized with 0 for all nodes are unvisited.

void DFS(int sNode){
  visited[sNode] = 1;
  printf("%d",sNode);
  for(int j = 0;j < 7; j++){
    if(graph[sNode][j] == 1 && !visited[j]){
      DFS(j);
    }
  }
}


int main(void) {
  

int sNode = 5;//Source Node
DFS(sNode);
  

return 0;
}
