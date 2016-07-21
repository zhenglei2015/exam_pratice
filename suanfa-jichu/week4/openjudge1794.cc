#include <iostream>
#include <string.h>

using namespace std;


int a[20000], b[20000];

int main() {
  int cas;
  freopen("acm.in", "r", stdin);
  scanf("%d", &cas);
  for(int T = 1; T <= cas; T++) {
    int tar;
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    scanf("%d", &tar);
    int na, nb;
    scanf("%d", &na);
    for(int i = 0; i < na; i++) {
      int t;
      scanf("%d", &t);
      a[t]++;
    }
    scanf("%d", &nb);
    for(int i = 0; i < nb; i++) {
      int t;
      scanf("%d", &t);
      b[t]++;
    }
    int cnt = 0; 
    for(int i = 1; i < tar; i++) {
      cnt += (a[i] * b[tar - i]);
    }
    printf("%d\n", cnt);
  }
  return 0;
}
