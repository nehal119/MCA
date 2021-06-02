#include<math.h>
#include <iostream>
using namespace std;

int main() {
  int t,i;
  float d;
  float XF[12],YF[12],XB[12],YB[12],VF;
  cout << "Pure Pursuit Problem in C++" << endl << endl;
  cout << "Enter Target path, XB[t] & YB[t]" << endl;

  for( i = 0; i < 12; i++){
    cout << "at t=" << i << " enter XB[" << i << "] : ";
    cin >> XB[i];
    cout << "at t=" << i << " enter YB[" << i << "] : ";
    cin >> YB[i];
  }
  cout << "Enter Fighter's Initial path, XF[0] & YF[0]: " << endl;
  cout << "at t=0" << " enter XF[0] : ";
  cin >> XF[0];
  cout << "at t=0" << " enter YF[0] : ";
  cin >> YF[0];
  cout << "Enter Fighter velocity, VF: ";
  cin >> VF;

  for( t = 0; t < 12; t++) {
    d = sqrt(pow((YB[t] - YF[t]), 2) + pow((XB[t] - XF[t]),2));
    if(d < 10) {
      cout << "Caught at " << t << "mts and" << d << "kms" << endl;
      break;
    } else{
      XF[t+1] = XF[t] + (VF*(XB[t] - XF[t])/d);
      YF[t+1] = YF[t] + (VF*(YB[t] - YF[t])/d);
    }
  }
  if(t > 11) {
    cout << "Target Escaped!" << endl;
  }
  return(0);
}