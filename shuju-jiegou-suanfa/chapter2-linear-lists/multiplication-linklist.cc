#include <iostream>
#include <string.h>

using namespace std;


class List {
  void clear();
  bool isEmpty();
  bool append(const int value);
  bool insert(const int p, const int value);
  bool release();
  bool getPos(int &p, const int value);
  bool getValue(const int p, int &value);
  bool setValue(const int p, const int value);
};

class Node {
  public:
    int data;
    Node *next;
    Node(const int info, Node *nextValue = NULL) {
      data = info;
      next = nextValue;
    }
    Node(Node* nextValue) {
      next = nextValue;
    }
};

class linkList : public List {
  private :
    int len;
    Node *head, *tail;
    Node *setPos(const int p);
  public :
    linkList(int s) {
      head = new Node(s);
      tail = head;
      len = 0;
    }
    ~linkList() {
      Node *cur = head;
      Node *net = head->next;
      while(net) {
        delete cur;
        cur = net;
        net = net->next;
      }
    }
    bool isEmpty();
    void clear();
    int length();
    bool append(const int value);
    bool insert(const int p, const int value);
    bool release(const int p);
    bool getValue(const int p, int &value);
    bool getPos(int &p, const int value); 
    void travel();
};

bool linkList::append(const int value) {
  Node *p = new Node(value);  
  tail->next = p;
  tail = p;
  len++;
  return true;
}

bool linkList::getValue(const int p, int &value) {
  if(p < 0) {
    cout << "invalid position" << endl;
    return false;
  }
  Node *q = setPos(p);
  value = q->data;
  return true;
}


int linkList::length() {
  return len;
}


//从零开始的
Node *linkList::setPos(int i) {
  int count = 0;
  if(i == -1)
    return head;
  Node *p = head->next;
  while(p != NULL && count < i) {
    p = p -> next;
    count++;
  }
  // 当列表中的节点小于给的下标的时候返回 NULL
  return p;
}

bool linkList::insert(const int i, const int value) {
  Node *p, *q;
  if((p = setPos(i -1)) == NULL) {
    cout<< "invalid position" << endl;
    return false;
  }
  q = new Node(value, p->next);
  p->next = q;
  if(p == tail)
    tail = q;
  len++;
  return true;
}

bool linkList::release(const int i) {
  Node *p, *q;
  if((p = setPos(i - 1)) == NULL || p == tail) {
    cout << "invalid node" << endl;
    return false;
  }
  printf("%d xxx\n", p->data);
  q = p -> next;
  printf("%d xxx\n", q->data);
  if(q == tail) {
    tail = p;
    p -> next = NULL;
  } else 
    p->next = q->next;
  delete q;

  printf("%d xxx\n", p->data);
  len--;
  return true;
}

void linkList::travel() {
  Node *p = head;
  while(p != NULL) {
    printf("%d ", p->data);
    p = p->next;
  }
  printf("\n");
}


int main() {
  linkList *link = new linkList(-1);
  for(int i = 0; i < 10; i++) 
    link->append(i);
  int len = link->length();
  printf("len %d \n", len);
  link->release(5);
  for(int i = 0; i < 9; i++) {
    int t;
    link->getValue(i, t);
    printf("%d ", t);
  }
  delete link;
  return 0;
}
