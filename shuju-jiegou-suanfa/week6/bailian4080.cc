#include <iostream>
#include <string.h>

using namespace std;

int in;
int input[1000];
int heap[1000];
int hsize = 0;

void swap(int &a, int &b) {
  int t = a;
  a = b;
  b = t;
}

int parent(int a) {
  return a/2;
}

int left(int a) {
  return a * 2;
}

int right(int a) {
  return a * 2 + 1;
}

void up(int a) {
  while(a > 1 && heap[parent(a)] > heap[a]) {
    swap(heap[parent(a)], heap[a]);
    a = parent(a);
  }
}

void down(int pos) {
  int l = left(pos);
  int index = pos;
  if(l <= hsize && heap[l] < heap[pos]) {
    index = l;
  }
  int r = right(pos);
  if(r <= hsize && heap[r] < heap[index]) {
    index = r;
  }
  if(pos != index) {
    swap(heap[pos], heap[index]);
    down(index);
  }
}

void add(int num) {
  heap[++hsize] = num;
  up(hsize);
}

int pop() {
  int res = heap[1];
  swap(heap[1], heap[hsize]);
  hsize--;
  down(1);
  return res;
}

int main() {
  freopen("acm.in", "r", stdin);
  scanf("%d", &in);
  for(int i = 0; i < in; i++) {
    int t;
    scanf("%d", &t);
    add(t);
  }
  int res = 0;
  while(hsize > 1) {
    int t = pop();
    t += pop();
    add(t);
    res += t;
  }
  printf("%d\n", res);
}
