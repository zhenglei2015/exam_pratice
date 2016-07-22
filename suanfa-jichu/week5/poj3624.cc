#include <iostream>
#include <stdio.h>

using namespace std;


int n,m;
int w[100000];
int d[100000];
int r[100000];

int main() {
  freopen("acm.in", "r", stdin);
  scanf("%d%d", &n, &m);
  for(int i = 0; i < n; i++) {
    scanf("%d%d", &w[i], &d[i]);
  }
  for(int i = 0; i < n; i++) {
    for(int j = m; j > 0; j--) {
      if(j >= w[i]) {
        int t= r[j - w[i]] + d[i];
        r[j] = t > r[j] ? t : r[j];
      }
    }
  }
  int res = -1;
  for(int i = 0;i <= m; i++) 
    res = res > r[i] ? res : r[i];
  printf("%d\n", res);
}
