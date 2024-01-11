#include <stdio.h>

#define MAX_M 500

typedef struct
{
  int u, v;
} Edge;

typedef struct
{
  int n, m;
  Edge edges[MAX_M];
} Graph;

void init_graph(Graph *pG, int n)
{
  pG->n = n;
  pG->m = 0;
}

void add_edge(Graph *pG, int u, int v)
{
  Edge e = {u, v};
  pG->edges[pG->m++] = e;
}

int main()
{
  Graph G;
  init_graph(&G, 3);
  add_edge(&G, 1, 3);
  add_edge(&G, 2, 3);
  add_edge(&G, 2, 2);
  return 0;
}