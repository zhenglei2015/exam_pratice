#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;

#define MAX 0x3f3f3f3f

int board[100][100];
int n;

int test(int state) {
  int press[100][100];
  for(int i = 0; i < 100; i++)
    for(int j = 0; j < 100; j++)
      press[i][j] = 0;
  int res = 0;
  for(int i = 0; i < n; i++) {
    press[1][i + 1] = (1) & (state >> i);
    res += (1 & (state >> i));
  }
  for(int i = 2; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      if((board[i - 1][j] + press[i - 2][j] +  press[i - 1][j] + press[i - 1][j - 1] + press[i - 1][j + 1]) % 2 == 1) {
        press[i][j] = 0;
      } else {
        press[i][j] = 1;
        res++;
      }
    }
  }
  for(int i = 1; i <= n; i++) {
    if((press[n][i - 1] + press[n][i] + press[n][i + 1] + press[n - 1][i] + board[n][i]) % 2 == 0)
      return MAX;
  }
  return res;
}

int main() {
  freopen("acm.in", "r", stdin);
  int cas;
  scanf("%d", &cas);
  for(int ca = 0; ca < cas; ca++) {
    scanf("%d", &n);
    for(int i = 0; i < 100; i++) {
      for(int j = 0; j < 100; j++) {
        board[i][j] = 0;
      }
    }
    for(int i = 1; i <= n; i++) {
      char ss[100];
      scanf("%s" , ss);
      for(int j = 1; j <= n; j++)
        board[i][j] = (ss[j - 1] == 'y');
    }
    int res = MAX;
    for(int i = 0; i < (1<<n); i++) {
      int temp = test(i);
      res = res > temp ? temp : res;
    }
    if(res == MAX)
      printf("inf\n");
    else
      printf("%d\n", res);
  }
  return 0;
}
