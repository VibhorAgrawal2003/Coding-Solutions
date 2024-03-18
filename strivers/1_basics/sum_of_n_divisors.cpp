#include <iostream>
#include <vector>

using namespace std;

int sumOfAllDivisors(int n) {
  int sum = 0;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j * j <= i; j++) {
      if (i % j == 0) {
        sum += j;
        if (j != i / j) {
          sum += i / j;
        }
      }
    }
  }

  return sum;
}

int main() {

  vector<int> testcases{};
  testcases.push_back(1);
  testcases.push_back(2);
  testcases.push_back(3);
  testcases.push_back(4);
  testcases.push_back(5);
  testcases.push_back(6);

  for (auto x : testcases) {
    cout << x << " : " << sumOfAllDivisors(x) << "\n";
  }

  return 0;
}