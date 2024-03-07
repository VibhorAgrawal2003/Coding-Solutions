#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  bool check(vector<int> &nums) {
    int count{0};
    for (int i = 0; i < (int)nums.size() - 1; i++) {
      if (nums[i] > nums[i + 1]) {
        count++;
      }
    }
    return (count == 1 && nums.back() <= nums.front()) || (count == 0);
  }
};

int main() {

  Solution S;
  vector<vector<int>> testcases{};
  testcases.push_back(vector<int>{3, 4, 5, 1, 2});
  testcases.push_back(vector<int>{1, 2, 3, 4});
  testcases.push_back(vector<int>{5, 6, 1, 2, 10, 11});

  cout << boolalpha;
  for (auto x : testcases) {
    cout << S.check(x) << "\n";
  }

  return 0;
}