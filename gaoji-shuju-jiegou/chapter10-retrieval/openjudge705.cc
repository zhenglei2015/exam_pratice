#include <stdio.h>
#include <string.h>


int rank[200000];
int pre[200000];

void init() {
  for(int i = 0;i < 200000; i++) {
    rank[i] = 0;
    pre[i] = i;
  }
}

int find(int x) {
  if(x == pre[x]) {
    return x;
  }
  int fa = find(pre[x]);
  rank[x] = (rank[x] + rank[pre[x]]) % 2; 
  // 注意rank只能由本节点和上一层父节点决定不是最终父节点
  // 当有合并的时候会根据节点与原父节点关系以及原父节点与新父节点关系确定自己的新关系
  pre[x] = fa;
  return fa;
}

void join(int a, int b) { // 只有 a 和 b 不同这一种关系
  int fa = find(a);
  int fb = find(b);
  if(fa == fb)
    return;
  // 这个地方根据子节点之间的关系判断这两个父节点之间的关系
  if(rank[a] + rank[b] != 1)
    rank[fb] = !rank[fb];
  pre[fb] = fa;
}

int main() {
  freopen("acm.in", "r", stdin);
  int T;
  scanf("%d", &T);
  int n, m;
  for(int cas = 1; cas <= T; cas++) {
    init();
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++) {
    char op[100];
    int a, b;
    scanf("%s%d%d", op, &a, &b);
    if(op[0] == 'D') {
      join(a, b);
    }
    if(op[0] == 'A') {
      if(find(a) != find(b))      
        printf("Not sure yet.\n");
      else if(rank[a] != rank[b])
        printf("In different gangs.\n");
      else 
        printf("In the same gang.\n");
    }
    }
  }    
  return 0;
}
