#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int beg{}, end{}, mid{}, row{};

    beg = 0;
    end = (int)matrix.size() - 1;

    while(beg < end) {
      mid = beg + (end - beg) / 2;
      if(target == matrix[mid].back()) {
        return true;
      }
      else if(target > matrix[mid].back()) {
        beg = mid + 1;
      }
      else {
        end = mid;
      }
    }

    row = beg;
    beg = 0;
    end = (int)matrix[row].size() - 1;
    while(beg <= end) {
      mid = beg + (end - beg) / 2;
      if(target == matrix[row][mid]) {
        return true;
      }
      else if(target > matrix[row][mid]) {
        beg = mid + 1;
      }
      else {
        end = mid - 1;
      }
    }

    return false;
  }
};

int main(){

  Solution S;
  typedef vector<vector<int>> matrix_int;

  vector<pair<matrix_int, int>> testcases {};
  testcases.push_back((pair<matrix_int, int>) {{{1,2,3}, {4,5,6}, {7,8,9}}, 8});
  testcases.push_back((pair<matrix_int, int>) {{{2, 4, 8, 9}, {10, 12, 20, 22}, {100, 120, 121, 199}}, 16});
  testcases.push_back((pair<matrix_int, int>) {{{0, 3, 21}, {70, 80, 82}, {90, 92, 99}, {121, 133, 144}, {150, 151, 199}}, 21});
  testcases.push_back((pair<matrix_int, int>) {{{1,3}}, 3});
  testcases.push_back((pair<matrix_int, int>) {{{1,3,5,7}, {10,11,16,20}, {23,30,34,50}}, 10});

  cout << boolalpha;
  for (auto x : testcases) {
    cout << S.searchMatrix(x.first, x.second) << "\n";
  }

  // Expected output: true, false, true, true, true

  return 0;
}