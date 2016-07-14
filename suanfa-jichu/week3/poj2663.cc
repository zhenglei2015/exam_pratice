#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;


int dp[100][8];

int num(int n, int state) {
  if(dp[n][state] != -1)
    return dp[n][state];
  int res = 0;
  switch(state) {
    case 0:
      res = num(n - 1, 7);
      break;
    case 1:
      res = num(n - 1, 6);
      break;
    case 2:
      res = num(n - 1, 5);
      break;
    case 3:
      res = num(n - 1, 4) + num(n, 0);
      break;
    case 4:
      res = num(n - 1, 3);
      break;
    case 5:
      res = num(n - 1, 2);
      break;
    case 6:
      res = num(n - 1, 1) + num(n, 0);
      break;
    case 7:
      res = num(n, 1) + num(n, 4) + num(n - 1, 0);
      break;
  }
  dp[n][state] = res;
  return res;
}

int main() {
  for(int i = 0; i < 40; i++)
    for(int j = 0; j < 8; j++)
      dp[i][j] = -1;
  for(int i = 0; i < 8; i++)
    dp[0][i] = 0;
  dp[0][7] = 1;
  int n;
  while(scanf("%d", &n)){
    if(n == -1)
      break;
    printf("%d\n", num(n, 7));
  }
}
