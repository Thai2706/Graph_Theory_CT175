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

int adjacent(Graph *pG, int u, int v)
{
  int i;
  for (i = 0; i < pG->m; i++)
  {
    Edge ei = pG->edges[i];
    if ((u == ei.u && v == ei.v))
      return 1;
  }
  return 0;
}

int main()
{
  Graph G;
  int n, m, i, u, v;
  scanf("%d%d", &n, &m);
  init_graph(&G, n);
  for (i = 0; i < m; i++)
  {
    scanf("%d%d", &u, &v);
    add_edge(&G, u, v);
  }

  for (u = 1; u <= n; u++)
  {
    printf("neighbours(%d) =", u);
    for (v = 1; v <= n; v++)
    {
      if (adjacent(&G, u, v))
        printf(" %d", v);
    }
    printf("\n");
  }

  return 0;
}