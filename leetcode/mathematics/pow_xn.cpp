#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:

  double myPow(double x, int n) {
    if (n < 0) {
      return myPowRecursive(1/x, abs(n));
    }
    else {
      return myPowRecursive(x, n);
    }
  }

  double myPowRecursive(double x, int n) {

    // Base Cases
    if (n == 0) {
      return 1;
    }
    else if (n == 1) {
      return x;
    }

    // General Cases
    if (n % 2 == 0) {
      double p = myPowRecursive(x, n/2);
      return p * p;
    }
    else {
      return myPowRecursive(x, n/2) * myPowRecursive(x, n/2+1);
    }
  }
};


int main(){

  Solution S;

  return 0;
}

  double lookup(int n) {
//     for (auto x : values) {
//       if (x.first == n) {
//         return x.second;
//       }
//     }
//     return -1;
//   }