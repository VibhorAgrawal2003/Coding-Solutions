#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  bool isIdealPermutation(vector<int> &nums) {
    int n = (int)nums.size();

    for (int i = 0; i < n; i++) {
      if (nums[i] != i) {
        if (i == n - 1) {
          return false;
        }
        else {
          if (nums[i] == i+1 && nums[i+1] == i) {
            i++;
          }
          else {
            return false;
          }
        }
      }
    }

    return true;
  }
};

class Brute {
public:
  bool isIdealPermutation(vector<int> &nums) {
    int local{};
    int global{};

    for (int i = 0; i < (int)nums.size() - 1; i++) {
      if (nums[i] > nums[i + 1]) {
        local += 1;
      }

      for (int j = i + 1; j < (int)nums.size(); j++) {
        if (nums[i] > nums[j]) {
          global += 1;
        }
      }
    }

    return global == local;
  }
};

int main() {

  Solution S;
  Brute B;

  vector<vector<int>> testcases{};
  testcases.push_back((vector<int>){1, 0, 2});
  testcases.push_back((vector<int>){1, 2, 0});
  testcases.push_back((vector<int>){0, 1, 2});
  testcases.push_back((vector<int>){1, 2, 3, 0, 4, 5});
  testcases.push_back((vector<int>){2, 1, 0, 3, 4, 5});

  cout << boolalpha;
  for (auto x : testcases) {
    cout << S.isIdealPermutation(x) << "\n";
  }


  cout << "\n";
  for (auto x : testcases) {
    cout << B.isIdealPermutation(x) << "\n";
  }

  return 0;
}