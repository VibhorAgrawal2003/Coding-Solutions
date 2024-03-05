#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int missingNumber(vector<int> &nums) {
    int n = (int)nums.size();
    int total = n * (n + 1) / 2;
    int sum{};
    for (auto x : nums) {
      sum += x;
    }
    return total - sum;
  }
};

int main() {
  Solution S;
  vector<vector<int>> testcases{};
  testcases.push_back((vector<int>){3, 0, 1});
  testcases.push_back((vector<int>){0, 1});
  testcases.push_back((vector<int>){9, 6, 4, 2, 3, 5, 7, 0, 1});

  for (auto x : testcases) {
    cout << S.missingNumber(x) << "\n";
  }

  return 0;
}