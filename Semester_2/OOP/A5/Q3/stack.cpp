#include<iostream>
#define SIZE 5
using namespace std;

class Stack {
  private:
    int num[SIZE];
    int top;
  public:
    Stack(); //defualt constructor
    int push(int);
    int pop();
    int isEmpty();
    int isFull();
    void displayItems();
};

Stack::Stack() {
  top = -1;
}

int Stack::isEmpty() {
  if (top == -1)
    return 1;
  else
    return 0;
}

int Stack::isFull() {
  if (top == (SIZE - 1))
    return 1;
  else
    return 0;
}

int Stack::push(int n) {
  if (isFull()) {
    return 0;
  }
  ++top;
  num[top] = n;
  return n;
}

int Stack::pop() {
  int temp;
  if (isEmpty())
    return 0;
  temp = num[top];
  --top;
  return temp;

}

void Stack::displayItems() {
  int i;
  cout << "Stack is: ";
  for (i = (top); i >= 0; i--)
    cout << num[i] << " ";
  cout << endl;
}

int main() {
  Stack stk;
  int choice, n, temp;

  do {
    cout << endl;
    cout << "0 - Exit." << endl;
    cout << "1 - Push Item." << endl;
    cout << "2 - Pop Item." << endl;
    cout << "3 - Display Items (Print Stack)." << endl;

    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
    case 0:
      break;

    case 1:
      cout << "Enter item to insert: ";
      cin >> n;
      temp = stk.push(n);
      if (temp == 0)
        cout << "Stack is FULL." << endl;
      else
        cout << temp << " inserted." << endl;
      break;

    case 2:
      temp = stk.pop();
      if (temp == 0)
        cout << "Stack IS EMPTY." << endl;
      else
        cout << temp << " is removed (popped)." << endl;
      break;

    case 3:
      stk.displayItems();
      break;

    default:
      cout << "An Invalid choice." << endl;
    }
  } while (choice != 0);

  return 0;

}