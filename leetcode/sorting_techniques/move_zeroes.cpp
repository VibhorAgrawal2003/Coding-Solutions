#include <iostream>
#include <vector>

using namespace std;

/**
 * This approach traverses the array forward and looks
 * for non-zero numbers. When it finds one, it pulls
 * the number forward and updates pointer 'p' for the
 * next nonzero number to be pulled forward.
 *
 * When all nonzero numbers have been brought ahead, we
 * can be sure that remaining positions are meant to have
 * the zeroes. We update accordingly.
 */

class Solution {
public:
  void moveZeroes(vector<int> &nums) {
    int n = (int)nums.size();
    int p = 0;

    for (int i = 0; i < n; i++) {
      if (nums[i] != 0) {
        nums[p++] = nums[i];
      }
    }

    for (p; p < n; p++) {
      nums[p] = 0;
    }
  }
};

/**
 * In this approach, we traverse the array from behind
 * until we find a zero. When this happens, we move all
 * the nonzero elements 1 position forward and the extra
 * space generated at the end is filled with the zero.
 *
 * This approach results in extra shifts than would be
 * needed to solve the problem.
 */
class Brute {
public:
  void moveZeroes(vector<int> &nums) {

    int n = (int)nums.size();
    int q = n - 1;

    for (int i = n - 1; i >= 0; i--) {
      if (nums[i] == 0) {
        for (int j = i + 1; j <= q; j++) {
          nums[j - 1] = nums[j];
        }
        nums[q--] = 0;
      }
    }
  }
};

int main() {

  Solution S;

  return 0;
}