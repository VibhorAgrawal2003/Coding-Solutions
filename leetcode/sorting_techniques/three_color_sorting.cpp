#include <iostream>
#include <vector>

using namespace std;

template <typename T> void showVector(vector<T> &v) {
  for (auto x : v) {
    cout << x << " ";
  }
  cout << endl;
}

/**
 * DUTCH NATIONAL FLAG ALGORITHM
 */
class Solution {
public:
  void swapItems(int &x, int &y) {
    int t = x;
    x = y;
    y = t;
  }

  void sortColors(vector<int> &nums) {

    int low = 0;
    int mid = 0;
    int high = (int)nums.size() - 1;

    while (mid <= high) {
      if (nums[mid] == 0) {
        swapItems(nums[mid], nums[low]);
        low++;
        mid++;
      }

      else if (nums[mid] == 1) {
        mid++;
      }

      else {
        swapItems(nums[mid], nums[high]);
        high--;
      }
    }
  }
};

/**
 * COUNT SORT
 */
class Subpar {
public:
  void sortColors(vector<int> &nums) {
    int zc{0}, oc{0};
    for (auto x : nums) {
      if (x == 0) {
        zc++;
      } else if (x == 1) {
        oc++;
      }
    }

    for (int i{0}; i < nums.size(); i++) {
      if (zc != 0) {
        nums[i] = 0;
        zc--;
      } else if (oc != 0) {
        nums[i] = 1;
        oc--;
      } else {
        nums[i] = 2;
      }
    }
  }
};

/**
 * BUBBLE SORT
 */
class Brute {
public:
  void swapItems(int &x, int &y) {
    int t = x;
    x = y;
    y = t;
  }

  void sortColors(vector<int> &nums) {
    for (int i = 0; i < nums.size(); i++) {
      for (int j = i; j < nums.size(); j++) {

        if (nums[i] > nums[j]) {
          swapItems(nums[i], nums[j]);
        }
      }
    }
  }
};

int main() {

  Solution S;
  vector<vector<int>> testcases{};

  testcases.push_back((vector<int>){2, 0, 2, 1, 1, 0});
  testcases.push_back((vector<int>){0});
  testcases.push_back((vector<int>){2, 1, 0});
  testcases.push_back((vector<int>){1, 1, 1, 2, 2, 0, 0});
  testcases.push_back((vector<int>){0, 0, 1, 2, 2, 2});
  testcases.push_back((vector<int>){2, 0, 1, 2, 0, 1, 2, 2});
  testcases.push_back((vector<int>){1, 0, 0, 2, 2, 2, 0, 2, 1, 0});
  testcases.push_back(
      (vector<int>){2, 1, 0, 2, 1, 2, 2, 2, 0, 0, 0, 1, 2, 2, 1});
  testcases.push_back(
      (vector<int>){1, 2, 0, 2, 1, 1, 1, 0, 0, 2, 1, 2, 2, 1, 2});
  testcases.push_back((vector<int>){0, 0, 0, 2, 2, 2, 1, 2, 1, 2, 1, 2});

  for (auto x : testcases) {
    S.sortColors(x);
    showVector(x);
  }

  return 0;
}