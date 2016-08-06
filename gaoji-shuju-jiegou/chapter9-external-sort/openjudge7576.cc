#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

int num[100000];
int pos[100000];
int tree[100000];
int n, m;


int build(int i) {
  if(i > n + n)
    return 0x3f3f3f3f;
  if(i > n)
    return num[i - n];
  int l = build(i * 2);
  int r = build(i * 2 + 1);
  int m = l < r ? l : r;
  int M = l < r ? r : l;
  tree[i] = M;
  return m;
}

int main() {
  freopen("acm.in", "r", stdin);
  scanf("%d%d", &n, &m);

  queue<int> q;
  for(int i = 1; i <= n; i++) {
    scanf("%d", &num[i]);
    q.push(num[i]);
  }
  for(int i = n; i > 0; i--) {
    int a = q.front();
    q.pop();
    int b = q.front();
    q.pop();
    if(a > b) {
      tree[i] = a;
      q.push(b);
    } else {
      tree[i] = b;
      q.push(a);
    }
  }
  for(int i = 0; i < n; i++)
    printf("%d ", tree[i]);
  printf("\n");
  for(int i = 0; i < m; i++) {
    int j, nu;
    scanf("%d%d", &j, &nu);
    num[j] = nu;
  }
}
