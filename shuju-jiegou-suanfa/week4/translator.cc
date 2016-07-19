#include<iostream>
#include<string.h>

using namespace std;

char line[100][20];

char num[32][20] = {"negative", "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety", "hundred", "thousand", "million"};

int val[32] = {-1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 ,15, 16, 17, 18, 19, 20, 30, 40, 50, 60, 70, 80, 100, 1000, 1000000};

int getValue(char *s) {
  for(int i = 0; i < 32; i++) {
    if(!strcmp(num[i], s))
      return val[i];
  }
  return -1;
}

int dfs(int s, int e) {
  int hundred = 0, thousands = 0, million = 0;
  int flag = s;
  for(int i = s; i <= e; i++) {
    if(!strcmp(line[i], "million")) {
      million = dfs(s, i - 1);
      flag = i + 1;
    }
  }
  for(int i = flag; i <= e; i++) {
    if(!strcmp(line[i], "thousand")) {
      thousands = dfs(flag, i - 1);
      flag = i + 1;
    }
  }
  for(int i = flag; i <= e; i++) {
    if(!strcmp(line[i], "hundred")) {
      hundred = dfs(flag, i - 1);
      flag = i + 1;
    }
  }
  int cur = 0;
  for(int i = flag; i <= e; i++) {
    cur += getValue(line[i]);
  }   
  return million * 1000000 + thousands * 1000 + hundred * 100  + cur;
}

int getLine() {
  int i = 0;
  int j = 0;

  char c = getchar();
  
  do {
    if(c == EOF)
      return c;
    else if(c == '\n') {
      line[i][j] = '\0';
      return i;
    } else if(c == ' ') {
      line[i][j] = '\0';
      i++;
      j = 0;
    } else {
      line[i][j++] = c; 
    }
    c = getchar();
  } while(true);
  return i;
}

int main() {
  int end;
  freopen("acm.in", "r", stdin);
  while((end = getLine()) != EOF) {
    if(line[0][0]== '\0')
      break;
    if(getValue(line[0]) == -1) {
      printf("%d\n", -dfs(1, end));
    } else {
      printf("%d\n", dfs(0, end));
    }
  }
  return 0;
}
