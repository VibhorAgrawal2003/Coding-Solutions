#include <iostream>
#include <vector>

using namespace std;

class Better2 {
public:
  void rotate(vector<int> &nums, int k) {
    vector<int> temp{};
    int n = (int)nums.size();
    k %= n;
    int x = n - k;

    for (int i = 0; i < x; i++) {
      temp.push_back(nums[i]);
    }

    for (int i = x; i < n; i++) {
      nums[i - x] = nums[i];
    }

    for (int i = 0; i < x; i++) {
      nums[i + k] = temp[i];
    }
  }
};

class Better1 {
public:
  void rotate(vector<int> &nums, int k) {
    vector<int> res{};
    int n{(int)nums.size()};
    for (int i = 0; i < n; i++) {
      res.push_back(0);
    }

    for (int i = 0; i < n; i++) {
      res[(i + k) % n] = nums[i];
    }

    nums.clear();
    nums = res;
  }
};

/**
 * This approach uses extra space and spends extra time
 * on performing dynamic memory allocations on the heap.
 * Not an ideal solution.
 */
class Brute {
public:
  void rotate(vector<int> &nums, int k) {
    int n = (int)nums.size();
    k = k % n;

    for (int i = 0; i < n - k; i++) {
      nums.push_back(nums.front());
      nums.erase(nums.begin());
    }
  }
};

int main() {
  Brute S;

  return 0;
}