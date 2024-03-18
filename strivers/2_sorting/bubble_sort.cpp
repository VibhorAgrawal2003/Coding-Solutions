#include <iostream>
#include <vector>

using namespace std;

void bubbleSort(vector<int> &nums) {
  int n = (int)nums.size();
  for (int i = 0; i < n - 1; i++) {
    bool flag = true;
    for (int j = 0; j < n - i - 1; j++) {
      if (nums[j] > nums[j + 1]) {
        swap(nums[j], nums[j + 1]);
        flag = false;
      }
    }
    if (flag) {
      return;
    }
  }
}

int main() {

  vector<vector<int>> testcases{};
  testcases.push_back((vector<int>){1, 3, 2, 9, 0, 6, 8, 12, 13});
  testcases.push_back((vector<int>){0, 1, 5, 2, 1, 8, 0, 0, 9, 2});
  testcases.push_back((vector<int>){0, 1, 0, 0, 0, 1, 1, 1, 0});

  for (auto &x : testcases) {
    bubbleSort(x);
  }

  for (auto &x : testcases) {
    for (auto &y : x) {
      cout << y << " ";
    }
    cout << "\n";
  }

  return 0;
}