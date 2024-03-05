#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/**
 * OPTIMAL APPROACH
 * Here, we create an array of size 'n' to track which values were visited.
 * If at any point we find that the value has been visited before, we return it.
 * Time complexity: O(n) + O(n+1) ---> O(n)
 */
class Solution {
public:
  int findDuplicate(vector<int> &nums) {
    vector<bool> flags{};
    for (int i = 1; i < (int)nums.size(); i++) {
      flags.push_back(false);
    }

    for (int i = 0; i < (int)nums.size(); i++) {
      if (flags[nums[i] - 1]) {
        return nums[i];
      } else {
        flags[nums[i] - 1] = true;
      }
    }

    return -1;
  }
};

/**
 * BETTER APPROACH
 * Here, we first sort the array in O(nlogn) time complexity.
 * Then we traverse to find the double occurence in O(n) time.
 * This brings our total time complexity to O(nlogn).
 * One issue with this result is that we modified the array.
 */
class Better {
public:
  int findDuplicate(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    for (int i = 0; i < (int)nums.size() - 1; i++) {
      if (nums[i] == nums[i + 1]) {
        return nums[i];
      }
    }
    return -1;
  }
};

/**
 * BRUTE FORCE APPROACH
 * Here, we compare every pair of elements.
 * This results in O(n^2) time complexity.
 */
class Brute {
public:
  int findDuplicate(vector<int> &nums) {
    for (int i = 0; i < (int)nums.size(); i++) {
      for (int j = 0; j < (int)nums.size(); j++) {
        if (i != j && nums[i] == nums[j]) {
          return nums[i];
        }
      }
    }
    return -1;
  }
};

int main() {
  Solution S;
  vector<vector<int>> testcases{};
  testcases.push_back((vector<int>){1, 3, 4, 2, 2});
  testcases.push_back((vector<int>){3, 1, 3, 4, 2});
  testcases.push_back((vector<int>){3, 3, 3, 3, 3});
  testcases.push_back((vector<int>){1, 3, 4, 2, 2});

  for (auto x : testcases) {
    cout << S.findDuplicate(x) << "\n";
  }

  return 0;
}