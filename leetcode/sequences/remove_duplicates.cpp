#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int removeDuplicates(vector<int> &nums) {
    int k{0};
    for (int i = 1; i < (int)nums.size(); i++) {
      if (nums[i] != nums[i - 1]) {
        nums[++k] = nums[i];
      }
    }
    return k;
  }
};

int main() {

  Solution S;
  vector<vector<int>> testcases{};
  testcases.push_back((vector<int>){1});
  testcases.push_back((vector<int>){1, 1, 2});
  testcases.push_back((vector<int>){1, 1, 1, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3});
  testcases.push_back((vector<int>){2, 3, 3, 4, 4, 4, 4, 6, 7, 9, 9, 10, 11});

  for (auto x : testcases) {
    cout << S.removeDuplicates(x) << "\n";
  }

  return 0;
}