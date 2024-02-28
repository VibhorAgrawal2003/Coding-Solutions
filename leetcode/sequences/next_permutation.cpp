#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void showVector(vector<int> v) {
  cout << "{ ";
  for (auto x : v) {
    cout << x << " ";
  }
  cout << "}\n";
}

class Solution {
public:
  void swapAround(int &x, int &y) {
    int t = x;
    x = y;
    y = t;
  }

  void nextPermutation(vector<int> &nums) {
    int i{}, j{};
    bool flag = false;

    // Find the criteria to make this vector bigger

    for (j = nums.size() - 1; j >= 0; j--) {
      for (i = nums.size() - 1; i > j; i--) {
        if (nums[i] > nums[j]) {
          swapAround(nums[i], nums[j]);
          flag = true;
          break;
        }
      }
      if (flag) {
        break;
      }
    }

    // Sort the succeeding values to get right vector
    sort(nums.begin() + j + 1, nums.end());
  }
};

int main() {

  Solution S;
  vector<int> v1 = {1, 2, 3};
  vector<int> v2 = {1, 3, 2};
  vector<int> v3 = {2, 1, 3};
  vector<int> v4 = {1, 2, 3, 4, 5};
  vector<int> v5 = {2};
  vector<int> v6 = {4, 2, 0, 2, 3, 2, 0};

  S.nextPermutation(v1);
  S.nextPermutation(v2);
  S.nextPermutation(v3);
  S.nextPermutation(v4);
  S.nextPermutation(v5);
  S.nextPermutation(v6);

  showVector(v1);
  showVector(v2);
  showVector(v3);
  showVector(v4);
  showVector(v5);
  showVector(v6);

  return 0;
}