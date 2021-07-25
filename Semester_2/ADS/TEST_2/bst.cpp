#include <iostream>
using namespace std;

struct Node {
  Node(int value): data(value), left(NULL), right(NULL) {}
  int data;
  Node * left;
  Node * right;
};

class BinarySearchTree {
  private:
    Node * _root;
    void insert(Node * treeNode, int data);
    Node getRoot(Node * treeNode);
    int numberOfNodes(Node * treeNode);
    int inOrder(Node * treeNode);
    void delDplicates(Node * treeNode);

  public:

    BinarySearchTree(); // constructor     
    ~BinarySearchTree(); // destractor

  void insert(int x) {
    insert(_root, x);
  }

  int numberOfNodes() {
    return numberOfNodes(_root);
  }

  Node getRoot() {
    return getRoot(_root);
  }

  Node * getMaxNode();
  Node * getMinNode();

  void delDplicates() {
    delDplicates(_root);
  }

  int inOrder() {
    inOrder(_root);
  }
};

BinarySearchTree::BinarySearchTree() {
  _root = NULL;
}

void BinarySearchTree::insert(Node * treeNode, int data) {
  if (!treeNode) {
    treeNode = new Node(data);
    _root = treeNode;
  } else {
    if (data < treeNode -> data) {
      if (!treeNode -> left) {
        Node * treeTemp = new Node(data);
        treeNode -> left = treeTemp;
      } else
        insert(treeNode -> left, data);
    } else {
      if (!treeNode -> right) {
        Node * treeTemp = new Node(data);
        treeNode -> right = treeTemp;
      } else
        insert(treeNode -> right, data);
    }
  }
}

int BinarySearchTree::numberOfNodes(Node * treeNode) {
  if (! treeNode -> left || ! treeNode -> right) {
    return 0;
  }
  if (!treeNode)
    return 0;
  return 1 + max(numberOfNodes(treeNode -> left), numberOfNodes(treeNode -> right));
}

Node BinarySearchTree::getRoot(Node * treeNode) {
  return *treeNode;
}

// Not complete
void BinarySearchTree::delDplicates(Node * treeNode) {
  if (!treeNode)
    return;
  Node * curTreeNode = treeNode;
  Node * leftTreeNode = treeNode -> left;
  Node * rightTreeNode = treeNode -> right;
  delete(curTreeNode);
  delDplicates(leftTreeNode);
  delDplicates(rightTreeNode);
}

BinarySearchTree::~BinarySearchTree() {
  delDplicates();
}

int BinarySearchTree::inOrder(Node * treeNode) {
  if (!treeNode)
    return;
  inOrder(treeNode -> left);
  cout << treeNode -> data << " ";
  inOrder(treeNode -> right);
}

int main() {
  BinarySearchTree bst;
  Node root(0);
  bst.insert(1);
  bst.insert(2);
  bst.insert(3);
  bst.insert(4);
  bst.insert(5);
  bst.insert(6);
  bst.insert(7);
  bst.insert(8);
  bst.insert(9);
  bst.insert(10);
  root = bst.getRoot();
  cout << "Number of nodes are: " << bst.numberOfNodes() << endl;
  cout << " in-order traverse is : " << endl;
  bst.inOrder();
  cout << endl;
  cout << endl;
}