#include <iostream>
#include <stdio.h>

using namespace std;

template <class T> class Link {
  public:
    T data;
    Link<T> *next;
    Link(const T info, Link<T> *nextValue = NULL) {
      data = info;
      next = nextValue;
    }
    Link(Link<T> *nextValue) {
      next = nextValue;
    }
};

template <class T> class linkList {
  private:
    Link<T> *head, *tail;
    Link<T> *setPos(const int p); // 第 p 个元素的指针
    int len;  
  public:
    linkList() {
      Link<T> node = new Link<T>(0, NULL);
      head = &node;
      tail = &node;
      len = 0;
    }
    bool isEmpty();
    int length();
    bool insert(const int p, const T value);
    bool deletenode(const int p);// 删除位置 P
    bool getValue(int p, T& value);
    bool getPos(int &p, const T value);
};

template <class T>
bool linkList<T>::getValue(int p, T& value) {
  Link<T> *pre = setPos(p);
  if(pre == NULL || pre == tail) {
    return false;
  }
  value = pre->data;
  return true;
}


template <class T>
int linkList<T>::length() {
  return len;
}

template <class T>
Link<T> *linkList<T>::setPos(int i) {
  int count = 0;
  if(i == -1)
    return head;
  Link<T> *p = head;
  while(p != NULL && count < i) {
    p = p -> next;
    count++;
  }
  return p;
}
template <class T>
bool linkList<T>::insert(const int i, const T value) {
  Link<T> *p, *q;
  if((p = setPos(i - 1)) == NULL) {
    cout << "error pos" <<endl;
    return false;
  }
  q = new Link<T>(value, p->next);
  p->next = q;
  if(p == tail)
    tail = q;
  len++;
  return true;
}
template<class T>
bool linkList<T>::deletenode(const int i) {
  Link<T> *p, *q;
  if((p = setPos(i - 1)) == NULL || p == tail) {
    cout<< "error pos" <<endl; 
    return false;
  }
  q = p -> next;
  if(q == tail) {
    tail = p;
    p -> next = NULL;
  } else 
    p -> next = q -> next;
  delete q;
  len--;
  return true;
}

int res = -1;
int main() {
  linkList<int> list;
  for(int i = 0; i < 1000; i++)
    list.insert(0, i);
  for(int i = 0 ; i < 200; i++) {
    list.getValue(i, res);
    printf("%d\n", res); 
  }
  printf("length %d\n", list.length());
  for(int i = 0; i < 100; i++)
    list.deletenode(5);
  printf("length %d\n", list.length());
}



























