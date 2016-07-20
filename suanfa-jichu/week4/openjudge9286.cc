#include <iostream>
#include <string.h>

using namespace std;


long long dp[50][50][50]; // 第 i 个袋子里 放 j 个 球 还剩下 k 个球

int C[200][200];

int CC(int n, int m) {
  return C[n][m];
}


int main() {
//  freopen("acm.in", "r", stdin);
  int n, m, k;
  for(int i = 0; i < 16; i++) {
    C[i][0] = C[i][i] = 1;
  }
  for(int i = 2; i < 16; i++) {
    for(int j = 1; j < i; j++) {
      C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
    }
  }
  while(scanf("%d%d%d", &n, &m, &k)) {
    if(!n && !m && !k)
      return 0;
    dp[0][0][1] = 1;
    memset(dp, 0, sizeof(dp));
    for(int i = k; i <= n ; i++) {
      dp[1][i][n - i] = CC(n, i); 
    }
    for(int i = 1; i < m; i++) {
      for(int j = k; j <= n; j++) { // 保证第 i 个满足要求
        for(int kk = k; kk <= n; kk++) { // 剩余数量
          for(int t = 0; t <= kk; t++) { // 下一个放置几个
            dp[i + 1][t][kk - t] += dp[i][j][kk] * CC(kk, t);
          }
        }
      }
    }
    long long res = 0;
    for(int j = k; j <= n; j++) {
      res += dp[m][j][0];
    }
    printf("%lld\n", res);
  }
  return 0;
}
