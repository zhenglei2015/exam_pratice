#include <iostream>
#include <stdio.h>
#include <string.h>

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

char sec[500];
char fir[500];
int lenfir, lensec;

arrList* mid[500];

void multi(int num, int start) {
  arrList *temp = new arrList(500); 
  mid[start] = temp;
  int i;
  for(i = 0; i < start; i++) {
    temp->insert(i, 0); 
  }
  int carry = 0; 
  for(int j = lenfir - 1; j >= 0; j--) {
    int t = (fir[j] - '0') * num + carry;
    carry = ( t) / 10;
    temp->insert(i++, t % 10 );
  }
  while(carry) {
    temp->insert(i++, carry % 10);
    carry /= 10;
  } 
}

arrList *addList(arrList *a, arrList *b) {
  arrList *res = new arrList(500);
  int along = true;
  int shortlength = b->length();
  if(a->length() < b->length()) {
    along = false;
    shortlength = a->length();
  }
  int carry = 0;
  int i;
  for(i = 0 ; i < shortlength; i++) {
    int numa, numb; 
    a->getValue(i, numa);
    b->getValue(i, numb);
    int tot = (numa + numb + carry);
    int left = tot % 10;
    res->insert(i, left);
    carry = tot / 10;
  }
  arrList *longarr;
  if(along)
    longarr = a;
  else
    longarr = b;
  for(; i < longarr->length(); i++) {
    int num;
    longarr->getValue(i, num);
    int tot = carry + num;
    int left = tot % 10;
    res->insert(i, left);
    carry = tot / 10;
  }
  while(carry) {
    res->insert(i++, carry % 10);
    carry /= 10;
  } 
  return res;
}

int main() {
  scanf("%s%s", fir, sec);   
  lenfir = strlen(fir);
  lensec = strlen(sec);
  for(int i = lensec - 1; i >= 0; i--) {
    multi(sec[i] - '0', lensec - 1 - i);
  }
  arrList *result;
  if(lensec == 1) {
    result = mid[0];
  } else {
    result = addList(mid[0], mid[1]);
    for(int i = 2; i < lensec; i++) {
      arrList* t = addList(mid[i], result);     
      delete result;
      result = t;
    }
  }
  for(int i = result->length() - 1; i >= 0; i--) {
    int num;
    result->getValue(i, num);
    printf("%d", num);
  } 
}





