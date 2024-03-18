#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int reversePairs(vector<int> &nums) {

  }
};

class Brute {
public:
  int reversePairs(vector<int> &nums) {

    int n = (int)nums.size();
    int count{};

    for (int i = 0; i < n - 1; i++) {
      for (int j = i + 1; j < n; j++) {
        if ((nums[i] / 2) + ((nums[i] % 2 != 0) ? 1 : 0) > nums[j]) {
          count++;
        }
      }
    }

    return count;
  }
};

int main() {

  Brute B;

  return 0;
}