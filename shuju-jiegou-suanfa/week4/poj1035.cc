#include <stdio.h>
#include <string.h>
#include <iostream>
#include <cmath>
#include <queue>

using namespace std;

char dict[12345][20];
char word[100][20];
int dictlen[12345];
int wordlen[123];

int dictcount;
int wordcount;

int smiliar(char *a, char *b, int lena, int lenb) {
  int diff = 0;
  int i = 0, j = 0;
  while(i < lena && j < lenb) {
    if(a[i] == b[j]) {
      i++, j++;
    } else if(lena < lenb) {
      j++;
      diff++;
    } else if(lena > lenb) {
      i++;
      diff++;
    } else {
      i++, j++;
      diff++;
    }
  }
  if(diff + lena - i + lenb - j > 1)
    return 0;
  return 1;
}

int main() {
  freopen("acm.in", "r", stdin);
  int i = 0;
  while(scanf("%s", dict[i++]) != EOF) {
    if(dict[i - 1][0] == '#') {
      dictcount = i - 1;
      i = 0;
      break;
    }
    dictlen[i - 1] = strlen(dict[i - 1]);
  }
  while(scanf("%s", word[i++]) != EOF) {
    if(word[i - 1][0] == '#') {
      wordcount = i - 1;
      i = 0;
      break;
    }  
    wordlen[i - 1] = strlen(word[i - 1]);
  }
  for(i = 0; i < wordcount; i++) {
    int correct = 0;
    for(int j = 0; j < dictcount; j++) {
      int difflen = dictlen[j] - wordlen[i];
      if(difflen == 0) {
        if(strcmp(word[i], dict[j]) == 0) {
          printf("%s is correct\n", word[i]);
          correct = 1;
          break;
        }
      }
    }
    if(!correct) {
      queue<int> si;
      for(int j = 0; j < dictcount; j++) {
        if(smiliar(word[i], dict[j], wordlen[i], dictlen[j])) {
          si.push(j);
        }        
      }
      printf("%s:", word[i]);
      while(!si.empty()) {
        printf(" %s", dict[si.front()]);
        si.pop();
      }
      printf("\n");
    }
  }
  return 0;
}
