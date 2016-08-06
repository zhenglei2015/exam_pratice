#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>

using namespace std;

vector<int> pos[2500];

char str[100][100];

int inverse(char s[]) {
  int cnt[300];
  memset(cnt, 0, sizeof(cnt));
  int len = strlen(s);
  int res = 0;
  for(int i = 0; i < len; i++) {
    char cc[4] = {'A', 'T', 'G', 'C'};
    for(int j = 0; j < 4; j++) {
      if(s[i] < cc[j])
        res += cnt[cc[j]];
    }
    cnt[s[i]]++;
  }
  return res;
}


int main() {
  int m, n;
  freopen("acm.in", "r", stdin);
  scanf("%d%d", &n, &m);
  for(int i = 0; i < m; i++) {
    scanf("%s", &str[i][0]);
    int inver = inverse(&str[i][0]);
    pos[inver].push_back(i);
  }
  for(int i = 0; i < 1500; i++) {
    for(int j = 0; j < pos[i].size(); j++) 
      printf("%s\n", &str[pos[i][j]][0]);
  }
  return 0;
}
