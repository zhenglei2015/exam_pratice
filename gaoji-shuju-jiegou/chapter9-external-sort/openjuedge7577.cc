#include <iostream>
#include <string.h>

using namespace std;


int heap[100000];
int nh, nn;
int num[100000];
int size;

int par(int i) {
  return i / 2;
}

int left(int i) {
  return 2 * i;
}

int right(int i) {
  return 2 * i + 1;
}

void minheapfy(int i) {
  int l = left(i);
  int r = right(i);
  int minnum;
  if(l <= size && heap[l] < heap[i])
    minnum = l;
  else
    minnum = i;
  if(r <= size && heap[r] < heap[minnum])
    minnum = r;
  if(minnum != i) {
    int t = heap[i];
    heap[i] = heap[minnum];
    heap[minnum] = t;
    minheapfy(minnum);
  }
}

void insert(int a) {
  size++;
  heap[size] = a;
  int i = size;
  while(i > 1 && heap[par(i)] > heap[i]) {
    int t = heap[i];
    heap[i] = heap[par(i)];
    heap[par(i)] = t;
    i = par(i);
  } 
}

int popmin() {
  int t = heap[1];
  heap[1] = heap[size];
  size--;
  minheapfy(1);
  return t;
}


int main() {
  freopen("acm.in", "r", stdin);
  scanf("%d%d", &nn, &nh);
  for(int i = 0; i < nn; i++)
    scanf("%d", &num[i]);
  for(int i = 1; i <= nh; i++)
    scanf("%d", &heap[i]);
  size = nh; 

  for(int i = nh / 2; i > 1; i--) {
    minheapfy(i);
  }
  for(int i = 0; i < nn; i++) {
    if(size == 0)
      break;
    if(heap[1] < num[i]) {
      printf("%d ", heap[1]);
      popmin();
      insert(num[i]);
    } else {
      printf("%d ", popmin());
    }
  } 
}





