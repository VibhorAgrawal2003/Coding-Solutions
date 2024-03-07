#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> findMissingAndRepeatedValues(vector<vector<int>> &grid) {
    vector<bool> flags{};
    for (int i = 0; i < pow((int)grid.size(), 2); i++) {
      flags.push_back(false);
    }

    vector<int> ans{};
    for (int i = 0; i < (int)grid.size(); i++) {
      for (int j = 0; j < (int)grid.size(); j++) {
        if (flags[grid[i][j] - 1]) {
          ans.push_back(grid[i][j]);
        } else {
          flags[grid[i][j] - 1] = true;
        }
      }
    }

    for (int i = 0; i < (int)flags.size(); i++) {
      if (!flags[i]) {
        ans.push_back(i + 1);
        return ans;
      }
    }

    return ans;
  }
};

int main() {
  Solution S;

  vector<vector<vector<int>>> testcases{};
  testcases.push_back((vector<vector<int>>){{1, 3}, {2, 2}});
  testcases.push_back((vector<vector<int>>){{9, 1, 7}, {8, 9, 2}, {3, 4, 6}});

  for (auto x : testcases) {
    for (auto y : S.findMissingAndRepeatedValues(x)) {
      cout << y << " ";
    }
    cout << "\n";
  }

  return 0;
}