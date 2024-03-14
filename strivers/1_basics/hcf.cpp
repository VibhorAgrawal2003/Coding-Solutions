#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b) {
  for (int i = min(a, b); i>= 1; i--) {
    if (a%i==0 && b%i==0) {
	  return i;
	}
  }
  return 1;
}

int main() {

  vector<pair<int, int>> testcases {};
  testcases.push_back((pair<int, int>) {2, 4});
  testcases.push_back((pair<int, int>) {21, 11});
  testcases.push_back((pair<int, int>) {444, 666});
  testcases.push_back((pair<int, int>) {510, 1010});

  for (auto x : testcases) {
    cout << x.first << " " << x.second << " have hcf: " << gcd(x.first, x.second) << "\n";
  }

  return 0;
}