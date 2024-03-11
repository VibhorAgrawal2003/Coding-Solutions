#include <iostream>
#include <vector>

using namespace std;

struct node {
  char name;
  int wt;
};

struct edge {
  node *src;
  node *dest;
  int wt;
};

struct graph {
  int V;
  int E;
  edge *edges;
};

graph *createGraph(int V, int E) {
  graph *G = new graph;
  G->V = V;
  G->E = E;
  G->edges = new edge[E];
  return G;
}

void showNodes(vector<node *> nodeV) {
  for (int i = 0; i < (int)nodeV.size(); i++) {
    cout << nodeV[i]->name << " : " << nodeV[i]->wt << "\n";
  }
}

void showMatrix(vector<vector<int>> matrix) {
  for (auto x : matrix) {
    for (auto y : x) {
      cout << y << " ";
    }
    cout << "\n";
  }
}

void bellmanFord(graph *G, vector<node *> nodeV) {

  vector<vector<int>> distanceArr{};
  vector<vector<char>> piArr{};

  vector<int> piRow{};
  for (int i = 0; i < G->V; i++) {
    piRow.push_back(i);
  }

  for (int count = 0; count < G->E - 1; count++) {

    for (int i = 0; i < G->E; i++) {
      int originalWt = G->edges[i].dest->wt;
      int newWt = G->edges[i].src->wt + G->edges[i].wt;
      G->edges[i].dest->wt = min(originalWt, newWt);

      // Update pi row
        }

    // Build distance array
    vector<int> row{};
    for (auto nodePtr : nodeV) {
      row.push_back(nodePtr->wt);
    }
    distanceArr.push_back(row);
  }

  showMatrix(distanceArr);
}

int main() {

  int V = 5;
  int E = 8;
  graph *G = createGraph(V, E);

  // Vertices

  node *s = new node;
  s->name = 's';
  s->wt = 0;

  node *t = new node;
  t->name = 't';
  t->wt = INT_MAX;

  node *x = new node;
  x->name = 'x';
  x->wt = INT_MAX;

  node *y = new node;
  y->name = 'y';
  y->wt = INT_MAX;

  node *z = new node;
  z->name = 'z';
  z->wt = INT_MAX;

  vector<node *> nodeV{s, t, x, y, z};

  // Edges

  G->edges[0].src = s;
  G->edges[0].dest = t;
  G->edges[0].wt = 6;

  G->edges[1].src = s;
  G->edges[1].dest = y;
  G->edges[1].wt = 7;

  G->edges[2].src = t;
  G->edges[2].dest = x;
  G->edges[2].wt = 5;

  G->edges[3].src = t;
  G->edges[3].dest = y;
  G->edges[3].wt = 8;

  G->edges[4].src = t;
  G->edges[4].dest = z;
  G->edges[4].wt = -4;

  G->edges[5].src = x;
  G->edges[5].dest = t;
  G->edges[5].wt = -2;

  G->edges[6].src = y;
  G->edges[6].dest = x;
  G->edges[6].wt = -3;

  G->edges[7].src = y;
  G->edges[7].dest = z;
  G->edges[7].wt = 9;

  G->edges[8].src = z;
  G->edges[8].dest = s;
  G->edges[8].wt = 2;

  G->edges[9].src = z;
  G->edges[9].dest = x;
  G->edges[9].wt = 7;

  //   showNodes(nodeV);
  bellmanFord(G, nodeV);

  return 0;
}