#include <iostream>
#include <string.h>

using namespace std;

struct point {
  int x, y;
  int count;
};


int comp(const void *a, const void *b) {
  int ca = ((point*)a)->count;
  int cb = ((point*)b)->count;
  return ca - cb;
}

int T;

int board[100][100];

int main() {
  scanf("%d", &T);
  for(int cas = 1; cas <= T; cas++) {
    int n,m,k;
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 1; i <= n; i++) {
      for(int j = 1; j <= m; j++) {
        scanf("%d", &board[i][j]);
      }
    }
    
  }
}
