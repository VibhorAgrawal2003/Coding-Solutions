#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int uniquePaths(int m, int n) {
    int ways[m][n];
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (i == 0 || j == 0) {
          ways[i][j] = 1;
        } else {
          ways[i][j] = ways[i - 1][j] + ways[i][j - 1];
        }
      }
    }
    return ways[m - 1][n - 1];
  }
};

int main() {

  Solution S;
  vector<pair<int, int>> testcases{};

  testcases.push_back((pair<int, int>){3, 4});
  testcases.push_back((pair<int, int>){4, 4});
  testcases.push_back((pair<int, int>){5, 5});
  testcases.push_back((pair<int, int>){5, 6});
  testcases.push_back((pair<int, int>){1, 1});
  testcases.push_back((pair<int, int>){1, 90});
  testcases.push_back((pair<int, int>){90, 1});
  testcases.push_back((pair<int, int>){3, 8});

  for (auto x : testcases) {
    cout << "\n";
    cout << x.first << " x " << x.second << " matrix\n";
    cout << "No. of ways: " << S.uniquePaths(x.first, x.second) << "\n";
  }

  return 0;
}