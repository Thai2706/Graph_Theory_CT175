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
  int n, m, i, u, v;
  FILE *fin = fopen("dt.txt", "r");
  fscanf(fin, "%d%d", &n, &m);
  init_graph(&G, n);
  for (i = 0; i < m; i++)
  {
    fscanf(fin, "%d%d", &u, &v);
    add_edge(&G, u, v);
  }

  for (u = 1; u <= n; u++)
    printf("deg(%d) = %d\n", u, degree(&G, u));
  return 0;
}