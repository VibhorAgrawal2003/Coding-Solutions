#include <iostream>
#include <vector>

using namespace std;

void showVector(vector<int> &v) {
  for (auto x : v) {
    cout << x << " ";
  }
  cout << "\n";
}

class Solution {
public:
  void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {

    int p = m - 1;
    int q = n - 1;
    int x = m + n - 1;

    while (p >= 0 && q >= 0) {
      if (nums1[p] >= nums2[q]) {
        nums1[x] = nums1[p];
        p--;
      } else {
        nums1[x] = nums2[q];
        q--;
      }
      x--;
    }

    if (p >= 0) {
      while (p >= 0) {
        nums1[x] = nums1[p];
        p--;
        x--;
      }
    }

    if (q >= 0) {
      while (q >= 0) {
        nums1[x] = nums2[q];
        q--;
        x--;
      }
    }
  }
};

int main() {

  Solution S;

  vector<int> a1{1, 3, 5, 9, 10, 0, 0, 0, 0, 0, 0};
  vector<int> b1{0, 2, 4, 6, 6, 11};
  int m1{5};
  int n1{6};

  S.merge(a1, m1, b1, n1);
  showVector(a1);
  cout << "------\n";

  vector<int> a2{1, 2, 3, 0, 0, 0};
  vector<int> b2{2, 5, 6};
  int m2{3};
  int n2{3};

  S.merge(a2, m2, b2, n2);
  showVector(a2);
  cout << "------\n";

  vector<int> a3{0};
  vector<int> b3{1};
  int m3{0};
  int n3{1};

  S.merge(a3, m3, b3, n3);
  showVector(a3);
  cout << "------\n";

  vector<int> a4{1};
  vector<int> b4{};
  int m4{1};
  int n4{0};

  S.merge(a4, m4, b4, n4);
  showVector(a4);
  cout << "------\n";

  vector<int> a5{7, 8, 9, 0, 0, 0, 0};
  vector<int> b5{1, 2, 3, 4};
  int m5{3};
  int n5{4};

  S.merge(a5, m5, b5, n5);
  showVector(a5);
  cout << "------\n";

  return 0;
}