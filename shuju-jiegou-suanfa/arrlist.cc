#include <iostream>
#include <stdio.h>

using namespace std;

class arrList {
  private :
    int *aList;
    int maxSize;
    int curLen;
    int position;
  public :
    arrList(const int size) {
      maxSize = size;
      aList = new int[maxSize];
      curLen = position = 0;
    }
    ~arrList(){
      delete[] aList;
    }
    void clear() {
      delete[] aList;
      curLen = position = 0;
      aList = new int[maxSize];
    }
    int length();
    bool insert(const int p, const int value);
    bool deleteNode(const int p);
    bool setValue(const int p, const int value);
    bool getValue(const int p, int &value);
    bool getPos(int &p, const int value);
};

int arrList::length() {
  return curLen;
}

bool arrList::setValue(const int p, const int value) {
  if(p >= 0 && p < curLen) {
    aList[p] = value;
    return true;
  }
  return false;
}

bool arrList::getValue(const int p, int &value) {
  if(p >= 0 && p < curLen) {
    value = aList[p];
    return true;
  }
  return false;
}


// start from 0
bool arrList::insert(const int p, const int value) {
  if(curLen >= maxSize) {
    cout << "overflow" << endl;
    return false;
  }
  if(p < 0 || p > curLen) {
    cout << "illegal" << endl;
  }
  for(int i = curLen; i > p; i--) {
    aList[i] = aList[i - 1];
  }
  aList[p] = value;
  curLen++;
  return true; 
}

bool arrList::deleteNode(const int p) {
  if(curLen <= 0) {
    cout<< "No element" << endl;
    return false;
  }
  if(p < 0 || p > curLen - 1) {
    cout << " illegal " << endl;
    return false;
  }
  for(int i = p; i < curLen - 1; i++) {
    aList[i] = aList[i + 1];
  }
  curLen--;
  return true;
}


int main() {
  int n, m;
  cin >> n >> m;
  arrList *list = new arrList(1000);
  for(int i = 1; i <= n; i++) {
    list->insert(i - 1, i);  
  }
  int start = 0;
  for(int i = 0; i < n - 1; i++) {
    int end = start + m - 1;    
    int pos = end % list->length();
    list->deleteNode(pos); 
    start = pos;
  }
  int num;
  list->getValue(0, num);
  printf("%d\n", num);
  return 0;
}
