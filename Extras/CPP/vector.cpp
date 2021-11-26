#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> v;
  v.push_back(11);
  // cout << v.begin();
  cout << v.size();
  cout << "Elements are: " << endl;
  //  for (auto it = g1.begin(); it != g1.end(); it++)
  //       cout << *it << " ";
  for (auto item = v.begin(); item != v.end(); item++) {
    cout << *item << endl;
  }
  return 0;
}
