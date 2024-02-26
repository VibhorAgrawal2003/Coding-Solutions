#include <iostream>
#include <set>
#include <vector>

using namespace std;

void showMatrix(vector<vector<int>> &v) {
  cout << "\n - - -\n";
  for (auto x : v) {
    for (auto y : x) {
      cout << y << " ";
    }
    cout << "\n";
  }
}

/**
 * Here, we try to achieve O(1) space complexity.
 * For this, we assign the zeroeth row and col as index.
 * We try to manipulate the index and use it to modify the matrix.
 * In the process, our original zeroeth row and col gets altered.
 *
 * To prevent inaccuracies, we therefore, pre-record the useful info
 * from these index row and col and then use it at the end to finish
 * the solution.
 */
class Solution {
public:
  void setZeroes(vector<vector<int>> &matrix) {

    int m = matrix.size();
    int n = matrix[0].size();
    bool xflag = false;
    bool yflag = false;

    // Record behavior of index vectors of matrix
    if (matrix[0][0] == 0) {
      xflag = true;
      yflag = true;
    } else {
      for (int i = 1; i < m; i++) {
        if (matrix[i][0] == 0) {
          yflag = true;
          break;
        }
      }

      for (int j = 1; j < n; j++) {
        if (matrix[0][j] == 0) {
          xflag = true;
          break;
        }
      }
    }

    for (int i = 1; i < m; i++) {
      for (int j = 1; j < n; j++) {
        if (matrix[i][j] == 0) {
          matrix[i][0] = 0;
          matrix[0][j] = 0;
        }
      }
    }

    // Go through all marked rows and adjust values
    for (int k = 1; k < m; k++) {
      if (matrix[k][0] == 0) {
        for (int l = 0; l < n; l++) {
          matrix[k][l] = 0;
        }
      }
    }

    // Go through all marked cols and adjust values
    for (int l = 1; l < n; l++) {
      if (matrix[0][l] == 0) {
        for (int k = 0; k < m; k++) {
          matrix[k][l] = 0;
        }
      }
    }

    // Adjust the index vectors of the matrix
    if (yflag) {
      for (int k = 0; k < m; k++) {
        matrix[k][0] = 0;
      }
    }

    if (xflag) {
      for (int l = 0; l < n; l++) {
        matrix[0][l] = 0;
      }
    }
  }
};

/**
 * Here, we make use of two sets to track which row and col
 * needs to be altered to get the solution.
 *
 * This approach needs less traversal but takes O(m+n) space complexity.
 */
class Subpar {
public:
  void setZeroes(vector<vector<int>> &matrix) {

    set<int> row;
    set<int> col;

    int m = matrix.size();
    int n = matrix[0].size();

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (matrix[i][j] == 0) {
          row.insert(i);
          col.insert(j);
        }
      }
    }

    for (auto i : row) {
      for (int k = 0; k < n; k++) {
        matrix[i][k] = 0;
      }
    }

    for (auto j : col) {
      for (int k = 0; k < m; k++) {
        matrix[k][j] = 0;
      }
    }
  }
};

int main() {

  Solution S;

  vector<vector<int>> t1 = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
  vector<vector<int>> t2 = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
  vector<vector<int>> t3 = {
      {1, 1, 1, 1}, {1, 0, 0, 1}, {1, 0, 0, 1}, {1, 1, 1, 1}};
  vector<vector<int>> t4 = {{0, 1, 1, 1, 1}, {1, 1, 1, 1, 1}};
  vector<vector<int>> t5 = {
      {1, 2, 3, 4}, {5, 0, 7, 8}, {0, 10, 11, 12}, {13, 14, 15, 0}};

  vector<vector<int>> t6 = {{1, 0, 3}};

  S.setZeroes(t1);
  S.setZeroes(t2);
  S.setZeroes(t3);
  S.setZeroes(t4);
  S.setZeroes(t5);
  S.setZeroes(t6);

  showMatrix(t1);
  showMatrix(t2);
  showMatrix(t3);
  showMatrix(t4);
  showMatrix(t5);
  showMatrix(t6);

  return 0;
}