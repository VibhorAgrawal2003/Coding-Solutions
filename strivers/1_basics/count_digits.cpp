#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int countDigits(int n){
  int dig {};
  while (n > 0) {
    dig++;
	n /= 10;
  }
  return dig;
}

int main() {

  vector<int> testcases {};
  testcases.push_back(12);
  testcases.push_back(789);
  testcases.push_back(90872);
  testcases.push_back(INT_MAX);

  for (auto x : testcases) {
    cout << setw(10) << left << x << " : " << countDigits(x) << " digits \n";
  }

  return 0;
}