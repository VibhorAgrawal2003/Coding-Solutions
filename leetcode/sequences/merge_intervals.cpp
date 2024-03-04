#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void showMatrix(vector<vector<int>> &v) {
  for (auto x : v) {
    for (auto y : x) {
      cout << y << " ";
    }
    cout << "\n";
  }
}

class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>> &intervals) {
    sort(intervals.begin(), intervals.end(),
         [](vector<int> &x, vector<int> &y) { return x[0] < y[0]; });

    vector<vector<int>> result{};
    vector<int> temp = intervals[0];
    int last = temp[1];
    for (auto x : intervals) {
      if (x[0] <= temp[1]) {
        temp[1] = max(temp[1], x[1]);
      } else {
        result.push_back(temp);
        temp = x;
      }
    }
    result.push_back(temp);

    return result;
  }
};

int main() {

  Solution S;
  vector<vector<vector<int>>> testcases{};
  testcases.push_back((vector<vector<int>>){{1, 3}, {2, 6}, {8, 10}, {15, 18}});
  testcases.push_back((vector<vector<int>>){{1, 4}, {4, 5}});
  testcases.push_back((vector<vector<int>>){
      {2, 6}, {3, 5}, {9, 11}, {1, 4}, {4, 5}, {7, 8}, {7, 9}});

  for (auto x : testcases) {
    showMatrix(x);
    vector<vector<int>> v = S.merge(x);
    showMatrix(v);
    cout << "\n-----------\n";
  }

  return 0;
}