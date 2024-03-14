#include <iostream>

using namespace std;

/**
 * Approach: Two Pointer Method
 * We use 'p' to check where we send 1s
 * We use 'q' to check current value from end
 * We have 'odd' as a condition to see if number is odd.
 * 
 * Until the number becomes odd, we look for a 1 to place
 * at the end.
 * 
 * Once it becomes odd, we bring all the remaining 1s to the
 * front at position 'p' from 'q'.
*/
class Solution {
public:
  string maximumOddBinaryNumber(string s) {
    int p = 0;
    int q = size(s) - 2;
    int end = size(s) - 1;
    string t = s;
    bool odd = (t[end] == '1'); // Keep track if odd

    // Adjust leading pointer to first zero
    while (t[p] == '1') {
      if (!odd) {
        swap(t[end], t[p]);
        odd = true;
        break;
      }
      p++;
    }

    // Perform two pointer approach to swap
    while (p < q) {
      if (!odd) {
        if (t[q] == '1') {
          swap(t[q], t[end]);
          odd = true;
        }
        q--;
      }
      else {
        if (t[p] == '0' && t[q] == '1') {
          swap(t[p++], t[q--]);
        }
        else {
          if (t[p] == '1') {
            p++;
          }
          if (t[q] == '0') {
            q--;
          }
        }
      }
    }

    return t;
  }
};

int main() {

  Solution S;
  string s1 {"1101001011"};
  string s2 {"1101001010"};
  string s3 {"0000101000"};
  string s4 {"0010000000"};
  cout << s1 << " " << S.maximumOddBinaryNumber(s1) << "\n";
  cout << s2 << " " << S.maximumOddBinaryNumber(s2) << "\n";
  cout << s3 << " " << S.maximumOddBinaryNumber(s3) << "\n";
  cout << s4 << " " << S.maximumOddBinaryNumber(s4) << "\n";

  return 0;
}