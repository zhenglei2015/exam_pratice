#include <stdio.h>
#include <queue>
#include <cmath>
#include <vector>
using namespace std;
vector<int> G[10000];
int color[10000];
int pa[10000];
int d[10000];
int n;
int s;
#define MAX 0x3f3f3f3f
#define WHITE 0
#define GRAY 1
#define BLACK 2
void bfs() {
  for(int i = 0; i < n; i++) {
    color[i] = WHITE;// WHITE
    d[i] = MAX;
    pa[i] = -1;
  }
  color[s] = GRAY;// GRAY
  d[s] = 0;
  pa[s] = -1;
  queue<int> q;
  q.push(s);
  while(!q.empty()) {
    int u = q.front();
    q.pop();
    for(int i = 0; i < G[u].size(); i++) {
      if(color[G[u][i]] == WHITE) {
        int v = G[u][i];
        color[v] = GRAY;
        d[v] = d[u] + 1;
        pa[v] = u;
        q.push(v);
      }
    }
    color[u] = BLACK;
  }
}


int main() {

}

