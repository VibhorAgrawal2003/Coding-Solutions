#include <iostream>
#include <vector>

using namespace std;

/**
 * Normal reversal with a twist.
 * Here, to handle overflow conditions, we use the digits present in INT_MAX
 * as a pattern against which we check the digits received during reversal
 * If at any point, we realize that the number being generated will cause an
 * overflow, we return 0 from the function.
 *
 * This kind of overflow may only occur from numbers of int type having 10
 * digits.
 */
class Solution {
public:
  int reverse(int x) {

    // If INT_MIN, return 0 to avoid undefined behavior
    if (x == INT_MIN) {
      return 0;
    }

    // Get the sign
    bool sign = (x < 0) ? true : false;
    int dig{0}, sum{0}, y{0};
    const vector<int> pattern = {2, 1, 4, 7, 4, 8, 3, 6, 4, 7};

    // Get the number of digits
    y = abs(x);
    while (y > 0) {
      dig++;
      y /= 10;
    }

    // Reverse the number
    y = abs(x);
    int p = 0;
    bool flag{false};
    if (dig == 10) {
      flag = true;
    }

    while (y > 0) {
      int val = (y % 10);
      if (flag) {
        if (val > pattern[p]) {
          return 0;
        } else if (val < pattern[p]) {
          flag = false;
        }
      }

      sum *= 10;
      sum += val;
      y /= 10;
      p++;
    }

    return sum * ((sign) ? -1 : 1);
  }
};

int main() {

  Solution S;
  vector<int> v{123,        -123,       120,        0,           4567,
                INT_MAX,    INT_MIN,    1534236469, -1534236461, -1463848412,
                1463847413, 1463947412, 1463847412, -2147483412};

  for (int x : v) {
    cout << "number: " << x << " and reversed: " << S.reverse(x) << "\n";
  }

  // -2147483412
  //

  return 0;
}