#include <bits/stdc++.h>
using namespace std;

#define NIL -1
#define MAX 100

int lookup[MAX];

void initialize() {
  for(int i=0; i< MAX; i++) {
    lookup[i] = NIL;
  }
}

// int fib(int n) {
//   if (lookup[n] == NIL) {
//     if (n <= 1) {
//       lookup[n] = n;
//     } else {
//       lookup[n] = fib(n-1) + fib(n-2);
//     }
//   }
//   return lookup[n];
// }

// // 0, 1, 1, 2, 3, 5
// Using Memioz
// int fib(int n) {
//   if (n == 0)
//     return 0;
//   if (n == 1)
//     return 0;
//   if (n==2)
//     return 1;

//   if (lookup[n] != NIL) {
//     return lookup[n];
//   }

//   lookup[n] = fib(n-1) + fib(n-2);

//   return lookup[n];
// }

// Using Table
int fib(int n) {
  int T[n+1];

  T[0] = 0;
  T[1] = 1;

  for(int i = 2; i <= n; i++) {
    T[i] = T[i-1] + T[i-2];
  }

  return T[n];
}

int main(){
  int n = 9;

  initialize();

  cout << "Fib is: " << fib(n) << endl;

  return 0;
}