#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int arr[100000];

void swap(int &a, int &b) {
  int t = a;
  a = b;
  b = t;
}

int partition(int l, int r) {
  int t = l - 1;
  for(int i = l; i < r; i++) {
    if(arr[i] < arr[r]) {
      swap(arr[++t], arr[i]);
    }
  }
  swap(arr[++t], arr[r]);
  return t;
}

int getMiddle(int pos, int l, int r) {
  int t = partition(l, r);
  if(pos == t)
    return arr[t];
  if(pos < t)
    return getMiddle(pos, l, t - 1);
  if(pos > t)
    return getMiddle(pos, t + 1, r);
}

int main() {
  freopen("acm.in", "r", stdin);
  int n;
  scanf("%d", &n);
  for(int i = 1; i <= n; i++)
    scanf("%d", &arr[i]);
  int m = (1 + n) / 2;
  printf("%d\n", getMiddle(m, 1, n)); 
}
