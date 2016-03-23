#include<stdio.h>
#include<string.h>
#include<vector>

using namespace std;

int b[20][20]; 

int result[1000][20];

int path[20];
int used[20];

int target;
int countt;

void dfs(int n) {
  if(n > target) {
    puts("");
    countt ++;
    for(int i = 1; i <= target; i++)
      result[countt][i] = path[i]; 
    return;
  }
  for(int i = 1; i <= target; i++) {
    if(!used[i]) {
      printf("%d", i);
      used[i] = 1;
      path[n] = i;
      dfs(n + 1);
      used[i] = 0;
    }
  }
}

int cal(int n) {
  int cnt = 0;
  for(int i = 1; i <= target; i++) {
    for(int j = 1; j < i; j++) {
      if(result[n][j] > result[n][i])
        cnt++;
    }
  }
  return cnt%2 == 0;
}

void printBoard(int resultNext) {
    puts("");
    for(int i = 1; i <= target; i++) {
      for(int j = 1; j <= target; j++) {
        if(j != result[resultNext][i]) {
          printf("%c", '*');
        } else { 
          printf("%c", '+');
        }
      }
      puts("");
    }
}
int main() {
  char c;
  scanf("%d%c", &target, &c);
  countt = 0;
  dfs(1);
  char next[20];
  int resultNext = 1;
  for(int i = 1; i <= countt; i++) {
    if(cal(i))
      printBoard(i);
    puts("");
  }
 return 0;
}
