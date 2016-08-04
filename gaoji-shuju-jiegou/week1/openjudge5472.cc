#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

int arr[1000000];
int temp[1000000];

int merge(int left, int right, int arr[], int temp[]) {
  int middle = (left + right) / 2;
  for(int i = left; i <= right; i++) {
    temp[i] = arr[i];
  }
  int ll = middle - left + 1;
  int lr = right - middle;
  int res = 0;
  int tl = left;
  int tr = middle + 1;
  int t = left;
  while(ll && lr) {
    if(temp[tl] <= temp[tr]) {
      arr[t++] = temp[tl++];
      ll--;
    } else if (temp[tl] > temp[tr]) {
      res += ll;
      arr[t++] = temp[tr++];
      lr--;
    }
  }
  while(ll) {
    arr[t++] = temp[tl++];
    ll--;
  }
  while(lr) {
    arr[t++] = temp[tr++];
    lr--;
  }
  return res;
}

int mergeSort(int left, int right, int arr[], int temparr[]) {
  int res = 0;
  if(left < right) {
    int middle = (left + right) / 2;
    res += mergeSort(left, middle, arr, temparr);
    res += mergeSort(middle + 1, right, arr, temparr);
    res += merge(left, right, arr, temparr);
  }
  return res;
}


int main() {
 int n;
  while(scanf("%d", &n)) {
    if(n == 0)
      break;
    for(int i = 0; i < n; i++) 
      scanf("%d", &arr[i]);
    int res = mergeSort(0, n - 1, arr, temp);
    printf("%d\n", res);
  }
  return 0;
}
