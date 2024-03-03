#include <iostream>
#include <vector>

using namespace std;

void showMatrix(vector<vector<int>> &matrix) {
  for (auto x : matrix) {
    for (auto y : x) {
      cout << y << " ";
    }
    cout << "\n";
  }
  cout << "\n";
}

class Solution {
public:
  void swapFour(int &p, int &q, int &r, int &s) {
    int t = s;
    s = r;
    r = q;
    q = p;
    p = t;
  }

  void rotate(vector<vector<int>> &matrix) {

    int n = (int)matrix.size();
    for (int i = 0; i < n / 2; i++) {
      for (int j = i; j < n - i - 1; j++) {
        swapFour(matrix[i][j], matrix[j][n - i - 1],
                 matrix[n - i - 1][n - j - 1], matrix[n - j - 1][i]);
      }
    }
  }
};

int main() {

  Solution S;
  vector<vector<vector<int>>> testcases{};
  testcases.push_back((vector<vector<int>>){{1}});
  testcases.push_back((vector<vector<int>>){{1, 2}, {3, 4}});
  testcases.push_back((vector<vector<int>>){{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});
  testcases.push_back((vector<vector<int>>){
      {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}});
  testcases.push_back((vector<vector<int>>){
      {5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}});
  testcases.push_back((vector<vector<int>>){{1, 2, 3, 4, 5},
                                            {6, 7, 8, 9, 10},
                                            {11, 12, 13, 14, 15},
                                            {16, 17, 18, 19, 20},
                                            {21, 22, 23, 24, 25}});

  for (auto x : testcases) {
    S.rotate(x);
    showMatrix(x);
  }

  return 0;
}