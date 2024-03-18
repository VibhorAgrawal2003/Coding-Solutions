#include <iostream>
#include <vector>

using namespace std;

void recursiveNTimes(int n, vector<string> &seq) {

  if (n == 0) {
    return;
  };

  seq.push_back("Coding Ninjas");
  recursiveNTimes(n - 1, seq);
}

vector<string> printNTimes(int n) {
  vector<string> res{};
  recursiveNTimes(n, res);
  return res;
}

int main() {

  vector<string> output = printNTimes(6);
  for (auto x : output) {
    cout << x << "\n";
  }

  return 0;
}