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

int degree(Graph *pG, int u)
{
  int deg = 0, i;
  for (i = 0; i < pG->m; i++)
  {
    Edge ei = pG->edges[i];
    if (u == ei.u || u == ei.v)
      deg++;
    if (u == ei.u && u == ei.v)
      deg++;
  }
  return deg;
}

int main()
{
  Graph G;
  int n = 4, u;

  init_graph(&G, n);
  add_edge(&G, 1, 2);
  add_edge(&G, 1, 3);
  add_edge(&G, 1, 3);
  add_edge(&G, 3, 4);
  add_edge(&G, 1, 4);

  for (u = 1; u <= n; u++)
    printf("deg(%d) = %d\n", u, degree(&G, u));
  return 0;
}