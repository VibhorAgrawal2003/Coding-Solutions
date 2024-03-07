#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  bool isPalindrome(int x) {

    // Negative numbers
    if (x < 0) {
      return false;
    }

    // Calculate no. of digits
    int y{x};
    int dig{};
    while (y > 0) {
      y /= 10;
      dig++;
    }

    // Calculate right half backwards
    int n{dig / 2};
    int half{};
    for (int i = 0; i < n; i++) {
      half *= 10;
      half += (x % 10);
      x /= 10;
    }

    // Check if odd no. of digits
    if (dig % 2 != 0) {
      x /= 10;
    }

    return (half == x);
  }
};

int main() {

  Solution S;
  vector<int> testcases{0,  121, 1331, 1465322, 89, 919,
                        22, 1,   909,  -909,    -2, -111};
  cout << boolalpha;
  for (int x : testcases) {
    cout << x << " : " << S.isPalindrome(x) << "\n";
  }

  return 0;
}