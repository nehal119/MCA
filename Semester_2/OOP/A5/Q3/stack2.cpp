#include<iostream>
using namespace std;

struct node {
  int data;
  node * next;
};

class Stack {
  node * top;
  public:
    Stack() {
      top = NULL;
    }
  void push();
  void pop();
  void display();
};
void Stack::push() {
  node * newlink;
  newlink = new node;
  cout << "enter the pointer element to push" << endl;
  cin >> newlink -> data;
  newlink -> next = top;
  top = newlink;
  cout << "push operation is succcessfull";
}
void Stack::pop() {
  if (top == NULL)
    cout << "stack is empty";
  else {
    node * t;
    t = top;
    top = top -> next;
    cout << "poped the elemets" << t -> data;
    delete t;
    cout << "\n pop operation is successfull";
  }
}
void Stack::display() {
  node * curt = top;
  if (top == NULL)
    cout << "stack empty";
  else {
    cout << "the elements in the stack is\n";
    while (curt != NULL) {
      cout << curt -> data;
      curt = curt -> next;
    }
  }
}
int main() {
  Stack s1;
  int ch = 0;
  cout << "stack operation using pointer";
  cout << "\n 1.PUSH \n 2.POP \n 3.DISPLAY \n4.EXIT\n";
  while (ch != 4) {
    cout << "enter the choice:";
    cin >> ch;
    switch (ch) {
    case 1:
      s1.push();
      break;
    case 2:
      s1.pop();
      break;
    case 3:
      s1.display();
      break;
    case 4:
      cout << "program terminated";
      break;
    }
  }
  return 0;
}