#include <iostream>
#include <string.h>

using namespace std;


class Node {
  public :
  Node *left;
  Node *right;
  int num;
  Node(){
    left = right = NULL;
  }
  Node(int n) {
    left = right = NULL;
    num = n;
  }
};


int n = 0;
int mid[100000];
int after[100000];

Node *build(int ml, int mr, int al,int  ar) {
  int root = after[ar]; 

  if(ml > mr && al > ar)
    return NULL;
  int count = 0;
  for(int i = ml; i <= mr; i++) {
    if(mid[i] != root) {
      count++;
    } else 
      break;
  }
  Node *r = new Node();
  r->left = build(ml, ml + count - 1, al, al + count - 1);
  r->right = build(ml + count + 2, mr, al + count, ar - 1);
  r->num = root;
  return r;
}

void dfs(Node *r) {
  if(r == NULL)
    return ;
  printf("%d ", r->num);
  dfs(r->left);
  dfs(r->right);
}

int main() {
  freopen("acm.in", "r", stdin);
  while(scanf("%d", &mid[n++]) != EOF);
  for(int i = n / 2; i < n; i++) {
    after[i - n/2] = mid[i];
  }
  Node *root = build(0, n / 2 - 1, 0, n / 2 - 1);
  dfs(root);  
  return 0;
}

