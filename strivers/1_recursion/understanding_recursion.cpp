#include <iostream>
#include <vector>

using namespace std;

void recursiveLoop(int x, vector<int> &seq) {
  if (seq.back() == x) {
    return;
  }

  seq.push_back(seq.back() + 1);
  recursiveLoop(x, seq);
}

vector<int> printNos(int x) {
  vector<int> seq = {1};
  recursiveLoop(x, seq);
  return seq;
}

int main() {
  vector<int> output = printNos(11);
  for (auto x : output) {
    cout << x << " ";
  }
  cout << "\n";
}