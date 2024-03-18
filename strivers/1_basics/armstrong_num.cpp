#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

bool checkArmstrong(int n) {
  int dig = 0;
  int x = n;
  while (x > 0) {
    dig++;
    x /= 10;
  }

  int total = 0;
  x = n;
  while (x > 0) {
    total += pow(x % 10, dig);
    x /= 10;
  }

  return (total == n);
}

int main() {

  vector<int> testcases{};
  testcases.push_back(371);
  testcases.push_back(300);
  testcases.push_back(1634);
  testcases.push_back(1601);

  cout << boolalpha;
  for (auto &x : testcases) {
    cout << checkArmstrong(x) << "\n";
  }

  return 0;
}