#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

long long dp[250][250];

long long dfs(int num, int start) {
  if(num == 0)
    return 1;
  if(num < start)
    return 0;
  if(dp[num][start] != -1)
    return dp[num][start];
  long long res = 0;
  // 继续分
  for(int i = start; i < num; i++) {
    res += dfs(num - 2 * i, i); 
  }
  // 不继续分了
  res++;
  dp[num][start] = res;
  return res;
}

int main() {
  freopen("acm.in", "r", stdin);
  memset(dp, -1, sizeof(dp));
  int n;
  while(scanf("%d", &n)) {
    if(n == 0)
      break;
    printf("%d %lld\n", n, dfs(n, 1));
  }
  for(int i = 0; i < 10; i++) {
    for(int j = 0; j < 10; j++) {
    }
  }
  return 0;
}
