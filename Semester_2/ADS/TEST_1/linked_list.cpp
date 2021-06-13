#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

struct node {
  int info;
  struct node * next;
  struct node * prev;
}* start;

class LinkedList {
  public:
    void create(int value);
    void display();
    LinkedList() {
      start = NULL;
    }
};

void node_swap(struct node * left, struct node * right) {
  struct node *tmp;
  tmp = left -> prev;
  if (tmp){
    tmp -> next = right;
  }
  right -> prev = tmp;
  left->prev = right;
  left->next = right->next;
  right -> next = left;
  if(left -> next != NULL){
    left -> next -> prev = right;
  }
  if (right->prev == NULL) {
    start = right;
  }
  if (left->prev == NULL) {
    start = left;
  }
}

void partition(){
  struct node * p1, * p2, * tmp;
  p1 = start;
  p2 = p1 -> next;
  tmp = p2;
  while (p2 != NULL) {
    node_swap(p1, p2);
    p2 = p1->next;
  }
}

int main() {
  int choice, element, position;
  LinkedList dl;
  while (1) {
    cout << endl << "----------------------------" << endl;
    cout << endl << "Linked list" << endl;
    cout << endl << "----------------------------" << endl;
    cout << "1.Create Node" << endl;
    cout << "2.Partiton" << endl;
    cout << "3.Display" << endl;
    cout << "4.Quit" << endl;
    cout << "Enter your choice : ";
    cin >> choice;
    switch (choice) {
    case 1:
      cout << "Enter the element: ";
      cin >> element;
      dl.create(element);
      cout << endl;
      break;
    case 2:
      partition();
      dl.display();
      cout << endl;
      break;
    case 3:
      dl.display();
      cout << endl;
      break;
    case 8:
      exit(1);
    default:
      cout << "Wrong choice" << endl;
    }
  }
  return 0;
}

void LinkedList::create(int value) {
  struct node * s, * temp;
  temp = new(struct node);
  temp -> info = value;
  temp -> next = NULL;
  if (start == NULL) {
    temp -> prev = NULL;
    start = temp;
  } else {
    s = start;
    while (s -> next != NULL)
      s = s -> next;
    s -> next = temp;
    temp -> prev = s;
  }
}

void LinkedList::display() {
  struct node * q;
  if (start == NULL) {
    cout << "List empty,nothing to display" << endl;
    return;
  }
  q = start;
  cout << "The Doubly Link List is :" << endl;
  while (q != NULL) {
    cout << "(" << q -> prev << " " << q -> info << " " << q -> next << "), ";
    q = q -> next;
  }
}