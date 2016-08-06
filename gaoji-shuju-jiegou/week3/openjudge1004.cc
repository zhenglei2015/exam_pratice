#include <iostream>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;



vector<int> pos[50000]; // 一维横坐标 里面是纵坐标

int x[2000];
int y[2000];

// 枚举正方形最上面的边

int main() {
  int n;
  freopen("acm.in", "r", stdin);
  while(scanf("%d", &n)) {

    if(n == 0)
      break;
    
    for(int i = 0; i < 50000; i++)
      pos[i].clear();
    
    for(int i = 0; i < n; i++) {
      scanf("%d%d", &x[i], &y[i]);
      pos[x[i] + 20000].push_back(y[i]);
    }
    
    for(int i = 0; i < 50000; i++) {
      if(pos[i].size() > 0)
        sort(pos[i].begin(), pos[i].end());
    }
    
    int res = 0;
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        if(x[j] > x[i] && y[j] < y[i]) {
          int x3 = x[i] - (y[i] - y[j]);
          int y3 = y[i] - (x[j] - x[i]);
          bool left = false, right = false;
          if(x3 > -20000 && y3 > -20000) {
            left = binary_search(pos[x3 + 20000].begin(), pos[x3 + 20000].end(), y3);
          }
          int x4 = x[j] - (y[i] - y[j]);
          int y4 = y[j] - (x[j] - x[i]);
          if(x4 > -20000 && y4 > -20000) {
            right = binary_search(pos[x4 + 20000].begin(), pos[x4 + 20000].end(), y4);
          }
          if(left && right)
            res++;
        }
        if(x[j] > x[i] && y[j] == y[i]) {
          bool left = false, right = false;
          int len = x[j] - x[i];
          int yy = y[j] - len;
          if(yy > -20000) {
              left = binary_search(pos[x[i] + 20000].begin(), pos[x[i] + 20000].end(), yy);
              right = binary_search(pos[x[j] + 20000].begin(), pos[x[j] + 20000].end(), yy);
              if(left && right)
                res++;
          }
        }
      } 
    }
    printf("%d\n", res);
  }
  return 0;
}
