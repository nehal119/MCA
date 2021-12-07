#include<iostream>
using namespace std;

// #define MOD 1e9+7
// #define MAX 1e5+2

const int MAX = 1e5+2, MOD = 1e9+7;

int lookup[MAX];

// // Brute force approach
// int minSquare(int n) {
//   if (n ==0 || n==1 || n==2 || n==3)
//     return n;
  
//   int ans = MOD;

//   for (int i = 1; i*i <= n; i++) {
//     ans = min(ans, 1 + minSquare(n - i*i));
//   }

//   return ans;
// }

// Memioz
int minSquare(int n) {
  if (n == 0 || n == 1 || n==2 || n==3) {
    return n;
  }
  if (lookup[n] != MOD) {
    return lookup[n];
  }

  for(int i = 1; i*i <= n; i++) {
    lookup[n] = min(lookup[n], 1+ minSquare(n - i*i));
  }

  return lookup[n];
  
}

int main() {
  // int n; cin >> n;

  for (int i = 0; i < MAX; i++) {
    lookup[i] = MOD;
  }

  cout << minSquare(1000) << endl;

  return 0;
}