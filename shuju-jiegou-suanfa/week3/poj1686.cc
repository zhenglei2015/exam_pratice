#include <stdio.h>
#include <stack>
#include <string.h>

using namespace std;

int n;
char f1[10000], f2[10000];

void input(char s[]) {
  char c;
  int i = 0;
  for(;;) {
    c = getchar();
    if(c == ' ' || c == '\t')
      continue;
    if(c == '\n')
      break;
    s[i] = c;
    i++;
  }
  s[i] = '\0';
}

char res1[10000];
char res2[10000];

void change(char res[], char src[]) {
  stack<int> sta;
  int len = strlen(src);
  int j = 0;
  for(int i = 0; i < len; i++) {
    if((src[i] >= '0' && src[i] <= '9') 
        || (src[i] >= 'a' && src[i] <= 'z') 
        || (src[i] >= 'A' && src[i] <= 'Z')) {
      res[j] = src[i];
      j++;
    } else if (src[i] == '(') {
      sta.push(src[i]);
    } else if (src[i] == ')') {
      while(sta.top() != '(') {
        res[j] = sta.top();
        j++;
        sta.pop();
      }
      sta.pop();
    } else if(sta.empty()){
      sta.push(src[i]);
    } else {
      while(!sta.empty() && sta.top() != '(') {
        res[j] = sta.top();
        j++;
        sta.pop();
      }
      sta.push(src[i]);
    }
  }
  while(!sta.empty()) {
    res[j] = sta.top();
    j++;
    sta.pop();
  }
  res[j] = '\0';
}

int exe(char f[]) {
  stack<int> sta;
  int res = 0;
  int len = strlen(f);
  for(int i = 0; i < len; i++) {
    if((f[i] >= '0' && f[i] <= '9') 
        || (f[i] >= 'a' && f[i] <= 'z') 
        || (f[i] >= 'A' && f[i] <= 'Z')) {
      if(f[i] >= '0' && f[i] <= '9')
        sta.push(f[i] - '0');
      else
        sta.push(f[i]);
    } else {
      int fir = sta.top();
      sta.pop();
      int sec = sta.top();
      sta.pop();
      if(f[i] == '+')
        sta.push(fir + sec);
      if(f[i] == '-')
        sta.push(sec - fir);
      if(f[i] == '*')
        sta.push(sec * fir);
      if(f[i] == '/')
        sta.push(sec / fir);
    }
  }
  return sta.top();
}

int main() {
  freopen("acm.in", "r", stdin);
  scanf("%d", &n);
  getchar();
  for(int cas = 0; cas < n; cas++) {
    input(f1);
    input(f2);
    change(res1, f1);
    change(res2, f2);
//    printf("%s\n%s\n\n", res1, res2);
    int a = exe(res1);
    int b = exe(res2);
//    printf("aa %d %d\n", a, b);
    if(a == b)
      printf("YES\n");
    else 
      printf("NO\n");
  }
  return 0;
}
