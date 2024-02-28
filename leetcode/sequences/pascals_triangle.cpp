#include <iostream>
#include <vector>

using namespace std;

void showPascal(vector<vector<int>> &pascal) {
  cout << "{ ";
  for (auto x : pascal) {
    cout << "{ ";
    for (auto y : x) {
      cout << y << " ";
    }
    cout << "} ";
  }
  cout << "}\n";
}

class Solution {
public:
  vector<vector<int>> generate(int numRows) {

    if (numRows == 0) {
      return {};
    } else if (numRows == 1) {
      return {{1}};
    } else {
      vector<vector<int>> pascal;
      pascal.push_back({1});
      pascal.push_back({1, 1});

      for (int i = 2; i < numRows; i++) {
        vector<int> row = {1};
        for (int j = 0; j < i - 1; j++) {
          row.push_back(pascal[i - 1][j] + pascal[i - 1][j + 1]);
        }
        row.push_back(1);
        pascal.push_back(row);
      }
      return pascal;
    }
  }
};

int main() {

  Solution S;
  vector<vector<int>> v0 = S.generate(0);
  vector<vector<int>> v1 = S.generate(1);
  vector<vector<int>> v2 = S.generate(2);
  vector<vector<int>> v3 = S.generate(3);
  vector<vector<int>> v4 = S.generate(4);
  vector<vector<int>> v5 = S.generate(5);
  showPascal(v0);
  showPascal(v1);
  showPascal(v2);
  showPascal(v3);
  showPascal(v4);
  showPascal(v5);

  return 0;
}