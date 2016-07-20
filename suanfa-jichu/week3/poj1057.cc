#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue>
#include <vector>

using namespace std;

int dfs(int col, int fst) {
  char file[50][50];
  int filecnt = 0;
  char buf[50];
  while(scanf("%s", buf) != EOF) {
    if(fst && buf[0] != '#') {
      printf("ROOT\n");
      fst = 0;
    } 
    if(buf[0] == '#')
      return -1;
    if(buf[0] == 'd') {
      for(int i = 0; i < col; i++) {
        printf("|     ");
      }
      printf("%s\n", buf);
      dfs(col + 1, 0);
    }
    if(buf[0] == '*' || buf[0] == ']') {
      for(int i = filecnt - 1; i > 0 ; i--) {
        int flag = false;
        for(int j = filecnt - 1; j > 0; j--) {
          if(strcmp(file[j], file[j-1]) < 0) {
            char buff[50];
            strcpy(buff, file[j]);
            strcpy(file[j], file[j - 1]);
            strcpy(file[j-1], buff);
            flag = true;
          }
        }
        if(!flag)
          break;
      }
      for(int i = 0; i < filecnt; i++) {
        for(int j = 0; j < col - 1; j++) {
          printf("|     ");
        }
        printf("%s\n", file[i]);
      }   
      return 0;
    }
    if(buf[0] == 'f') {
      strcpy(&file[filecnt][0], buf);
      filecnt++;
    }
  }
  return 0;
}

int main() {
  freopen("acm.in", "r", stdin);
  int cas = 1;

  printf("DATA SET %d:\n", cas++);
  while(dfs(1, 1) != -1) {
    printf("DATA SET %d:\n", cas++);
  }
  return 0;
}
